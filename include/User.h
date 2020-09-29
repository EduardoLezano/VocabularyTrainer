#pragma once

#include <string>
#include <iostream>
#include <cstring>

struct StructUser
{
    char name[32];
    unsigned int puntaje;
};


class User
{
private:
    std::string m_name;
    unsigned int m_puntaje {0};

public:
    User(const std::string name);
    User(const struct StructUser user);
    User();
    ~User();
    
    const std::string GetName() const;
    struct StructUser GetUserStruct();
    unsigned int GetPuntaje() const;

    void SetName(const std::string name);
    void SetPuntaje(unsigned int p);
    void SetFromStruct(struct StructUser u);

    void ShowValues();
    void ShowValues(struct StructUser u);
};
