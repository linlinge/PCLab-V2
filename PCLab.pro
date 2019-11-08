#-------------------------------------------------
#
# Project created by QtCreator 2019-04-29T02:43:49
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PCLab
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT += core gui xml opengl

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        pcviewer.cpp \
    denoisingmodule.cpp \
    global.cpp \
    src/OutlierRemoval.cpp \
    about.cpp \
    gui_outlier_removal.cpp

HEADERS += \
        pcviewer.h \
    denoisingmodule.h \
    global.h \
    src/OutlierRemoval.h \
    about.h \
    gui_outlier_removal.h

FORMS += \
        pcviewer.ui \
    about.ui \
    gui_outlier_removal.ui

# eigen3
INCLUDEPATH += /usr/include/eigen3

# libCGAL
#INCLUDEPATH += /usr/local/include/CGAL
#LIBS += /usr/local/lib/libCGAL*.so
#LIBS +=-lCGAL -lCGAL_Core -lgmp

# vtk
INCLUDEPATH += /usr/include/vtk-6.3
LIBS += /usr/lib/x86_64-linux-gnu/libvtk*.so

# boost
INCLUDEPATH += /usr/include/boost
LIBS += /usr/lib/x86_64-linux-gnu/libboost_*.so

# pcl
INCLUDEPATH += /usr/include/pcl-1.8
LIBS += /usr/lib/x86_64-linux-gnu/libpcl_*.so

RESOURCES += \
    res.qrc
