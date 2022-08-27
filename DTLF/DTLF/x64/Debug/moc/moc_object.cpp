/****************************************************************************
** Meta object code from reading C++ file 'object.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../object.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'object.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Object_t {
    const uint offsetsAndSize[10];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Object_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Object_t qt_meta_stringdata_Object = {
    {
QT_MOC_LITERAL(0, 6), // "Object"
QT_MOC_LITERAL(7, 4), // "Type"
QT_MOC_LITERAL(12, 7), // "Invalid"
QT_MOC_LITERAL(20, 6), // "Static"
QT_MOC_LITERAL(27, 7) // "Dynamic"

    },
    "Object\0Type\0Invalid\0Static\0Dynamic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Object[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x2,    3,   19,

 // enum data: key, value
       2, uint(Object::Type::Invalid),
       3, uint(Object::Type::Static),
       4, uint(Object::Type::Dynamic),

       0        // eod
};

const QMetaObject Object::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_Object.offsetsAndSize,
    qt_meta_data_Object,
    nullptr,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Object_t
, QtPrivate::TypeAndForceComplete<Object, std::true_type>



>,
    nullptr
} };

QT_WARNING_POP
QT_END_MOC_NAMESPACE
