/*!
 * 	\file	receiver.cpp
 * 	\brief	
 *
 */


#include "receiver.hpp"

#include <unistd.h>
#include <stdexcept>
#include <arpa/inet.h>
#include <memory>
#include <string>


void ReadData(int fd, void* ptr, size_t size)
{
	size_t offset = 0;
	while (size)
	{
		char* buffer = (char*)ptr + offset;

		int received = read(fd, buffer, size);
		if (received < 0)
		{
			throw std::runtime_error("Cannot read from file.");
		}
		else if (received == 0)
		{
			throw std::runtime_error("No more data.");
		}
		offset += received;
		size -= received;
	}
}

std::string ReadMessage(int fd)
{
	uint32_t encoded_size = 0;
	ReadData(fd, &encoded_size, sizeof(encoded_size));

	uint32_t size = ntohl(encoded_size);
	auto data = std::make_unique<char[]>(size);
	ReadData(fd, data.get(), size);

	return std::string(data.get(), size);
}
