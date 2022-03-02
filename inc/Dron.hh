#ifndef DRON_HH
#define DRON_HH
/**
 * @file Dron.hh
 * @brief Definicja klasy Dron 
 * 
 * 
 * 
 */

#include "Prostopadloscian.hh"
#include "Wirnik.hh"
#include <iostream>
#include <unistd.h>
#include <cmath>


/**
 * @brief klasa Dron
 * 
 */
class Dron
{


/**
 * @brief Wektor położenia drona w układzie globalnym
 * 
 */
Wektor3D Wek_Tran;

/**
 * @brief Zmienna z nazwą pliku 
 * 
 * Plik do zaspisywania wierzchołków globalnych 
 */

const char* Nazwa_Zapisu = "bryly/Dron.dat";

/**
 * @brief aktulany kąt obrotu drona w płaszczyźnie Z
 * 
 */

double kat=0;

/**
 * @brief Promien kuli opisanej na Dronie
 * 
 * Do wykrywania kolizji
 */
double promien_drona = 0;

int kolizja = 0;

protected:



public:

/**
 * @brief Korpus drona klasy prostopadłosćian
 * 
 * publiczne bo za dużo metod byłoby
 * potrzebnych do zmian w scenie 
 */
Prostopadloscian Korpus;

/**
 * @brief wirnik drona klasy wirnik
 * 
 * publiczne bo za dużo metod byłoby
 * potrzebnych do zmian w scenie 
 */
Wirnik Wirnik1;

/**
 * @brief wirnik drona klasy wirnik
 * 
 * publiczne bo za dużo metod byłoby
 * potrzebnych do zmian w scenie 
 */
Wirnik Wirnik2;



/**
 * @brief łącze do gnuplota
 * 
 */
PzG::LaczeDoGNUPlota* Lacze;


/**
 * @brief metoda animacji ruchu 
 *
 * Ruch do "przodu" oraz 
 * opadania/Wznoszenia
 * 
 * @param odleglosc 
 * @param opad 
 * @param Lista
 */

void Plyn(double odleglosc, double opad, std::list<Bryla*> &Lista);

/**
 * @brief metoda animacji ruchu z modyfikacji 
 *
 * Ruch do "przodu" oraz 
 * opadania/Wznoszenia
 * 
 * @param odleglosc 
 * @param opad 
 * @param Lista
 */

void Plyn_Mod(double odleglosc, double opad, std::list<Bryla*> &Lista);

/**
 * @brief Wykrywanie kolizji z obiektem na scenie
 * 
 * @param Przeszkoda 
 * @return true 
 * @return false 
 */
bool Kolizja_prostopadloscian(Bryla &Przeszkoda);

/**
 * @brief Sprawdzenie kolizji z lista przeszkod
 * 
 * @param Lista 
 */
void Kolizja(std::list<Bryla*> &Lista);

/**
 * @brief metoda animacji obrotu wokoł osi Z
 * 
 * @param alfa 
 * @param Lista
 */

void Obroc_Animacja(double alfa, std::list<Bryla*> &Lista);

/**
 * @brief obraca dron o podany kąt
 * 
 * @param alfa 
 * @param Lista
 */

void Obroc(double alfa, std::list<Bryla*> &Lista);

/**
 * @brief Przemieszcza Drona o dany wektor
 * 
 * @param przesun 
 * @param Lista
 */

void PoruszOWektor(Wektor3D przesun, std::list<Bryla*> &Lista);

/**
 * @brief Zamienia wektor połozenia w ukladzie globalnym
 * 
 * @param Trans 
 */

void Pobierz_Wektor(Wektor3D Trans)
{
 Wek_Tran = Trans;
}

/**
 * @brief Zwraca ścieżke zapisu do pliku 
 * 
 * @return const char* 
 */
const char* Nazwa()
{
    return Nazwa_Zapisu;
} 

/**
 * @brief Zwraca informacje o kolizji 
 * 
 * @return int 
 */
int Zwroc_Kolizja()
{
    return kolizja;
} 

};

#endif
