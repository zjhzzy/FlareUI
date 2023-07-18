#include "BaseButton.h"

void BaseButton::enterEvent(QEnterEvent* event) {
	QAbstractButton::enterEvent(event);
	isAbove = true;
	update();
	emit moveAbove();
}

void BaseButton::leaveEvent(QEvent* event) {
	QAbstractButton::leaveEvent(event);
	isAbove = false;
	update();
	emit leaveAbove();
}

void BaseButton::mousePressEvent(QMouseEvent* event) {
	QAbstractButton::mousePressEvent(event);
	isPress = true;
	update();
}

void BaseButton::mouseReleaseEvent(QMouseEvent* event) {
	QAbstractButton::mouseReleaseEvent(event);
	isPress = false;
	update();
}

BaseButton::BaseButton(QWidget *parent)
	: QAbstractButton(parent),
	xRadius(0),yRadius(0),
	isAbove(false),isPress(false){
}

BaseButton::~BaseButton()
{}

f32 BaseButton::XRadius() {
	return xRadius;
}

f32 BaseButton::YRadius() {
	return yRadius;
}

bool BaseButton::IsPress() {
	return isPress;
}

bool BaseButton::IsAbove() {
	return isAbove;
}

void BaseButton::setXRadius(const f32& Radius) {
	xRadius = Radius;
}

void BaseButton::setYRadius(const f32& Radius) {
	yRadius = Radius;
}

void BaseButton::setRadius(const f32& Xradius, const f32& Yradius) {
	setXRadius(Xradius);
	setYRadius(Yradius);
}
