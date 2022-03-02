/**
 * @file Bryla.cpp
 * 
 * @brief plik z metodami klasy Bryla
 * 
 * 
 */

#include <fstream>
#include <iostream>
#include <string.h>
#include "Bryla.hh"



/**
 * @brief Pobiera wierzchołki z pliku
 * 
 * @param NazwaPliku 
 */
void Bryla::PobierzKsztalt(const char* NazwaPliku)
{
    Wektor3D  pom;
    std::ifstream plik(NazwaPliku);
    Wek_Trans[0]=0;
    Wek_Trans[1]=0;
    Wek_Trans[2]=0;


    if(plik.is_open())
    {
        while (!plik.eof( )) 
        {   
            plik>>pom;
            SzeregPunktow_Lok.push_back(pom); 
            SzeregPunktow_Glb.push_back(pom);
        }

    plik.close();
    }
    else
	std::cout<<"BŁAD: Nie udało się otworzyć pliku"<<std::endl;
   
}



/**
 * @brief Zapisuje wierzchołki do strumienia wyjściowego
 * 
 * @param StrmWy 
 * @return true 
 * @return false 
 */
bool Bryla::ZapiszDoStrumienia(std::ostream& StrmWy) 
{
    Wektor3D  pom;
    int i=0;

    for (Wektor3D&  W_Glb : SzeregPunktow_Glb)
    {
        pom = W_Glb;
        StrmWy << pom << std::endl;
      
    }
    return !StrmWy.fail();
}



/**
 * @brief Ustawia strumień wyjściowy do pliku
 * 
 * @param sNazwaPliku 
 * @return true 
 * @return false 
 */
bool Bryla::ZapiszDoPliku(const char* sNazwaPliku)
{
    std::ofstream   StrmWy(sNazwaPliku);

    if (!StrmWy.is_open())
    {
        std::cerr << std::endl
             << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
             << "' nie powiodlo sie." << std::endl
             << std::endl;
        return false;
    }
    return ZapiszDoStrumienia(StrmWy);
}




/**
 * @brief metoda obracania bryly wokol osi Z
 * 
 * @param alfa 
 */
void Bryla::Obroc(double alfa)
{
    MacierzRot3D M_Rot;
    Wektor3D  pom;
    int i=0;
    kat=kat+alfa;
    if(kat>360)
    kat=kat-360;


    std::vector<Wektor3D> Wierzcholki;
    Wierzcholki= Zwroc_Wierzcholki();



    for (const Wektor3D&  W_lok : Wierzcholki)
    {
        M_Rot = M_Rot.Z(kat);
        
        pom = W_lok;
        pom = (M_Rot * pom);
        pom= pom+Wek_Trans;
       

        
        Wierzcholki[i]=pom;
        i++;
    }
    Pobierz_Wierzcholki(Wierzcholki);



}






/**
 * @brief motoda przesuniecia bryly od zadany wektor
 * 
 * @param przesun 
 */
void Bryla::PoruszOWektor(Wektor3D przesun)
{
    std::vector<Wektor3D> Wierzcholki;
    Wektor3D  pom;
    int i=0;

    
    Wek_Trans=Wek_Trans+przesun;
    Wierzcholki=Zwroc_Wierzcholki_Glb();



    for (const Wektor3D&  W_Glb : Wierzcholki)
    {
        pom = W_Glb;
        pom= pom+przesun;        
        Wierzcholki[i]=pom;
        i++;
    }
    Pobierz_Wierzcholki(Wierzcholki);

}


/**
 * @brief metoda wykrywajaca skrajne punkty Bryly
 * 
 */
void Bryla::Skrajne_Wierzcholki()
{
    std::vector<Wektor3D> Wierzcholki;
    Wierzcholki=Zwroc_Wierzcholki_Glb();

        x_min = 100;
        x_max = -100;
        y_min = 100;
        y_max = -100;
        z_min = 100;
        z_max = -100;

    for (const Wektor3D&  W_Glb : Wierzcholki)
    {   

        if(W_Glb[0] < x_min)
        x_min = W_Glb[0];

        if(W_Glb[0] > x_max)
        x_max = W_Glb[0];

        if(W_Glb[1] < y_min)
        y_min = W_Glb[1];

        if(W_Glb[1] > y_max)
        y_max = W_Glb[1];

        if(W_Glb[2] < z_min)
        z_min = W_Glb[2];

        if(W_Glb[2] > z_max)
        z_max = W_Glb[2];

    }
    
}

/**
 * @brief metoda powiekszania i zmniejszania bryl
 * 
 * @param skala 
 */
void Bryla::Skaluj(double skala)
{
    std::vector<Wektor3D> Wierzcholki;
    Wektor3D  pom;
    int i=0;

    
    Wierzcholki=Zwroc_Wierzcholki_Glb();



    for (const Wektor3D&  W_Glb : Wierzcholki)
    {
        pom = W_Glb;
        pom= pom * skala;        
        Wierzcholki[i]=pom;
        i++;
    }
    Pobierz_Wierzcholki(Wierzcholki);

}