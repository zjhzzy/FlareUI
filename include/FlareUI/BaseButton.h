/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

#ifndef FLARE_BASEBUTTON_H
#define FLARE_BASEBUTTON_H
#include <QtWidgets/QAbstractButton>
#include "flare_global.h"

typedef float_t f32;

namespace Flare{
    class FLARE_EXPORT BaseButton : public QAbstractButton {
    Q_OBJECT

    protected:
        void enterEvent(QEnterEvent* event) override;
        void leaveEvent(QEvent* event) override;
        void mousePressEvent(QMouseEvent* event) override;
        void mouseReleaseEvent(QMouseEvent* event) override;
    public:
        BaseButton(QWidget* parent);
        BaseButton(BaseButton const &button);
        ~BaseButton();

        struct Icon {
            QIcon buttonIcon;
            QIcon buttonHoverIcon;
            QIcon buttonPressedIcon;
            Icon();
            Icon setAllIcon(const QIcon& icon);
        };

        bool IsPress() const;
        bool IsAbove() const;

        void setAllIcon(const QIcon& icon);
        void setIcon(Icon* icon);
        bool IsIcon() const;

        void setButtonIcon(const QIcon& icon);
        void setButtonHoverIcon(const QIcon& icon);
        void setButtonPressedIcon(const QIcon& icon);

        QIcon ButtonIcon();
        QIcon ButtonHoverIcon();
        QIcon ButtonPressedIcon();

    signals:
        void moveAbove();
        void leaveAbove();

    private:
        bool isPress;
        bool isAbove;
        bool isIcon;
        Icon* buttonIcon;
    };
}

#endif