#ifndef PRZESZKODA_PlASZCZYZNA_HH
#define PRZESZKODA_PLASZCZYZNA_HH

/**
 * @file Przeszkoda_plaszczyzna.hh
 * @brief Klasa przeszkody - plaszczyzny
 * 
 * 
 */
#include "Bryla.hh"
#include <iostream>


/**
 * @brief Klasa Przeszkoda_Plaszczyzna
 * 
 * Dziedziczy publicznie klasa Bryla
 */
class Przeszkoda_Plaszczyzna: public Bryla
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
    return "Przeszkoda - Plaszczyzna";
}

};

#endif
