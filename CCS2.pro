QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bricks.cpp \
    bullet.cpp \
    bulletage.cpp \
    bulletbox.cpp \
    bulletshot.cpp \
    enemy1.cpp \
    enemy2.cpp \
    enemy2image.cpp \
    enemyimage.cpp \
    game.cpp \
    gateway.cpp \
    health.cpp \
    heart.cpp \
    house.cpp \
    housee.cpp \
    housemario.cpp \
    ice.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    playerimage.cpp \
    power.cpp \
    powersqr.cpp \
    powersymbol.cpp

HEADERS += \
    bricks.h \
    bullet.h \
    bulletage.h \
    bulletbox.h \
    bulletshot.h \
    enemy1.h \
    enemy2.h \
    enemy2image.h \
    enemyimage.h \
    game.h \
    gateway.h \
    health.h \
    heart.h \
    house.h \
    housee.h \
    housemario.h \
    ice.h \
    mainwindow.h \
    player.h \
    playerimage.h \
    power.h \
    powersqr.h \
    powersymbol.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    BulletAge.png \
    OneDrive - Personal - Shortcut.lnk \
    Practice.pro.user \
    background.jpg \
    brick22.png \
    bricks.png \
    bricks2.png \
    bullet.png \
    bulletbox.png \
    bulletshot.png \
    enemy1.png \
    enemy2.png \
    enemy2resize.png \
    game over.png \
    game over.png \
    gameover.png \
    gate1.png \
    gate2.png \
    gate3.png \
    gate4.png \
    heartp.png \
    house.png \
    housemario.png \
    ice.png \
    kirbyleft1.png \
    kirbyleft2.png \
    kirbyleft3.png \
    kirbyleftd1.png \
    kirbyleftd2.png \
    kirbyleftd3.png \
    kirbyright1.png \
    kirbyright2.png \
    kirbyright3.png \
    kirbyrightd1.png \
    kirbyrightd2.png \
    kirbyrightd3.png \
    kirbyupleft1.png \
    kirbyupleft2.png \
    kirbyupleft3.png \
    kirbyupright1.png \
    kirbyupright2.png \
    kirbyupright3.png \
    map.txt \
    power.png \
    powersqr.png \
    powersymbol.png \
    tree.png \
    youwin.png
