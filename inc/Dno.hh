#ifndef DNO_HH
#define DNO_HH
/**
 * @file Dno.hh
 * @brief Definicja klasy Dno
 */
#include "Bryla.hh"
#include <vector>
#include <fstream>
#include <iostream>


/**
 * @brief Klasa prostopadloscian
 * 
 * Dziedziczy publicznie klasa Bryla
 */
class Dno: public Bryla
{

/**
 * @brief Sciezka do pliku ze wzorcowa plaszczyzna
 * 
 */
const char* Nazwa_Pliku = "bryly/Dno.dat";

public:

/**
 * @brief Zwraca sciezke do pliku ze wzorcowa plaszczyzna
 * 
 * @return const char* 
 */
const char* Zwroc_Nazwa()
{
    return Nazwa_Pliku;
} 

};

#endif
