//
// Created by zjh_3 on 2023/7/24.
//

#include "RadioButton.h"

void Flare::RadioButton::connectSlot() {
    connect(this, &RadioButton::pressed, this, [this]() {
        emit checked();
        setChecked(!check);
        update();
    });
}

Flare::RadioButton::RadioButton(QWidget *parent) :
        BaseButton(parent),
        buttonColor(new Color()),
        penWidget(1),
        check(false) {
    connectSlot();
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
    buttonBrushDisabledColor = color;
    return *this;
}

Flare::RadioButton::Color Flare::RadioButton::Color::setAllPenColor(const QColor &color) {
    buttonPenColor = color;
    buttonPenHoverColor = color;
    buttonPenPressedColor = color;
    buttonPenDisabledColor = color;
    return *this;
}

void Flare::RadioButton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter painter(this);

    if(isEnabled()) {
        painter.setPen(QPen(buttonColor->buttonPenDisabledColor, penWidget));
        painter.setBrush(buttonColor->buttonBrushDisabledColor);
        painter.drawEllipse(1, 1, width() - 2, height() - 2);
        painter.drawPixmap(0, 0, ButtonPressedIcon().pixmap(iconSize()));
        painter.end();
        return;
    }

    if (isChecked()) {
        painter.setPen(QPen(buttonColor->buttonPenPressedColor, penWidget));
        painter.setBrush(buttonColor->buttonBrushPressedColor);
        painter.drawEllipse(1, 1, width() - 2, height() - 2);
        painter.drawPixmap(0, 0, ButtonPressedIcon().pixmap(iconSize()));
        painter.end();
        return;
    }

    if (IsAbove()) {
        if (IsPress()) {
            painter.setPen(QPen(buttonColor->buttonPenPressedColor, penWidget));
            painter.setBrush(buttonColor->buttonBrushPressedColor);
            painter.drawEllipse(1, 1, width() - 2, height() - 2);
            painter.drawPixmap(0, 0, ButtonPressedIcon().pixmap(iconSize()));
        } else {
            painter.setPen(QPen(buttonColor->buttonPenHoverColor, penWidget));
            painter.setBrush(buttonColor->buttonBrushHoverColor);
            painter.drawEllipse(1, 1, width() - 2, height() - 2);
            painter.drawPixmap(0, 0, ButtonHoverIcon().pixmap(iconSize()));
        }
    } else {
        painter.setPen(QPen(buttonColor->buttonPenColor, penWidget));
        painter.setBrush(buttonColor->buttonBrushColor);
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

Flare::RadioButton::~RadioButton() {
    delete buttonColor;
}

void Flare::RadioButton::setChecked(bool checked) {
    check = checked;
    update();
}

bool Flare::RadioButton::isChecked() const {
    return check;
}
