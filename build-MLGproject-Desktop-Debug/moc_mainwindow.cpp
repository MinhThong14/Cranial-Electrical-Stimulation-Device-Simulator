/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MLGproject/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "powerButton"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "startButton"
QT_MOC_LITERAL(4, 36, 13), // "historyButton"
QT_MOC_LITERAL(5, 50, 15), // "drainBatteryBy3"
QT_MOC_LITERAL(6, 66, 16), // "drainBatteryBy10"
QT_MOC_LITERAL(7, 83, 19), // "chargeBatteryToFull"
QT_MOC_LITERAL(8, 103, 17), // "increaseIntensity"
QT_MOC_LITERAL(9, 121, 17), // "decreaseIntensity"
QT_MOC_LITERAL(10, 139, 14), // "toggleCheckbox"
QT_MOC_LITERAL(11, 154, 7), // "checked"
QT_MOC_LITERAL(12, 162, 16), // "toggleAttachment"
QT_MOC_LITERAL(13, 179, 18), // "select20MinSession"
QT_MOC_LITERAL(14, 198, 18), // "select45MinSession"
QT_MOC_LITERAL(15, 217, 19), // "selectCustomSession"
QT_MOC_LITERAL(16, 237, 18), // "selectAlphaSession"
QT_MOC_LITERAL(17, 256, 17), // "selectBetaSession"
QT_MOC_LITERAL(18, 274, 18), // "selectDeltaSession"
QT_MOC_LITERAL(19, 293, 18) // "selectThetaSession"

    },
    "MainWindow\0powerButton\0\0startButton\0"
    "historyButton\0drainBatteryBy3\0"
    "drainBatteryBy10\0chargeBatteryToFull\0"
    "increaseIntensity\0decreaseIntensity\0"
    "toggleCheckbox\0checked\0toggleAttachment\0"
    "select20MinSession\0select45MinSession\0"
    "selectCustomSession\0selectAlphaSession\0"
    "selectBetaSession\0selectDeltaSession\0"
    "selectThetaSession"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    1,  107,    2, 0x08 /* Private */,
      12,    1,  110,    2, 0x08 /* Private */,
      13,    0,  113,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->powerButton(); break;
        case 1: _t->startButton(); break;
        case 2: _t->historyButton(); break;
        case 3: _t->drainBatteryBy3(); break;
        case 4: _t->drainBatteryBy10(); break;
        case 5: _t->chargeBatteryToFull(); break;
        case 6: _t->increaseIntensity(); break;
        case 7: _t->decreaseIntensity(); break;
        case 8: _t->toggleCheckbox((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->toggleAttachment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->select20MinSession(); break;
        case 11: _t->select45MinSession(); break;
        case 12: _t->selectCustomSession(); break;
        case 13: _t->selectAlphaSession(); break;
        case 14: _t->selectBetaSession(); break;
        case 15: _t->selectDeltaSession(); break;
        case 16: _t->selectThetaSession(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
