/*!
 *  \file       led_driver.h
 *  \brief
 *
 */


#ifndef LED_DRIVER_H
#define LED_DRIVER_H

    #include <stdint.h>
    #include <stdbool.h>

    void LedDriver_Create(uint16_t* address);
    void LedDriver_Destroy(void);
    void LedDriver_TurnOn(int ledNumber);
    void LedDriver_TurnOff(int ledNumber);
    void LedDriver_TurnAllOn(void);
    bool LedDriver_IsOn(int ledNumber);
    bool LedDriver_IsOff(int ledNumber);
    void LedDriver_TurnAllOff(void);

#endif  /* LED_DRIVER_H */
