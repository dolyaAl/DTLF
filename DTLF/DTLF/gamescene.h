#pragma once
#include <QGraphicsScene>

#include "gamemap.h"

class GameScene: public QGraphicsScene
{
public:
	explicit GameScene(const QRectF& rect, QObject* parent = nullptr);
	~GameScene() override = default;
	void setCurrentMap(const QString& map_name);
public slots:
	void gameTimerSlot();
private:
	void updateObjectPositions();
	static float pixelsToMeters(qreal pixels);
	static qreal metersToPixels(float meters);
	auto coordsToScene(const GameMap& currentMap, const QPointF& coords) const -> QPointF;
	auto shapeToScene(const GameMap& currentMap, const QPolygonF& shape) const -> QPolygonF;
	void generateWorld();
	
	static constexpr float m_pixelsToMeters = 1.0f / 16.0f;
	b2World* m_world = nullptr;
	const GameMap* m_currentMap = nullptr;
	QGraphicsPixmapItem* m_currentPixmap = nullptr;
	float m_timeStep = 1.0f / 60.0f;
	int m_velocityIterations = 6;
	int m_positionIterations = 2;
};
