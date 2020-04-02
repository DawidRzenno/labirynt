#include <iostream>
#include <cstdlib>
#include <string>

/* About Studio
                         _________________________________________________
 /======================//=========//== LABIRYNT - the Game ==\\=========\\======================\
 |                       --         --                         --         --                     |
 \======================\\=========\\=========.--=--.=========//=========//======================/

                                     The RES Center production
 -------------------------------------------------------------------------------------------------
 @PR1V4T3_R
 @Jakubowski
 -------------------------------------------------------------------------------------------------
*/

// WAZNA WIADOMOSC DO PAN KOCOT XD!
// WSZYSTKIE zmienne jakie wystapia w kodzie zawsze sa pisane pod 'using namespace std;' ! Ma to swoje powody m.in. czytelnosc kodu.
// najpierw wysokosc potem szerokosc w argumentach - nie wiem co sie pokielbasilo ale tak wlasnie trzeba pisac argumenty i wprowadzac dane

/* Zmiany w kodzie || v0.0.2 || 18.11.2015
- inne nazwy zmiennych - sorry nastepnym razem bede pisal jakie zmieniam - teraz zapomnialem a nie chce mi sie wciskac tego Ctrl + Z :D - porownaj sam z wczesniejsza wersja ;)
- inne nazwy funkcji
- usunalem tablice w argumentach funkcji bo nie wiem po co one tam sa :p bez nich dziala tak samo, a nawet chyba lepiej
- dodałem funkcje c() ktora jest skrocona wersja system("clear"), mozna przez to dostosowac kod do danego systemu, mozna wybrac ktore funkcje beda uzywane w zalezonosci co wybierze
uzytkownik na poczatku dzialania (WINDOWS lub LINUX - sorry OSX - bussiness is bussiness)
*/

void c(bool linux_czy_windows) // UPDATE: Zamiast system("clear") lub ("cls")
{
    using namespace std;

    switch(linux_czy_windows)
    {
        case 0: // Linux
        system("clear"); // bedzie sie trzeba tego pozbyc bo to jest jedna ze zbrodni przeciwko programowaniu zaraz po ulomnym korzystaniu ze zmiennych globalnych :) chyba bylo cos podobnego w libce NewCurses - do ogarniecia
        break;

        case 1: // Windows
        system("cls");
        break;

        default:
        cout << "Nie zdefiniowano systemu operacyjnego w funkcji: void c()" << endl;
        break;
    }

}



void generowanie_i_wyswietlanie_mapy(char tekstura_mapy, int wysokosc, int szerokosc, int wej_wys_gracza, int wej_szer_gracza, char reprezentacja_gracza)
{
    using namespace std;

    char mapa_oryginalna[wysokosc][szerokosc];                   // UPDATE: dalem tutaj tablice bo wtedy mozna podczas wywolywania TEJ funkcji dawac jej wymiary przez uzytkownika lub funkcji np. main(),
    char zastepowany_element;                                    //      ...podczas gdy pierwotne rozwiazanie zakladalo, ze w argumentach funkcji trzeba by bylo podać wartosci od razu w jednym miejscu w kodzie ;__; fuj!

    int wspolrzedne_gracza[2] = {wej_wys_gracza, wej_szer_gracza};

/*  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                        WYPELNIANIE MAPY

    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */


	for(int wiersz = 0; wiersz == wysokosc; wiersz++)
	{
		for(int kolomna = 0; kolomna == szerokosc; kolomna++)
		{
			mapa_oryginalna[wiersz][kolomna] = tekstura_mapy;
		}
	}

/*  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                    NANOSZENIE IKONY GRACZA

    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */



    zastepowany_element = mapa_oryginalna[wspolrzedne_gracza[0]][wspolrzedne_gracza[1]];

    mapa_oryginalna[wspolrzedne_gracza[0]][wspolrzedne_gracza[1]] = reprezentacja_gracza;

/*  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                        WYSWIETLANIE MAPY

    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */

	for(int wiersz = 0; wiersz == wysokosc; wiersz++)
	{
		for(int kolomna = 0; kolomna == szerokosc; kolomna++)
		{
			cout << mapa_oryginalna[wiersz][kolomna];
		}
	}

/*  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                        STEROWANIE POSTACIA

    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */




}




int wspolrzedne_gracza_po_wcisnieciu_klawisza(char kierunek_poruszania, int aktualna_wysokosc, int aktualna_szerokosc, bool ktore_dane_zwracac) // 0x0 to jest gorny lewy rog terminala! dlatego jest -- oraz ++
{
    using namespace std;

    int obliczone_wspolrzedne_gracza[2]; // indeks 0 to wysokosc a 1 to szerokosc

    switch(kierunek_poruszania)
    {
        case 'f': // forward
        obliczone_wspolrzedne_gracza[0] = aktualna_wysokosc++;
        break;

        case 'b': // backward
        obliczone_wspolrzedne_gracza[0] = aktualna_wysokosc--;
        break;

        case 'l': // left
        obliczone_wspolrzedne_gracza[1] = aktualna_szerokosc--;
        break;

        case 'r': // right
        obliczone_wspolrzedne_gracza[1] = aktualna_szerokosc++;
        break;

    }

return obliczone_wspolrzedne_gracza[ktore_dane_zwracac]; // w innej funkcji zdefiniuje czy chce najpierw szerokosc czy wysokosc
}


int main()
{
    using namespace std;

	int wysokosc = 20;
	int szerokosc = 2*wysokosc; // UPDATE: bo tak wynika z czcionki 8x12 ;)
    char tekstura = '#';
	const char reprezentacja_gracza = '0'; // UPDATE: Mozesz dawac wartosci juz podczas tworzenia zmiennej ;) lepiej dac tez dodatkowo stala

    int wejsciowa_wysokosc_gracza  = 0;
    int wejsciowa_szerokosc_gracza = 0;

    generowanie_i_wyswietlanie_mapy(tekstura, wysokosc, szerokosc, wejsciowa_wysokosc_gracza, wejsciowa_szerokosc_gracza, reprezentacja_gracza);

    cout << "Koniec";
    cin >> wysokosc;

	return 0;
}
