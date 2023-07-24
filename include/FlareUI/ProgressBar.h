//
// Created by zjh_3 on 2023/7/23.
//

#ifndef FLARELIST_PROGRESSBAR_H
#define FLARELIST_PROGRESSBAR_H

#include "Widget.h"
#include <QPainter>

typedef float_t f32;

namespace Flare {

    class FLARE_EXPORT ProgressBar : public Widget {
    Q_OBJECT

    private:
        f32 progress;
        QColor *progressBarColor;
        int xMargin;
        int lineWidth;
    protected:
        void paintEvent(QPaintEvent *event) override;

    public:
        ProgressBar(QWidget*parent = nullptr);

        void setProgress(const f32 &p);

        f32 Progress() const;

        // 回到VS后记得改成继承于Flare::Widget而不是QWidget，并且记得修复一下Widget绘制圆角矩形的bug

        void setColor(const QColor &color);

        void setXMargin(const int &Margin);

        int XMargin() const;

        void setLineWidth(const int &l);

        int LineWidth() const;

        QColor Color();
    };

} // Flare

#endif //FLARELIST_PROGRESSBAR_H
