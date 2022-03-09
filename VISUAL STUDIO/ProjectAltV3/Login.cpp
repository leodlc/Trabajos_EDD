#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>
#include "Administrador.h"
#include "Archivo.h"



#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3


using namespace std;

void login() {
    ListaCircularDoble listaProfesor;
	ListaCircularDoble listaAlumno;
    Archivo archivo;
    Profesor profesor;
    Alumno alumno;
    //listaAlumno = archivo.leerArchivoAlumno("Alumnos.txt");
    //listaProfesor = archivo.leerArchivoProfesor("Profesores.txt" );
    vector<string> usuarios;
    vector<string> claves;
    Administrador admin;
    


    // Se a�aden usuarios al vector
    usuarios.push_back("leo");
    

    // Se a�aden claves al vector
    claves.push_back("1234");
    

    string usuario, password;
    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin >> ws, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = _getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = _getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if(!listaAlumno.estaVacia()){
            listaAlumno.recorrer([&](Alumno alumno) {
                if(alumno.getUsuario() == usuario && alumno.getContrasenaa() == password)
                    cout << "\n\n\tBienvenido al sistema - Alumno" << endl;
                ingresa = true;
                });
        }

        if(!listaProfesor.estaVacia()){
            listaProfesor.recorrer([&](Profesor profesor) {
                if(profesor.getUsuario() == usuario && profesor.getContrasenaa() == password)
                    cout << "\n\n\tBienvenido al sistema - Profesor" << endl;    
                ingresa = true;
                });
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    if (usuario == "leo" && password == "1234") {
        admin.pantallaAdmin();
        
    }
    else
    {
        listaAlumno.recorrer([&](Alumno alumno) {
            if(alumno.getUsuario() == usuario && alumno.getContrasenaa() == password){
                cout << "\n\n\tBienvenido al sistema" << endl;
                //alumno.verNotas(usuario);
            }
        });

        listaProfesor.recorrer([&](Profesor profesor) {
            if(profesor.getUsuario() == usuario && profesor.getContrasenaa() == password){
                cout << "\n\n\tBienvenido al sistema" << endl; 
                //profesor.pantallaProfe(usuario);
            }
            
        });
    }
}