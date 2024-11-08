/*!
 * 	\file	receiver.hpp
 * 	\brief	
 *
 */


#pragma once

#include <stddef.h>
#include <string>

void ReadData(int fd, void* ptr, size_t size);

std::string ReadMessage(int fd);
