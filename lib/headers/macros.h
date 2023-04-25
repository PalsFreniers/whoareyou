#pragma once

#include <iostream>

#define LOG(x)     std::cout << "\x1b[1;4m[LOG] : "       << x << "\x1b[0m" << std::endl;
#define WARNING(x) std::cout << "\x1b[33;1;4m[WARNING] : " << x << "\x1b[0m" << std::endl;
#define ERROR(x)   std::cout << "\x1b[31;1;4m[ERROR] : "   << x << "\x1b[0m" << std::endl;

#define LOG_ARG(x, ...)     std::cout << "\x1b[1;4m[LOG] : " << x << __VA_ARGS__ << "\x1b[0m" << std::endl;
#define WARNING_ARG(x, ...) std::cout << "\x1b[33;1;4m[WARNING] : " << x << __VA_ARGS__ << "\x1b[0m" << std::endl;
#define ERROR_ARG(x, ...)   std::cout << "\x1b[31;1;4m[ERROR] : " << x << __VA_ARGS__ << "\x1b[0m" << std::endl;
