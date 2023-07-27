//
// Created by zjh_3 on 2023/7/27.
//

#ifndef FLARE_IMAGEBOX_H
#define FLARE_IMAGEBOX_H
#include <QImage>
#include <QPainter>
#include "Widget.h"

namespace Flare {
    class ImageBox : public Widget {
        Q_OBJECT
    public:
        explicit ImageBox(QWidget* parent = nullptr);
        explicit ImageBox(const QImage& image,QWidget* parent = nullptr);
        void setImageSize(const QSize& size);
        QSize ImageSize();
        void setImage(const QImage& image);
        QImage Image();
    protected:
        void paintEvent(QPaintEvent* event)override;
    private:
        QSize imageSize;
        QImage boxImage;
    };
}


#endif //FLARE_IMAGEBOX_H
