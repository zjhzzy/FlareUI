/*
 * 版权所有 (c) 2023 Zeng Jing Hong. 保留所有权利.
 * 版权所有者：Zeng Jing Hong
 * 起始年份：2023
 * 本软件遵循BSD 2-Clause协议。
 * 对于使用本库所产生的任何直接或间接损失和风险，版权所有者不承担任何责任。
 */

#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FLARE_LIB)
#  define FLARE_EXPORT Q_DECL_EXPORT
# else
#  define FLARE_EXPORT Q_DECL_IMPORT
# endif
#else
# define FLARE_EXPORT
#endif
