#include "SystemIcon.h"
#include "Widget.h"
#include <QCursor>
#include <QScreen>
#include <QApplication>

using namespace Flare;

void Flare::SystemIcon::connectSlots() {
    connect(this, &QSystemTrayIcon::activated, this, [this]
            (QSystemTrayIcon::ActivationReason reason) {
        switch (reason) {
            case QSystemTrayIcon::Unknown:
                emit Unknown();
                break;
            case QSystemTrayIcon::Context:
                emit Context();
                break;
            case QSystemTrayIcon::DoubleClick:
                emit DoubleClick();
                break;
            case QSystemTrayIcon::Trigger:
                emit Trigger();
                break;
            case QSystemTrayIcon::MiddleClick:
                emit MiddleClick();
                break;
            default:
                QSystemTrayIcon::showMessage("FlareUI Error",
                                             "你碰到了莫名奇妙的Bug请你告知FlareUI库的开发者或者你使用的软件的开发者",
                                             QSystemTrayIcon::Warning);
                break;
        }
    });
}

void SystemIcon::showMenu() {
    if (iconMenu != nullptr) {
        QPoint point = QCursor::pos();
        // 检查是否超出屏幕边界 - 右侧
        bool isExceedingBoundaryOnRight =
                point.x() + iconMenu->width() >= QApplication::primaryScreen()->geometry().width();

        // 检查是否超出屏幕边界 - 下方
        bool isExceedingBoundaryOnBottom =
                point.y() + iconMenu->height() >= QApplication::primaryScreen()->geometry().height();

        iconMenu->show();

        // 1 1
        if(isExceedingBoundaryOnRight and isExceedingBoundaryOnBottom)
            iconMenu->move(point.x()-iconMenu->width(),point.y()-iconMenu->height());
        // 1 0
        else if(isExceedingBoundaryOnRight and !isExceedingBoundaryOnBottom)
            iconMenu->move(point.x()-iconMenu->width(),point.y());
        // 0 1
        else if(!isExceedingBoundaryOnRight and isExceedingBoundaryOnBottom)
            iconMenu->move(point.x(),point.y()-iconMenu->height());
        // 0 0
        else if(!isExceedingBoundaryOnRight and !isExceedingBoundaryOnBottom)
            iconMenu->move(point);
    }
}


void Flare::SystemIcon::setTriggerMenu(QSystemTrayIcon::ActivationReason trigger) {
    switch (trigger) {
        case QSystemTrayIcon::Unknown:
            connect(this, &SystemIcon::Unknown, this, [this]() {
                showMenu();
            });
            break;
        case QSystemTrayIcon::Context:
            connect(this, &SystemIcon::Context, this, [this]() {
                showMenu();
            });
            break;
        case QSystemTrayIcon::DoubleClick:
            connect(this, &SystemIcon::DoubleClick, this, [this]() {
                showMenu();
            });
            break;
        case QSystemTrayIcon::Trigger:
            connect(this, &SystemIcon::Trigger, this, [this]() {
                showMenu();
            });
            break;
        case QSystemTrayIcon::MiddleClick:
            connect(this, &SystemIcon::MiddleClick, this, [this]() {
                showMenu();
            });
            break;
        default:
            QSystemTrayIcon::showMessage("FlareUI Error",
                                         "你碰到了莫名奇妙的Bug请你告知FlareUI库的开发者或者你使用的软件的开发者",
                                         QSystemTrayIcon::Warning);
            break;
    }
}

SystemIcon::SystemIcon(QObject *parent)
        : QSystemTrayIcon(parent), iconMenu(nullptr) {
    connectSlots();
}

SystemIcon::SystemIcon(const QIcon &icon, QObject *parent)
        : QSystemTrayIcon(icon, parent), iconMenu(nullptr) {
    connectSlots();
}

SystemIcon::SystemIcon(Widget *appMenu, const QIcon &icon, QObject *parent)
        : QSystemTrayIcon(icon, parent), iconMenu(appMenu) {
    connectSlots();
}

SystemIcon::~SystemIcon() = default;

void Flare::SystemIcon::setMenu(Flare::Widget *menu) {
    iconMenu = menu;
}

