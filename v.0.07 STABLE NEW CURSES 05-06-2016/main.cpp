#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "Teren.h"
//#include "Menu.h"

#include <string>

int main()
{

    Teren t1('o', 'H');

    t1.wczytanie_poziomu();
    int a = 1;
    do
    {
        t1.test();

        t1.nakladanie_scian();
        t1.nakladanie_reprezentacji_gracza();
        t1.wyswietlanie();
        t1.ruch_gracza();

    }while(a == 1);


    return 0;
}
