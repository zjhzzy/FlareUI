/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

#ifndef FLARE_SYSTEMICON_H
#define FLARE_SYSTEMICON_H

#include <QSystemTrayIcon>
#include <QGuiApplication>
#include <QScreen>
#include "flare_global.h"


namespace Flare {

    class Widget;

    class FLARE_EXPORT SystemIcon : public QSystemTrayIcon {
    Q_OBJECT

    private:
        Widget *iconMenu;

    protected:

        void connectSlots();

        void showMenu();

    public:
        explicit SystemIcon(QObject *parent = nullptr);

        explicit SystemIcon(const QIcon &icon, QObject *parent = nullptr);

        SystemIcon(Widget *appMenu, const QIcon &icon, QObject *parent = nullptr);

        ~SystemIcon();

        void setTriggerMenu(ActivationReason trigger);

        void setMenu(Widget *menu);

    signals:

        void Unknown();

        void Context();

        void Trigger();

        void MiddleClick();

        void DoubleClick();

        void hovered();
    };

} // namespace Flare

#endif