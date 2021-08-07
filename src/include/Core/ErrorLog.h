#ifndef ERROR_LOG_H
#define ERROR_LOG_H

#include <stdio.h>
#include <string>	

#define fLOG(x) printf("[LOG] %s\n", x)
#define fWARN(x) printf("[WARNING] %s\n", x)
#define fERROR(x) printf("[ERROR] %s\n", x)

#endif // ERROR_LOG_H
