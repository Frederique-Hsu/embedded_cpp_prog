/*!
 * 	\file	sender_main.cpp
 * 	\brief	
 *
 */


#include "sender.hpp"

#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fd = open("envconv.data", O_WRONLY | O_APPEND | O_CREAT, 0666);

	for (int index = 1; index < argc; ++index)
	{
		WriteMessage(fd, argv[index]);
	}
}
