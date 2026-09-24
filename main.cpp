#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <windows.h>

using namespace std;


void registrarEstudiante(int estcarne[], string estnombres[], string estapellidos[], int &totalestudiantes)
{
    string carne, nombres, apellidos;
    bool valido;
    int carnenumero = 0;

    if (totalestudiantes >= 50){
        cout<<"---Registro de estudiante---"<<endl;
        cout<<"Error: Ya no se pueden registrar mas estudiantes, el limite es 50"<<endl;
        system("pause");
        system("cls");
        return;
    }

    do{
        valido = true;

        cout<<"---Registro de estudiante---"<<endl;
        cout<<"Ingrese el carne del estudiante: ";
        getline(cin, carne);

        if (carne.empty()){
            cout<<"Error: El carne no puede estar vacio"<<endl;
            valido = false;
            system("pause");
            system("cls");
        }
        else{
            for (char c: carne){
                if(!isdigit(c)){
                    cout<<"Error: El carne debe contener solo numeros"<<endl;
                    valido = false;
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }
        if (valido && carne.length() > 9){
            cout<<"Error: El carne no debe tener mas de 9 digitos"<<endl;
            valido = false;
            system("pause");
            system("cls");
        }
        if (valido){
            carnenumero = stoi(carne);

            if (carnenumero <= 0){
                cout<<"Error: El carne debe ser mayor a cero"<<endl;
                valido = false;
                system("pause");
                system("cls");
            }
        }
        if (valido){
            for (int i=0; i<totalestudiantes; i++){
                if (estcarne[i] == carnenumero){
                    cout<<"Error: Ya existe un estudiante registrado con el carne "<<carnenumero<<endl;
                    valido = false;
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }

    } while (!valido);
    system("cls");

    do{
        valido = true;

        cout<<"---Registro de estudiante---"<<endl;
        cout<<"Ingrese los nombres del estudiante: ";
        getline(cin, nombres);

        if (nombres.empty()){
            cout<<"Error: Los nombres no pueden estar vacios"<<endl;
            valido = false;
            system("pause");
            system("cls");
        }
        else{
            bool tieneletra = false;
            for (char c: nombres){
                if (isalpha(c)){
                    tieneletra = true;
                }
                else if (c != ' '){
                    cout<<"Error: Los nombres solo deben contener letras y espacios"<<endl;
                    valido = false;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            if (valido && !tieneletra){
                cout<<"Error: Los nombres no pueden ser solo espacios"<<endl;
                valido = false;
                system("pause");
                system("cls");
            }
        }

    } while (!valido);
    system("cls");

    do{
        valido = true;

        cout<<"---Registro de estudiante---"<<endl;
        cout<<"Ingrese los apellidos del estudiante: ";
        getline(cin, apellidos);

        if (apellidos.empty()){
            cout<<"Error: Los apellidos no pueden estar vacios"<<endl;
            valido = false;
            system("pause");
            system("cls");
        }
        else{
            bool tieneletra = false;
            for (char c: apellidos){
                if (isalpha(c)){
                    tieneletra = true;
                }
                else if (c != ' '){
                    cout<<"Error: Los apellidos solo deben contener letras y espacios"<<endl;
                    valido = false;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            if (valido && !tieneletra){
                cout<<"Error: Los apellidos no pueden ser solo espacios"<<endl;
                valido = false;
                system("pause");
                system("cls");
            }
        }

    } while (!valido);
    system("cls");

    estcarne[totalestudiantes] = carnenumero;
    estnombres[totalestudiantes] = nombres;
    estapellidos[totalestudiantes] = apellidos;
    totalestudiantes++;

    cout<<"Estudiante registrado correctamente!"<<endl;
    system("pause");
    system("cls");
}

void consultarEstudiantes(int estcarne[], string estnombres[], string estapellidos[], int totalestudiantes)
{
    cout<<"---listado de estudiantes---"<<endl;

    if (totalestudiantes == 0){
        cout<<"No hay estudiantes registrados"<<endl;
    }
    else{
        cout<<"Total de estudiantes: "<<totalestudiantes<<endl;
        cout<<"----------------------------"<<endl;
        for (int i=0; i<totalestudiantes; i++){
            cout<<"Estudiante #"<<i+1<<endl;
            cout<<"Carne: "<<estcarne[i]<<endl;
            cout<<"Nombres: "<<estnombres[i]<<endl;
            cout<<"Apellidos: "<<estapellidos[i]<<endl;
            cout<<"----------------------------"<<endl;
        }
    }
    system("pause");
    system("cls");
}

int main()
{
    //Arreglos para guardar los libros

    string libcodigo[50];
    string libtitulo[50];
    string libautor[50];
    int libanio[50];
    string libcategoria[50];
    int libejemplares[50];

    //Arreglos para guardar estudiantes

    int estcarne[50];
    string estnombres[50];
    string estapellidos[50];

    //Variables

    int totallibros=0, totalestudiantes=0, opcion, i;
    int anioactual=2026, anio, ejemplares, opcat;
    string codigo, titulo, autor, categoria, anioingresado, categoriaingresada, ejemplaresingresados;

    //Bucle principal del sistema

    do{

        cout<<"----SISTEMA BIBLIOTECA----"<<endl;
        cout<<"1.Registrar libros"<<endl;
        cout<<"2.Registrar estudiantes"<<endl;
        cout<<"3.consultar libros "<<endl;
        cout<<"4.Consultar estudiantes"<<endl;
        cout<<"5.Salir"<<endl;
        cout<<"Ingrese una opcion:";
        cin>> opcion;
        cin.ignore();
        system("cls");

        switch (opcion){
            case 1:
                //Validar que el codigo no este vacio
                do{
                    cout<<"---Registro de libro---"<<endl;
                    cout<<"Ingrese el codigo del libro: ";
                    getline(cin, codigo);
                    if (codigo.empty()) {
                        cout<<"Error: El codigo no puede estar vacio"<<endl;
                        system("pause");
                        system("cls");
                    }
                    } while (codigo.empty());
                    system("cls");

                //Validar que el titulo no este vacio
                do{
                    cout<<"---Registro de libro---"<<endl;
                    cout<<"Ingrese el titulo del libro: ";
                    getline(cin, titulo);
                    if (titulo.empty()) {
                        cout<<"Error: El titulo no puede estar vacio"<<endl;
                        system("pause");
                        system("cls");
                    }
                    } while (titulo.empty());
                    system("cls");

                //Validar que el autor no este vacio
                do{
                    cout<<"---Registro de libro---"<<endl;
                    cout<<"Ingrese el autor del libro: ";
                    getline(cin, autor);
                    if (autor.empty()) {
                        cout<<"Error: El autor no puede estar vacio"<<endl;
                        system("pause");
                        system("cls");
                    }
                    } while (autor.empty());
                    system("cls");

                //Validar que el anio no sea mayor al actual, no este vacio, sea mayor a 0 y sean solo numeros
                //Variable para realizar las comprobaciones del anio:
                bool valido;

                do{

                    valido= true;

                    cout<<"---Registro de libro---"<<endl;
                    cout<<"Ingrese el anio de publicacion del libro: ";
                    getline(cin, anioingresado);

                    if  (anioingresado.empty()){
                        cout<<"Error: El anio no debe estar vacio"<<endl;
                        valido = false;
                        system("pause");
                        system("cls");
                    }
                    else{
                        for (char c: anioingresado){
                            if(!isdigit(c)){
                                cout<<"Error: El anio debe contener solo numeros"<<endl;
                                valido = false;
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }
                    if (valido){
                        anio = stoi(anioingresado);

                        if(anio<=0 or anio>anioactual){
                            cout<<"Error: El anio debe ser mayor a cero y menor o igual a: "<<anioactual<<endl;
                            valido = false;
                        }
                        system("pause");
                        system("cls");
                    }

                    } while (!valido);
                    system("cls");

                    //Validar que el usuario ingrese una categoria valida
                do{

                    valido = true;

                    cout<<"---Registro de libro---"<<endl;
                    cout<<"Categorias disponibles: "<<endl;
                    cout<<"1. Literatura"<<endl;
                    cout<<"2. Ciencias"<<endl;
                    cout<<"3. Informatica: "<<endl;
                    cout<<"4. Sociales"<<endl;
                    cout<<"5. Otra"<<endl;
                    cout<<"Elija la categoria del libro: ";
                    getline(cin, categoriaingresada);

                    if  (categoriaingresada.empty()){
                        cout<<"Error: Elija una categoria, el espacio no debe estar vacio"<<endl;
                        valido = false;
                        system("pause");
                        system("cls");
                    }

                    else{
                        for (char c: categoriaingresada){
                            if(!isdigit(c)){
                                cout<<"Error: Por favor ingrese el numero correspondiente a la categoria"<<endl;
                                valido = false;
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }
                    if (valido){
                        opcat = stoi(categoriaingresada);

                        if(opcat < 1 or opcat > 5){
                            cout<<"Error: Debe elegir una categoria entre 1 y 5 "<<endl;
                            valido = false;
                        }
                        system("pause");
                        system("cls");
                    }

                    } while (!valido);
                    system("cls");

                    //Almacenar la categoria en su variable
                    switch (opcat){
                        case 1:
                            categoria = "Literatura";
                            break;
                        case 2:
                            categoria = "Ciencias";
                            break;
                        case 3:
                            categoria = "Informatica";
                            break;
                        case 4:
                            categoria = "Sociales";
                            break;
                        case 5:
                            categoria = "Otra";
                            break;

                        }
                //Validar que la cantidad de ejemplares sea mayor a 0
                do{

                    valido= true;

                    cout<<"---Registro de libro---"<<endl;
                    cout<<"Ingrese la cantidad de ejemplares: ";
                    getline(cin, ejemplaresingresados);

                    if  (ejemplaresingresados.empty()){
                        cout<<"Error: Este campo no debe estar vacio"<<endl;
                        valido = false;
                        system("pause");
                        system("cls");
                    }
                    else{
                        for (char c: ejemplaresingresados){
                            if(!isdigit(c)){
                                cout<<"Error: Este campo debe contener solo numeros"<<endl;
                                valido = false;
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }
                    if (valido){
                        ejemplares = stoi(ejemplaresingresados);

                        if(ejemplares<=0){
                            cout<<"Error: La cantidad debe ser mayor a cero "<<endl;
                            valido = false;
                        }
                        system("pause");
                        system("cls");
                    }

                    } while (!valido);
                    system("cls");

                //Guardar el libro en los arreglos

                libcodigo[totallibros] = codigo;
                libtitulo[totallibros] = titulo;
                libautor[totallibros] = autor;
                libanio[totallibros] = anio;
                libcategoria[totallibros] = categoria;
                libejemplares[totallibros] = ejemplares;
                totallibros++;

                cout<<"Libro registrado correctamente!"<<endl;
                system("pause");
                system("cls");

                break;
            case 2:
                registrarEstudiante(estcarne, estnombres, estapellidos, totalestudiantes);
                break;
            case 3:
                cout<<"---listado de libros---"<<endl;
                for (int i=0; i<totallibros; i++){
                    cout<<"Codigo: "<< libcodigo[i]<<endl;
                    cout<<"Titulo: "<< libtitulo[i]<<endl;
                    cout<<"Autor: "<< libautor[i]<<endl;
                    cout<<"Anio de publicacion: "<< libanio[i]<<endl;
                    cout<<"Categoria: "<< libcategoria[i]<<endl;
                    cout<<"Ejemplares: "<< libejemplares[i]<<endl;
                    }
                    system("pause");
                    system("cls");
                break;
            case 4:
                consultarEstudiantes(estcarne, estnombres, estapellidos, totalestudiantes);
                break;
            case 5:
                cout<<"---Gracias por usar el sistema---"<<endl;
                break;
            default:
                cout<<"---Opcion invalida---"<<endl;
                break;




        }



    } while(opcion !=5);

    return 0;
    }
