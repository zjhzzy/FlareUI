#include "TextButton.h"

void Flare::TextButton::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	if (IsAbove()) {
		painter.setPen(*buttonPenHoverColor);
		painter.setBrush(*buttonBrushHoverColor);
	} else {
		painter.setPen(*buttonPenColor);
		painter.setBrush(*buttonBrushColor);
	}
	if (IsPress()) {
		painter.setPen(*buttonPenPressedColor);
		painter.setBrush(*buttonBrushPressedColor);
	}
	painter.setRenderHint(QPainter::Antialiasing, true);

	painter.drawRoundedRect(1, 1, width() - 2, height() - 2, XRadius(), YRadius());

	painter.setFont(font());
	if (IsAbove()) {
		painter.setPen(*buttonTextHoverColor);
		painter.setBrush(*buttonTextHoverColor);
	} else {
		painter.setPen(*buttonTextColor);
		painter.setBrush(*buttonTextColor);
	}
	if (IsPress()) {
		painter.setPen(*buttonTextPressedColor);
		painter.setBrush(*buttonTextPressedColor);
	}

	painter.drawText((width() / 2) - (painter.fontMetrics().horizontalAdvance(text()) / 2),
		(height() / 2) + (painter.fontMetrics().height() / 2) - 1, text());
	painter.end();
}

QColor Flare::TextButton::ButtonBrushColor() const {
	return *buttonBrushColor;
}

QColor Flare::TextButton::ButtonBrushHoverColor() const {
	return *buttonBrushHoverColor;
}

QColor Flare::TextButton::ButtonBrushPressedColor() const {
	return *buttonBrushPressedColor;
}


QColor Flare::TextButton::ButtonTextColor() const {
	return *buttonTextColor;
}

QColor Flare::TextButton::ButtonTextHoverColor() const {
	return *buttonTextHoverColor;
}

QColor Flare::TextButton::ButtonTextPressedColor() const {
	return *buttonTextPressedColor;
}

void Flare::TextButton::setButtonBrushColor(const QColor& color) {
	*buttonBrushColor = color;
	*buttonBrushHoverColor = color;
	*buttonBrushPressedColor = color;
}

void Flare::TextButton::setButtonBrushHoverColor(const QColor& color) {
	*buttonBrushHoverColor = color;
}

void Flare::TextButton::setButtonBrushPressedColor(const QColor& color) {
	*buttonBrushPressedColor = color;
}


void Flare::TextButton::setButtonTextColor(const QColor& color) {
	*buttonTextColor = color;
}

void Flare::TextButton::setButtonTextHoverColor(const QColor& color) {
	*buttonTextHoverColor = color;
}

void Flare::TextButton::setButtonTextPressedColor(const QColor& color) {
	*buttonTextPressedColor = color;
}

void Flare::TextButton::setColor(const Color& color) {
	*buttonBrushColor = color.buttonBrushColor;
	*buttonBrushHoverColor = color.buttonBrushHoverColor;
	*buttonBrushPressedColor = color.buttonBrushPressedColor;
	*buttonTextColor = color.buttonTextColor;
	*buttonTextHoverColor = color.buttonTextHoverColor;
	*buttonTextPressedColor = color.buttonTextPressedColor;
}


Flare::TextButton::TextButton(QWidget* parent)
	: BaseButton(parent),
	buttonBrushColor(new QColor(FlareColor::Green)),
	buttonBrushHoverColor(new QColor(FlareColor::Green)),
	buttonBrushPressedColor(new QColor(FlareColor::Green)),
	buttonPenColor(new QColor(FlareColor::Green)),
	buttonPenHoverColor(new QColor(FlareColor::Green)),
	buttonPenPressedColor(new QColor(FlareColor::Green)),
	buttonTextColor(new QColor(FlareColor::White)),
	buttonTextHoverColor(new QColor(FlareColor::White)),
	buttonTextPressedColor(new QColor(FlareColor::White)),
	AutoSize(false){}

Flare::TextButton::TextButton(const QString& text, QWidget* parent) : TextButton(parent) {
	this->setText(text);
}

Flare::TextButton::TextButton(const QString& text, Color& color, QWidget* parent) : TextButton(text) {
	setColor(color);
}

Flare::TextButton::~TextButton() {
	delete buttonBrushColor;
	delete buttonBrushHoverColor;
	delete buttonBrushPressedColor;
	delete buttonPenColor;
	delete buttonPenHoverColor;
	delete buttonPenPressedColor;
	delete buttonTextColor;
	delete buttonTextHoverColor;
	delete buttonTextPressedColor;
}

Flare::TextButton::Color Flare::TextButton::Color::setButtonColor(const QColor& ButtonColor) {
	setButtonPenColor(ButtonColor);
	setButtonBrushColor(ButtonColor);
	return *this;
}

Flare::TextButton::Color Flare::TextButton::Color::setButtonPenColor(const QColor& ButtonColor) {
	buttonPenColor = ButtonColor;
	buttonPenHoverColor = ButtonColor;
	buttonPenPressedColor = ButtonColor;
	return *this;
}

Flare::TextButton::Color Flare::TextButton::Color::setButtonBrushColor(const QColor& ButtonColor) {
	buttonBrushColor = ButtonColor;
	buttonBrushHoverColor = ButtonColor;
	buttonBrushPressedColor = ButtonColor;
	return *this;
}

Flare::TextButton::Color Flare::TextButton::Color::setTextColor(QColor TextColor) {
	buttonTextColor = TextColor;
	buttonTextHoverColor = TextColor;
	buttonTextPressedColor = TextColor;
	return *this;
}

Flare::TextButton::Color::Color(QColor ButtonColor, QColor TextColor) {
	setTextColor(TextColor);
	setButtonColor(ButtonColor);
}
