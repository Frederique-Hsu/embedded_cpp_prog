/*!
 * 	\file	receiver_main.cpp
 * 	\brief	
 *
 */



#include "receiver.hpp"

#include <unistd.h>
#include <fcntl.h>
#include <iostream>

int main(int argc, char* argv[])
{
	int fd = open("envconv.data", O_RDONLY, 0666);

	while (true)
	{
		try 
		{
			auto s = ReadMessage(fd);
			std::cout << "Read: " << s << std::endl;
		}
		catch (const std::runtime_error& exception)
		{
			std::cout << exception.what() << std::endl;
			break;
		}
	}
	return 0;
}
