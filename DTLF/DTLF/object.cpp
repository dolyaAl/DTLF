#include "object.h"
#include <QMetaEnum>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_world.h>

Object::Object(Type type, const QPolygonF& shape, const QPointF& position):
	m_pos(position),
	m_shape(shape),
	m_type(type)
{}

Object::Object(Type type, const QRectF& rect, const QPointF& position):
	Object(type, QPolygonF(rect), position)
{}

auto Object::type() const -> Object::Type
{
	return m_type;
}

auto Object::pos() const -> QPointF
{
	return m_pos;
}

auto Object::shape() const -> const QPolygonF&
{
	return m_shape;
}

auto Object::body() const -> b2Body*
{
	return m_body;
}

auto Object::item() const -> QGraphicsItem*
{
	return m_appropriateItem;
}

auto Object::createB2BodyShape(float pixelsToMeters(qreal)) const -> b2PolygonShape
{
	b2PolygonShape polygonShape;
	const decltype(shape().count()) pointsCount = shape().count();
	auto points = new b2Vec2[pointsCount];
	for (int i = 0; i < pointsCount; ++i)
	{
		points[i] = { pixelsToMeters(shape().at(i).x()),
						pixelsToMeters(shape().at(i).y()) };
	}
	polygonShape.Set(points, pointsCount);
	return polygonShape;
}

void Object::setItem(QGraphicsItem* item)
{
	m_appropriateItem = item;
}

void Object::createBody(b2World* world, float pixelsToMeters(qreal))
{
	if(m_body)
	{
		return;
	}
	b2BodyDef bodyDef;
	b2FixtureDef fixtureDef;
	if(type() == Type::Dynamic)
	{
		bodyDef.type = b2_dynamicBody;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.restitution = 0.5f;
	}
	bodyDef.position.Set(pixelsToMeters(pos().x()), pixelsToMeters(pos().y()));
	b2PolygonShape polygonShape = createB2BodyShape(pixelsToMeters);
	fixtureDef.shape = &polygonShape;
	m_body = world->CreateBody(&bodyDef);
	m_body->CreateFixture(&fixtureDef);
}

void Object::setPos(const QPointF& point)
{
	m_pos = point;
}

void Object::setShape(const QPolygonF& shape)
{
	m_shape = shape;
}

Object::Type Object::typeByName(const QStringView& name)
{
	const QMetaEnum metaEnum = QMetaEnum::fromType<Type>();
	const QByteArray latin1 = name.toLatin1();
	int result = metaEnum.keyToValue(latin1.constData());
	return static_cast<Type>(result);
}
