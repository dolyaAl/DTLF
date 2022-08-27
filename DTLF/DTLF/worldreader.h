#pragma once
#include <QXmlStreamReader>
#include <QMetaEnum>
#include "gamemap.h"
class WorldReader
{
	Q_GADGET
public:
	explicit WorldReader(QIODevice* device);
	[[nodiscard]]auto readMap(bool& ok) -> GameMap;
	[[nodiscard]]auto readTileSet()->GameMap::TileSet;
	[[nodiscard]]auto readMapLayer()->GameMap::MapLayer*;
	[[nodiscard]]auto readObjectGroup()->GameMap::ObjectGroup*;
	[[nodiscard]]auto readObject()->Object*;
	[[nodiscard]]auto readObjectProperties()->QHash<QString, QString>;
	[[nodiscard]]auto readPolygon() -> QPolygonF;
	void readMapAttributes(GameMap& map);

	enum class Token
	{
		invalid = -1,
		map,
		tileset,
		layer,
		data,
		tile,
		objectgroup,
		object,
		image,
		properties,
		property,
		polygon
	};
	Q_ENUM(Token)
	static auto tokenByName(const QStringView& name) -> Token;
	enum class ObjectProperty
	{
		Invalid = -1,
		Shape,
		Type
	};
	Q_ENUM(ObjectProperty)
	static auto objectPropertyByName(const QStringView& name) -> ObjectProperty;
private:
	QXmlStreamReader m_reader;
};

