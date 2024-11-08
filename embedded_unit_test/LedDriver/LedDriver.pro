TEMPLATE = app
CONFIG += console -Wall -Werror
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../unity.test.framework/extras/fixture/unity_fixture.c \
        ../unity.test.framework/extras/memory/unity_memory.c \
        ../unity.test.framework/unity.c \
        LED_Driver/led_driver.c \
        LED_Driver/test_led_driver.c \
        circular_buffer.c \
        main.c \
        mocks/RuntimeErrorStub.c

HEADERS += \
    ../unity.test.framework/extras/bdd/unity_bdd.h \
    ../unity.test.framework/extras/fixture/unity_fixture.h \
    ../unity.test.framework/extras/fixture/unity_fixture_internals.h \
    ../unity.test.framework/extras/memory/unity_memory.h \
    ../unity.test.framework/unity.h \
    ../unity.test.framework/unity_internals.h \
    LED_Driver/led_driver.h \
    circular_buffer.h \
    mocks/RuntimeErrorStub.h \
    util/RuntimeError.h
