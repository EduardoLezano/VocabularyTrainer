#pragma once 

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

#include "MensajesConsola.h"

class DocumentHandler
{
private:
    using VectorLineas = std::vector<std::string>;;
    VectorLineas lineasDocumento;
    std::string  dirDocumentoTXT;

    int numLineas {0}; 

public:
    DocumentHandler();
    DocumentHandler(const std::string dir);
    ~DocumentHandler();

    const void Cargar();
    unsigned int GetNumeroDeLineas() const;
    void mostrarDocumento();
    VectorLineas GetLineasDocumento() const
    {
        return lineasDocumento;
    }
    
};
