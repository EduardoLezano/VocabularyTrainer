#pragma once

#include <iostream>
#include <string>
class MensajesConsola
{
private:
    /* data */
public:
    MensajesConsola()
    {
    }
    ~MensajesConsola() {}
    void printCaraError(const std::string mensaje)
    {
        std::cout << " ... " << std::endl;
        std::cout << "(X X)" << std::endl;
        std::cout << "  U  " << std::endl;
    }
};

