#include "Widget.h"

void Widget::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	painter.setPen(WidgetColor());
	painter.setBrush(WidgetColor());
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawRoundedRect(0, 0, width(), height(), XRadius(), YRadius(), Qt::RelativeSize);
	painter.end();
}

void Widget::enterEvent(QEnterEvent* Event) {
	QWidget::enterEvent(Event);
	isAbove = true;
}

void Widget::leaveEvent(QEvent* Event) {
	QWidget::leaveEvent(Event);
	isAbove = false;
}

void Widget::mousePressEvent(QMouseEvent* Event) {
	QWidget::mousePressEvent(Event);
	emit press(Event->pos());
}

void Widget::mouseReleaseEvent(QMouseEvent* Event) {
	QWidget::mouseReleaseEvent(Event);
	emit release();
}

Widget::Widget(QWidget *parent)
	: QWidget(parent),WidgetBackColor(new QColor(FlareColor::White)){
	xRadius = 0;
	yRadius = 0;
	isAbove = false;
}

Widget::~Widget()
{}

f32 Widget::XRadius() {
	return xRadius;
}

f32 Widget::YRadius() {
	return yRadius;
}

QColor Widget::WidgetColor() {
	return *WidgetBackColor;
}

void Widget::setxRadius(f32 Radius) {
	xRadius = Radius;
}

void Widget::setyRadius(f32 Radius) {
	yRadius = Radius;
}

void Widget::setRadius(f32 XRadius, f32 YRadius) {
	xRadius = XRadius;
	yRadius = YRadius;
}

void Widget::setWidgetColor(const QColor& color) {
	*WidgetBackColor = color;
}
