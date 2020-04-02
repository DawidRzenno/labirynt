#ifndef TEREN_H
#define TEREN_H
#include <iostream>
// #include <ncurses.h>
#include <fstream>
#include <string>



class Teren
{
protected:

    int wysokosc = 20;
    int szerokosc = 40;
    int pozycja_wysokosc;
    int pozycja_szerokosc;
    char tekstura_sciany, reprezentacja_gracza, mapa[20][40], uklad_scian[20][40];
    char przezroczysta_tekstura = ' ';
    char miejsce_startu = '@';
    char miejsce_mety = 'M';
    std::fstream plik_planszy;
    std::string a = "JANEK";
    std::string b = ".txt";
    std::string c = a + b;

public:
    Teren(char, char);  //Kolejno reprezentacja_gracza, tekstura_sciany
    void test();
    void wczytanie_poziomu();
    void nakladanie_scian();
    void nakladanie_reprezentacji_gracza();
    void ruch_gracza();
    void wyswietlanie();
    ~Teren();





};

#endif
