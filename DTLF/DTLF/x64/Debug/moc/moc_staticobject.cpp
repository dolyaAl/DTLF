/****************************************************************************
** Meta object code from reading C++ file 'staticobject.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../staticobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'staticobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StaticObject_t {
    const uint offsetsAndSize[10];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_StaticObject_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_StaticObject_t qt_meta_stringdata_StaticObject = {
    {
QT_MOC_LITERAL(0, 12), // "StaticObject"
QT_MOC_LITERAL(13, 4), // "Type"
QT_MOC_LITERAL(18, 7), // "Invalid"
QT_MOC_LITERAL(26, 4), // "Wall"
QT_MOC_LITERAL(31, 5) // "Floor"

    },
    "StaticObject\0Type\0Invalid\0Wall\0Floor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StaticObject[] = {

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
       2, uint(StaticObject::Type::Invalid),
       3, uint(StaticObject::Type::Wall),
       4, uint(StaticObject::Type::Floor),

       0        // eod
};

const QMetaObject StaticObject::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_StaticObject.offsetsAndSize,
    qt_meta_data_StaticObject,
    nullptr,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_StaticObject_t
, QtPrivate::TypeAndForceComplete<StaticObject, std::true_type>



>,
    nullptr
} };

QT_WARNING_POP
QT_END_MOC_NAMESPACE
