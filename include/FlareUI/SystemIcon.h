#ifndef FLARE_SYSTEMICON_H
#define FLARE_SYSTEMICON_H

#include <QtWidgets/QSystemTrayIcon>
#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include "Menu.h"

namespace Flare {
	class SystemIcon : public QSystemTrayIcon {
		Q_OBJECT
	private:
		Menu* iconMenu;
	protected:
		void connectSlots();
		void showMenu();
	public:
		void setTriggerMenu(QSystemTrayIcon::ActivationReason trigger);

		SystemIcon(QObject* parent = nullptr);
		SystemIcon(const QIcon& icon, QObject* parent = nullptr);
		SystemIcon(Menu* appMenu, const QIcon& icon, QObject* parent = nullptr);
		~SystemIcon();

	signals:
		void Unknown();
		void Context();
		void Trigger();
		void MiddleClick();
		void DoubleClick();
		void messageClicked();
		void hovered();

	public slots:
		void show();
		void hide();
		void setIcon(const QIcon& icon);
		void setToolTip(const QString& tip);
		void setContextMenu(Menu* menu);
		void showMessage(const QString& title, const QString& message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int msecs = 10000);
		void showMessage(const QString& title, const QString& message, const QIcon& icon, int msecs = 10000);
	};
}

#endif
