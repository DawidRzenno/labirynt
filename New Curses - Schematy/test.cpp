#include <ncurses.h>
#include <cstdio>

void generowanie()
{
    int wysokosc = 20;
    int szerokosc = 40;
    char tab[20][40];
    char postac = '#';
    for(int wiersz = 0; wiersz < wysokosc; wiersz++)
    {
        for(int kolumna = 0; kolumna < szerokosc; kolumna++)
        {
            tab[wiersz][kolumna] = postac;
        }
    }

    initscr();
    for(int wiersz = 0; wiersz < wysokosc; wiersz++)
    {
        for(int kolumna = 0; kolumna < szerokosc; kolumna++)
        {
            printw("%c",tab[wiersz][kolumna]);
        }
        printw("\n");
    }
        getch();
        endwin();



}

int main()
{
    generowanie();
    return 0;
}