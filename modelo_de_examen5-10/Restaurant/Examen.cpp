#include <iostream>
using namespace std;

#include "Examen.h"
#include "ServicioMesa.h"
#include "ArchivoServicioMesa.h"


void Examen::EjemploDeListado()
{
    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;

    int i, cantidadRegistros = archivo.CantidadRegistros();
    for(i = 0; i < cantidadRegistros; i++)
    {
        registro = archivo.Leer(i);
        cout << registro.toCSV() << endl;
    }

}
float busquedaP()
{
    float promedioP = 0;
    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;
    int i, cantidadRegistros = archivo.CantidadRegistros();
    for(i = 0; i < cantidadRegistros; i++)
    {
        registro = archivo.Leer(i);
        promedioP += registro.getPuntajeObtenido();
    }
    promedioP =(promedioP/cantidadRegistros);
    //cout<<promedioP<<'\n'; el promedio de los puntajes
    return promedioP;
}

void Examen::Punto1()
{
    float promm = busquedaP();
    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;
    int i, cantidadRegistros = archivo.CantidadRegistros();
    cout <<"los servicios de mesa superiores al promedio"<< endl;
    for(i = 0; i < cantidadRegistros; i++)
    {

        if(registro.getPuntajeObtenido()>promm)
        {
            cout << registro.toCSV() << endl;
        }
    }
    cout <<"-----" << endl;
}
void recuadacioDePropinas(int propinasMozos[])
{

    int mozo;

    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;
    int i, cantidadRegistros = archivo.CantidadRegistros();
    for(i = 0; i < cantidadRegistros; i++)
    {
        registro = archivo.Leer(i);
        if(registro.getPropina()>0){
            mozo = registro.getIDMozo();
            propinasMozos[mozo-1]++;
        }
    }
}


void recuadacioDePlatos(float recuadacioplatos[])
{
    int plato=0;

    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;
    int i, cantidadRegistros = archivo.CantidadRegistros();
    for(i = 0; i < cantidadRegistros; i++)
    {
        registro = archivo.Leer(i);
        plato=registro.getIDPlato();
        recuadacioplatos[plato-1] += registro.getImporte();
    }
}

void Examen::Punto2()
{
    float recuadacioplatos[70]= {};
    recuadacioDePlatos(recuadacioplatos);
    int mayorRecaudacion=0;
    for(int i = 1; i < 70; i++)
    {
        if(recuadacioplatos[i]>recuadacioplatos[mayorRecaudacion])
        {
            mayorRecaudacion=i;
        }
    }
    cout<<"el plato de mayor recaudacion es el plato nro: "<< mayorRecaudacion+1<<'\n';




}




void Examen::Punto3()
{

    int propinasMozos[20]= {};
    int mozoConMasPropinas = 0;
    recuadacioDePropinas(propinasMozos);

    ArchivoServicioMesa archivo("restaurant.dat");
    ServicioMesa registro;

    int i, cantidadRegistros = archivo.CantidadRegistros();
    for(i = 1; i < 20; i++)
    {
        if(propinasMozos[i]>propinasMozos[mozoConMasPropinas]){
            mozoConMasPropinas=i;
        }
    }
    cout<<"el mozo que mas propinas recibio fue el:"<<mozoConMasPropinas+1;

}
