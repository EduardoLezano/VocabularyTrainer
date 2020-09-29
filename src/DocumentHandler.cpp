#include "DocumentHandler.h"

DocumentHandler::DocumentHandler()
    : dirDocumentoTXT("/home/eduardo/VocabularioIngles.txt")
{
    Cargar();
}

DocumentHandler::DocumentHandler(const std::string dir)
    : dirDocumentoTXT(dir)
{
    Cargar();
}

const void DocumentHandler::Cargar()
{
    std::ifstream archivo;
    archivo.open(dirDocumentoTXT.c_str());

    if (archivo.fail())
    {
        MensajesConsola  mc;
        mc.printCaraError("Algo va mal");
    }
    else
    {
        char linea[128];
        while (!archivo.eof())
        {
            archivo.getline(linea, sizeof(linea));
            std::string strLinea(linea);
            if (strLinea.length() > 1 && strLinea[0] != '/')
            {
                lineasDocumento.push_back(strLinea);
                numLineas++;
            }
        }
        archivo.close();
    }
}

DocumentHandler::~DocumentHandler()
{
}

unsigned int DocumentHandler::GetNumeroDeLineas() const
{
    return numLineas;
}

void DocumentHandler::mostrarDocumento(){
    std::cout<<"   Archivo: "<< dirDocumentoTXT <<std::endl;
    std::cout<<"Num lineas: "<< numLineas <<std::endl;

    for (unsigned int i = 0; i <lineasDocumento.size(); i++)
    {
        std::cout<<lineasDocumento[i]<<std::endl;
    } 
}