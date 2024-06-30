TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lunity

DEFINES += UNITY_FIXTURE_NO_EXTRAS

SOURCES += \
        UTest4Sprintf.c \
        main.c \
        unity_fixture.c

HEADERS += \
    unity_fixture.h \
    unity_fixture_internals.h
