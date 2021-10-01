QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DBP.cpp \
    Get_signature.cpp \
    Mario.cpp \
    Maxroot.cpp \
    Mine.cpp \
    Period_string.cpp \
    Sum_hex.cpp \
    add1.cpp \
    building.cpp \
    closest_pair.cpp \
    data.cpp \
    database1.cpp \
    database6.cpp \
    easy_city2.cpp \
    escape.cpp \
    factorial.cpp \
    fibonacci.cpp \
    findstructuresoftree.cpp \
    floor.cpp \
    get_solution.cpp \
    judgewindow.cpp \
    large_factorial.cpp \
    longest_common_substring.cpp \
    longest_pair.cpp \
    longest_peek_palindrome.cpp \
    main.cpp \
    mainwindow.cpp \
    maze.cpp \
    mydatabase.cpp \
    mymath.cpp \
    myother.cpp \
    mystring.cpp \
    mytree.cpp \
    people.cpp \
    prime.cpp \
    problemset.cpp \
    scheduler.cpp \
    shortestsummationdistance.cpp \
    shy_game.cpp \
    substract1.cpp \
    the_easy_city_1.cpp \
    the_median.cpp

HEADERS += \
    DBP.h \
    Get_signature.h \
    Mario.h \
    Maxroot.h \
    Mine.h \
    Period_string.h \
    Sum_hex.h \
    add1.h \
    building.h \
    closest_pair.h \
    data.h \
    database1.h \
    database6.h \
    easy_city2.h \
    escape.h \
    factorial.h \
    fibonacci.h \
    findstructuresoftree.h \
    floor.h \
    get_solution.h \
    judgewindow.h \
    large_factorial.h \
    longest_common_substring.h \
    longest_pair.h \
    longest_peek_palindrome.h \
    mainwindow.h \
    maze.h \
    mydatabase.h \
    mymath.h \
    myother.h \
    mystring.h \
    mytree.h \
    people.h \
    prime.h \
    problemset.h \
    scheduler.h \
    shortestsummationdistance.h \
    shy_game.h \
    substract1.h \
    the_easy_city_1.h \
    the_median.h

FORMS += \
    judgewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
