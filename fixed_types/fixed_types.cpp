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
    uint32_t size = sizeof(buffer);
    SendDataToDevice(&size, sizeof(size));
    SendDataToDevice(buffer, size);

    return 0;
}