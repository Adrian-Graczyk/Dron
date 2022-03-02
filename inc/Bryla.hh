#ifndef BRYLA_HH
#define BRYLA_HH

/**
 * @file Bryla.hh
 * @brief Klasa Bryły geometrycznej
 * 
 * 
 */

#include "MacierzRot3D.hh"
#include "Wektor3D.hh"
#include "lacze_do_gnuplota.hh"
#include <vector>
#include <fstream>
#include <iostream>

/**
 * @brief Klasa bryły geometrycznej
 * 
 */

class Bryla
{
    /**
     * @brief kontener wierzchołków lokalnych 
     * 
     */
std::vector<Wektor3D> SzeregPunktow_Lok;
/**
 * @brief kontener wierzchołków globalnych
 * 
 */
std::vector<Wektor3D> SzeregPunktow_Glb;

/**
 * @brief aktulany kąt obrotu bryly w płaszczyźnie Z
 * 
 */

double kat=0;



protected:

/**
 * @brief Wektor położenia bryły
 * 
 */

Wektor3D Wek_Trans;



public:

/**
 * @brief zainicjowane z góry wierzchołki aby poprawnie policzyć później
 * 
 */
double x_min=100, x_max=-100, y_min=100, y_max=-100, z_min=100, z_max=-100; 

/**
 * @brief wirtualna metoda zwracajaca rodzaj przeszkody
 * 
 * @return std::string 
 */
virtual std::string Zwroc_Typ()
{
    return "Bryla";
}




/**
 * @brief metoda wykrywania wierzchołków
 * 
 */
void Skrajne_Wierzcholki();

/**
 * @brief obraca bryle o podany kąt
 * 
 * @param alfa 
 */

void Obroc(double alfa);



/**
 * @brief Przemieszcza bryle o dany wektor
 * 
 * @param przesun 
 */

void PoruszOWektor(Wektor3D przesun);


/**
 * @brief metoda powiekszania i zmniejszania bryl
 * 
 * @param skala 
 */
void Skaluj(double skala);


/**
 * @brief zwraca wierzchołki lokalne bryly
 * 
 * @return std::vector<Wektor3D> 
 */

std::vector<Wektor3D> Zwroc_Wierzcholki()
{
    return SzeregPunktow_Lok;
}

/**
 * @brief zwraca wierzchołki globalne bryły
 * 
 * @return std::vector<Wektor3D> 
 */

std::vector<Wektor3D> Zwroc_Wierzcholki_Glb()
{
    return SzeregPunktow_Glb;
}

/**
 * @brief Zamienia wierzchołki globalne bryly 
 * 
 * @param Wierzcholki 
 */
void Pobierz_Wierzcholki(std::vector<Wektor3D> Wierzcholki)
{
 SzeregPunktow_Glb = Wierzcholki;
}


/**
 * @brief Zwraaca wektor położenia
 * 
 * @return Wektor3D 
 */

Wektor3D Zwroc_Wektor()
{
    return Wek_Trans;
}


/**
 * @brief Zmienia wektor położenia bryły
 * 
 * @param Trans 
 */

void Pobierz_Wektor(Wektor3D Trans)
{
 Wek_Trans = Trans;
}


/**
 * @brief Pobiera wierzchołki z pliku
 * 
 * @param NazwaPliku 
 */

void PobierzKsztalt(const char* NazwaPliku);

/**
 * @brief Zapisuje wierzchołki do strumienia wyjściowego
 * 
 * @param StrmWy 
 * @return true 
 * @return false 
 */
 

bool ZapiszDoStrumienia(std::ostream& StrmWy);

/**
 * @brief Ustawia strumień wyjściowy do pliku
 * 
 * @param sNazwaPliku 
 * @return true 
 * @return false 
 */

bool ZapiszDoPliku(const char* sNazwaPliku);
};









#endif
