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
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    shell.c \
    sqlite3.c\


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
    login.h \
    mainwindow.h \
    sqlite3.h \
    sqlite3ext.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    css/lightstyle.qrc

DISTFILES += \
    css/lightstyle.qss \
    css/rc/.keep \
    css/rc/arrow_down.png \
    css/rc/arrow_down@2x.png \
    css/rc/arrow_down_disabled.png \
    css/rc/arrow_down_disabled@2x.png \
    css/rc/arrow_down_focus.png \
    css/rc/arrow_down_focus@2x.png \
    css/rc/arrow_down_pressed.png \
    css/rc/arrow_down_pressed@2x.png \
    css/rc/arrow_left.png \
    css/rc/arrow_left@2x.png \
    css/rc/arrow_left_disabled.png \
    css/rc/arrow_left_disabled@2x.png \
    css/rc/arrow_left_focus.png \
    css/rc/arrow_left_focus@2x.png \
    css/rc/arrow_left_pressed.png \
    css/rc/arrow_left_pressed@2x.png \
    css/rc/arrow_right.png \
    css/rc/arrow_right@2x.png \
    css/rc/arrow_right_disabled.png \
    css/rc/arrow_right_disabled@2x.png \
    css/rc/arrow_right_focus.png \
    css/rc/arrow_right_focus@2x.png \
    css/rc/arrow_right_pressed.png \
    css/rc/arrow_right_pressed@2x.png \
    css/rc/arrow_up.png \
    css/rc/arrow_up@2x.png \
    css/rc/arrow_up_disabled.png \
    css/rc/arrow_up_disabled@2x.png \
    css/rc/arrow_up_focus.png \
    css/rc/arrow_up_focus@2x.png \
    css/rc/arrow_up_pressed.png \
    css/rc/arrow_up_pressed@2x.png \
    css/rc/base_icon.png \
    css/rc/base_icon@2x.png \
    css/rc/base_icon_disabled.png \
    css/rc/base_icon_disabled@2x.png \
    css/rc/base_icon_focus.png \
    css/rc/base_icon_focus@2x.png \
    css/rc/base_icon_pressed.png \
    css/rc/base_icon_pressed@2x.png \
    css/rc/branch_closed.png \
    css/rc/branch_closed@2x.png \
    css/rc/branch_closed_disabled.png \
    css/rc/branch_closed_disabled@2x.png \
    css/rc/branch_closed_focus.png \
    css/rc/branch_closed_focus@2x.png \
    css/rc/branch_closed_pressed.png \
    css/rc/branch_closed_pressed@2x.png \
    css/rc/branch_end.png \
    css/rc/branch_end@2x.png \
    css/rc/branch_end_disabled.png \
    css/rc/branch_end_disabled@2x.png \
    css/rc/branch_end_focus.png \
    css/rc/branch_end_focus@2x.png \
    css/rc/branch_end_pressed.png \
    css/rc/branch_end_pressed@2x.png \
    css/rc/branch_line.png \
    css/rc/branch_line@2x.png \
    css/rc/branch_line_disabled.png \
    css/rc/branch_line_disabled@2x.png \
    css/rc/branch_line_focus.png \
    css/rc/branch_line_focus@2x.png \
    css/rc/branch_line_pressed.png \
    css/rc/branch_line_pressed@2x.png \
    css/rc/branch_more.png \
    css/rc/branch_more@2x.png \
    css/rc/branch_more_disabled.png \
    css/rc/branch_more_disabled@2x.png \
    css/rc/branch_more_focus.png \
    css/rc/branch_more_focus@2x.png \
    css/rc/branch_more_pressed.png \
    css/rc/branch_more_pressed@2x.png \
    css/rc/branch_open.png \
    css/rc/branch_open@2x.png \
    css/rc/branch_open_disabled.png \
    css/rc/branch_open_disabled@2x.png \
    css/rc/branch_open_focus.png \
    css/rc/branch_open_focus@2x.png \
    css/rc/branch_open_pressed.png \
    css/rc/branch_open_pressed@2x.png \
    css/rc/checkbox_checked.png \
    css/rc/checkbox_checked@2x.png \
    css/rc/checkbox_checked_disabled.png \
    css/rc/checkbox_checked_disabled@2x.png \
    css/rc/checkbox_checked_focus.png \
    css/rc/checkbox_checked_focus@2x.png \
    css/rc/checkbox_checked_pressed.png \
    css/rc/checkbox_checked_pressed@2x.png \
    css/rc/checkbox_indeterminate.png \
    css/rc/checkbox_indeterminate@2x.png \
    css/rc/checkbox_indeterminate_disabled.png \
    css/rc/checkbox_indeterminate_disabled@2x.png \
    css/rc/checkbox_indeterminate_focus.png \
    css/rc/checkbox_indeterminate_focus@2x.png \
    css/rc/checkbox_indeterminate_pressed.png \
    css/rc/checkbox_indeterminate_pressed@2x.png \
    css/rc/checkbox_unchecked.png \
    css/rc/checkbox_unchecked@2x.png \
    css/rc/checkbox_unchecked_disabled.png \
    css/rc/checkbox_unchecked_disabled@2x.png \
    css/rc/checkbox_unchecked_focus.png \
    css/rc/checkbox_unchecked_focus@2x.png \
    css/rc/checkbox_unchecked_pressed.png \
    css/rc/checkbox_unchecked_pressed@2x.png \
    css/rc/line_horizontal.png \
    css/rc/line_horizontal@2x.png \
    css/rc/line_horizontal_disabled.png \
    css/rc/line_horizontal_disabled@2x.png \
    css/rc/line_horizontal_focus.png \
    css/rc/line_horizontal_focus@2x.png \
    css/rc/line_horizontal_pressed.png \
    css/rc/line_horizontal_pressed@2x.png \
    css/rc/line_vertical.png \
    css/rc/line_vertical@2x.png \
    css/rc/line_vertical_disabled.png \
    css/rc/line_vertical_disabled@2x.png \
    css/rc/line_vertical_focus.png \
    css/rc/line_vertical_focus@2x.png \
    css/rc/line_vertical_pressed.png \
    css/rc/line_vertical_pressed@2x.png \
    css/rc/radio_checked.png \
    css/rc/radio_checked@2x.png \
    css/rc/radio_checked_disabled.png \
    css/rc/radio_checked_disabled@2x.png \
    css/rc/radio_checked_focus.png \
    css/rc/radio_checked_focus@2x.png \
    css/rc/radio_checked_pressed.png \
    css/rc/radio_checked_pressed@2x.png \
    css/rc/radio_unchecked.png \
    css/rc/radio_unchecked@2x.png \
    css/rc/radio_unchecked_disabled.png \
    css/rc/radio_unchecked_disabled@2x.png \
    css/rc/radio_unchecked_focus.png \
    css/rc/radio_unchecked_focus@2x.png \
    css/rc/radio_unchecked_pressed.png \
    css/rc/radio_unchecked_pressed@2x.png \
    css/rc/toolbar_move_horizontal.png \
    css/rc/toolbar_move_horizontal@2x.png \
    css/rc/toolbar_move_horizontal_disabled.png \
    css/rc/toolbar_move_horizontal_disabled@2x.png \
    css/rc/toolbar_move_horizontal_focus.png \
    css/rc/toolbar_move_horizontal_focus@2x.png \
    css/rc/toolbar_move_horizontal_pressed.png \
    css/rc/toolbar_move_horizontal_pressed@2x.png \
    css/rc/toolbar_move_vertical.png \
    css/rc/toolbar_move_vertical@2x.png \
    css/rc/toolbar_move_vertical_disabled.png \
    css/rc/toolbar_move_vertical_disabled@2x.png \
    css/rc/toolbar_move_vertical_focus.png \
    css/rc/toolbar_move_vertical_focus@2x.png \
    css/rc/toolbar_move_vertical_pressed.png \
    css/rc/toolbar_move_vertical_pressed@2x.png \
    css/rc/toolbar_separator_horizontal.png \
    css/rc/toolbar_separator_horizontal@2x.png \
    css/rc/toolbar_separator_horizontal_disabled.png \
    css/rc/toolbar_separator_horizontal_disabled@2x.png \
    css/rc/toolbar_separator_horizontal_focus.png \
    css/rc/toolbar_separator_horizontal_focus@2x.png \
    css/rc/toolbar_separator_horizontal_pressed.png \
    css/rc/toolbar_separator_horizontal_pressed@2x.png \
    css/rc/toolbar_separator_vertical.png \
    css/rc/toolbar_separator_vertical@2x.png \
    css/rc/toolbar_separator_vertical_disabled.png \
    css/rc/toolbar_separator_vertical_disabled@2x.png \
    css/rc/toolbar_separator_vertical_focus.png \
    css/rc/toolbar_separator_vertical_focus@2x.png \
    css/rc/toolbar_separator_vertical_pressed.png \
    css/rc/toolbar_separator_vertical_pressed@2x.png \
    css/rc/transparent.png \
    css/rc/transparent@2x.png \
    css/rc/transparent_disabled.png \
    css/rc/transparent_disabled@2x.png \
    css/rc/transparent_focus.png \
    css/rc/transparent_focus@2x.png \
    css/rc/transparent_pressed.png \
    css/rc/transparent_pressed@2x.png \
    css/rc/window_close.png \
    css/rc/window_close@2x.png \
    css/rc/window_close_disabled.png \
    css/rc/window_close_disabled@2x.png \
    css/rc/window_close_focus.png \
    css/rc/window_close_focus@2x.png \
    css/rc/window_close_pressed.png \
    css/rc/window_close_pressed@2x.png \
    css/rc/window_grip.png \
    css/rc/window_grip@2x.png \
    css/rc/window_grip_disabled.png \
    css/rc/window_grip_disabled@2x.png \
    css/rc/window_grip_focus.png \
    css/rc/window_grip_focus@2x.png \
    css/rc/window_grip_pressed.png \
    css/rc/window_grip_pressed@2x.png \
    css/rc/window_minimize.png \
    css/rc/window_minimize@2x.png \
    css/rc/window_minimize_disabled.png \
    css/rc/window_minimize_disabled@2x.png \
    css/rc/window_minimize_focus.png \
    css/rc/window_minimize_focus@2x.png \
    css/rc/window_minimize_pressed.png \
    css/rc/window_minimize_pressed@2x.png \
    css/rc/window_undock.png \
    css/rc/window_undock@2x.png \
    css/rc/window_undock_disabled.png \
    css/rc/window_undock_disabled@2x.png \
    css/rc/window_undock_focus.png \
    css/rc/window_undock_focus@2x.png \
    css/rc/window_undock_pressed.png \
    css/rc/window_undock_pressed@2x.png
