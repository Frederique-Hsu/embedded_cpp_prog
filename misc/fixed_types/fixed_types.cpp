/*!
 *  \file       fixed_types.cpp
 *  \brief      Study how to use fixed-size data types in the embedded C++ programming, to make the code 
 *              portable across architectures. 
 *  \author     Frederique Hsu (frederique.hsu@outlook.com)
 *  \date       Sat.    27 May 2023
 *  
 */


#include <iostream>


/*!
 *  \brief      This is a stub function to send data pointer by buffer
 *  \param      buffer - pointer to where data is stored
 *  \param      size - specify how many bytes 
 *  \return     none
 */
void SendDataToDevice(void* buffer, uint32_t size)
{
    std::cout << "Sending data chunk of size " << size << std::endl;
}

int main(int argc, char* argv[])
{
    char buffer[] = "Hello, world!";
    #if 1
    /*!
     *	\note		To make embedded code working with the external hardware or communication 
     *			protocols portable, embedded developers should use fixed-size integer 
     *			types, which explicitly specify the size of a data field.
     *
     *			`uint32_t` means that it will take 32 bits exactly on every platform -
     *			16-, 32-, or 64-bit platform.
     */
    uint32_t size = sizeof(buffer);
    #else
    /*!
     *	\warning	Suppose that we declare the `int` data type, in this case, 
     *			the code can only work on 32- and 64-bit systems, and silently
     *			produce incorrect results on 16-bit system, because `sizeof(int)` 
     *			is 16 here.
     */
    int size = sizeof(buffer);
    #endif
    SendDataToDevice(&size, sizeof(size));
    SendDataToDevice(buffer, size);

    return 0;
}