//
// Created by zjh_3 on 2023/7/24.
//

#include "RadioButton.h"

void Flare::RadioButton::connectSlot() {
    connect(this, &RadioButton::pressed, this, [this]() {
        click();
    });
}

Flare::RadioButton::RadioButton(QWidget *parent) :
        BaseButton(parent),
        buttonBrushColor(new QColor()),
        buttonBrushHoverColor(new QColor()),
        buttonBrushPressedColor(new QColor(FlareColor::BlueDark)),
        buttonPenColor(new QColor(FlareColor::BlueLight)),
        buttonPenHoverColor(new QColor(FlareColor::BlueDark)),
        buttonPenPressedColor(new QColor(FlareColor::BlueDark)),
        penWidget(1) {

}

Flare::RadioButton::Color::Color(const QColor &color) :
        buttonBrushColor(color),
        buttonBrushHoverColor(color),
        buttonBrushPressedColor(color),
        buttonPenColor(color),
        buttonPenHoverColor(color),
        buttonPenPressedColor(color) {

}

Flare::RadioButton::Color Flare::RadioButton::Color::setAllColor(const QColor &color) {
    setAllBrushColor(color);
    setAllPenColor(color);
    return *this;
}

Flare::RadioButton::Color Flare::RadioButton::Color::setAllBrushColor(const QColor &color) {
    buttonBrushColor = color;
    buttonBrushHoverColor = color;
    buttonBrushPressedColor = color;
    return *this;
}

Flare::RadioButton::Color Flare::RadioButton::Color::setAllPenColor(const QColor &color) {
    buttonPenColor = color;
    buttonPenHoverColor = color;
    buttonPenPressedColor = color;
    return *this;
}

void Flare::RadioButton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter painter(this);

    if(isChecked()) {
        painter.setPen(QPen(*buttonPenPressedColor, penWidget));
        painter.setBrush(*buttonBrushPressedColor);
        painter.drawEllipse(1, 1, width() - 2, height() - 2);
        painter.drawPixmap(0, 0, ButtonPressedIcon().pixmap(iconSize()));
        painter.end();
        return;
    }

    if (IsAbove()) {
        if (IsPress()) {
            painter.setPen(QPen(*buttonPenPressedColor, penWidget));
            painter.setBrush(*buttonBrushPressedColor);
            painter.drawEllipse(1, 1, width() - 2, height() - 2);
            painter.drawPixmap(0, 0, ButtonPressedIcon().pixmap(iconSize()));
        } else {
            painter.setPen(QPen(*buttonPenHoverColor, penWidget));
            painter.setBrush(*buttonBrushHoverColor);
            painter.drawEllipse(1, 1, width() - 2, height() - 2);
            painter.drawPixmap(0, 0, ButtonHoverIcon().pixmap(iconSize()));
        }
    } else {
        painter.setPen(QPen(*buttonPenColor, penWidget));
        painter.setBrush(*buttonBrushColor);
        painter.drawEllipse(1, 1, width() - 2, height() - 2);
        painter.drawPixmap(0, 0, ButtonIcon().pixmap(iconSize()));
    }
    painter.end();
}

void Flare::RadioButton::setPenWidget(const int &w) {
    penWidget = w;
}

int Flare::RadioButton::PenWidget() const {
    return penWidget;
}

Flare::RadioButton::~RadioButton(){
    delete buttonPenColor;
    delete buttonPenHoverColor;
    delete buttonPenPressedColor;
    delete buttonBrushColor;
    delete buttonBrushHoverColor;
    delete buttonBrushPressedColor;
}