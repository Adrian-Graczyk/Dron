#ifndef SWEKTOR_HH
#define SWEKTOR_HH

/**
 * @file SWektor.hh
 * @brief Szablon Wektora
 * 
 */
#include <iostream>
#include <cmath>


/**
 * @brief  klasa wektor
 * 
 */
template <typename STyp, int SWymiar>
class SWektor {

   
    /**
     * @brief  Przechowuje informacje o ilości aktualnie istniejących obiektów klasy Wektor3D.
     * 
     */
    static int WektoryAktualne;

    /**
     * @brief Przechowuje informacje o ilości ogólnie stworzonych obiektów klasy Wektor3D.
     * 
     */
    static int WektoryOgolne;

    /**
     * @brief tablica zmiennych
     * 
     */
    STyp tab[SWymiar];
  
  
  public:

    /**
     * @brief Metoda wyświetlająca aktualną zawartość zmiennych statycznych wraz z odpowiednim opisem.
     * 
     */
    static void PokazWektory()
    {
        std::cout <<std::endl<< "Laczna ilosc stworzonych obiektow klasy Wektor"<<SWymiar<<"D: " << WektoryOgolne << std::endl;
        std::cout << "Ilosc istniejacych obiektow klasy Wektor"<<SWymiar<<"D: " << WektoryAktualne << std::endl << std::endl;
    }

     /**
      * @brief Konstruktor obiektu SWektor
      * 
      */
    SWektor();

    /**
     * @brief Destruktor obiektu SWektor
     * 
     */
    ~SWektor();

    /**
     * @brief konstruktor dla push_back().
     * 
     * @param W 
     */
    SWektor(const SWektor<STyp, SWymiar> &W);

    /**
     * @brief przeciazenie operatora indeksujacego
     * 
     * @param Ind 
     * @return STyp 
     */
  STyp  operator [] (unsigned int Ind) const { return tab[Ind]; } 
  STyp &operator [] (unsigned int Ind)       { return tab[Ind]; }
  
  /**
   * @brief metoda licząca długośc wektora bledu
   * 
   * @return STyp 
   */
  STyp dlugosc() const; 

  
  /**
   * @brief Przeciążenia operatora Dodawania
   * 
   * @param W2 
   * @return SWektor<STyp,SWymiar> 
   */
  SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &W2) const ; 

  /**
   * @brief Odejmowanie
   * 
   * @param W2 
   * @return SWektor<STyp,SWymiar> 
   */
  SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &W2) const; 

  /**
   * @brief mnozenie przez liczbe
   * 
   * @param liczba 
   * @return SWektor<STyp,SWymiar> 
   */
  SWektor<STyp,SWymiar> operator * (const STyp &liczba) const; 

  /**
   * @brief dzielenie przez liczbe
   * 
   * @param liczba 
   * @return SWektor<STyp,SWymiar> 
   */
  SWektor<STyp,SWymiar> operator / (const STyp &liczba) const; 

  /**
   * @brief Mnozenie skalarne wektorów
   * 
   * @param W2 
   * @return STyp 
   */
  STyp operator * (const SWektor<STyp,SWymiar> &W2) const; 

  /**
   * @brief porowanie wektorów
   * 
   * @param W2 
   * @return true 
   * @return false 
   */
  bool operator == (const SWektor<STyp,SWymiar> &W2) const; 
  
};




/**
 * @brief Inicjalizacja zmiennej statycznej.
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 */
template <typename STyp, int SWymiar>
int SWektor<STyp, SWymiar>::WektoryAktualne;

/**
 * @brief Inicjalizacja zmiennej statycznej.
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 */
template <typename STyp, int SWymiar>
int SWektor<STyp, SWymiar>::WektoryOgolne;

/**
 * @brief Inicjaluje wszystkie współrzędne wektora wartością 0, a nastepnie zwiększa zmienne statyczne.
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 */
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar>::SWektor()
{
    for (STyp &Wsp: tab) 
    Wsp = 0;
    ++WektoryAktualne;
    ++WektoryOgolne;
}

/**
 * @brief Konstruktor dla push_back()
 * 
 * Od domyślnego konstruktora kopiującego ten różni się tylko tym, że dodatkowo
 * dokumentuje stworzenie obiektu  Wektor3D. Konstruktor ten jest wywoływany
 * w metodach push.back().
 * @tparam STyp 
 * @tparam SWymiar 
 * @param W 
 */
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar>::SWektor(const SWektor<STyp, SWymiar> &W)
{
    for(int i = 0; i<SWymiar; ++i) 
    tab[i] = W[i];

    ++WektoryAktualne;
    ++WektoryOgolne;
}

/**
 * @brief Desktuktor obiektu SWektor
 * 
 * Destruktor ten pomniejsza licznik wektorów aktualnie istniejących przy niszczeniu
 * obiektów klasy Wektor3D.
 * @tparam STyp 
 * @tparam SWymiar 
 */
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar>::~SWektor()
{
    --WektoryAktualne;
}






/**
 * @brief Wczytywanie Wektora
 * Przeciążenie operatora wczytywania Wektora
 * Zwraca wczytany wektor
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @param wej 
 * @param Wek 
 * @return std::istream& 
 */
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &wej, SWektor<STyp,SWymiar> &Wek)
{
    for(int i=0; i<SWymiar; i++) //Pętla do wczytywania wartości wektora o danym rozmiarze
    {
        wej >> Wek[i];
        if(wej.fail())
        return wej;
    }
    return wej; 
}


/**
 * @brief Przeciążenie operatora wypisywania wektora
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @param wyj 
 * @param Wek 
 * @return std::ostream& 
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &wyj, const SWektor<STyp,SWymiar> &Wek)
{
    for(int i=0; i<SWymiar; i++) //Petla wyswietlajaca wartości wektora o danym rozmiarze
    {
        wyj << Wek[i] <<' ';
    }
    return wyj;
}


/**
 * @brief Przeciążenie operatora dodawwania wektorów
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @param W2 
 * @return SWektor<STyp,SWymiar> 
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &W2) const
{
    SWektor<STyp,SWymiar> wynik, W1;
    W1 = *this;

    for(int i=0; i<SWymiar; i++)
    wynik[i] = W1[i] + W2[i];
    return wynik;
}

/**
 * @brief Przeciążenie operatora odejmowania wektorów
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @param W2 
 * @return SWektor<STyp,SWymiar> 
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &W2) const
{
    SWektor<STyp,SWymiar> wynik, W1;
    W1 = *this;

    for(int i=0; i<SWymiar; i++)
    wynik[i] = W1[i] - W2[i];
    return wynik;
}

/**
 * @brief Przeciążenie operatora mnożenia wektora i liczby
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @param liczba 
 * @return SWektor<STyp,SWymiar> 
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (const STyp &liczba) const
{
    SWektor<STyp,SWymiar> wynik, W;
    W = *this;
    for(int i=0; i<SWymiar; i++)
    wynik[i] = W[i] * liczba;
    return wynik;
}

/**
 * @brief Przeciążenie operatora dzeielnia wektora przez liczbe
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @param liczba 
 * @return SWektor<STyp,SWymiar> 
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (const STyp &liczba) const
{
    SWektor<STyp,SWymiar> wynik;
    SWektor<STyp,SWymiar> W = *this;
     
    for(int i=0; i<SWymiar; i++)
    wynik[i] = W[i] / liczba;
    return wynik;
}

/**
 * @brief Przeciążenie operatora mnożenia skalarnego wektorów
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @param W2 
 * @return STyp 
 */
template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &W2) const
{
    STyp wynik=0;
    SWektor<STyp,SWymiar> W1 = *this;

    for(int i=0; i<SWymiar; i++)
    wynik = wynik + W1[i] * W2[i];
    return wynik;
}


/**
 * @brief Przeciążenie operatora porównywania wektorów
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @param W2 
 * @return true 
 * @return false 
 */
template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator == (const SWektor<STyp,SWymiar> &W2) const
{
    SWektor<STyp,SWymiar> W1;
    W1 = *this;
    int licznik=0;
    for(int i=0; i<SWymiar; i++)
    {
        if(W1[i]==W2[i])
        licznik++;
    }
    if (licznik==SWymiar)
    return true;
    else
    return false;
}

/**
 * @brief metoda licząca długośc wektora bledu
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 * @return STyp 
 */
template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::dlugosc() const
{
    STyp dlugosc;
    dlugosc = sqrt((*this)*(*this));
    return dlugosc;
}



#endif
