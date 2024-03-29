QT       += core gui
QT       += sql
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

TARGET = Game
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Control.cpp \
    Enemyplane.cpp \
    MyPlane.cpp \
    Object.cpp \
    Plane.cpp \
    dbhelper.cpp \
    main.cpp \
    userinfoform.cpp \
    userlogin.cpp \
    userrankform.cpp \
    usersignup.cpp \
    userspace.cpp \
    wuziqigame.cpp \
    wuziqimodel.cpp

HEADERS += \
    Bullet.h \
    Control.h \
    EnemyPlane.h \
    MyPlane.h \
    Object.h \
    Plane.h \
    dbhelper.h \
    userinfoform.h \
    userlogin.h \
    userrankform.h \
    usersignup.h \
    userspace.h \
    wuziqigame.h \
    wuziqimodel.h

FORMS += \
    userinfoform.ui \
    userlogin.ui \
    userrankform.ui \
    usersignup.ui \
    userspace.ui \
    wuziqihelp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
