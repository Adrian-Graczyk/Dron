#ifndef SMACIERZ_HH
#define SMACIERZ_HH
/**
 * @file SMacierz.hh
 *
 * @brief Szablon Macierzy 
 *
 * 
 */
#define ZERO 1e-12
#include "SWektor.hh"
#include <iostream>
#include <iomanip>




/**
 * @brief klasa macierz
 * 
 * @tparam STyp 
 * @tparam SWymiar 
 */
template <typename STyp, int SWymiar>
class SMacierz {
  SWektor<STyp,SWymiar> tab[SWymiar];
  
  public:
  SWektor<STyp,SWymiar>  operator [] (unsigned int Ind) const { return tab[Ind]; } 
  SWektor<STyp,SWymiar> &operator [] (unsigned int Ind)       { return tab[Ind]; }
    

  void pobierz(SWektor<STyp,SWymiar> a, int i) //pobieranie wektora i wpisanie do tablicy macierzy
  {
    tab[i]=a;
  }  

  SWektor<STyp,SWymiar> zwroc(int a) const //Metoda zwracająca dany wiersz macierzy
  {
    return tab[a];
  }

  void transponuj(); //transponowanie macierzy


  //obliczanie wyznacznika metodą Gaussa
  STyp wyznacznik();

  //Przeciązenie operatora mnozenia macierzy i wektora
  SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> &W) const;

  //Przeciązenie operatora mnozenia dwoch macierzy 
  SMacierz<STyp, SWymiar> operator * (const SMacierz<STyp, SWymiar> &M2) const;

};






//Przeciążenie operatora wczytywania macierzy
//Zwraca wczytana macierz
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &wej, SMacierz<STyp, SWymiar> &Mac)
{
    SWektor<STyp,SWymiar> wynik;
    for(int i = 0; i<SWymiar; i++) //Petla wczytujaca wektory do klasy
    {   
        
        wej >> wynik;
        Mac.pobierz(wynik,i); //Wektor przekazywany za pomoca metody
    }
    return wej;
}


//Przeciążenie operatora wyświetlania macierzy
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &wyj, const SMacierz<STyp, SWymiar> &Mac)
{
    for(int i = 0; i<SWymiar; i++) //Petla wyswietlajaca daną ilość wierszy
    {
        wyj << Mac.zwroc(i) << std::endl; //wyswietlanie odpowiedniego wiersza
    }
    return wyj;
}

//Przeciążenie operatora mnożenia macierzy i wektora
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SMacierz<STyp, SWymiar>::operator * (const SWektor<STyp,SWymiar> &W) const
{
    SWektor<STyp,SWymiar> wynik;
    SMacierz<STyp, SWymiar> M=*this;
    for(int i=0; i<SWymiar; i++)
    {
        for(int j=0; j<SWymiar; j++)
        {
            wynik[i] = wynik[i] + M[i][j] * W[j];
        }
    }
    return wynik; //zwraca wektor 
}

//metoda służąca do tranponowania macierzy
template <typename STyp, int SWymiar>
void SMacierz<STyp, SWymiar>::transponuj()
{
    SMacierz<STyp, SWymiar> tmp;
    tmp = *this;
     for(int i=0; i<SWymiar; i++)
    {
        for(int j=0; j<SWymiar; j++)
        {
            tab[i][j] = tmp[j][i];
        }
    }
}

template <typename STyp, int SWymiar>
STyp SMacierz<STyp, SWymiar>::wyznacznik()
{
  
  STyp wyznacznik, mnoznik, tmp; //zmienne pomocnicze
  int znak = 0, zero = 0,  pom=0 ,licznik=0;
  wyznacznik = 1;
  tmp = 0;
  SMacierz<STyp, SWymiar> M = *this;

    //sprawdzenie czy któraś z kolumn jest wyzerowana
    for (int j=0;j<SWymiar;j++)
    {   
        zero = 0;
        for (int i=0;i<SWymiar;i++)  
        {
            if(M[i][j]==0)
                zero++;
        }
        if(zero==SWymiar) // jeśli jest, to wartość wyznacznika jest równa 0
        {
            wyznacznik = 0;
            return wyznacznik;
        }
    }
    //sprawdzenie czy któryś z wierszy nie jest wyzerowany
    for (int i=0;i<SWymiar;i++)
    {   
        zero = 0;
        for (int j=0;j<SWymiar;j++)  
        {
            if(M[i][j]==0)
                zero++;
        }
        if(zero==SWymiar) // jeśli jest, to wartość wyznacznika jest równa 0
        {
        wyznacznik = 0;
        return wyznacznik; 
        }
          
    }
    
   //sprawdzenie czy nie ma równoważnych wierszy
     for (int i=0;i<SWymiar-1;i++)
    {  
        for(int k=i+1;k<SWymiar;k++)
        {
            licznik=0; //wyzerowanie zmiennych przed badaniem kolejnych wierszy
            tmp=0;
            pom=0;
            for (int j=0;j<SWymiar;j++)
            {   
                
                if(M[i][j]==0 || M[k][j]==0)
                {
                    if(M[i][j]==M[k][j])
                    licznik++; 
                }
                else
                {
                    if(pom==0) //ustalenie raz wartości mnożnika wierszy 
                    {
                        tmp=M[i][j]/M[k][j];
                        pom++;
                    }

                    if(tmp==M[i][j]/M[k][j])
                    licznik++;
                }
                
            }
            /* jeśli wiersz macierzy jest równoważny z innym 
            czyli kazdy jego element jest wynikiem mnożenia stałej liczby
            przez odpowiadający elemnt drugiego wiersza */
            if(licznik==SWymiar) 
                { 
                    wyznacznik = 0;
                    return wyznacznik;
                }
        }
        
    }

   

    // obliczanie macierzy trójkątnej 
    for(int i=0; i<SWymiar-1; i++)
    {
        //Piwotyzacja aby na przekątnej znajdowały sie jak najwieksze liczby
        //element podstawowy najwiekszy do zniwelowania błędu
        for (int k=i+1;k<SWymiar;k++)
        {
            if (fabs(M[i][i])<fabs(M[k][i])){
            	znak++;
                
            	for (int j=0;j<SWymiar;j++){
                    STyp temp=M[i][j];
                    M[i][j]=M[k][j];
                    M[k][j]=temp;
                }
			}
        }
        //przekształcanie kolejnych wierszy
        for(int j=i+1; j<SWymiar; j++)
        {   
            mnoznik = (M[j][i] / M[i][i]);
            for(int k=i; k<SWymiar; k++)
            {
                M[j][k]= M[j][k] - (mnoznik * M[i][k]);
                if(fabs(M[j][k]) < ZERO)
                M[j][k]=0;
            } 
        }   
    }




   //sprawdzenie czy któryś z wierszy nie jest wyzerowany
    for (int i=0;i<SWymiar;i++)
    {   
        zero = 0;
        for (int j=0;j<SWymiar;j++)  
        {
            if(M[i][j]==0)
            zero++;
        }
        if(zero==SWymiar) // jeśli jest, to wartość wyznacznika jest równa 0
        {
            wyznacznik = 0;
            return wyznacznik;
        }
        
    }

 



    //obliczanie wyznacznika jako iloczyn przekątnej
    for(int i=0;i<SWymiar;i++)
    wyznacznik = wyznacznik * M[i][i];
    
    if(fabs(wyznacznik) < ZERO)
    {
            wyznacznik = 0;
            return wyznacznik;
    }
   

    if(wyznacznik==0)
    {
        wyznacznik = 0;
        return wyznacznik;
    }

    
    //sprawdzenie parzystości zamian wierszy
    //i zmiana znaku wyznacznika jeśli nieparzysta
    if(znak%2!=0)
    wyznacznik = wyznacznik*(-1);

    return wyznacznik;
  
}


//Przeciązenie operatora mnozenia dwoch macierzy
template <typename STyp, int SWymiar>
SMacierz<STyp, SWymiar> SMacierz<STyp, SWymiar>::operator * (const SMacierz<STyp, SWymiar> &M2) const
{
    SMacierz<STyp, SWymiar> wynik, M1;
    M1 = *this;
    for(int i=0; i<SWymiar; i++)
    {
        for(int j=0; j<SWymiar; j++)
        {
            wynik[i][j]=0;
        }
    }
    
    for(int i=0; i<SWymiar; i++)
    {
        for(int j=0; j<SWymiar; j++)
        {
            for(int k=0; k<SWymiar; k++)
            {
                wynik[i][j] = wynik[i][j] + M1[i][k]*M2[k][j];
            }
        }
    }
    
    return wynik; //zwraca Macierz
}



#endif
