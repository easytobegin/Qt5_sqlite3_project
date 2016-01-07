/****************************************************************************
** Meta object code from reading C++ file 'managementform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "managementform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managementform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ManagementForm_t {
    QByteArrayData data[14];
    char stringdata[362];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ManagementForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ManagementForm_t qt_meta_stringdata_ManagementForm = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 34),
QT_MOC_LITERAL(2, 50, 0),
QT_MOC_LITERAL(3, 51, 34),
QT_MOC_LITERAL(4, 86, 29),
QT_MOC_LITERAL(5, 116, 31),
QT_MOC_LITERAL(6, 148, 26),
QT_MOC_LITERAL(7, 175, 30),
QT_MOC_LITERAL(8, 206, 29),
QT_MOC_LITERAL(9, 236, 24),
QT_MOC_LITERAL(10, 261, 27),
QT_MOC_LITERAL(11, 289, 27),
QT_MOC_LITERAL(12, 317, 16),
QT_MOC_LITERAL(13, 334, 26)
    },
    "ManagementForm\0on_importRecordradioButton_clicked\0"
    "\0on_exportRecordradioButton_clicked\0"
    "on_storageradioButton_clicked\0"
    "on_refreshStorageButton_clicked\0"
    "on_querypushButton_clicked\0"
    "on_increaseradioButton_clicked\0"
    "on_descendradioButton_clicked\0"
    "on_addpushButton_clicked\0"
    "on_deletepushButton_clicked\0"
    "on_modifypushButton_clicked\0"
    "on_wrong_clicked\0on_closepushButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManagementForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08,
       3,    0,   75,    2, 0x08,
       4,    0,   76,    2, 0x08,
       5,    0,   77,    2, 0x08,
       6,    0,   78,    2, 0x08,
       7,    0,   79,    2, 0x08,
       8,    0,   80,    2, 0x08,
       9,    0,   81,    2, 0x08,
      10,    0,   82,    2, 0x08,
      11,    0,   83,    2, 0x08,
      12,    0,   84,    2, 0x08,
      13,    0,   85,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void ManagementForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManagementForm *_t = static_cast<ManagementForm *>(_o);
        switch (_id) {
        case 0: _t->on_importRecordradioButton_clicked(); break;
        case 1: _t->on_exportRecordradioButton_clicked(); break;
        case 2: _t->on_storageradioButton_clicked(); break;
        case 3: _t->on_refreshStorageButton_clicked(); break;
        case 4: _t->on_querypushButton_clicked(); break;
        case 5: _t->on_increaseradioButton_clicked(); break;
        case 6: _t->on_descendradioButton_clicked(); break;
        case 7: _t->on_addpushButton_clicked(); break;
        case 8: _t->on_deletepushButton_clicked(); break;
        case 9: _t->on_modifypushButton_clicked(); break;
        case 11: _t->on_closepushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ManagementForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManagementForm.data,
      qt_meta_data_ManagementForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *ManagementForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManagementForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManagementForm.stringdata))
        return static_cast<void*>(const_cast< ManagementForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int ManagementForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
