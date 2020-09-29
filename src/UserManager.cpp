#include "UserManager.h"

UserManager::UserManager()
{
}

UserManager::~UserManager()
{
}

void UserManager::CargarUsuarios() 
{
    std::ifstream fsEntrada(DIR ,std::ios::in | std::ios::binary);
    struct StructUser us;
    User u;
  
    while (fsEntrada.eof())
    {
        fsEntrada.read(reinterpret_cast<char*>(&us),sizeof(StructUser));
        u.SetFromStruct(us);
        m_VectorUsuarios.push_back(u);
    }
    
    fsEntrada.close();
}

bool UserManager::BorrarUsuario() 
{
    return true;
}

User UserManager::SeleccionarUsuario()
{
    User u;

    unsigned int i = 1;

        std::cout<< "["<<i<<"]" << u.GetName() <<std::endl;

    
    return u;
}

void UserManager::GuardarUsuario(User u) 
{
    std::ofstream fsSalida(DIR ,std::ios::out | std::ios::binary);
    struct StructUser us;
    us = u.GetUserStruct();
    fsSalida.write(reinterpret_cast<char*>(&u),sizeof(StructUser));
    fsSalida.close();
}

void UserManager::IngresarUsuario()
{
    std::cout<<"Ingreso de Nuevo Jugador"<<std::endl;
    std::cout<<"Name: "<<std::endl;
    std::string name;
    getline(std::cin, name);
    User u(name);
    GuardarUsuario(u);
}

void UserManager::ListarUsuariosPuntaje()
{
    
}

void UserManager::MostrarUsuario(User u)
{
    std::cout<< u.GetName() << "............."<<u.GetPuntaje();
}   