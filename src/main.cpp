/**
 * @file main.cpp
 * @author Adrian Graczyk
 * @brief Program imitujący poruszanie sie Drona w 3D
 * 
 * Program za pomoca programu gnoplot wyswietla
 * Drona oraz dno i fale w trojwymiarze
 * Daje uzytkownikowi mozliwosc obrotu drona wokol osi Z
 * oraz poruszania nim do przodu z zadanym katem opadania/wznoszenia
 */
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"
#include "Bryla.hh"
#include "Scena.hh"
#include "Dron.hh"
#include <unistd.h>
using namespace std;

/**
 * @brief Funkcja main programu
 * 
 * @return int 
 */
int main()
{
  {
    /**
    * @brief Stworzenie obiektu Scena
    * 
    */
    Scena Woda;

    /**
    * @brief Inicjalizacja i rozpoczecie działania Sceny 
    * 
    */
    Woda.Start();
  }
  /**
   * @brief wyswietlenie wektorów po zakonczeniu działania programu
   * 
   */
  Wektor3D::PokazWektory();

}
