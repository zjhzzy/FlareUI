#include "FlareWindow.h"

Flare::FlareWindow::FlareWindow(QWidget* parent)
	: QMainWindow(parent),
	CloseButton(new IconButton(this)),
	HideButton(new IconButton(this)),
	EnlargeButton(new IconButton(this)),
	isMax(false),
	EnlargeIcon(new IconButton::Icon()),
	MinimizeIcon(new IconButton::Icon()),
	OriginalSize(new QSize()),
	Title(new Widget(this)),
	OriginalPoint(new QPoint()),
	MousePoint(new QPoint()),
	Background(new Widget(this)) {
	connectSlot();

	isTitlePress = false;

	IconButton::Icon CloseIcon;
	CloseIcon.setAllIcon(QIcon(":/image/closebutton-hover.png"));
	CloseIcon.buttonIcon = QIcon(":/image/closebutton.png");
	CloseButton->setIcon(CloseIcon);
	IconButton::Icon HideIcon;
	HideIcon.setAllIcon(QIcon(":/image/minibutton-hover.png"));
	HideIcon.buttonIcon = QIcon(":/image/minibutton.png");
	HideButton->setIcon(HideIcon);
	EnlargeIcon->setAllIcon(QIcon(":/image/maxbutton-hover.png"));
	EnlargeIcon->buttonIcon = QIcon(":/image/maxbutton.png");
	EnlargeButton->setIcon(*EnlargeIcon);
	MinimizeIcon->setAllIcon(QIcon(":/image/restorebutton-hover.png"));
	MinimizeIcon->buttonIcon = QIcon(":/image/restorebutton.png");

	setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//去掉标题栏
	setAttribute(Qt::WA_TranslucentBackground);

	CloseButton->resize(20, 20);
	EnlargeButton->resize(20, 20);
	HideButton->resize(20, 20);
	CloseButton->setColor(Flare::IconButton::Color().setAllColor(FlareColor::White));
	EnlargeButton->setColor(Flare::IconButton::Color().setAllColor(FlareColor::White));
	HideButton->setColor(Flare::IconButton::Color().setAllColor(FlareColor::White));
	widgetMove();
	Title->move(0, 1);
	Background->move(0, Title->y() + Title->height());
	Background->resize(width(), height() - Title->height());
}


void Flare::FlareWindow::connectSlot() {
	connect(CloseButton, &IconButton::clicked, this, &FlareWindow::close);
	connect(HideButton, &IconButton::clicked, this, &FlareWindow::showMinimized);
	connect(EnlargeButton, &IconButton::clicked, this, [&]() {
		if (isMax) {
			restoreOriginalSize();
			EnlargeButton->setIcon(*EnlargeIcon);
		} else {
			OriginalSize->setWidth(width());
			OriginalSize->setHeight(height());
			OriginalPoint->setX(x());
			OriginalPoint->setY(y());
			showMaximized();
			EnlargeButton->setIcon(*MinimizeIcon);
		}
		isMax = !isMax;
		});
	connect(Title, &Widget::press, this, [&](QPoint mouseOffset) {
		isTitlePress = true;
		*MousePoint = mouseOffset;
		});
	connect(Title, &Widget::release, this, [&]() {
		isTitlePress = false;
		});
	connect(this, &FlareWindow::show, this, [&]() {
		MousePoint->setX(x());
		qDebug() << x();
		qDebug() << y();
		MousePoint->setY(y());
		});

}

void Flare::FlareWindow::widgetMove() {
	CloseButton->move(width() - 21, 1);
	EnlargeButton->move(CloseButton->x() - CloseButton->width(), 1);
	HideButton->move(EnlargeButton->x() - EnlargeButton->width(), 1);
	Title->resize(width() - 1, 20);
	Background->resize(width()-1, height() - Title->height());
}

void Flare::FlareWindow::resizeEvent(QResizeEvent* Event) {
	QWidget::resizeEvent(Event);
	widgetMove();
}

void Flare::FlareWindow::restoreOriginalSize() {
	resize(*OriginalSize);
	move(OriginalPoint->x(), OriginalPoint->y());
}

void Flare::FlareWindow::mouseMoveEvent(QMouseEvent* event) {
	QMainWindow::mouseMoveEvent(event);

	if (isTitlePress && event->buttons() & Qt::LeftButton) {
		// 计算鼠标移动的偏移量
		QPoint delta = event->pos() - *MousePoint;
		// 移动窗口到新位置
		move(pos() + delta);
	}
}

Flare::FlareWindow::~FlareWindow() {
	delete EnlargeIcon;
	delete MinimizeIcon;
	delete OriginalPoint;
	delete OriginalSize;
	delete EnlargeButton;
	delete CloseButton;
	delete HideButton;
}