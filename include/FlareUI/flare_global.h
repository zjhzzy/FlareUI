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
