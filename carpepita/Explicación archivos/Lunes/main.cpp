#include <iostream>
#include <cstring>
#include "clsAlumno.h"

using namespace std;

/**
Crear un programa con un menú con las siguientes opciones:
1-Agregar un registro al archivo.
2-Listar los registros del archivo.
EXTRA:
Hacer una opción que reciba una posición y liste el registro de esa posición (el primer registro de mi archivo ocupa la posición 0).
*/

void readRegs();
void addRegs();
void selecct(int num);
int ops();







int main()
{


    selecct(ops());





    return 0;
}



int ops()
{
    int num;
    cout<<"menu de usos \n 1-Agregar un registro al archivo \n 2-Listar los registros del archivo. \n";
    cin>>num;
    return num;
}

void selecct(int num)
{
    switch(num)
    {
    case 1:
        addRegs();
        break;
    case 2:
        readRegs();
        break;
    }
}

void addRegs()
{
    FILE *pArchivo;
    Alumno obj;
    pArchivo = fopen("alumnos.dat", "ab");
    if(pArchivo == nullptr){
        cout<<"ERROR DE APERTURA DE ARCHIVO"<<endl;
        return;
    }
    obj.Cargar();
    fwrite(&obj, sizeof obj, 1, pArchivo);
    fclose(pArchivo);
}

void readRegs()
{
    FILE *pArchivo;
    Alumno obj;
    pArchivo = fopen("alumnos.dat", "rb");
    if(pArchivo == nullptr){
        cout<<"ERROR DE APERTURA DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&obj, sizeof obj, 1, pArchivo) == 1)
    {
        cout<<"========================"<<endl;
        obj.Mostrar();
    }


}
