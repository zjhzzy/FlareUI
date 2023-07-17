#include "PushButton.h"

void Flare::PushButton::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	if (isAbove) {
		painter.setPen(*buttonHoverColor);
		painter.setBrush(*buttonHoverColor);
	} else {
		painter.setPen(*buttonColor);
		painter.setBrush(*buttonColor);
	}
	if (isPress) {
		painter.setPen(*buttonPressedColor);
		painter.setBrush(*buttonPressedColor);
	}
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawRoundedRect(1.5, 1.5, width() - 1.5, height() - 1.5, XRadius(), YRadius());
	painter.setFont(font());
	if (isAbove) {
		painter.setPen(*buttonTextHoverColor);
		painter.setBrush(*buttonTextHoverColor);
	} else {
		painter.setPen(*buttonTextColor);
		painter.setBrush(*buttonTextColor);
	}
	if (isPress) {
		painter.setPen(*buttonTextPressedColor);
		painter.setBrush(*buttonTextPressedColor);
	}

	painter.drawText((width() / 2) - (painter.fontMetrics().horizontalAdvance(text()) / 2),
		(height() / 2) + (painter.fontMetrics().height() / 2) - 1, text());
	painter.end();
}

void Flare::PushButton::enterEvent(QEnterEvent* Event) {
	QAbstractButton::enterEvent(Event);
	isAbove = true;
	update();
}

void Flare::PushButton::leaveEvent(QEvent* Event) {
	QAbstractButton::leaveEvent(Event);
	isAbove = false;
	update();
}

void Flare::PushButton::connectSlot() {
	connect(this, &PushButton::pressed, this, [&]() {
		isPress = true;
		update();
		});
	connect(this, &PushButton::released, this, [&]() {
		isPress = false;
		update();
		});
}

QColor Flare::PushButton::ButtonColor() const {
	return *buttonColor;
}

QColor Flare::PushButton::ButtonHoverColor() const {
	return *buttonHoverColor;
}

QColor Flare::PushButton::ButtonPressedColor() const {
	return *buttonPressedColor;
}


QColor Flare::PushButton::ButtonTextColor() const {
	return *buttonTextColor;
}

QColor Flare::PushButton::ButtonTextHoverColor() const {
	return *buttonTextHoverColor;
}

QColor Flare::PushButton::ButtonTextPressedColor() const {
	return *buttonTextPressedColor;
}

f32 Flare::PushButton::XRadius() {
	return xRadius;
}

f32 Flare::PushButton::YRadius() {
	return yRadius;
}

void Flare::PushButton::setButtonColor(const QColor& color) {
	*buttonColor = color;
}

void Flare::PushButton::setButtonHoverColor(const QColor& color) {
	*buttonHoverColor = color;
}

void Flare::PushButton::setButtonPressedColor(const QColor& color) {
	*buttonPressedColor = color;
}


void Flare::PushButton::setButtonTextColor(const QColor& color) {
	*buttonTextColor = color;
}

void Flare::PushButton::setButtonTextHoverColor(const QColor& color) {
	*buttonTextHoverColor = color;
}

void Flare::PushButton::setButtonTextPressedColor(const QColor& color) {
	*buttonTextPressedColor = color;
}

void Flare::PushButton::setColor(const Color& color) {
	*buttonColor = color.buttonColor;
	*buttonHoverColor = color.buttonHoverColor;
	*buttonPressedColor = color.buttonPressedColor;
	*buttonTextColor = color.buttonTextColor;
	*buttonTextHoverColor = color.buttonTextHoverColor;
	*buttonTextPressedColor = color.buttonTextPressedColor;
}

void Flare::PushButton::setxRadius(f32 Radius) {
	xRadius = Radius;
}

void Flare::PushButton::setyRadius(f32 Radius) {
	yRadius = Radius;
}

void Flare::PushButton::setRadius(f32 XRadius, f32 YRadius) {
	setxRadius(XRadius);
	setyRadius(YRadius);
}


Flare::PushButton::PushButton(QWidget* parent)
	: QAbstractButton(parent),
	isAbove(false),
	isPress(false),
	xRadius(0),
	yRadius(0),
	buttonColor(new QColor(FlareColor::BlueLight)),
	buttonHoverColor(new QColor(FlareColor::BlueLight)),
	buttonPressedColor(new QColor(FlareColor::Black)),
	buttonTextColor(new QColor(FlareColor::White)),
	buttonTextHoverColor(new QColor(FlareColor::White)),
	buttonTextPressedColor(new QColor(FlareColor::White)) {
	connectSlot();
}

Flare::PushButton::PushButton(const QString& text, QWidget* parent) : PushButton(parent) {
	this->setText(text);
}

Flare::PushButton::PushButton(const QString& text, Color& color, QWidget* parent) : PushButton(text) {
	setColor(color);
}

Flare::PushButton::~PushButton() {
	delete buttonColor;
	delete buttonHoverColor;
	delete buttonPressedColor;
	delete buttonTextColor;
	delete buttonTextHoverColor;
	delete buttonTextPressedColor;
}

Flare::PushButton::Color Flare::PushButton::Color::setButtonColor(QColor ButtonColor) {
	buttonColor = ButtonColor;
	buttonHoverColor = ButtonColor;
	buttonPressedColor = ButtonColor;
	return *this;
}

Flare::PushButton::Color Flare::PushButton::Color::setTextColor(QColor TextColor) {
	buttonTextColor = TextColor;
	buttonTextHoverColor = TextColor;
	buttonTextPressedColor = TextColor;
	return *this;
}

Flare::PushButton::Color::Color(QColor ButtonColor, QColor TextColor) {
	setTextColor(TextColor);
	setButtonColor(ButtonColor);
}
