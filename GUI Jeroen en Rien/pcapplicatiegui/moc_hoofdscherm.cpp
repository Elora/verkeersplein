/****************************************************************************
** Meta object code from reading C++ file 'hoofdscherm.h'
**
** Created: Wed Oct 31 14:37:44 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hoofdscherm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hoofdscherm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HoofdScherm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      28,   12,   12,   12, 0x0a,
      42,   12,   12,   12, 0x0a,
      58,   12,   12,   12, 0x0a,
      75,   12,   12,   12, 0x0a,
      94,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HoofdScherm[] = {
    "HoofdScherm\0\0zetGroenTijd()\0zetRoodTijd()\0"
    "zetOranjeTijd()\0zetKnipperTijd()\0"
    "zetNachtstandAan()\0zetNachtstandUit()\0"
};

const QMetaObject HoofdScherm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HoofdScherm,
      qt_meta_data_HoofdScherm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HoofdScherm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HoofdScherm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HoofdScherm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HoofdScherm))
        return static_cast<void*>(const_cast< HoofdScherm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HoofdScherm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zetGroenTijd(); break;
        case 1: zetRoodTijd(); break;
        case 2: zetOranjeTijd(); break;
        case 3: zetKnipperTijd(); break;
        case 4: zetNachtstandAan(); break;
        case 5: zetNachtstandUit(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
