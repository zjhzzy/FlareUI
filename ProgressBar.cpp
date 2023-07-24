//
// Created by zjh_3 on 2023/7/23.
//

#include "ProgressBar.h"

namespace Flare {
    ProgressBar::ProgressBar(QWidget *parent) : Widget(parent), progress(0.f), progressBarColor(new QColor()),
                                                xMargin(0), lineWidth(1) {

    }

    void ProgressBar::setProgress(const f32 &p) {
        if (p > 1)
            progress = 1;
        else
            progress = p;
        update();
    }

    void ProgressBar::setColor(const QColor &color) {
        *progressBarColor = color;
    }

    QColor ProgressBar::Color() {
        return *progressBarColor;
    }

    f32 ProgressBar::Progress() const {
        return progress;
    }

    void ProgressBar::paintEvent(QPaintEvent *event) {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setPen(QPen(Color(), LineWidth()));
        painter.setBrush(Color());
        f32 barWidth = width() - (2 * xMargin);
        painter.drawLine(XMargin(), height() / 2,
                // 宽减去两边的边距再乘进度在加上左边的边距
                         barWidth * Progress() + XMargin(),
                         height() / 2);
        painter.end();
    }

    void ProgressBar::setXMargin(const int &Margin) {
        xMargin = Margin;
    }

    int ProgressBar::XMargin() const {
        return xMargin;
    }

    void ProgressBar::setLineWidth(const int &l) {
        lineWidth = l;
    }

    int ProgressBar::LineWidth() const {
        return lineWidth;
    }


} // Flare
