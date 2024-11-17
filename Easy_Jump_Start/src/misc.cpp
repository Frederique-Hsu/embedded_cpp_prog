/*!
 *  \file       misc.cpp
 *  \brief      
 *  
 */


#include "misc.hpp"


void initialize() {}
void use_i(const int) {}
void use_j(const int) {}
void use_k(const int) {}


bool valid() { return false; }
bool login() { return true;  }
void start_session() {}

void do_something()
{
    initialize();

    // Declare i when using it in use_i()
    const int i = 3;
    use_i(i);

    const int j = 7;
    use_j(j);

    // Declare k in the scope of for-loop
    for (int k = 0; k < 10; ++k)
    {
        use_k(k);
    }


    const bool session_is_ok = (valid() && login());
    if (session_is_ok)
    {
        start_session();
    }
}