/*!
 *  \file       crt0.cpp
 *  \brief      
 *  
 */


#include "crt.hpp"

#include "../../../../mcal/avr/mcal_cpu.hpp"

asm(".extern __initial_stack_pointer");

extern "C" void __my_startup() __attribute__((section(".startup"), used, noinline));

void __my_startup()
{
        // Load the sreg register
    asm volatile("eor r1, r1");
    asm volatile("out 0x3f, r1");

    // Set the stack pointer
    asm volatile("ldi r28, lo8(__initial_stack_pointer)");
    asm volatile("ldi r29, hi8(__initial_stack_pointer)");

    asm volatile("out 0x3e, r29");      // Load the sph register (stack pointer high-8-bits)
    asm volatile("out 0x3d, r28");      // Load the spl register (stack pointer low-8-bits)

    mcal::cpu::init();      // Initialize the CPU, including watchdog, ports, oscillators and other clocks

    crt::init_ram();        // Initialize statics from ROM to RAM, zero-clear default-initialized static RAM
    crt::init_ctors();      // Call all ctors initializatios.

    asm volatile("jmp main");   // Jump to main() portal function of user program (, and never return)

    while(true)     // Catch the unexpected return from main() routine
    {
        ;           // Replace with a loudable error if needed
    }
}
