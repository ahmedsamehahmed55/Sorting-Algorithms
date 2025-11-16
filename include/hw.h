#ifndef HW_H_
#define HW_H_

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#ifdef DEBUG
#define PDEBUG 1
#else
#define PDEBUG 0
#endif
/*
#define DPRINT(fmt, ...) do { if (PDEBUG) fprintf(stderr, "%s:%d:%s(): "fmt,\
                __FILE__, __LINE__, __func__, ##__VA_ARGS__); } while (0)
*/
#define DPRINT(fmt, ...) do {\
		 		if (PDEBUG) {\
					char str[100];\
					sprintf(str, fmt, ##__VA_ARGS__);\
					std::cerr << "DEBUG-->";\
					std::cerr << __FILE__ << ":" << __LINE__ << ":";\
					std::cerr << __func__ << "():" << str;\
		 		}\
                	} while (0)

#endif
