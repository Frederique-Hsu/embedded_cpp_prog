/*!
 *	\file	endianness.cpp
 *	\brief	Determine the endianness of target platform.
 *	
 */
 
 
 
 #include <iostream>
 
 int main(int argc, char* argv[])
 {
 	union {
 		uint32_t 	i;
 		uint8_t		c[4];
 	} data;
 	
 	data.i = 0x01020304;
 	std::cout << "data.c[0] = " << static_cast<int>(data.c[0]) << std::endl;
 	std::cout << "data.c[1] = " << static_cast<int>(data.c[1]) << std::endl;
 	std::cout << "data.c[2] = " << static_cast<int>(data.c[2]) << std::endl;
 	std::cout << "data.c[3] = " << static_cast<int>(data.c[3]) << std::endl;
 	
 	if (data.c[0] == 0x01)
 	{
 		std::cout << "Big-endian." << std::endl;
 	}
 	else
 	{
 		std::cout << "Little-endian." << std::endl;
 	}
 	return 0;
 }