#ifndef WIRNIK_HH
#define WIRNIK_HH
/**
 * @file Wirnik.hh
 * @brief Definicja klasy Wirnik
 * 
 */
#include "Bryla.hh"
#include <iostream>


/**
 * @brief Klasa Wirnik
 * 
 * Dziedziczy publicznie klase Bryla
 */
class Wirnik: public Bryla
{
/**
 * @brief kat aktualnego obrotu w osi x
 * 
 */
double kat_x = 0;

/**
 * @brief kat aktualnego obrotu w osi x
 * 
 */
double kat_z = 0;


/**
 * @brief rozroznianie wirnikow
 * 
 */
int ktory;

/**
 * @brief przesunienie wirnika wzgledem korpusu drona
 * 
 */
Wektor3D Przesuniecie;


protected:

public:

void Pobierz_Przesuniecie(Wektor3D nowe)
{
    Przesuniecie = nowe;
}

/**
 * @brief metoda obracania wirnikami
 * 
 * @param alfa 
 * @param ktory
 */
void Obrot(double alfa, int ktory);

};

#endif
