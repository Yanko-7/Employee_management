QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DatabaseUtil.cpp \
    DiFactory.cpp \
    Employee.cpp \
    EmployeeDAO.cpp \
    EmployeePosition.cpp \
    Manager.cpp \
    ManagerDAO.cpp \
    Person.cpp \
    User.cpp \
    UserDAO.cpp \
    decorater.cpp \
    main.cpp \
    mainwindow.cpp \
    shell.c \
    sqlite3.c

HEADERS += \
    DatabaseUtil.h \
    DiFactory.h \
    Employee.h \
    EmployeeDAO.h \
    Manager.h \
    ManagerDAO.h \
    Person.h \
    User.h \
    UserDAO.h \
    decorater.h \
    mainwindow.h \
    sqlite3.h \
    sqlite3ext.h \
    ui_mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
