/*!
 *  \file       led.hpp
 *  \brief      Define the led class
 *  
 */


#pragma once

#include <cstdint>


#define STANDALONE_LED_CLASS    1
#define EFFICIENT_LED_TEMPLATE  2

#define LED_DEFINITION          EFFICIENT_LED_TEMPLATE

#if (LED_DEFINITION == STANDALONE_LED_CLASS)
    class led
    {
    public:
        using port_type = std::uint8_t;
        using bval_type = std::uint8_t;
    public:
        explicit led(const port_type p, const bval_type b);
    private:
        const port_type port;
        const bval_type bval;
    public:
        void toggle() const;
    };
#elif (LED_DEFINITION == EFFICIENT_LED_TEMPLATE)
    template<typename port_type,
            typename bval_type,
            const port_type port,
            const bval_type bval>
    class led_template
    {
    public:
        led_template();
    private:
        static constexpr port_type pdir = port - 1U;
    public:
        static void toggle();
    };

    template<typename port_type, typename bval_type, const port_type port, const bval_type bval>
    led_template<port_type, bval_type, port, bval>::led_template()
    {
        // Set the port pin value to low
        *reinterpret_cast<volatile bval_type*>(port) &= static_cast<bval_type>(~bval);
        // Set the port pin direction to output
        *reinterpret_cast<volatile bval_type*>(pdir) |= bval;
    }

    template<typename port_type, typename bval_type, const port_type port, const bval_type bval>
    void led_template<port_type, bval_type, port, bval>::toggle()
    {
        *reinterpret_cast<volatile bval_type*>(port) ^= bval;
    }
#endif