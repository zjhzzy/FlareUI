#include "IconButton.h"

void Flare::IconButton::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	if (IsAbove()) {
		painter.setPen(*buttonBackHoverColor);
		painter.setBrush(*buttonBackHoverColor);
	} else {
		if (IsPress()) {
			painter.setPen(*buttonBackPressedColor);
			painter.setBrush(*buttonBackPressedColor);
		} else {
			painter.setPen(*buttonBackColor);
			painter.setBrush(*buttonBackColor);
		}
	}

	painter.drawRoundedRect(1, 1, width() - 2, height() - 2, XRadius(), YRadius());

	if (IsAbove() and !IsPress()) {
		painter.drawPixmap(1 + wDistance, 1 + hDistance, width() - (wDistance * 2) - 2, height() - (hDistance * 2) - 2,
			buttonHovenIcon->pixmap(width() - (wDistance * 2) - 2, height() - (hDistance * 2) - 2));
	} else if (!IsAbove() and !IsPress()) {
		painter.drawPixmap(1 + wDistance, 1 + hDistance, width() - (wDistance * 2) - 2, height() - (hDistance * 2) - 2,
			buttonIcon->pixmap(width() - (wDistance * 2) - 2, height() - (hDistance * 2) - 2));
	} else if (IsPress()) {
		painter.drawPixmap(1 + wDistance, 1 + hDistance, width() - (wDistance * 2) - 2, height() - (hDistance * 2) - 2,
			buttonPressedIcon->pixmap(width() - (wDistance * 2) - 2, height() - (hDistance * 2) - 2));
	}
	painter.end();
}

void Flare::IconButton::setWDistance(const f32& Distance) {
	wDistance = Distance;
}

void Flare::IconButton::setHDistance(const f32& Distance) {
	hDistance = Distance;
}

void Flare::IconButton::setDistance(const f32& WDistance, const f32& HDistance) {
	setWDistance(WDistance);
	setHDistance(HDistance);
}

Flare::IconButton::IconButton(QWidget* parent)
	:BaseButton(parent),
	buttonIcon(new QIcon()),
	buttonHovenIcon(new QIcon()),
	buttonPressedIcon(new QIcon()),
	buttonBackColor(new QColor(FlareColor::White)),
	buttonBackHoverColor(new QColor(FlareColor::Grey4)),
	buttonBackPressedColor(new QColor(FlareColor::Grey3)),
	wDistance(0),
	hDistance(0){
	resize(32, 32);

}

Flare::IconButton::IconButton(const Icon& icon, QWidget* parent)
	: IconButton(parent) {
	buttonIcon = new QIcon(icon.buttonIcon);
	buttonHovenIcon = new QIcon(icon.buttonHovenIcon);
	buttonPressedIcon = new QIcon(icon.buttonPressedIcon);
}

Flare::IconButton::~IconButton() {}

void Flare::IconButton::setIcon(const Icon& icon) {
	*buttonIcon = icon.buttonIcon;
	*buttonHovenIcon = icon.buttonHovenIcon;
	*buttonPressedIcon = icon.buttonPressedIcon;
}

void Flare::IconButton::setColor(const Color& color) {
	*buttonBackColor = color.buttonBackColor;
	*buttonBackHoverColor = color.buttonBackHaverColor;
	*buttonBackPressedColor = color.buttonBackPressedColor;
}

Flare::IconButton::Color Flare::IconButton::Color::setAllColor(const QColor& color) {
	buttonBackColor = color;
	buttonBackHaverColor = color;
	buttonBackPressedColor = color;
	return *this;
}


Flare::IconButton::Icon Flare::IconButton::Icon::setAllIcon(const QIcon& icon) {
	buttonIcon = icon;
	buttonHovenIcon = icon;
	buttonPressedIcon = icon;
	return *this;
}
