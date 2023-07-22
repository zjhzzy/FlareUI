#include "PushButton.h"

void Flare::PushButton::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setFont(font());
	QFontMetrics metrics(font());

	if (!IsAbove()) {
		painter.setPen(*buttonBackColor);
		painter.setBrush(*buttonBackBrushColor);
	} else {
		if (IsPress()) {
			painter.setPen(*buttonBackPressedColor);
			painter.setBrush(*buttonBackBrushPressedColor);
		} else {
			painter.setPen(*buttonBackHoverColor);
			painter.setBrush(*buttonBackBrushHoverColor);
		}
	}

	painter.drawRoundedRect(1, 1, width() - 2, height() - 2, XRadius(), YRadius());

	f32 X = 0.f;
	f32 Y = 0.f;
	if (isSetIcon()) {
		X = (width() - (iconSize().width() + metrics.horizontalAdvance(text()))) / 2.f;
		Y = (height() - iconSize().height()) / 2.f;
		if (!IsAbove()) {
			painter.drawPixmap(X, Y, buttonIcon->pixmap(iconSize()));
			painter.setPen(*buttonTextColor);
			painter.setBrush(*buttonTextColor);
		} else {
			if (IsPress()) {
				painter.drawPixmap(X, Y, buttonPressedIcon->pixmap(iconSize()));
				painter.setPen(*buttonTextPressedColor);
				painter.setBrush(*buttonTextPressedColor);
			} else {
				painter.drawPixmap(X, Y, buttonHoverIcon->pixmap(iconSize()));
				painter.setPen(*buttonTextHoverColor);
				painter.setBrush(*buttonTextHoverColor);
			}
		}
		X = X + iconSize().width();
		Y = (height() + metrics.ascent() - metrics.descent()) / 2.f;
	} else {
		if (!IsAbove()) {
			painter.setPen(*buttonTextColor);
			painter.setBrush(*buttonTextColor);
		} else {
			if (IsPress()) {
				painter.setPen(*buttonTextPressedColor);
				painter.setBrush(*buttonTextPressedColor);
			} else {
				painter.setPen(*buttonTextHoverColor);
				painter.setBrush(*buttonTextHoverColor);
			}
		}
		X = (width() - metrics.horizontalAdvance(text())) / 2.f;
		Y = (height() + metrics.ascent() - metrics.descent()) / 2.f;
	}

	painter.drawText(X, Y, text());

	painter.end();
}


Flare::PushButton::PushButton(QWidget* parent)
	: BaseButton(parent),
	buttonBackColor(new QColor(FlareColor::Green)),
	buttonBackHoverColor(new QColor(FlareColor::Green)),
	buttonBackPressedColor(new QColor(FlareColor::Green)),
	buttonBackBrushColor(new QColor(FlareColor::Green)),
	buttonBackBrushHoverColor(new QColor(FlareColor::Green)),
	buttonBackBrushPressedColor(new QColor(FlareColor::Green)),
	buttonTextColor(new QColor(FlareColor::White)),
	buttonTextHoverColor(new QColor(FlareColor::White)),
	buttonTextPressedColor(new QColor(FlareColor::White)),
	buttonIcon(new QIcon()),
	buttonHoverIcon(new QIcon()),
	buttonPressedIcon(new QIcon()),
	isIcon(false) {}

Flare::PushButton::PushButton(const QString& Text, QWidget* parent) :PushButton(parent) {
	setText(Text);
}

Flare::PushButton::PushButton(const Icon& icon, const QString& Text, QWidget* parent) :PushButton(Text, parent) {
	setIcon(icon);
}

Flare::PushButton::PushButton(const Color& color, const Icon& icon, const QString& Text, QWidget* parent) : PushButton(icon, Text, parent) {
	setColor(color);
}

Flare::PushButton::~PushButton() {
	delete buttonBackColor;
	delete buttonTextColor;
	delete buttonBackHoverColor;
	delete buttonTextHoverColor;
	delete buttonBackPressedColor;
	delete buttonTextPressedColor;
	delete buttonBackBrushColor;
	delete buttonBackBrushHoverColor;
	delete buttonBackBrushPressedColor;
	delete buttonIcon;
	delete buttonHoverIcon;
	delete buttonPressedIcon;
}

void Flare::PushButton::setButtonColor(const QColor& color) {
	*buttonBackColor = color;
}

void Flare::PushButton::setButtonHoverColor(const QColor& color) {
	*buttonBackHoverColor = color;
}

void Flare::PushButton::setButtonPressedColor(const QColor& color) {
	*buttonBackPressedColor = color;
}

void Flare::PushButton::setButtonBrushColor(const QColor& color) {
	*buttonBackBrushColor = color;
}

void Flare::PushButton::setButtonBrushHoverColor(const QColor& color) {
	*buttonBackBrushHoverColor = color;
}

void Flare::PushButton::setButtonBrushPressedColor(const QColor& color) {
	*buttonBackBrushPressedColor = color;
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

void Flare::PushButton::setAllIcon(const QIcon& icon) {
	isIcon = true;
	*buttonHoverIcon = icon;
	*buttonIcon = icon;
	*buttonPressedIcon = icon;
}

Flare::PushButton::Icon Flare::PushButton::Icon::setAllIcon(const QIcon& icon) {
	buttonIcon = icon;
	buttonHoverIcon = icon;
	buttonPressedIcon = icon;
}

void Flare::PushButton::setIcon(const Icon& icon) {
	isIcon = true;
	*buttonIcon = icon.buttonIcon;
	*buttonHoverIcon = icon.buttonHoverIcon;
	*buttonPressedIcon = icon.buttonPressedIcon;
}

bool Flare::PushButton::isSetIcon() {
	return isIcon;
}

void Flare::PushButton::setColor(const Color& color) {
	*buttonBackColor = color.buttonBackColor;
	*buttonBackHoverColor = color.buttonBackHoverColor;
	*buttonBackPressedColor = color.buttonBackPressedColor;
	*buttonTextColor = color.buttonTextColor;
	*buttonTextHoverColor = color.buttonTextHoverColor;
	*buttonTextPressedColor = color.buttonTextPressedColor;
}

Flare::PushButton::Color Flare::PushButton::Color::setAllBackColor(const QColor& color) {
	setAllPenColor(color);
	setAllBrushColor(color);
	return *this;
}

Flare::PushButton::Color Flare::PushButton::Color::setAllPenColor(const QColor& color) {
	buttonBackColor = color;
	buttonBackHoverColor = color;
	buttonBackPressedColor = color;
	return *this;
}

Flare::PushButton::Color Flare::PushButton::Color::setAllBrushColor(const QColor& color) {
	buttonBackBrushColor = color;
	buttonBackBrushHoverColor = color;
	buttonBackBrushPressedColor = color;
	return *this;
}

Flare::PushButton::Color Flare::PushButton::Color::setAllTextColor(const QColor& color) {
	buttonTextColor = color;
	buttonTextHoverColor = color;
	buttonTextPressedColor = color;
	return *this;
}
