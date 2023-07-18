#include "IconButton.h"

void Flare::IconButton::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	if (IsAbove()) {
		painter.setPen(*buttonBackHoverColor);
		painter.setBrush(*buttonBackHoverColor);
	} else {
		painter.setPen(*buttonBackColor);
		painter.setBrush(*buttonBackColor);
	}
	if (IsPress()) {
		painter.setPen(*buttonBackPressedColor);
		painter.setBrush(*buttonBackPressedColor);
	}
	painter.drawRoundedRect(1, 1, width() - 1.5, height() - 1.5, XRadius(), YRadius(), Qt::SizeMode::RelativeSize);
	if (IsAbove() and !IsPress()) {
		painter.drawPixmap(1, 1, width() - 1.5, height() - 1.5,
			buttonHovenIcon->pixmap(width() - 1.5, height() - 1.5));
	} else if (!IsAbove() and !IsPress()) {
		painter.drawPixmap(1, 1, width() - 1.5, height() - 1.5,
			buttonIcon->pixmap(width() - 1.5, height() - 1.5));
	} else if (IsPress()) {
		painter.drawPixmap(1, 1, width() - 1.5, height() - 1.5,
			buttonPressedIcon->pixmap(width() - 1.5, height() - 1.5));
	}
	painter.end();
}

Flare::IconButton::IconButton(QWidget* parent)
	:BaseButton(parent),
	buttonIcon(new QIcon()),
	buttonHovenIcon(new QIcon()),
	buttonPressedIcon(new QIcon()),
	buttonBackColor(new QColor(FlareColor::White)),
	buttonBackHoverColor(new QColor(FlareColor::Grey4)),
	buttonBackPressedColor(new QColor(FlareColor::Grey3)){
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
