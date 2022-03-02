#ifndef PRZESZKODA_PROSTOPADLOSCIAN_HH
#define PRZESZKODA_PROSTOPADLOSCIAN_HH
/**
 * @file Przeszkoda_prostopadloscian.hh
 * @brief Klasa przeszkody prostopadlościennej
 * 
 */
#include "Bryla.hh"
#include <iostream>


/**
 * @brief Klasa Przeszkoda_Prostopadloscian
 * 
 * Dziedziczy publicznie klasa Bryla
 */
class Przeszkoda_Prostopadloscian: public Bryla
{

protected:


public:

/**
 * @brief wirtualna metoda zwracajaca rodzaj przeszkody
 * 
 * @return std::string 
 */
virtual std::string Zwroc_Typ() override
{
    return "Przeszkoda - Prostopadloscian";
}

};

#endif
