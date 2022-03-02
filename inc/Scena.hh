#ifndef SCENA_HH
#define SCENA_HH


/**
 * @file Scena.hh
 * @brief Definicja klasy Scena
 * 
 * 
 */
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Woda.hh"
#include "Przeszkoda_prostopadloscian.hh"
#include "Przeszkoda_Plaszczyzna.hh"
#include "Przeszkoda_Pret.hh"
#include "Dno.hh"


#include <iostream>


/**
 * @brief klasa Scena
 * 
 * słuzy jako zbiór wszystkich obiektów 
 * oraz do komunikacji z uzytkownikiem 
 */
class Scena
{
 /**
  * @brief obiekt Drona
  * 
  */
Dron Robot;
/**
 * @brief Obiekt Wody
 * 
 */
Woda Fale;

/**
 * @brief obiekt Dna
 * 
 */
Dno Powierzchnia;

/**
 * @brief Lista z przeszkodami
 * 
 */
std::list<Bryla*> Lista_Przeszkod;



protected:




public:

/**
 * @brief lacze do gnuplota
 * 
 */

PzG::LaczeDoGNUPlota Lacze;

/**
 * @brief metoda inciująca poczatek sceny
 * 
 */

void Start();

/**
 * @brief metoda wyswietlania menu
 * 
 */

void Wyswietl_Menu();

/**
 * @brief metoda obslugi menu
 * 
 */
void Menu();

/**
 * @brief Metoda dodawnia drona
 * 
 */

void Dodaj_Drona();

/**
 * @brief metoda dodawania Dna
 * 
 */
void Dodaj_Dno();

/**
 * @brief Metoda dodawania Wody
 * 
 */
void Dodaj_Wode();


/**
 * @brief Metoda dodawania przeszkody
 * 
 */
void Dodaj_Przeszkode(int numer_przeszkody);

};

#endif
