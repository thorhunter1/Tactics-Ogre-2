#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>

#define Debug(x)    do{ std::cout << "[Debug]:  " << x << std::endl; }while(0)
#define Warning(x)  do{ std::cout << "[Warn] :  " << x << std::endl; }while(0)
#define Error(x)    do{ std::cout << "[Error]:  " << x << std::endl; }while(0)

#endif //DEBUG_HPP
