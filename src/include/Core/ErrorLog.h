#ifndef ERROR_LOG_H
#define ERROR_LOG_H

#include <stdio.h>
#include <string>

static void fERROR() 
{
	printf("\n");
}

template<typename First, typename ... Strings>
static void fERROR(First arg, const Strings&... rest) 
{
	printf("[ERROR] ");
	printf("%s ", arg);
	fERROR(rest...);
}

#define LOG(x) printf("[LOG] %s\n", x)
#define WARN(x) printf("[WARNING] %s\n", x)

#endif // ERROR_LOG_H
