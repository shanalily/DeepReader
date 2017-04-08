/****************************************************************************
** Meta object code from reading C++ file 'deepreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DeepReader/deepreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeepReader_t {
    QByteArrayData data[10];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeepReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeepReader_t qt_meta_stringdata_DeepReader = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DeepReader"
QT_MOC_LITERAL(1, 11, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 19), // "on_previous_clicked"
QT_MOC_LITERAL(4, 56, 15), // "on_next_clicked"
QT_MOC_LITERAL(5, 72, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(6, 98, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(7, 125, 33), // "on_actionOpen_Text_File_trigg..."
QT_MOC_LITERAL(8, 159, 19), // "on_zoom_out_clicked"
QT_MOC_LITERAL(9, 179, 18) // "on_zoom_in_clicked"

    },
    "DeepReader\0on_actionOpen_triggered\0\0"
    "on_previous_clicked\0on_next_clicked\0"
    "on_lineEdit_returnPressed\0"
    "on_actionSave_As_triggered\0"
    "on_actionOpen_Text_File_triggered\0"
    "on_zoom_out_clicked\0on_zoom_in_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeepReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeepReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeepReader *_t = static_cast<DeepReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionOpen_triggered(); break;
        case 1: _t->on_previous_clicked(); break;
        case 2: _t->on_next_clicked(); break;
        case 3: _t->on_lineEdit_returnPressed(); break;
        case 4: _t->on_actionSave_As_triggered(); break;
        case 5: _t->on_actionOpen_Text_File_triggered(); break;
        case 6: _t->on_zoom_out_clicked(); break;
        case 7: _t->on_zoom_in_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DeepReader::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DeepReader.data,
      qt_meta_data_DeepReader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DeepReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepReader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DeepReader.stringdata0))
        return static_cast<void*>(const_cast< DeepReader*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DeepReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
