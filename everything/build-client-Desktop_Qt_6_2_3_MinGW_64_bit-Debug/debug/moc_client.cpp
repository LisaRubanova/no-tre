/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ClientAndWindowsInOne/client.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client_t {
    const uint offsetsAndSize[52];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_client_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 6), // "client"
QT_MOC_LITERAL(7, 17), // "log_in_as_student"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 17), // "log_in_as_teacher"
QT_MOC_LITERAL(44, 17), // "wrong_credentials"
QT_MOC_LITERAL(62, 10), // "registered"
QT_MOC_LITERAL(73, 11), // "user_exists"
QT_MOC_LITERAL(85, 8), // "solved_1"
QT_MOC_LITERAL(94, 8), // "solved_2"
QT_MOC_LITERAL(103, 8), // "solved_3"
QT_MOC_LITERAL(112, 12), // "not_solved_1"
QT_MOC_LITERAL(125, 12), // "not_solved_2"
QT_MOC_LITERAL(138, 12), // "not_solved_3"
QT_MOC_LITERAL(151, 9), // "not_yet_1"
QT_MOC_LITERAL(161, 9), // "not_yet_2"
QT_MOC_LITERAL(171, 9), // "not_yet_3"
QT_MOC_LITERAL(181, 7), // "allowed"
QT_MOC_LITERAL(189, 9), // "not_allow"
QT_MOC_LITERAL(199, 6), // "get_it"
QT_MOC_LITERAL(206, 1), // "g"
QT_MOC_LITERAL(208, 5), // "group"
QT_MOC_LITERAL(214, 7), // "teacher"
QT_MOC_LITERAL(222, 7), // "student"
QT_MOC_LITERAL(230, 10), // "you_cannot"
QT_MOC_LITERAL(241, 16), // "student_in_group"
QT_MOC_LITERAL(258, 14) // "slotServerRead"

    },
    "client\0log_in_as_student\0\0log_in_as_teacher\0"
    "wrong_credentials\0registered\0user_exists\0"
    "solved_1\0solved_2\0solved_3\0not_solved_1\0"
    "not_solved_2\0not_solved_3\0not_yet_1\0"
    "not_yet_2\0not_yet_3\0allowed\0not_allow\0"
    "get_it\0g\0group\0teacher\0student\0"
    "you_cannot\0student_in_group\0slotServerRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      22,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  152,    2, 0x06,    1 /* Public */,
       3,    0,  153,    2, 0x06,    2 /* Public */,
       4,    0,  154,    2, 0x06,    3 /* Public */,
       5,    0,  155,    2, 0x06,    4 /* Public */,
       6,    0,  156,    2, 0x06,    5 /* Public */,
       7,    0,  157,    2, 0x06,    6 /* Public */,
       8,    0,  158,    2, 0x06,    7 /* Public */,
       9,    0,  159,    2, 0x06,    8 /* Public */,
      10,    0,  160,    2, 0x06,    9 /* Public */,
      11,    0,  161,    2, 0x06,   10 /* Public */,
      12,    0,  162,    2, 0x06,   11 /* Public */,
      13,    0,  163,    2, 0x06,   12 /* Public */,
      14,    0,  164,    2, 0x06,   13 /* Public */,
      15,    0,  165,    2, 0x06,   14 /* Public */,
      16,    0,  166,    2, 0x06,   15 /* Public */,
      17,    0,  167,    2, 0x06,   16 /* Public */,
      18,    1,  168,    2, 0x06,   17 /* Public */,
      20,    1,  171,    2, 0x06,   19 /* Public */,
      21,    1,  174,    2, 0x06,   21 /* Public */,
      22,    1,  177,    2, 0x06,   23 /* Public */,
      23,    0,  180,    2, 0x06,   25 /* Public */,
      24,    0,  181,    2, 0x06,   26 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      25,    0,  182,    2, 0x0a,   27 /* Public */,

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
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<client *>(_o);
        (void)_t;
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
        case 17: _t->group((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->teacher((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->student((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->you_cannot(); break;
        case 21: _t->student_in_group(); break;
        case 22: _t->slotServerRead(); break;
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
        {
            using _t = void (client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::group)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::teacher)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::student)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::you_cannot)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::student_in_group)) {
                *result = 21;
                return;
            }
        }
    }
}

const QMetaObject client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_client.offsetsAndSize,
    qt_meta_data_client,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_client_t
, QtPrivate::TypeAndForceComplete<client, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 23;
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

// SIGNAL 17
void client::group(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void client::teacher(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void client::student(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void client::you_cannot()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void client::student_in_group()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
