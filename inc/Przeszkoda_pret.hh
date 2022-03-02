#ifndef PRZESZKODA_PRET_HH
#define PRZESZKODA_PRET_HH

/**
 * @file Przeszkoda_pret.hh
 * @brief Klasa przeszkody - pretu
 * 
 * 
 */
#include "Bryla.hh"
#include <iostream>


/**
 * @brief Klasa Przeszkoda_Pret
 * 
 * Dziedziczy publicznie klasa Bryla
 */
class Przeszkoda_Pret: public Bryla
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
    return "Przeszkoda - Pret";
}

};

#endif
