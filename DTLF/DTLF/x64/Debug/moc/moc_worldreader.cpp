/****************************************************************************
** Meta object code from reading C++ file 'worldreader.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../worldreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worldreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorldReader_t {
    const uint offsetsAndSize[36];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_WorldReader_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_WorldReader_t qt_meta_stringdata_WorldReader = {
    {
QT_MOC_LITERAL(0, 11), // "WorldReader"
QT_MOC_LITERAL(12, 5), // "Token"
QT_MOC_LITERAL(18, 7), // "invalid"
QT_MOC_LITERAL(26, 3), // "map"
QT_MOC_LITERAL(30, 7), // "tileset"
QT_MOC_LITERAL(38, 5), // "layer"
QT_MOC_LITERAL(44, 4), // "data"
QT_MOC_LITERAL(49, 4), // "tile"
QT_MOC_LITERAL(54, 11), // "objectgroup"
QT_MOC_LITERAL(66, 6), // "object"
QT_MOC_LITERAL(73, 5), // "image"
QT_MOC_LITERAL(79, 10), // "properties"
QT_MOC_LITERAL(90, 8), // "property"
QT_MOC_LITERAL(99, 7), // "polygon"
QT_MOC_LITERAL(107, 14), // "ObjectProperty"
QT_MOC_LITERAL(122, 7), // "Invalid"
QT_MOC_LITERAL(130, 5), // "Shape"
QT_MOC_LITERAL(136, 4) // "Type"

    },
    "WorldReader\0Token\0invalid\0map\0tileset\0"
    "layer\0data\0tile\0objectgroup\0object\0"
    "image\0properties\0property\0polygon\0"
    "ObjectProperty\0Invalid\0Shape\0Type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorldReader[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x2,   12,   24,
      14,   14, 0x2,    3,   48,

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
      11, uint(WorldReader::Token::properties),
      12, uint(WorldReader::Token::property),
      13, uint(WorldReader::Token::polygon),
      15, uint(WorldReader::ObjectProperty::Invalid),
      16, uint(WorldReader::ObjectProperty::Shape),
      17, uint(WorldReader::ObjectProperty::Type),

       0        // eod
};

const QMetaObject WorldReader::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_WorldReader.offsetsAndSize,
    qt_meta_data_WorldReader,
    nullptr,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_WorldReader_t
, QtPrivate::TypeAndForceComplete<WorldReader, std::true_type>



>,
    nullptr
} };

QT_WARNING_POP
QT_END_MOC_NAMESPACE
