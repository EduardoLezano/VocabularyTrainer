#pragma once

#include <iostream>
#include <string>


class Adivinar
{
private:
    std::string answer;
    std::string playerInput;
public:
    Adivinar();

    bool Evaluar(const std::string ans, const std::string pin);
    const std::string getUserInput();

};
