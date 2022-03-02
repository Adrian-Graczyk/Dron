#ifndef WODA_HH
#define WODA_HH
/**
 * @file Woda.hh
 * @brief Definicja klasy Woda
 */
#include "Bryla.hh"
#include <vector>
#include <fstream>
#include <iostream>


/**
 * @brief Klasa Woda
 * 
 * Dziedziczy publicznie klasa Bryla
 */
class Woda: public Bryla
{

/**
 * @brief Sciezka do pliku ze wzorcowa plaszczyzna z falami
 * 
 */
const char* Nazwa_Pliku = "bryly/Woda.dat";

public:

/**
 * @brief Zwraca sciezke do pliku ze wzorcowa plaszczyzna z falami
 * 
 * @return const char* 
 */
const char* Zwroc_Nazwa()
{
    return Nazwa_Pliku;
} 


};

#endif
