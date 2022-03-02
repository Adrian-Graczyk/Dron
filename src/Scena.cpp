/**
 * @file Scena.cpp
 * @brief plik z metodami klasy Scena
 * 
 */
#include <fstream>
#include <iostream>
#include <string>
#include "Scena.hh"

/**
 * @brief metoda inciująca poczatek sceny
 * 
 */
void Scena::Start()
{
 
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-100, 100);
  Lacze.UstawZakresY(-100, 100);
  Lacze.UstawZakresZ(-101, 31);
  Lacze.UstawRotacjeXZ(77,27); // Tutaj ustawiany jest widok 

  Dodaj_Drona();
  Dodaj_Dno();
  Dodaj_Wode();
  Lacze.Rysuj(); 

  Menu();


 for(Bryla *Przeszkoda : Lista_Przeszkod)
 delete Przeszkoda;
}


/**
 * @brief Metoda dodawnia drona
 * 
 */
void Scena::Dodaj_Drona()
{
    Wektor3D Start, wirnik1, wirnik2;
    Start[0]=0;
    Start[1]=0;
    Start[2]=-50;

    wirnik1[0]=0;
    wirnik1[1]=2.5;
    wirnik1[2]=0;
    
   
    wirnik2[0]=0;
    wirnik2[1]=-2.5;
    wirnik2[2]=0;


    

    Robot.Lacze = &Lacze; 
    Robot.Korpus.PobierzKsztalt(Robot.Korpus.Zwroc_Nazwa());
    Robot.Wirnik1.PobierzKsztalt("bryly/Wirnik-wzor.dat");
    Robot.Wirnik1.Pobierz_Przesuniecie(wirnik1);
    Robot.Wirnik2.PobierzKsztalt("bryly/Wirnik-wzor.dat");
    Robot.Wirnik2.Pobierz_Przesuniecie(wirnik2);
    Lacze.DodajNazwePliku(Robot.Nazwa());
    Lacze.DodajNazwePliku("bryly/Wirnik1.dat");
    Lacze.DodajNazwePliku("bryly/Wirnik2.dat");
    Robot.Wirnik1.Obrot(0,1);
    Robot.Wirnik2.Obrot(0,2);
    Robot.Wirnik1.ZapiszDoPliku("bryly/Wirnik1.dat");
    Robot.Wirnik2.ZapiszDoPliku("bryly/Wirnik2.dat");
    Robot.PoruszOWektor(Start, Lista_Przeszkod);
    
    
    
    
}

/**
 * @brief metoda dodawania Dna
 * 
 */
void Scena::Dodaj_Dno()
{
    Powierzchnia.PobierzKsztalt(Powierzchnia.Zwroc_Nazwa());
    Lacze.DodajNazwePliku(Powierzchnia.Zwroc_Nazwa());
}

/**
 * @brief Metoda dodawania Wody
 * 
 */
void Scena::Dodaj_Wode()
{
    Fale.PobierzKsztalt(Fale.Zwroc_Nazwa());
    Lacze.DodajNazwePliku(Fale.Zwroc_Nazwa());
}





/**
 * @brief metoda wyswietlania menu
 * 
 */
void Scena::Wyswietl_Menu()
{
    std::cout << "r -> ruch drona" << std::endl;
    std::cout << "o -> Obrot" << std::endl;
    std::cout << "d -> dodawanie Przeszkody" << std::endl;
    std::cout << "m -> wyswietl menu" << std::endl;
    std::cout << "s -> wyswietl ilość obiektów Wektor3D" << std::endl;
    std::cout << "w -> ruch drona z modyfikacji" << std::endl;
    std::cout << "q -> Zakonczenie dzialania programu" << std::endl;
}

/**
 * @brief metoda obslugi menu
 * 
 */
void Scena::Menu()
{
    char znak;
    int numer_przeszkody=0;
    Wyswietl_Menu();
    do
    {
        std::cin>>znak;

        switch(znak)
        {
        case 'r':
            double tmp, tmp2;
            std::cout << "Podaj odleglosc (ilosc jednostek) na jaka ma sie przemiescic robot: \n";
            std::cin >> tmp;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> tmp;
            } 
            std::cout << "Podaj kąt wznoszenia / opadania: \n";
            std::cin >> tmp2;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> tmp2;
            } 
            Robot.Plyn(tmp, tmp2, Lista_Przeszkod);
            if(Robot.Zwroc_Kolizja() == 1)
            return;
            
            break;

        case 'w':
            double tmp3, tmp4;
            std::cout << "Podaj odleglosc (ilosc jednostek) na jaka ma sie przemiescic robot: \n";
            std::cin >> tmp3;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> tmp3;
            } 
            std::cout << "Podaj kąt wznoszenia / opadania: \n";
            std::cin >> tmp4;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> tmp4;
            } 
            Robot.Plyn_Mod(tmp3, tmp4, Lista_Przeszkod);
            if(Robot.Zwroc_Kolizja() == 1)
            return;
            break;

        case 'd':
            Dodaj_Przeszkode(numer_przeszkody);
            numer_przeszkody++;
            break;

        case 'm':
            Wyswietl_Menu();
            break;

        case 's':
            Wektor3D::PokazWektory();
            break;

        case 'o':
            double kat;
            std::cout << "Podaj kat o jaki ma sie obrocic robot: \n";
            std::cin >> kat;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> kat;
            } 
            Robot.Obroc_Animacja(kat, Lista_Przeszkod);
            if(Robot.Zwroc_Kolizja() == 1)
            return;
            break;

        case 'q':
                std::cout << "Koniec dzialania programu \n";
               
                
                return;

        default:
            {
                std::cout << "Proszę wybrać odpowiednia opcje. \n";
            }
            break;
        }
    }while(znak != 'q');
    

}


/**
 * @brief Metoda dodająca przeszkody do Sceny
 * 
 * @param numer_przeszkody 
 */
void Scena::Dodaj_Przeszkode(int numer_przeszkody)
{
    char znak2;
    std::cout << "w -> Prostopadlscian" << std::endl;
    std::cout << "e -> Plaszczyzna" << std::endl;
    std::cout << "r -> Pret pionowy" << std::endl;
    std::cout << "t -> Pret poziomy" << std::endl;
    
    std::cin>>znak2;

        switch(znak2)
        {
        case 'w':
        {
            Wektor3D pomoc;
            double skala;
            Bryla *Nowe = new Przeszkoda_Prostopadloscian;
           

            std::stringstream ss;
            ss <<"bryly/Przeszkoda"<<numer_przeszkody<<".dat";
            std::string str(ss.str());
            const char* plik =str.c_str(); 
            Nowe ->PobierzKsztalt("bryly/Przeszkoda-prostopadloscian.dat");

            std::cout << "podaj wektor polozenia: " << std::endl;
            std::cin >> pomoc;
             while(std::cin.fail())
            {
                std::cout << "Podaj poprawnie Wektor"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> pomoc;
            } 

            std::cout << "podaj skale przeszkody " << std::endl;
            std::cin >> skala;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> skala;
            } 

            Nowe->Skaluj(skala);
            Nowe->PoruszOWektor(pomoc);
            Lista_Przeszkod.push_back(Nowe);
            Nowe->ZapiszDoPliku(plik);
            Lacze.DodajNazwePliku(plik);
            Lacze.Rysuj();
            
        }
            break;

        case 'e':
        {   
            double skala;
            Wektor3D pomoc;
            Bryla *Nowe = new Przeszkoda_Plaszczyzna;
           

            std::stringstream ss;
            ss <<"bryly/Przeszkoda"<<numer_przeszkody<<".dat";
            std::string str(ss.str());
            const char* plik =str.c_str(); 
            Nowe ->PobierzKsztalt("bryly/Przeszkoda-plaszczyzna.dat");

            std::cout << "podaj wektor polozenia: " << std::endl;
            std::cin >> pomoc;
            while(std::cin.fail())
            {
                std::cout << "Podaj Poprawnie Wektor"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> pomoc;
            } 
            
            std::cout << "podaj skale przeszkody " << std::endl;
            std::cin >> skala;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> skala;
            } 

            Nowe->Skaluj(skala);
            Nowe->PoruszOWektor(pomoc);
            Lista_Przeszkod.push_back(Nowe);
            Nowe->ZapiszDoPliku(plik);
            Lacze.DodajNazwePliku(plik);
            Lacze.Rysuj();
        }
            
            break;

        case 'r':
        {
            Wektor3D pomoc;
            double skala;
            Bryla *Nowe = new Przeszkoda_Pret;
           
            std::stringstream ss;
            ss <<"bryly/Przeszkoda"<<numer_przeszkody<<".dat";
            std::string str(ss.str());
            const char* plik =str.c_str(); 
            Nowe ->PobierzKsztalt("bryly/Przeszkoda-pret-pion.dat");

            std::cout << "podaj wektor polozenia: " << std::endl;
            std::cin >> pomoc;
            while(std::cin.fail())
            {
                std::cout << "Podaj Poprawnie Wektor"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> pomoc;
            } 

            std::cout << "podaj skale przeszkody " << std::endl;
            std::cin >> skala;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> skala;
            } 

            Nowe->Skaluj(skala);
            Nowe->PoruszOWektor(pomoc);
            Lista_Przeszkod.push_back(Nowe);
            Nowe->ZapiszDoPliku(plik);
            Lacze.DodajNazwePliku(plik);
            Lacze.Rysuj();
        }   
            break;

        case 't':
        {   
            double skala;
            Wektor3D pomoc;
            Bryla *Nowe = new Przeszkoda_Pret;
           

            std::stringstream ss;
            ss <<"bryly/Przeszkoda"<<numer_przeszkody<<".dat";
            std::string str(ss.str());
            const char* plik =str.c_str(); 
            Nowe ->PobierzKsztalt("bryly/Przeszkoda-pret-poziom.dat");

            std::cout << "podaj wektor polozenia: " << std::endl;
            std::cin >> pomoc;
            while(std::cin.fail())
            {
                std::cout << "Podaj Poprawnie Wektor"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> pomoc;
            } 
            
            std::cout << "podaj skale przeszkody " << std::endl;
            std::cin >> skala;
            while(std::cin.fail())
            {
                std::cout << "Podaj liczbe"<<std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                std::cin >> skala;
            } 

            Nowe->Skaluj(skala);
            Nowe->PoruszOWektor(pomoc);
            Lista_Przeszkod.push_back(Nowe);
            Nowe->ZapiszDoPliku(plik);
            Lacze.DodajNazwePliku(plik);
            Lacze.Rysuj();
        }
            
            break;


        default:
            {
                std::cout << "Zle podana opcja \n";
            }
            break;
        }
    

}






