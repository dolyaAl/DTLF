#pragma once
#include "object.h"

class GameMap
{
public:
	GameMap() = default;
	//~GameMap();
	struct TileSet
	{
		void loadImage();
		int firstgid = 0;
		int imageHeight = 0;
		int imageWidth = 0;
		QString sourceImage = {};
		QPixmap* image = nullptr;
	};
	struct MapLayer
	{
		QVector<quint16> indexes;
		QPixmap* layer = nullptr;
		void initPixmap(const TileSet& tileset, int height, int width, int tileHeight, int tileWidth);
	};
	struct ObjectGroup
	{
		QVector<Object*> objects;
	};
	void addMapLayer(MapLayer* layer);
	void addObjectGroup(ObjectGroup* group);
	void setMapAttributes(int height, int width, int tile_height, int tile_width);
	void setTileSet(const TileSet& tileset);
	[[nodiscard]] auto mapPixmap() const->const QPixmap&;
	[[nodiscard]] auto isNull() const -> bool;
	[[nodiscard]] auto mapObjectGroups() const ->QVector<ObjectGroup*>;
	[[nodiscard]] auto height() const -> int;
	[[nodiscard]] auto width() const -> int;
	[[nodiscard]] auto widthPix() const -> int;
	[[nodiscard]] auto heightPix() const -> int;
	static auto mapPixmapByName(const QString& map_name) -> const QPixmap*;
	static auto mapByName(const QString& map_name) -> const GameMap&;
private:
	[[nodiscard]] auto mapLayers() const->QVector<MapLayer*>;
	void initLayersPixmaps();
	void initMapPixmap();

	int m_height = 0;
	int m_width = 0;
	int m_tileWidth = 0;
	int m_tileHeight = 0;
	//bool m_infiniteFlag = false; - maybe it'll be added later
	bool m_isNull = true;
	TileSet m_tileSet;
	QVector<MapLayer*> m_mapLayers;
	QVector<ObjectGroup*> m_objectGroups;
	QPixmap m_mapPixmap;
	static QHash<QString, GameMap> m_maps;
};
