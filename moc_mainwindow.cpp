/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "slotLogin"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "slotLogout"
QT_MOC_LITERAL(4, 33, 12), // "slotAddTheme"
QT_MOC_LITERAL(5, 46, 15), // "slotUpdateTheme"
QT_MOC_LITERAL(6, 62, 15), // "slotDeleteTheme"
QT_MOC_LITERAL(7, 78, 15), // "slotSelectTheme"
QT_MOC_LITERAL(8, 94, 3), // "row"
QT_MOC_LITERAL(9, 98, 4), // "coll"
QT_MOC_LITERAL(10, 103, 15), // "slotAddQuestion"
QT_MOC_LITERAL(11, 119, 18), // "slotUpdateQuestion"
QT_MOC_LITERAL(12, 138, 18), // "slotDeleteQuestion"
QT_MOC_LITERAL(13, 157, 18), // "slotSelectQuestion"
QT_MOC_LITERAL(14, 176, 18), // "slotAddProposition"
QT_MOC_LITERAL(15, 195, 21), // "slotUpdateProposition"
QT_MOC_LITERAL(16, 217, 21), // "slotDeleteProposition"
QT_MOC_LITERAL(17, 239, 21), // "slotSelectProposition"
QT_MOC_LITERAL(18, 261, 11), // "slotAddUser"
QT_MOC_LITERAL(19, 273, 14), // "slotUpdateUser"
QT_MOC_LITERAL(20, 288, 14), // "slotDeleteUser"
QT_MOC_LITERAL(21, 303, 14) // "slotSelectUser"

    },
    "MainWindow\0slotLogin\0\0slotLogout\0"
    "slotAddTheme\0slotUpdateTheme\0"
    "slotDeleteTheme\0slotSelectTheme\0row\0"
    "coll\0slotAddQuestion\0slotUpdateQuestion\0"
    "slotDeleteQuestion\0slotSelectQuestion\0"
    "slotAddProposition\0slotUpdateProposition\0"
    "slotDeleteProposition\0slotSelectProposition\0"
    "slotAddUser\0slotUpdateUser\0slotDeleteUser\0"
    "slotSelectUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    2,  109,    2, 0x0a /* Public */,
      10,    0,  114,    2, 0x0a /* Public */,
      11,    0,  115,    2, 0x0a /* Public */,
      12,    0,  116,    2, 0x0a /* Public */,
      13,    2,  117,    2, 0x0a /* Public */,
      14,    0,  122,    2, 0x0a /* Public */,
      15,    0,  123,    2, 0x0a /* Public */,
      16,    0,  124,    2, 0x0a /* Public */,
      17,    2,  125,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    0,  132,    2, 0x0a /* Public */,
      21,    0,  133,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotLogin(); break;
        case 1: _t->slotLogout(); break;
        case 2: _t->slotAddTheme(); break;
        case 3: _t->slotUpdateTheme(); break;
        case 4: _t->slotDeleteTheme(); break;
        case 5: _t->slotSelectTheme((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->slotAddQuestion(); break;
        case 7: _t->slotUpdateQuestion(); break;
        case 8: _t->slotDeleteQuestion(); break;
        case 9: _t->slotSelectQuestion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->slotAddProposition(); break;
        case 11: _t->slotUpdateProposition(); break;
        case 12: _t->slotDeleteProposition(); break;
        case 13: _t->slotSelectProposition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->slotAddUser(); break;
        case 15: _t->slotUpdateUser(); break;
        case 16: _t->slotDeleteUser(); break;
        case 17: _t->slotSelectUser(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
