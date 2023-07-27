//
// Created by zjh_3 on 2023/7/27.
//

#include "ImageBox.h"

Flare::ImageBox::ImageBox(QWidget *parent) : Widget(parent), imageSize(0, 0), boxImage(QImage()) {

}

Flare::ImageBox::ImageBox(const QImage &image, QWidget *parent) : ImageBox(parent) {
    boxImage = image;
}

void Flare::ImageBox::paintEvent(QPaintEvent *event) {
    Widget::paintEvent(event);
    QPainter painter(this);
    painter.drawImage(
            QRect(QPoint(size().width() / 2 - imageSize.width() / 2,
                         size().height() / 2 - imageSize.height() / 2),
                  imageSize), boxImage);
    painter.end();
}

void Flare::ImageBox::setImageSize(const QSize &size) {
    imageSize = size;
}

QSize Flare::ImageBox::ImageSize() {
    return imageSize;
}

void Flare::ImageBox::setImage(const QImage &image) {
    boxImage = image;
    if (isVisible()) {
        update();
    }
}

QImage Flare::ImageBox::Image() {
    return boxImage;
}
