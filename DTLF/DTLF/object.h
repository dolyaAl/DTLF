#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QPolygonF>
#include <box2d/b2_body.h>
class Object
{
	Q_GADGET
public:
	enum class Type
	{
		Invalid = -1,
		Static,
		Dynamic
	};
	Q_ENUM(Type)
	explicit Object(Type type, const QPolygonF& shape = {}, const QPointF& position = {});
	explicit Object(Type type, const QRectF& rect, const QPointF& position);
	~Object() = default;
	[[nodiscard]] auto type() const -> Type;
	[[nodiscard]] auto pos() const -> QPointF;
	[[nodiscard]] auto shape() const -> const QPolygonF&;
	[[nodiscard]] auto body() const -> b2Body*;
	[[nodiscard]] auto item() const->QGraphicsItem*;
	void setItem(QGraphicsItem* item);
	void createBody(b2World* world, float pixelsToMeters(qreal));
	void setPos(const QPointF& point);
	void setShape(const QPolygonF& shape);
	static Type typeByName(const QStringView& name);
private:
	[[nodiscard]] auto createB2BodyShape(float (*pixelsToMeters)(qreal)) const -> b2PolygonShape;

	QPointF m_pos = {0, 0};
	QPolygonF m_shape;
	Type m_type;
	b2Body* m_body = nullptr;
	QGraphicsItem* m_appropriateItem = nullptr;
};

