#pragma once 
#include "DocumentHandler.h"
#include "User.h"
#include "ColorTerminal.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

class Game
{
private:
    DocumentHandler m_DocumentHandler;
    User m_User; 

    using VectorLineas = std::vector<std::string>;
    VectorLineas partidaPalabras;
    VectorLineas partidaRespuestas;
    bool partidaEstadoRespuesta[5];

    unsigned int numPalabrasNivel {5};
    unsigned int puntajePartida;
    
public:
    Game(const std::string nameUser, const std::string docDir);
    Game(const std::string file);
    Game();
    ~Game();

    void StartScream();
    void CrearPartida();
    void Run();
    void MostrarPalabrasNivel();
    void MostrarPalabrasNivelResult();
    void Play();
    
    const bool CagarUsuario();
    void GuardarDatosUsuario();

    std::string GetUserInput();
    bool Evaluar(const std::string respuesta);

    unsigned int GenerarNumeroAleatorio(unsigned int limMax );
    std::string GetSpanish(const std::string linea);
    std::string GetEnglish(const std::string linea);

};
