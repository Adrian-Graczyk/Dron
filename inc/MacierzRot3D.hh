#ifndef MACIERZROT3D_HH
#define MACIERZROT3D_HH
/**
 * @file MacierzRot3D.hh
 * @brief Klasa Macierzy rotacji 
 */
#include "SMacierz.hh"
#include "Wektor3D.hh"

/**
 * @brief Stworzenie typu Macierz 3D
 * 
 */
typedef SMacierz<double ,3> Macierz3D;

/**
 * @brief Klasa Macierzy Rotacji 
 * 
 * Dziedziczy publicznie klasa Macierz3D
 */
class MacierzRot3D: public Macierz3D
{

public:
/**
 * @brief Metoda tworząca macierz obortu wokoł osi Z
 * 
 * W pliku .hh aby nie tworzyć pliku cpp dla jednej metody
 * @param x kat obrotu
 * @return MacierzRot3D 
 */
MacierzRot3D Z(double x)
{
    MacierzRot3D M;
    double alfa;
    alfa = (x*M_PI)/180;
    
        M[0][0]= cos(alfa);
        M[0][1]= -sin(alfa);
        M[0][2]= 0;
        M[1][0]= sin(alfa);
        M[1][1]= cos(alfa);
        M[1][2]= 0;
        M[2][0]= 0;
        M[2][1]= 0;
        M[2][2]= 1;
    return M;
}



public:
/**
 * @brief Metoda tworząca macierz obortu wokoł osi Z
 * 
 * W pliku .hh aby nie tworzyć pliku cpp dla jednej metody
 * @param x kat obrotu
 * @return MacierzRot3D 
 */
MacierzRot3D X(double x)
{
    MacierzRot3D M;
    double alfa;
    alfa = (x*M_PI)/180;
    
        M[0][0]= 1;
        M[0][1]= 0;
        M[0][2]= 0;
        M[1][0]= 0;
        M[1][1]= cos(alfa);
        M[1][2]= -sin(alfa);
        M[2][0]= 0;
        M[2][1]= sin(alfa);
        M[2][2]= cos(alfa);
    return M;
}

};






#endif
