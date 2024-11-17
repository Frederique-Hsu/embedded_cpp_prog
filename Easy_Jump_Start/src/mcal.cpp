/*!
 *  \file       mcal.cpp
 *  \brief      
 *  
 */


#include "mcal.hpp"


/*!
 *  \fn     init
 *  \brief  Initialize the mcal, note that the clean organization with namespaces.
 */
void mcal::init()
{
    mcal::gpt::init();
    mcal::adc::init();
}


void mcal::gpt::init()
{
}


void mcal::adc::init()
{
}


namespace   // An anonymous namespace can be used for file-level localization.
{
    [[maybe_unused]] unsigned local_counter;
}