TEMPLATE = app
CONFIG += console
CONFIG -= qt

HEADERS += \
    Tempo.h \
    Socket.h \
    Sha1.h \
    Mutex.h \
    HttpServer.h \
    Base64.h \
    Authentication.h \
    Address.h

SOURCES += \
    Tempo.cpp \
    Socket.cpp \
    Sha1.cpp \
    Mutex.cpp \
    main.cpp \
    HttpServer.cpp \
    Base64.cpp \
    Authentication.cpp \
    Address.cpp

