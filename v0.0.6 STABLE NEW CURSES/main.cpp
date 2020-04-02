#include <ncurses.h>
#include <iostream>
#include <fstream> //Obsluga pliku tekstowego

void nakladanie_planszy(char mapa[20][40], char przezroczysta_tekstura, char sciana) //Naklada sciany z pliku tekstowego
{
    char plansza[20][40];
    std::fstream plik_plansza;
    plik_plansza.open("lvl.txt"); //Plik txt musi znajdowac sie w folderze z gra
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 40; j++)
            plik_plansza >> plansza[i][j]; 
           
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 40; j++)
        {
            if(plansza[i][j] == sciana)
            {
                mapa[i][j] = plansza[i][j];
            }
        }
 
}

void generowanie(char mapa[20][40], char sciana, char przezroczysta_tekstura)//Generuje obszar roboczy
{
    int wysokosc = 20;
    int szerokosc = 40;
   for(int generowana_wysokosc = 0; generowana_wysokosc < wysokosc; generowana_wysokosc++)
   {
       for(int generowana_szerokosc = 0; generowana_szerokosc < szerokosc; generowana_szerokosc++)
           mapa[generowana_wysokosc][generowana_szerokosc] = przezroczysta_tekstura;
   }
}


void pozycja_gracza(char mapa[20][40], char reprezentacja_gracza, int pozycja_wysokosc, int pozycja_szerokosc)//Naklada reprezentacje gracza na wybrane wspolrzedne
{

    mapa[pozycja_wysokosc][pozycja_szerokosc] = reprezentacja_gracza;
    
}

void wypisanie(char mapa[20][40], char reprezentacja_gracza, char sciana, char przezroczysta_tekstura, int pozycja_wysokosc, int pozycja_szerokosc)//Wypisuje calosc na ekran
{
    int wysokosc = 20;
    int szerokosc = 40;
    generowanie(mapa, sciana, przezroczysta_tekstura);
    nakladanie_planszy(mapa, przezroczysta_tekstura, sciana);
    
    pozycja_gracza(mapa, reprezentacja_gracza, pozycja_wysokosc, pozycja_szerokosc);
    for(int wypisana_wysokosc = 0; wypisana_wysokosc < wysokosc; wypisana_wysokosc++ )
    {
        for(int wypisana_szerokosc = 0; wypisana_szerokosc < szerokosc; wypisana_szerokosc++ )
        {
            printw("%c", mapa[wypisana_wysokosc][wypisana_szerokosc]);
        }
        printw("\n");    
    }   
    
}

void poruszanie(int & pozycja_wysokosc, int & pozycja_szerokosc, char sciana, char mapa[20][40])//Poruszanie po mapie
{
    int ruch_w_gore; //W
    int ruch_w_dol; //A
    int ruch_w_lewo; //S
    int ruch_w_prawo; //D
    char ruch = getch();
    switch(ruch)
    {
        case 'w':
        ruch_w_gore = pozycja_wysokosc - 1;
        if(mapa[ruch_w_gore][pozycja_szerokosc] != '#')
         {
            pozycja_wysokosc-- ;
            break;
         }

        else
            break;
            
        case 'a':
        ruch_w_prawo = pozycja_szerokosc - 1;
        if(mapa[pozycja_wysokosc][ruch_w_prawo] != '#')
        {
            pozycja_szerokosc-- ;
            break;
        }    
        else
            break;
            
        case 's':
        ruch_w_dol = pozycja_wysokosc + 1;
        if(mapa[ruch_w_dol][pozycja_szerokosc] != '#')
        {
            pozycja_wysokosc++ ;
            break;
        }
        
        else
            break;
 
        case 'd':
        ruch_w_prawo = pozycja_szerokosc + 1;
        if(mapa[pozycja_wysokosc][ruch_w_prawo] != '#')
        {
        pozycja_szerokosc++ ;
        break;
        }

        else
            break;
        
    }
}

int main()
{
    char mapa[20][40];
    char reprezentacja_gracza = 'i';
    char sciana = '#';
    char przezroczysta_tekstura = ' ';
    int gra = 1;
    
    int pozycja_wysokosc = 1;
    int pozycja_szerokosc = 1;
    
    
    initscr(); //Rozpoczecie pracy z New Curses
    do
    {
        wypisanie(mapa, reprezentacja_gracza, sciana, przezroczysta_tekstura, pozycja_wysokosc, pozycja_szerokosc);
        poruszanie(pozycja_wysokosc, pozycja_szerokosc, sciana, mapa);
        clear();//Odpowiedzialna z ponizsza za odswiezanie, czyszczenie okna
        refresh();
        
    }while(gra == 1);//Zapetlenie rozgrywki

    
    
    endwin(); //Koniec pracy z New Curses
    return 0;
}