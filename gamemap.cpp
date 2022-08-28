#include "gamemap.h"
#include "worldreader.h"
#include <QFile>
#include <QPainter>

//GameMap::~GameMap()
//{
	//for (auto layer: m_mapLayers)
	//{
		//delete layer;
	//}
	//for (auto group: m_objectGroups)
	//{
		//delete group;
	//}
//}

void GameMap::TileSet::loadImage()
{
	image = new QPixmap();
	image->load(":/images/" + sourceImage);
}

void GameMap::MapLayer::initPixmap(const TileSet& tileset, int height, int width, int tileHeight, int tileWidth)
{
	if(!tileset.image)
	{
		return;
	}
	if(layer)
	{
		return;
	}
	if(!layer)
	{
		layer = new QPixmap(tileWidth * width, tileHeight * height);
		layer->fill(Qt::transparent);
	}
	const int columns = tileset.imageWidth / tileWidth;
	QPainter painter(layer);
	for(decltype(indexes.size()) pos = 0; pos < indexes.size(); ++pos)
	{
		QRect target(pos % width * tileWidth, pos / width * tileHeight, tileWidth, tileHeight);
		QRect source((indexes[pos] - 1)%columns * tileWidth, (indexes[pos] - 1)/columns * tileHeight, tileWidth, tileHeight);
		painter.drawPixmap(target, *tileset.image, source);
	}
}

void GameMap::addMapLayer(MapLayer* layer)
{
	m_mapLayers.push_back(layer);
}

void GameMap::addObjectGroup(ObjectGroup* group)
{
	m_objectGroups.push_back(group);
}

void GameMap::setMapAttributes(int height, int width, int tile_height, int tile_width)
{
	m_height = height;
	m_width = width;
	m_tileWidth = tile_width;
	m_tileHeight = tile_height;
}

void GameMap::setTileSet(const TileSet& tileset)
{
	m_tileSet = tileset;
}

QVector<GameMap::MapLayer*> GameMap::mapLayers() const
{
	return m_mapLayers;
}

const QPixmap* GameMap::mapPixmapByName(const QString& map_name)
{
	if(m_maps[map_name].mapPixmap().isNull())
	{
		return nullptr;
	}
	return &m_maps[map_name].mapPixmap();
}

auto GameMap::mapByName(const QString& map_name) -> const GameMap&
{
	if(!m_maps[map_name].isNull())
	{
		return m_maps[map_name];
	}
	QFile file(":/maps/" + map_name + ".tmx");
	file.open(QFile::ReadOnly | QFile::Text);
	WorldReader pars(&file);
	bool ok = false;
	m_maps[map_name] = pars.readMap(ok);
	if(ok)
	{
		m_maps[map_name].initLayersPixmaps();
		m_maps[map_name].initMapPixmap();
	}
	file.close();
	return m_maps[map_name];
}

void GameMap::initLayersPixmaps()
{
	if(!m_tileSet.image)
	{
		m_tileSet.loadImage();
	}
	for (auto layer: m_mapLayers)
	{
		layer->initPixmap(m_tileSet, m_height, m_width, m_tileHeight, m_tileWidth);
	}
}

void GameMap::initMapPixmap()
{
	m_mapPixmap = QPixmap(m_width * m_tileWidth, m_height * m_tileHeight);
	QPainter painter(&m_mapPixmap);
	for(int i = 0; i < m_mapLayers.size(); ++i)
	{
		painter.drawPixmap(0, 0, *m_mapLayers[i]->layer);
	}
	m_isNull = false;
}

const QPixmap& GameMap::mapPixmap() const
{
	return m_mapPixmap;
}

auto GameMap::isNull() const -> bool
{
	return m_isNull;
}

auto GameMap::mapObjectGroups() const -> QVector<ObjectGroup*>
{
	return m_objectGroups;
}

auto GameMap::height() const -> int
{
	return m_height;
}

auto GameMap::width() const -> int
{
	return m_width;
}

auto GameMap::widthPix() const -> int
{
	return m_width * m_tileWidth;
}

auto GameMap::heightPix() const -> int
{
	return m_height * m_tileHeight;
}

QHash<QString, GameMap> GameMap::m_maps;
