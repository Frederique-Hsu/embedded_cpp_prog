/*!
 * 	\file	sender.cpp
 * 	\brief	
 *
 */


#include "sender.hpp"

#include <unistd.h>
#include <stdexcept>
#include <cstring>
#include <arpa/inet.h>
#include <stdint.h>

void WriteData(int fd, const void* ptr, size_t size)
{
	size_t offset = 0;
	while (size)
	{
		const char* buffer = (const char*)ptr + offset;
		int written = write(fd, buffer, size);
		if (written < 0)
		{
			throw std::runtime_error("Cannot write to file");
		}
		offset += written;
		size -= written;
	}
}

void WriteMessage(int fd, const char* str)
{
	uint32_t size = std::strlen(str);
	uint32_t encoded_size = htonl(size);

	WriteData(fd, &encoded_size, sizeof(encoded_size));
	WriteData(fd, str, size);
}
