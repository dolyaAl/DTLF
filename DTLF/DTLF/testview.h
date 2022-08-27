#pragma once
#include <QGraphicsView>
#include <box2d/box2d.h>
#include "gamescene.h"
class testview: public QGraphicsView
{
public:
	testview(QWidget* parent = nullptr);
	~testview() = default;
private:
	QTimer* m_timer;
};

