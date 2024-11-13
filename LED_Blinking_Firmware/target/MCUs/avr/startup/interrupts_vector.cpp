/*!
 *  \file       interrupts_vector.cpp
 *  \brief      
 *  
 */


#include <array>
#include <cstdint>

#include "../../../../mcal/avr/mcal_cpu.hpp"

extern "C" void __my_startup()        __attribute__((section(".startup"), used, noinline));
extern "C" void __vector_unused_irq() __attribute__((signal, used, externally_visible));
extern "C" void __vector_16()         __attribute__((signal, used, externally_visible));


extern "C" void __vector_unused_irq()
{
    while (true)
    {
        mcal::cpu::nop();
    }
}


namespace
{
    typedef struct isr_type
    {
        typedef void (*function_type)(void);

        const std::uint16_t jmp[2];     // JMP instruction (0x940C): 0x0C = low byte, 0x94 = high byte
        const function_type func;       // The interrupt service routine
    }
    isr_type;
}


extern "C" const volatile std::array<isr_type, 26U> __isr_vector __attribute__((section(".isr_vector"))) = 
{{  // jmp[0] jmp[1]    func                        addr.   nr.     interrupt service routine
    { {0x0C,  0x9C},  __my_startup },           //  0x00,    0,     reset 
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x02,    1,     ext0
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x04,    2,     ext1
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x06,    3,     pin0
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x08,    4,     pin1
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x0A,    5,     pin2
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x0C,    6,     watchdog
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x0E,    7,     timer2 cmp a
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x10,    8,     timer2 cmp b
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x12,    9,     timer2 ovf
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x14,   10,     timer1 cap
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x16,   11,     timer1 cmp a
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x18,   12,     timer1 cap b
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x1A,   13,     timer1 ovf
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x1C,   14,     timer0 cmp a
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x1E,   15,     timer0 cmp b
    { {0x0C,  0x94},  __vector_16 },            //  0x2E,   16,     timer1 ovf
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x20,   17,     spi (TM)
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x22,   18,     usart rx
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x24,   19,     usart err
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x26,   20,     usart tx
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x28,   21,     adc
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x2A,   22,     eep ready
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x2C,   23,     comparator
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x2E,   24,     two-wire
    { {0x0C,  0x94},  __vector_unused_irq },    //  0x30,   25,     spm
}};
