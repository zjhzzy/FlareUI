#include "PushButton.h"

void Flare::PushButton::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	QFontMetrics metrics = QFontMetrics(this->font());
	if (!IsAbove()) {
		painter.setPen(*buttonBackColor);
		painter.setBrush(*buttonBackColor);
	} else {
		if (IsPress()) {
			painter.setPen(*buttonBackPressedColor);
			painter.setBrush(*buttonBackPressedColor);
		} else {
			painter.setPen(*buttonBackHoverColor);
			painter.setBrush(*buttonBackHoverColor);
		}
	}
	painter.drawRoundedRect(1, 1, width() - 2, height() - 2, XRadius(), YRadius());
	if (!IsAbove()) {
		painter.setPen(*buttonTextColor);
		painter.setBrush(*buttonTextColor);
	} else {
		if (IsPress()) {
			painter.setPen(*buttonBackPressedColor);
			painter.setBrush(*buttonBackPressedColor);
		} else {
			painter.setPen(*buttonBackHoverColor);
			painter.setBrush(*buttonBackHoverColor);
		}
	}
	if (isIcon) {
		f32 X = (width() - metrics.horizontalAdvance(text()) + iconSize().width()) / 2.0;
		if (!IsAbove()) {
			painter.drawPixmap(X, (height() - iconSize().height()) / 2.0,
				iconSize().width(), iconSize().height(), buttonIcon->pixmap(iconSize()));
			painter.drawText(X + iconSize().width(), (height() - metrics.height()) / 2.0, text());
		} else {
			if (IsPress()) {
				painter.drawPixmap(X, (height() - iconSize().height()) / 2.0,
					iconSize().width(), iconSize().height(), buttonPressedIcon->pixmap(iconSize()));
				painter.drawText(X + iconSize().width(), (height() - metrics.height()) / 2.0, text());
			} else {
				painter.drawPixmap(X, (height() - iconSize().height()) / 2.0,
					iconSize().width(), iconSize().height(), buttonHoverIcon->pixmap(iconSize()));
				painter.drawText(X + iconSize().width(), (height() - metrics.height()) / 2.0, text());
			}
		}
	} else {
		painter.drawText((width() - metrics.horizontalAdvance(text())) / 2.0,
			(height() - metrics.height()) / 2.0, text());
	}
	painter.end();
}

Flare::PushButton::PushButton(QWidget* parent)
	: BaseButton(parent),
	buttonBackColor(new QColor(FlareColor::Green)),
	buttonBackHoverColor(new QColor(FlareColor::Green)),
	buttonBackPressedColor(new QColor(FlareColor::Green)),
	buttonTextColor(new QColor(FlareColor::White)),
	buttonTextHoverColor(new QColor(FlareColor::White)),
	buttonTextPressedColor(new QColor(FlareColor::White)),
	buttonIcon(new QIcon()),
	buttonHoverIcon(new QIcon()),
	buttonPressedIcon(new QIcon()),
	isIcon(false) {}

Flare::PushButton::~PushButton() {
	delete buttonBackColor;
	delete buttonTextColor;
	delete buttonBackHoverColor;
	delete buttonTextHoverColor;
	delete buttonBackPressedColor;
	delete buttonTextPressedColor;
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
	buttonBackColor = color;
	buttonBackHoverColor = color;
	buttonBackPressedColor = color;
	return *this;
}

Flare::PushButton::Color Flare::PushButton::Color::setAllTextColor(const QColor& color) {
	buttonTextColor = color;
	buttonTextHoverColor = color;
	buttonTextPressedColor = color;
	return *this;
}
