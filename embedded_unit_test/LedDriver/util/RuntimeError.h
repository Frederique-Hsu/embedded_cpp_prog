/*!
 *  \file       RuntimeError.h
 *  \brief
 *
 */


#pragma once

void RuntimeError(const char* message, int parameter, const char* file, int line);

#define RUNTIME_ERROR(description, parameter) \
    RuntimeError(description, parameter, __FILE__, __LINE__)
