/****************************************************************************
** Meta object code from reading C++ file 'tmxpars.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../tmxpars.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tmxpars.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TmxPars_t {
    const uint offsetsAndSize[22];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TmxPars_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TmxPars_t qt_meta_stringdata_TmxPars = {
    {
QT_MOC_LITERAL(0, 7), // "TmxPars"
QT_MOC_LITERAL(8, 5), // "Token"
QT_MOC_LITERAL(14, 7), // "invalid"
QT_MOC_LITERAL(22, 3), // "map"
QT_MOC_LITERAL(26, 7), // "tileset"
QT_MOC_LITERAL(34, 5), // "layer"
QT_MOC_LITERAL(40, 4), // "data"
QT_MOC_LITERAL(45, 4), // "tile"
QT_MOC_LITERAL(50, 11), // "objectgroup"
QT_MOC_LITERAL(62, 6), // "object"
QT_MOC_LITERAL(69, 5) // "image"

    },
    "TmxPars\0Token\0invalid\0map\0tileset\0"
    "layer\0data\0tile\0objectgroup\0object\0"
    "image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TmxPars[] = {

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
       1,    1, 0x2,    9,   19,

 // enum data: key, value
       2, uint(WorldReader::Token::invalid),
       3, uint(WorldReader::Token::map),
       4, uint(WorldReader::Token::tileset),
       5, uint(WorldReader::Token::layer),
       6, uint(WorldReader::Token::data),
       7, uint(WorldReader::Token::tile),
       8, uint(WorldReader::Token::objectgroup),
       9, uint(WorldReader::Token::object),
      10, uint(WorldReader::Token::image),

       0        // eod
};

const QMetaObject WorldReader::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_TmxPars.offsetsAndSize,
    qt_meta_data_TmxPars,
    nullptr,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TmxPars_t
, QtPrivate::TypeAndForceComplete<WorldReader, std::true_type>



>,
    nullptr
} };

QT_WARNING_POP
QT_END_MOC_NAMESPACE
