/**
 * @file Wirnik.cpp
 * 
 * @brief plik z metodami klasy Wirnik
 * 
 * 
 */

#include <fstream>
#include <iostream>
#include <string.h>
#include "Wirnik.hh"


/**
 * @brief Metoda obracania wirnikami
 * 
 * @param alfa 
 * @param ktory
 */
void Wirnik::Obrot(double alfa, int ktory)
{
    MacierzRot3D M_RotX, M_RotZ;
    Wektor3D  pom, wirnik;
    int i=0;
    double obrocik;
    kat_z=kat_z+alfa;
    if(kat_z>360)
    kat_z=kat_z-360;


    obrocik=kat_x+3;
    if(obrocik>360)
    obrocik=obrocik-360;

    if((alfa>0 && ktory == 1) || (alfa<0 && ktory ==2) || alfa==0)
    {
        kat_x=obrocik;
    }
    
    std::vector<Wektor3D> Wierzcholki;
    Wierzcholki= Zwroc_Wierzcholki();

    M_RotX = M_RotX.X(kat_x);
    M_RotZ = M_RotZ.Z(kat_z);

    wirnik = M_RotZ*Przesuniecie;

    
    for (const Wektor3D&  W_lok : Wierzcholki)
    {
        
        pom = W_lok;
        pom = (M_RotX * pom);
        pom = (M_RotZ * pom);
        pom= pom + Wek_Trans + wirnik;
       
        Wierzcholki[i]=pom;
        i++;
    }
    
    Pobierz_Wierzcholki(Wierzcholki);
}