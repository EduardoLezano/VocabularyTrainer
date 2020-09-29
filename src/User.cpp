#include "User.h"

User::User(const std::string name)
    : m_name(name)
{
}
User::User()
    : m_name("")
{
}
User::User(const struct StructUser user)
{
    m_name = user.name;
    m_puntaje = user.puntaje;
}

User::~User()
{
}

const std::string User::GetName() const
{
    return m_name;
}

struct StructUser User::GetUserStruct()
{
    struct StructUser user;
    strcpy(user.name,m_name.c_str());
    user.puntaje = m_puntaje;

    return user;
}

void User::SetFromStruct(struct StructUser u)
{
    m_name = u.name;
    m_puntaje = u.puntaje;
}


void User::SetName(const std::string name)
{
    m_name = name;
}

unsigned int User::GetPuntaje() const
{
    return m_puntaje;
}

void User::SetPuntaje(unsigned int p)
{
    m_puntaje = p;
}

void User::ShowValues()
{
    std::cout<<"   name: "<<m_name<<std::endl;
    std::cout<<"puntaje: "<<m_name<<std::endl;
}

void User::ShowValues(struct StructUser u)
{
    std::cout<<"   name: "<<u.name<<std::endl;
    std::cout<<"puntaje: "<<u.puntaje<<std::endl;
}