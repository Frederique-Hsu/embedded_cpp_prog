/*!
 * 	\file	sender.hpp
 * 	\brief	
 *
 */


#pragma once

#include <stddef.h>

void WriteData(int fd, const void* ptr, size_t size);

void WriteMessage(int fd, const char* str);
