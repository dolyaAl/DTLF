#include "worldreader.h"
#include <QFile>

WorldReader::WorldReader(QIODevice* device)
{
	m_reader.setDevice(device);
}

auto WorldReader::readMap(bool& ok) -> GameMap
{
	if(!m_reader.readNextStartElement())
	{
		return {};
	}
	if(tokenByName(m_reader.name()) != Token::map)
	{
		return {};
	}
	GameMap map;
	readMapAttributes(map);
	while(m_reader.readNextStartElement())
	{
		if(!ok)
		{
			ok = true;
		}
		switch (tokenByName(m_reader.name()))
		{
			case Token::layer:
			{
				if(const auto layer = readMapLayer())
				{
					map.addMapLayer(layer);
				}
			}
			break;
			case Token::tileset:
			{
				GameMap::TileSet tileset = readTileSet();
				map.setTileSet(tileset);
			}
			break;
			case Token::objectgroup:
			{
				GameMap::ObjectGroup* group = readObjectGroup();
				map.addObjectGroup(group);
			}
			break;
			default:
			{
				m_reader.skipCurrentElement();
			}
			break;
		}
	}
	return map;
}

auto WorldReader::readTileSet() -> GameMap::TileSet
{
	GameMap::TileSet tileset;
	const QString tilesetFileName = m_reader.attributes().value("source").toString();
	QFile tsxFile(":/tsx/" + tilesetFileName);
	tsxFile.open(QFile::ReadOnly | QFile::Text);
	QXmlStreamReader reader(&tsxFile);
	while(reader.readNextStartElement())
	{
		if(tokenByName(reader.name()) == Token::image)
		{
			tileset.sourceImage = reader.attributes().value("source").toString();
			tileset.imageHeight = reader.attributes().value("height").toInt();
			tileset.imageWidth = reader.attributes().value("width").toInt();
		}
	}
	tsxFile.close();
	m_reader.skipCurrentElement(); //exits from tileset empty tag
	return tileset;
}

auto WorldReader::readMapLayer() -> GameMap::MapLayer*
{
	if(!m_reader.readNextStartElement())
	{
		return nullptr;
	}
	if(tokenByName(m_reader.name()) != Token::data)
	{
		return nullptr;
	}
	auto layer = new GameMap::MapLayer;
	while(m_reader.readNextStartElement())
	{
		if(tokenByName(m_reader.name()) == Token::tile)
		{
			layer->indexes.push_back(m_reader.attributes().value("gid").toUShort());
			m_reader.skipCurrentElement();//since we are inside an empty tag
										  //to move on to the next one,
										  //we need to get out of this one
		}
		else
		{
			m_reader.skipCurrentElement();
		}
	}
	m_reader.skipCurrentElement();
	return layer;
}

auto WorldReader::readObjectGroup() -> GameMap::ObjectGroup*
{
	auto group = new GameMap::ObjectGroup;
	while(m_reader.readNextStartElement())
	{
		if(tokenByName(m_reader.name()) == Token::object)
		{
			if(const auto object = readObject())
			{
				group->objects.push_back(object);
			}
		}
	}
	return group;
}

auto WorldReader::readObject() -> Object*
{
	const qreal width = m_reader.attributes().hasAttribute("width")? m_reader.attributes().value("width").toDouble(): 0;
	const qreal height = m_reader.attributes().hasAttribute("height")? m_reader.attributes().value("height").toDouble(): 0;
	const qreal x = m_reader.attributes().value("x").toDouble() + width/2;//if item has a rect shape, its pos will be in the center
	const qreal y = m_reader.attributes().value("y").toDouble() + height/2;
	Object::Type type{};
	QString shapeType{};
	QPolygonF shape{};
	while(m_reader.readNextStartElement())
	{
		switch(tokenByName(m_reader.name()))
		{
			case Token::properties:
			{
				const QHash<QString, QString> properties = readObjectProperties();
				type = Object::typeByName(properties["Type"]);
				shapeType = properties["Shape"];
			}
			break;
			case Token::polygon:
			{
				shape = readPolygon();
			}
			break;
			default:
			{
				m_reader.skipCurrentElement();
			}
			break;
		}
	}
	Object* object = shapeType == "Polygon"
					 ? new Object(type, shape, { x, y })
					 :shapeType == "Rect"
					 ? new Object(type, QRectF(-width/2,-height/2, width, height), { x, y })
					 :nullptr;
	return object;
}

auto WorldReader::readObjectProperties() -> QHash<QString, QString>
{
	QHash<QString, QString> properties;
	while(m_reader.readNextStartElement())
	{
		if(tokenByName(m_reader.name()) != Token::property)
		{
			continue;
		}
		switch(objectPropertyByName(m_reader.attributes().value("name")))
		{
			case ObjectProperty::Shape: 
			{
				properties["Shape"] = m_reader.attributes().value("value").toString();
			}
			break;
			case ObjectProperty::Type:
			{
				properties["Type"] = m_reader.attributes().value("value").toString();
			}
			break;
			default: 
			{
				m_reader.skipCurrentElement();
			}
			break;
		}
		m_reader.skipCurrentElement();
	}
	return properties;
}

auto WorldReader::readPolygon() -> QPolygonF
{
	if(!m_reader.attributes().hasAttribute("points"))
	{
		return{};
	}
	QPolygonF polygon;
	const QString pointsString = m_reader.attributes().value("points").toString();
	const auto pointsStrList = pointsString.split(QLatin1Char(' '));
	for(auto pointStr = pointsStrList.begin(); pointStr != pointsStrList.end(); ++pointStr)
	{
		const auto pointCoords = pointStr->split(QLatin1Char(','));
		polygon << QPointF(pointCoords[0].toDouble(), pointCoords[1].toDouble());
	}
	m_reader.skipCurrentElement();
	return polygon;
}

void WorldReader::readMapAttributes(GameMap& map)
{
	const int height = m_reader.attributes().value("height").toInt();
	const int width = m_reader.attributes().value("width").toInt();
	const int tileHeight = m_reader.attributes().value("tileheight").toInt();
	const int tileWidth = m_reader.attributes().value("tilewidth").toInt();
	map.setMapAttributes(height, width, tileHeight, tileWidth);
}

auto WorldReader::tokenByName(const QStringView& name) -> Token
{
	const QMetaEnum metaEnum = QMetaEnum::fromType<Token>();
	const QByteArray latin1 = name.toLatin1();
	int result = metaEnum.keyToValue(latin1.constData());
	return static_cast<Token>(result);
}

auto WorldReader::objectPropertyByName(const QStringView& name) -> ObjectProperty
{
	const QMetaEnum metaEnum = QMetaEnum::fromType<ObjectProperty>();
	const QByteArray latin1 = name.toLatin1();
	int result = metaEnum.keyToValue(latin1.constData());
	return static_cast<ObjectProperty>(result);
}
