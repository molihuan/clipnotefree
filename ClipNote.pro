QT       += core gui websockets concurrent sql network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET=ClipNoteFree
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
RC_ICONS = asset/logo.ico
include(QHotkey/qhotkey.pri)
SOURCES += \
    src/dao/DataManager.cpp \
src/mainwindow.cpp\
src/main.cpp\
    src/ocr/BaiduOcr.cpp \
    src/ocr/BaseOcr.cpp \
    src/utils/CommonUtil.cpp \
    src/utils/HttpUtil.cpp \
    src/utils/StrUtil.cpp \
tests/test1.cpp

HEADERS += \
    src/dao/DataManager.h \
    src/include/Constants.h \
src/include/mainwindow.h \
    src/ocr/BaiduOcr.h \
    src/ocr/BaseOcr.h \
    src/utils/CommonUtil.h \
    src/utils/HttpUtil.h \
    src/utils/StrUtil.h

FORMS += \
src/ui/mainwindow.ui

TRANSLATIONS += \
    asset/ClipNote_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES +=res.qrc


