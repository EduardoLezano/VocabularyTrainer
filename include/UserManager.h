#pragma once

#include "User.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>



class UserManager
{
private:
    UserManager* m_pUserManager;
    using UserVector = std::vector<User>;
    UserVector m_VectorUsuarios;
    const char* DIR {"usuario.dat"};

public:
    UserManager();
    ~UserManager();

    void CargarUsuarios(); 
    bool BorrarUsuario();
    void GuardarUsuario(User u);

    User SeleccionarUsuario();
    void IngresarUsuario();
    void ListarUsuariosPuntaje();
    void MostrarUsuario(User u);

    bool existeUsuario(const std::string name) const;
    User leerUsuario();
    User buscarUsuario();
    void listarUsuarios();
};
