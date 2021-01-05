QT       += core gui sql charts
QT +=printsupport
QT += sql
QT += multimedia
QT        += core gui serialport
QT       += sql network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addw.cpp \
    arduino.cpp \
    chambre.cpp \
    connection.cpp \
    dsikstat.cpp \
    email.cpp \
    equipemaintenance.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp \
    medicament.cpp \
    modw.cpp \
    patient.cpp \
    personnel.cpp \
    qcustomplot.cpp \
    requette.cpp \
    service.cpp \
    smtp.cpp \
    statchart.cpp \
    stats.cpp \
    widadd2.cpp \
    widmod2.cpp

HEADERS += \
    addw.h \
    arduino.h \
    chambre.h \
    connection.h \
    dsikstat.h \
    email.h \
    equipemaintenance.h \
    fournisseur.h \
    mainwindow.h \
    medicament.h \
    modw.h \
    patient.h \
    personnel.h \
    qcustomplot.h \
    requette.h \
    service.h \
    smtp.h \
    statchart.h \
    stats.h \
    widadd2.h \
    widmod2.h

FORMS += \
    addw.ui \
    dsikstat.ui \
    email.ui \
    mainwindow.ui \
    modw.ui \
    statchart.ui \
    stats.ui \
    widadd2.ui \
    widmod2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
