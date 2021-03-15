QT       += core gui
QT       += charts

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
    addtableform.cpp \
    hallform.cpp \
    helperform.cpp \
    logger.cpp \
    main.cpp \
    generalform.cpp \
    rangeform.cpp \
    table.cpp

HEADERS += \
    addtableform.h \
    generalform.h \
    hallform.h \
    helperform.h \
    logger.h \
    rangeform.h \
    table.h

FORMS += \
    addtableform.ui \
    generalform.ui \
    hallform.ui \
    helperform.ui \
    rangeform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
