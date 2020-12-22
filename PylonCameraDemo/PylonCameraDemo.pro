######################################################################
# Automatically generated by qmake (3.1) Tue Dec 22 14:42:34 2020
######################################################################

TEMPLATE = app
TARGET = PylonCameraDemo
INCLUDEPATH += .
INCLUDEPATH += /opt/pylon/include/

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT += quick multimedia

LIBS += -L/opt/pylon/lib -lpylonbase -lGenApi_gcc_v3_1_Basler_pylon -lGCBase_gcc_v3_1_Basler_pylon -lLog_gcc_v3_1_Basler_pylon \
-lMathParser_gcc_v3_1_Basler_pylon -lXmlParser_gcc_v3_1_Basler_pylon -lNodeMapData_gcc_v3_1_Basler_pylon \
-lpylonutility

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += QPylonCamera.h
SOURCES += main.cpp QPylonCamera.cpp
RESOURCES += qml.qrc
