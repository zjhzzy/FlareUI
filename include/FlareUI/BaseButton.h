#ifndef FLARE_BASEBUTTON_H
#define FLARE_BASEBUTTON_H
#include <QtWidgets/QAbstractButton>
#include "flare_global.h"

typedef float_t f32;

class FLARE_EXPORT BaseButton : public QAbstractButton {
	Q_OBJECT
private:
	f32 xRadius;
	f32 yRadius;
	bool isPress;
	bool isAbove;
protected:
	void enterEvent(QEnterEvent* event) override;
	void leaveEvent(QEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
public:
	BaseButton(QWidget* parent);
	~BaseButton();

	f32 XRadius();
	f32 YRadius();
	bool IsPress();
	bool IsAbove();


	void setXRadius(const f32& Radius);
	void setYRadius(const f32& Radius);
	void setRadius(const f32& Xradius, const f32& Yradius);

signals:
	void moveAbove();
	void leaveAbove();

};

#endif