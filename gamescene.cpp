#include "gamescene.h"

#include <qpalette.h>
#include <box2d/b2_world.h>

GameScene::GameScene(const QRectF& rect, QObject* parent):
	QGraphicsScene(rect, parent)
{
}

void GameScene::setCurrentMap(const QString& map_name)
{
	clear();
	m_currentMap = &GameMap::mapByName(map_name);
	if(!m_currentMap)
	{
		return;
	}
	m_currentPixmap = addPixmap(m_currentMap->mapPixmap().scaled(width(), height(), Qt::AspectRatioMode::KeepAspectRatioByExpanding));
	generateWorld();
}

void GameScene::gameTimerSlot()
{
	if(!m_world)
	{
		return;
	}
	m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);
	updateObjectPositions();
}

void GameScene::updateObjectPositions()
{
	for(auto objectGroup: m_currentMap->mapObjectGroups())
	{
		for(auto object:objectGroup->objects)
		{
			if(object->type() == Object::Type::Dynamic)
			{
				b2Vec2 position = object->body()->GetPosition();
				float angle = object->body()->GetAngle();
				QPointF newPos(coordsToScene(*m_currentMap,
						{ metersToPixels(position.x), metersToPixels(position.y) }));
				object->item()->setPos(newPos);
				object->item()->setRotation(qRadiansToDegrees(angle));
			}
		}
	}
	update();
}

float GameScene::pixelsToMeters(qreal pixels)
{
	return static_cast<float>(pixels) * m_pixelsToMeters;
}

qreal GameScene::metersToPixels(float meters)
{
	return static_cast<qreal>(meters/m_pixelsToMeters);
}

auto GameScene::coordsToScene(const GameMap& currentMap, const QPointF& coords) const -> QPointF
{
	return {coords.x() / currentMap.widthPix() * m_currentPixmap->pixmap().width(),
		coords.y() / currentMap.heightPix() * m_currentPixmap->pixmap().height()};
}

auto GameScene::shapeToScene(const GameMap& currentMap, const QPolygonF& shape) const -> QPolygonF
{
	QPolygonF newShape;
	for(auto point: shape)
	{
		newShape.push_back(coordsToScene(currentMap, point));
	}
	return newShape;
}

void GameScene::generateWorld()
{
	delete m_world;

	m_world = new b2World({ 0, 9.8f });
	for(auto objectGroup: m_currentMap->mapObjectGroups())
	{
		for(auto object:objectGroup->objects)
		{
			object->createBody(m_world, pixelsToMeters);
			object->setItem(addPolygon(shapeToScene(*m_currentMap, object->shape())));
			object->item()->setPos(coordsToScene(*m_currentMap, object->pos()));
		}
	}
}
