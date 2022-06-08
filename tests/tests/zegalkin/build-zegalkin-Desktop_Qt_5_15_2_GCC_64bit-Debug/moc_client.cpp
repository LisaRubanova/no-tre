/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ClientAndWindowsInOne/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client_t {
    QByteArrayData data[21];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "client"
QT_MOC_LITERAL(1, 7, 17), // "log_in_as_student"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "log_in_as_teacher"
QT_MOC_LITERAL(4, 44, 17), // "wrong_credentials"
QT_MOC_LITERAL(5, 62, 10), // "registered"
QT_MOC_LITERAL(6, 73, 11), // "user_exists"
QT_MOC_LITERAL(7, 85, 8), // "solved_1"
QT_MOC_LITERAL(8, 94, 8), // "solved_2"
QT_MOC_LITERAL(9, 103, 8), // "solved_3"
QT_MOC_LITERAL(10, 112, 12), // "not_solved_1"
QT_MOC_LITERAL(11, 125, 12), // "not_solved_2"
QT_MOC_LITERAL(12, 138, 12), // "not_solved_3"
QT_MOC_LITERAL(13, 151, 9), // "not_yet_1"
QT_MOC_LITERAL(14, 161, 9), // "not_yet_2"
QT_MOC_LITERAL(15, 171, 9), // "not_yet_3"
QT_MOC_LITERAL(16, 181, 7), // "allowed"
QT_MOC_LITERAL(17, 189, 9), // "not_allow"
QT_MOC_LITERAL(18, 199, 6), // "get_it"
QT_MOC_LITERAL(19, 206, 1), // "g"
QT_MOC_LITERAL(20, 208, 14) // "slotServerRead"

    },
    "client\0log_in_as_student\0\0log_in_as_teacher\0"
    "wrong_credentials\0registered\0user_exists\0"
    "solved_1\0solved_2\0solved_3\0not_solved_1\0"
    "not_solved_2\0not_solved_3\0not_yet_1\0"
    "not_yet_2\0not_yet_3\0allowed\0not_allow\0"
    "get_it\0g\0slotServerRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    0,  110,    2, 0x06 /* Public */,
       9,    0,  111,    2, 0x06 /* Public */,
      10,    0,  112,    2, 0x06 /* Public */,
      11,    0,  113,    2, 0x06 /* Public */,
      12,    0,  114,    2, 0x06 /* Public */,
      13,    0,  115,    2, 0x06 /* Public */,
      14,    0,  116,    2, 0x06 /* Public */,
      15,    0,  117,    2, 0x06 /* Public */,
      16,    0,  118,    2, 0x06 /* Public */,
      17,    0,  119,    2, 0x06 /* Public */,
      18,    1,  120,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,  123,    2, 0x0a /* Public */,

 // signals: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->log_in_as_student(); break;
        case 1: _t->log_in_as_teacher(); break;
        case 2: _t->wrong_credentials(); break;
        case 3: _t->registered(); break;
        case 4: _t->user_exists(); break;
        case 5: _t->solved_1(); break;
        case 6: _t->solved_2(); break;
        case 7: _t->solved_3(); break;
        case 8: _t->not_solved_1(); break;
        case 9: _t->not_solved_2(); break;
        case 10: _t->not_solved_3(); break;
        case 11: _t->not_yet_1(); break;
        case 12: _t->not_yet_2(); break;
        case 13: _t->not_yet_3(); break;
        case 14: _t->allowed(); break;
        case 15: _t->not_allow(); break;
        case 16: _t->get_it((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->slotServerRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::log_in_as_student)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::log_in_as_teacher)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::wrong_credentials)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::registered)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::user_exists)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::solved_1)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::solved_2)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::solved_3)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::not_solved_1)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::not_solved_2)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::not_solved_3)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::not_yet_1)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::not_yet_2)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::not_yet_3)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::allowed)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::not_allow)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::get_it)) {
                *result = 16;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_client.data,
    qt_meta_data_client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void client::log_in_as_student()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void client::log_in_as_teacher()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void client::wrong_credentials()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void client::registered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void client::user_exists()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void client::solved_1()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void client::solved_2()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void client::solved_3()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void client::not_solved_1()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void client::not_solved_2()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void client::not_solved_3()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void client::not_yet_1()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void client::not_yet_2()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void client::not_yet_3()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void client::allowed()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void client::not_allow()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void client::get_it(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
