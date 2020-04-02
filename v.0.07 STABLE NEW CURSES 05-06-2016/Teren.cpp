#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "Teren.h"
#include <string>

Teren::Teren(char player_text, char wall_text)
{
    reprezentacja_gracza = player_text;
    tekstura_sciany = wall_text;
    initscr();

}

void Teren::test()
{
    clear();
    refresh();
    for(int i = 0; i < wysokosc; i++)
        for(int j = 0; j < szerokosc; j++)
            mapa[i][j] = przezroczysta_tekstura;
}

void Teren::wczytanie_poziomu()
{
    plik_planszy.open(c.c_str());
    for(int i = 0; i < wysokosc; i++)
        for(int j = 0; j < szerokosc; j++)
        {

            plik_planszy >> uklad_scian[i][j];
            if(uklad_scian[i][j] == miejsce_startu)
            {
                pozycja_wysokosc = i;
                pozycja_szerokosc = j;
            }
        }
}

void Teren::nakladanie_scian()
{
    for(int i = 0; i < wysokosc; i++)
    {
        for(int j = 0; j < szerokosc; j++)
        {
            if(uklad_scian[i][j] == tekstura_sciany)
            {
                mapa[i][j] = uklad_scian[i][j];
            }
        }
    }
}

void Teren::nakladanie_reprezentacji_gracza()
{
    mapa[pozycja_wysokosc][pozycja_szerokosc] = reprezentacja_gracza;
}

void Teren::ruch_gracza()
{
    int ruch_w_gore;
    int ruch_w_dol;
    int ruch_w_lewo;
    int ruch_w_prawo;
    char ruch = getch();
    switch(ruch)
    {
        case 'w':
        ruch_w_gore = pozycja_wysokosc - 1;
        if(mapa[ruch_w_gore][pozycja_szerokosc] != tekstura_sciany && pozycja_wysokosc > 0)
        {
            pozycja_wysokosc--;
            break;
        }
        else
            break;

        case 's':
        ruch_w_dol = pozycja_wysokosc + 1;
        if(mapa[ruch_w_dol][pozycja_szerokosc] != tekstura_sciany && pozycja_wysokosc < 19)
        {
            pozycja_wysokosc++ ;
            break;
        }
        else
            break;

        case 'a':
        ruch_w_lewo = pozycja_szerokosc - 1;
        if(mapa[pozycja_wysokosc][ruch_w_lewo] != tekstura_sciany && pozycja_szerokosc > 0)
        {
            pozycja_szerokosc-- ;
            break;
        }

        else
            break;

        case 'd':
        ruch_w_prawo = pozycja_szerokosc + 1;
        if(mapa[pozycja_wysokosc][ruch_w_prawo] != tekstura_sciany && pozycja_szerokosc < 39)
        {
            pozycja_szerokosc++ ;
            break;
        }
        else
            break;
    }
}

void Teren::wyswietlanie()
{
    for(int i = 0; i < wysokosc; i++)
    {
        for(int j = 0; j < szerokosc; j++)
            if(mapa[i][j] == reprezentacja_gracza)
            {
                start_color();
                init_pair(1, COLOR_RED, COLOR_BLACK);
                attron(COLOR_PAIR(1));
                printw("%c", mapa[i][j]);
                attroff(COLOR_PAIR(1));
            }
        else
            printw("%c", mapa[i][j]);



     printw("\n");

    }
}

Teren::~Teren()
{
    endwin();
}
