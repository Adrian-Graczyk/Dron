#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
/**
 * @file Prostopadloscian.hh
 * @brief Definicja klasy Prostopadloscian
 * 
 */
#include "Bryla.hh"
#include <iostream>


/**
 * @brief Klasa prostopadloscian
 * 
 * Dziedziczy publicznie klasa Bryla
 */
class Prostopadloscian: public Bryla
{

/**
 * @brief Sciezka do pliku ze wzorcowym prostopadloscianem
 * 
 */
const char* Nazwa_Pliku= "bryly/Prostopadloscian.dat";

protected:


public:

/**
 * @brief Zwraca sciezke do pliku ze wzorcowym prostopadloscianem
 * 
 * @return const char* 
 */
const char* Zwroc_Nazwa()
{
    return Nazwa_Pliku;
} 

};

#endif
