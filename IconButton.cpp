#include "IconButton.h"

void Flare::IconButton::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	if (isAbove) {
		painter.setPen(*buttonBackHoverColor);
		painter.setBrush(*buttonBackHoverColor);
	} else {
		painter.setPen(*buttonBackColor);
		painter.setBrush(*buttonBackColor);
	}
	if (isPress) {
		painter.setPen(*buttonBackPressedColor);
		painter.setBrush(*buttonBackPressedColor);
	}
	painter.drawRoundedRect(1, 1, width() - 1.5, height() - 1.5, xRadius, yRadius, Qt::SizeMode::RelativeSize);
	if (isAbove and !isPress) {
		painter.drawPixmap(1, 1, width() - 1.5, height() - 1.5,
			buttonHovenIcon->pixmap(width() - 1.5, height() - 1.5));
	} else if (!isAbove and !isPress) {
		painter.drawPixmap(1, 1, width() - 1.5, height() - 1.5,
			buttonIcon->pixmap(width() - 1.5, height() - 1.5));
	} else if (isPress) {
		painter.drawPixmap(1, 1, width() - 1.5, height() - 1.5,
			buttonPressedIcon->pixmap(width() - 1.5, height() - 1.5));
	}
	painter.end();
}

void Flare::IconButton::connectSlot() {
	connect(this, &IconButton::pressed, this, [&]() {
		isPress = true;
		update();
		});
	connect(this, &IconButton::released, this, [&]() {
		isPress = false;
		update();
		});
}

Flare::IconButton::IconButton(QWidget* parent)
	:QAbstractButton(parent),
	isAbove(false),
	isPress(false),
	buttonIcon(new QIcon()),
	buttonHovenIcon(new QIcon()),
	buttonPressedIcon(new QIcon()),
	buttonBackColor(new QColor(FlareColor::White)),
	buttonBackHoverColor(new QColor(FlareColor::Grey4)),
	buttonBackPressedColor(new QColor(FlareColor::Grey3)),
	xRadius(8),
	yRadius(8) {
	resize(32, 32);
	connectSlot();

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

void Flare::IconButton::setxRadius(const f32 Radius) {
	xRadius = Radius;
}

void Flare::IconButton::setyRadius(const f32 Radius) {
	yRadius = Radius;
}

void Flare::IconButton::setRadius(const f32 XRadius, const f32 YRadius) {
	setxRadius(XRadius);
	setxRadius(YRadius);
}

f32 Flare::IconButton::XRadius() {
	return xRadius;
}

f32 Flare::IconButton::YRadius() {
	return yRadius;
}

void Flare::IconButton::enterEvent(QEnterEvent* Event) {
	QAbstractButton::enterEvent(Event);
	isAbove = true;
	update();
}

void Flare::IconButton::leaveEvent(QEvent* Event) {
	QAbstractButton::leaveEvent(Event);
	isAbove = false;
	update();
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
