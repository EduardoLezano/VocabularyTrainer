#include <cstdlib>
#include <iostream>
#include <time.h>
#include "Game.h"
#include <random>

using namespace std;

Game::Game(const std::string nameUser, const std::string docDir)
    : m_User(nameUser)
    , m_DocumentHandler(docDir)
{
    srand(time(NULL));
}

Game::Game()
{
    srand(time(NULL));

    //Cargar usuarios
    if(!CagarUsuario())
    {
        string name;
        std::cout<<"Ingrese Nombre: ";
        name = GetUserInput();
        m_User.SetName(name);
        m_User.SetPuntaje(0);
    }  

}

Game::Game(const std::string file)
    : m_DocumentHandler(file)
{
    srand(time(NULL));
    //Cargar usuarios
    if(!CagarUsuario())
    {
        string name;
        std::cout<<"Ingrese Nombre: ";
        name = GetUserInput();
        m_User.SetName(name);
        m_User.SetPuntaje(0);
    }  
}

Game::~Game()
{
    //delete m_User;
}

const bool Game::CagarUsuario()
{
    bool out = false;

    ifstream fileReaded("Usuario.dat" , ios::in | ios::binary);
    
    if( !fileReaded.fail())
    {
        struct StructUser u;
        out = true;
        fileReaded.read(reinterpret_cast<char*>(&u),sizeof(StructUser));
        m_User.SetFromStruct(u);
    }

    fileReaded.close();
    return out;
}

void Game::CrearPartida()
{
    for (unsigned int i = 0 ; i < numPalabrasNivel ; i++)
    {
        unsigned int j = GenerarNumeroAleatorio(m_DocumentHandler.GetNumeroDeLineas());
        partidaPalabras.push_back(m_DocumentHandler.GetLineasDocumento()[j]);
    }
}

std::string Game::GetUserInput()
{
    std::string strUserInput;
    getline(std::cin , strUserInput);

    return strUserInput;
}

bool Game::Evaluar(const std::string respuesta)
{
    bool eval = false; 
    return eval;
}   

void Game::StartScream(){
    system("clear");
    std::cout << "\n\nEntrenador de Vocabulario " << std::endl;
    std::cout << "        ver: 0.1.1 " << std::endl << std::endl;
    std::cout << " Name: " <<m_User.GetName()<< std::endl;
    std::cout << "Score: " <<m_User.GetPuntaje()<< std::endl;

    std::cout << "\t\tOptions" << std::endl;
    std::cout << "1.- Start" << std::endl;
    std::cout << "2.- Create new user" << std::endl;
    std::cout << "3.- Change user" << std::endl;
    std::cout << "4.- Ver puntajes" << std::endl;
    std::cout << "5.- Imprimir base de datos" << std::endl;
    std::cout << "0.- Salir" << std::endl;
}

unsigned int Game::GenerarNumeroAleatorio(unsigned int limMax )
{
    return std::rand() % (limMax + 1);
}

std::string Game::GetSpanish(const std::string linea)
{
    std::string sp = " ";

    size_t found = linea.find("=");
    if( found != std::string::npos)
    {
        sp = linea.substr(found + 2,linea.size());
    }
    else
    {
        sp = "----";
    }
    
    return sp;
}

std::string Game::GetEnglish(const std::string linea)
{
    std::string sp = " ";

    size_t found = linea.find("=");
    if( found != std::string::npos){
        sp = linea.substr(0,found - 1);
    }
    else
    {
        sp = "----";
    }
    
    return sp;
}

void Game::Run()
{
    std::string userIn;
    do
    {
        StartScream();
        userIn = GetUserInput();

        if (userIn == "1")
        {
            CrearPartida();
            MostrarPalabrasNivel();
            std::cout << "Pulse Enter para continuar... " << std::endl;
            userIn = GetUserInput();
            Play();
        }
        else if(userIn == "2"){
            //Crear Nuevo Jugador
        }
        else if(userIn == "3"){
            //Cambiar de Juagador
        }
        else if(userIn == "4"){
            //Mostrar puntajes de Jugadores
        }
        else if(userIn == "5"){
            //imprimir base de datos
            m_DocumentHandler.mostrarDocumento();
            userIn = GetUserInput();
        }
        else if(userIn == "0"){
            //Salir
            std::cout<<"Sesion terminada"<<std::endl;
        }
        else
        {
            std::cout<<"Opcion No valida"<<std::endl;
        }
        

    } while (userIn != "0");
}

void Game::MostrarPalabrasNivelResult()
{
    system("clear");
    std::cout<<"        Player: "<<m_User.GetName()<<std::endl;
    std::cout<<"Puntaje partida: "<<puntajePartida<<std::endl;
    std::cout<<"  Puntaje Total: "<<m_User.GetPuntaje()<<std::endl;

    for (unsigned int i = 0; i<partidaPalabras.size() ; i++)
    {
        if (partidaEstadoRespuesta[i])
        {
            std::cout<< i + 1  <<".- "<<partidaPalabras[i]<< "-- [V]" <<std::endl;
        }
        else
        {
            std::cout << SetForeRED << SetBackWHT;
            std::cout<< i + 1  <<".- "<<partidaPalabras[i]<< "-- [F]"<<" You Write: "<<partidaRespuestas[i] <<std::endl;
            std::cout << RESETTEXT ;
            
        }
    }
    partidaPalabras.clear();
    partidaRespuestas.clear();
    GetUserInput();
}

void Game::MostrarPalabrasNivel()
{
    system("clear");
    std::cout<<"Learn it: "<<std::endl;
    for (unsigned int i = 0; i<partidaPalabras.size() ; i++)
    {   
        std::cout << i + 1  <<".-   "<<partidaPalabras[i] <<std::endl;
        //partidaRespuestas[i] = false;
    }  
}

void Game::Play()
{
    unsigned int salir = 1;
    unsigned int i = 0;
    unsigned int acuDeErr = 0;
    puntajePartida = 0;
    std::string respuesta;

    while (salir != 0 && i < partidaPalabras.size())
    {
        system("clear");
        if(acuDeErr >= 3 )
        {
            partidaEstadoRespuesta[i] = false;
            partidaRespuestas.push_back(respuesta);
            std::cout<<"Intenta con la siguiente palabra"<<std::endl;
            acuDeErr = 0;
            i++;
            continue;
        }

        std::string objetivo = partidaPalabras[i];
        std::string strSpanish = GetSpanish(objetivo);
        std::string strEnglish = GetEnglish(objetivo);

        std::cout << "Español: " << strSpanish << std::endl;
        // comensar con repuesta
        std::cout << "English: ";
        getline(std::cin, respuesta);

        if (respuesta == strEnglish)
        {
            std::cout << "Bien hecho.. " << std::endl;
            puntajePartida ++;
            partidaEstadoRespuesta[i] = true;
            partidaRespuestas.push_back(respuesta);
            i++;
            acuDeErr = 0;
        }
        else
        {
            std::cout << "Vuelve a intentarlo" << std::endl;
            acuDeErr ++;
            continue;
        }

        //completado con todas las palabras entonces salir
        if(i == partidaPalabras.size())
            break;

        std::cout <<"       Pulse"<<std::endl;
        std::cout<< "(1)     Para Siguiente" << std::endl<< std::endl;
        std::cout<< "(0)     Para salir" << std::endl;
        std::string sal;
        std::getline( std::cin , sal );
        salir = atoi(sal.c_str());
        if(sal == "") salir = 1;
    }
    //Añador el puntaje de la partida actual
    m_User.SetPuntaje(m_User.GetPuntaje() + puntajePartida);
    MostrarPalabrasNivelResult();
    GuardarDatosUsuario();
}

void Game::GuardarDatosUsuario()
{
    ofstream fsSalida("Usuario.dat" , ios::out | ios::binary);
    struct StructUser u;
    u = m_User.GetUserStruct();
    fsSalida.write(reinterpret_cast<char*>(&u),sizeof(StructUser));
    fsSalida.close();
}




















// string RemoveSpaces(string cadena){
//     string s = "";

//     for (unsigned int i = 0; i < cadena[i] !=  '\0'; i++)
//     {
//         if(cadena[i] == ' ')
//         {
//             continue;
//         }
//         else
//         {
//             s += cadena[i];
//         }
        
//     }

//     return s;
// }
