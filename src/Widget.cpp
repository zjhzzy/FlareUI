#include "Widget.h"

void Flare::Widget::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	painter.setPen(BackColor());
	painter.setBrush(BackColor());
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawRoundedRect(1, 1, width() - 2, height() - 2, XRadius(), YRadius(), Qt::AbsoluteSize);
	painter.end();
}

void Flare::Widget::enterEvent(QEnterEvent* Event) {
	QWidget::enterEvent(Event);
	isAbove = true;
}

void Flare::Widget::leaveEvent(QEvent* Event) {
	QWidget::leaveEvent(Event);
	isAbove = false;
}

void Flare::Widget::mousePressEvent(QMouseEvent* Event) {
	QWidget::mousePressEvent(Event);
	emit press(Event->pos());
}

void Flare::Widget::mouseReleaseEvent(QMouseEvent* Event) {
	QWidget::mouseReleaseEvent(Event);
	emit release();
}

Flare::Widget::Widget(QWidget* parent)
	: QWidget(parent), backColor(new QColor(FlareColor::White)) {
	xRadius = 0;
	yRadius = 0;
	isAbove = false;
}

Flare::Widget::~Widget(){
    qDebug() << "已经调用Widget析构函数";
    delete backColor;
}

f32 Flare::Widget::XRadius() const {
	return xRadius;
}

f32 Flare::Widget::YRadius() const {
	return yRadius;
}

QColor Flare::Widget::BackColor() {
	return *backColor;
}

void Flare::Widget::setxRadius(f32 Radius) {
	xRadius = Radius;
}

void Flare::Widget::setyRadius(f32 Radius) {
	yRadius = Radius;
}

void Flare::Widget::setRadius(f32 XRadius, f32 YRadius) {
	xRadius = XRadius;
	yRadius = YRadius;
}

void Flare::Widget::setBackColor(const QColor& color) {
	*backColor = color;
}

