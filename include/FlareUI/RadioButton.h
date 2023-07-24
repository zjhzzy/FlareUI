//
// Created by zjh_3 on 2023/7/24.
//

#ifndef FLARE_RADIOBUTTON_H
#define FLARE_RADIOBUTTON_H

#include <QColor>
#include "BaseButton.h"
#include <QPainter>
#include "FlareColor.h"

namespace Flare {
    class FLARE_EXPORT RadioButton : public BaseButton {
    Q_OBJECT

    private:
        QColor *buttonBrushColor;
        QColor *buttonBrushHoverColor;
        QColor *buttonBrushPressedColor;
        QColor *buttonPenColor;
        QColor *buttonPenHoverColor;
        QColor *buttonPenPressedColor;
        int penWidget;
    protected:
        void connectSlot();

        void paintEvent(QPaintEvent *event) override;

    public:
        struct Color {
            QColor buttonBrushColor;
            QColor buttonBrushHoverColor;
            QColor buttonBrushPressedColor;
            QColor buttonPenColor;
            QColor buttonPenHoverColor;
            QColor buttonPenPressedColor;

            Color(const QColor &color);

            Color setAllColor(const QColor &color);

            Color setAllBrushColor(const QColor &color);

            Color setAllPenColor(const QColor &color);
        };

        explicit RadioButton(QWidget *parent = nullptr);

        ~RadioButton();

        void setPenWidget(const int& w);

        int PenWidget() const;
    };
}
#endif //FLARE_RADIOBUTTON_H
