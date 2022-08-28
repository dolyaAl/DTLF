#include "testview.h"
#include "gamemap.h"
#include "object.h"
#include <QTimer>

testview::testview(QWidget* parent):QGraphicsView(parent)
{
	m_timer = new QTimer(this);
	showFullScreen();
	auto scene = new GameScene(rect(), this);
	scene->setCurrentMap("some");
	//setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setScene(scene);
	connect(m_timer, &QTimer::timeout, scene, &GameScene::gameTimerSlot);
	m_timer->start(1000.0/60.0);
}
