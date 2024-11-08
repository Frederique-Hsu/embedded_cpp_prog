/*!
 *  \file       RuntimeErrorStub.c
 *  \brief
 *
 */


#include "RuntimeErrorStub.h"
#include "../util/RuntimeError.h"

#include <stdio.h>

static const char* message = "No Error";
static int parameter = -1;
static const char* file = NULL;
static int line = -1;

void RuntimeErrorStub_Reset(void)
{
    message = "No Error";
    parameter = -1;
}

const char* RuntimeErrorStub_GetLastError(void)
{
    return message;
}

void RuntimeError(const char* mesg, int param, const char* fi, int ln)
{
    message = mesg;
    parameter = param;
    file = fi;
    line = ln;
}

int RuntimeErrorStub_GetLastParameter(void)
{
    return parameter;
}
