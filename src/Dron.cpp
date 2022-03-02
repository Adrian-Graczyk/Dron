/**
 * @file Dron.cpp
 * @brief Plik z metodami klasy Dron
 * 
 * 
 */


#include <fstream>
#include <iostream>
#include "Dron.hh"







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
void Dron::Plyn(double odleglosc, double opad, std::list<Bryla*> &Lista)
{
    double alfa, beta;
    Wektor3D wersor;
    alfa = (kat*M_PI)/180;
    beta = (opad*M_PI)/180;
    wersor[0]=cos(alfa);
    wersor[1]=sin(alfa);
    wersor[2]=1;
    
    wersor[0]*=cos(beta) ;
    wersor[1]*=cos(beta);
    wersor[2]*=sin(beta);


    
    for (int i = 0; i < odleglosc; ++i)
    {
       if(kolizja==1)
        return;
       
        if(Wek_Tran[2]<-75)
        {
            if(opad<0)
            {
                std::cout<<std::endl<<"Dron uderzył w dno "<<std::endl;
                kolizja = 1;
                return;

            }
            
        }

        if(Wek_Tran[2]>5)
        {
            if(opad>0)
            {
                std::cout<<"Dron wypłynął na powierzchnie "<<std::endl;
                return;
            }
            
        }
        
        PoruszOWektor(wersor, Lista);
        usleep(40000);

    }
    
}

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
void Dron::Plyn_Mod(double odleglosc, double opad, std::list<Bryla*> &Lista)
{
    double pion , poziom;
    double alfa, beta;
    Wektor3D wersor;
    alfa = (kat*M_PI)/180;
    beta = (opad*M_PI)/180;
    
    pion = odleglosc * sin(beta);
    poziom = odleglosc * cos(beta);

    
    if(opad > 0)
    Plyn(pion,90, Lista);

    if(opad < 0)
    {
        Plyn(fabs(pion),-90, Lista);
        return;
    }
    


    Plyn(poziom, 0, Lista);


    
}

/**
 * @brief metoda animacji obrotu wokoł osi Z
 * 
 * @param alfa 
 * @param Lista
 */

void Dron::Obroc_Animacja(double alfa, std::list<Bryla*> &Lista)
{   
    if(alfa>0)
    {
        for (int i = 0; i < fabs(alfa); ++i)
        {
            if(kolizja==1)
            return;
      
            Obroc(1, Lista);
            usleep(40000); 
        
        }
    }

    if(alfa<0)
    {
        for (int i = 0; i < fabs(alfa); ++i)
        {
            if(kolizja==1)
            return;
      
            Obroc(-1, Lista);
            usleep(40000); 
        
        }
    }

    return;
}

/**
 * @brief obraca dron o podany kąt
 * 
 * @param alfa 
 * @param Lista
 */
void Dron::Obroc(double alfa, std::list<Bryla*> &Lista)
{
    MacierzRot3D M_Rot;
    Wektor3D  pom;
    int i=0;
    kat=kat+alfa;
    if(kat>360)
    kat=kat-360;


    Wek_Tran = Korpus.Zwroc_Wektor();

    std::vector<Wektor3D> Wierzcholki;
    Wierzcholki= Korpus.Zwroc_Wierzcholki();

  



    for (const Wektor3D&  W_lok : Wierzcholki)
    {
        M_Rot = M_Rot.Z(kat);
        
        pom = W_lok;
        pom = (M_Rot * pom);
        pom= pom+Wek_Tran;
       
        Wierzcholki[i]=pom;
        i++;
    }

    
    Wirnik1.Obrot(alfa, 1);
    Wirnik2.Obrot(alfa, 2);

    Korpus.Pobierz_Wierzcholki(Wierzcholki);
    Korpus.ZapiszDoPliku(Nazwa());
    Wirnik1.ZapiszDoPliku("bryly/Wirnik1.dat");
    Wirnik2.ZapiszDoPliku("bryly/Wirnik2.dat");
    Lacze->Rysuj(); 
    Kolizja(Lista);
}


/**
 * @brief Przemieszcza Drona o dany wektor
 * 
 * @param przesun 
 * @param Lista 
 */
void Dron::PoruszOWektor(Wektor3D przesun, std::list<Bryla*> &Lista)
{
    std::vector<Wektor3D> Wierzcholki;
    Wektor3D  pom;
    int i=0;


    Wek_Tran=Wek_Tran+przesun;
    Wierzcholki= Korpus.Zwroc_Wierzcholki_Glb();


    


    for (const Wektor3D&  W_Glb : Wierzcholki)
    {
        pom = W_Glb;
        pom= pom+przesun;        
        Wierzcholki[i]=pom;
        i++;
    }
    Korpus.Pobierz_Wierzcholki(Wierzcholki);

    Korpus.Pobierz_Wektor(Wek_Tran);

    Wirnik1.Obrot(0, 1);
    Wirnik2.Obrot(0, 2);
    Wirnik1.PoruszOWektor(przesun);
    Wirnik2.PoruszOWektor(przesun);
    Korpus.ZapiszDoPliku(Nazwa());
    Wirnik1.ZapiszDoPliku("bryly/Wirnik1.dat");
    Wirnik2.ZapiszDoPliku("bryly/Wirnik2.dat");
    Lacze->Rysuj(); 
    Kolizja(Lista);
}


/**
 * @brief Wykrywanie kolizji z obiektem na scenie
 * 
 * @param Przeszkoda 
 * @return true 
 * @return false 
 */
bool Dron::Kolizja_prostopadloscian(Bryla &Przeszkoda)
{   
    Korpus.Skrajne_Wierzcholki();
    Przeszkoda.Skrajne_Wierzcholki();

    return ((Korpus.x_min < Przeszkoda.x_max && Korpus.x_max > Przeszkoda.x_min) && 
            (Korpus.y_min < Przeszkoda.y_max && Korpus.y_max > Przeszkoda.y_min) && 
            (Korpus.z_min < Przeszkoda.z_max && Korpus.z_max > Przeszkoda.z_min));
    
}

/**
 * @brief Sprawdzenie kolizji z lista przeszkod
 * 
 * @param Lista 
 */
void Dron::Kolizja(std::list<Bryla*> &Lista)
{
    for(Bryla *Przeszkoda : Lista)
    {
        if(Kolizja_prostopadloscian(*Przeszkoda))
        {
            std::cout<<std::endl<<"KOLIZJA: drona z "<<Przeszkoda->Zwroc_Typ()<<std::endl;
            kolizja=1;
            return;
        }
        

    }
    
}