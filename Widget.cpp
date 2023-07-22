#include "Widget.h"

void Flare::Widget::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	painter.setPen(WidgetColor());
	painter.setBrush(WidgetColor());
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawRoundedRect(1, 1, width() - 1, height() - 1, XRadius(), YRadius(), Qt::RelativeSize);
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
	: QWidget(parent), WidgetBackColor(new QColor(FlareColor::White)) {
	xRadius = 0;
	yRadius = 0;
	isAbove = false;
}

Flare::Widget::~Widget() {}

f32 Flare::Widget::XRadius() {
	return xRadius;
}

f32 Flare::Widget::YRadius() {
	return yRadius;
}

QColor Flare::Widget::WidgetColor() {
	return *WidgetBackColor;
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

void Flare::Widget::setWidgetColor(const QColor& color) {
	*WidgetBackColor = color;
}
