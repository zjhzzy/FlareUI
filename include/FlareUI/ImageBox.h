/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */


#ifndef FLARE_IMAGEBOX_H
#define FLARE_IMAGEBOX_H
#include <QImage>
#include <QPainter>
#include "Widget.h"

namespace Flare {
    class FLARE_EXPORT ImageBox : public Widget {
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
