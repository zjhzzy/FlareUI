//
// Created by zjh_3 on 2023/7/27.
//

#include "TextBox.h"

void Flare::TextBox::setText(const QString &string) {
    boxText = string;
    setTextArray();
}

QString Flare::TextBox::Text() {
    return boxText;
}

void Flare::TextBox::paintEvent(QPaintEvent *event) {
    Widget::paintEvent(event);
    QPainter painter(this);
    painter.setFont(font());
    QFontMetrics fontMetrics = painter.fontMetrics();

    painter.setPen(boxColor);
    painter.setBrush(boxColor);

    if (LineLength() == 0) {
        painter.drawText(width() / 2 - fontMetrics.horizontalAdvance(Text()) / 2,
                         height() / 2 - fontMetrics.height(), Text());
        painter.end();
        qDebug() << "调用的是第一个";
        return;
    } else {
        //Todo: 这段代码有问题大大的问题，渲染位置有误

        i32 x = (width() / 2) - (fontMetrics.horizontalAdvance(textArray.first()) / 2);
        i32 y = (height() / 2) - ((fontMetrics.height()*textArray.size()+textArray.size()*verticalGap-verticalGap)/2);
        painter.drawText(x, y, textArray.first());
        for (int i = 1; i != textArray.size(); i++) {
            y += fontMetrics.height() + verticalGap;
            painter.drawText(x, y, textArray.at(i));
        }
        painter.end();
        return;
    }
}

void Flare::TextBox::setLineLength(const i32 &length) {
    lineLength = length;
    setTextArray();
}

Flare::TextBox::TextBox(QWidget *parent) :
        Widget(parent),
        boxText(QString()),
        lineLength(0),
        textArray(QVector<QString>()),
        verticalGap(1) {
    setTextArray();
    qDebug() << "调用TextBox构造函数";
}

Flare::TextBox::TextBox(QString Text, QWidget *parent) :
        Widget(parent),
        boxText(std::move(Text)),
        textArray(QVector<QString>()),
        lineLength(0),
        verticalGap(1) {
    setTextArray();
    qDebug() << "调用TextBox构造函数";
}

i32 Flare::TextBox::LineLength() const {
    return lineLength;
}

void Flare::TextBox::setVerticalGap(const i32 &Gap) {
    verticalGap = Gap;
}

i32 Flare::TextBox::VerticalGap() const {
    return verticalGap;
}

void Flare::TextBox::setTextColor(const QColor &color) {
    boxColor = color;
}

QColor Flare::TextBox::TextColor() {
    return boxColor;
}


void Flare::TextBox::setTextArray() {
    textArray = QVector<QString>();
    textArray.append(QString());
    int i = 0;
    int j = 0;
    for (const auto &item : boxText) {
        if (i == lineLength) {
            textArray.append(QString());
            j++;
            i = 0;
        }
        textArray[j].append(item);
        i++;
    }
    qDebug() << "已经调用一次";
    for (const auto &item : textArray)
        qDebug() << item;
}
