/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

#ifndef FLARE_COLOR_H
#define FLARE_COLOR_H

#include <QtGui/QColor>
#include "flare_global.h"

typedef float_t f32;
typedef int32_t i32;
typedef int16_t i16;

struct FLARE_EXPORT FlareColor {
	static const QColor BlueLight;
	static const QColor BlueDark;
	static const QColor Cyan;
	static const QColor Teal;
	static const QColor Mint;
	static const QColor Green;
	static const QColor Yellow;
	static const QColor Orange;
	static const QColor Red;
	static const QColor Indigo;
	static const QColor Purple;
	static const QColor Pink;
	static const QColor BrownLight;
	static const QColor BrownDark;
	static const QColor Black;
	static const QColor Grey;
	static const QColor Grey2;
	static const QColor Grey3;
	static const QColor Grey4;
	static const QColor Grey5;
	static const QColor Grey6;
	static const QColor White;
};

#endif
