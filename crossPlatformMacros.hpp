//because windows sucks...

#ifndef SIZECONVERSIONSO_CROSSPLATFORMMACROS_HPP
#define SIZECONVERSIONSO_CROSSPLATFORMMACROS_HPP

#include <QtCore/QtGlobal>

//remember to define this variable in the .pro file
#if defined(SIZECONVERSIONSO_LIBRARY)
#  define EXPIMP_SIZECONVERSIONSO Q_DECL_EXPORT
#else
#  define EXPIMP_SIZECONVERSIONSO Q_DECL_IMPORT
#endif

#endif // SIZECONVERSIONSO_CROSSPLATFORMMACROS_HPP