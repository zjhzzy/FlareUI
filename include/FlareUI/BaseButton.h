#ifndef FLARE_BASEBUTTON_H
#define FLARE_BASEBUTTON_H
#include <QtWidgets/QAbstractButton>
#include "flare_global.h"

typedef float_t f32;

namespace Flare{
    class FLARE_EXPORT BaseButton : public QAbstractButton {
    Q_OBJECT
    private:
        bool isPress;
        bool isAbove;
        bool isIcon;
        QIcon* buttonIcon;
        QIcon* buttonHoverIcon;
        QIcon* buttonPressedIcon;
    protected:
        void enterEvent(QEnterEvent* event) override;
        void leaveEvent(QEvent* event) override;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseReleaseEvent(QMouseEvent* event) override;
    public:
        BaseButton(QWidget* parent);
        ~BaseButton();

        struct Icon {
            QIcon buttonIcon;
            QIcon buttonHoverIcon;
            QIcon buttonPressedIcon;
            Icon setAllIcon(const QIcon& icon);
        };

        bool IsPress() const;
        bool IsAbove() const;

        void setAllIcon(const QIcon& icon);
        void setIcon(const Icon& icon);
        bool isSetIcon() const;

        QIcon ButtonIcon();
        QIcon ButtonHoverIcon();
        QIcon ButtonPressedIcon();

    signals:
        void moveAbove();
        void leaveAbove();

    };
}

#endif