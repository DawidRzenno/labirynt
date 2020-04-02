#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

/* About Studio
                         _________________________________________________
 /======================//=========//== LABIRYNT - the Game ==\\=========\\======================\
 |                       --         --                         --         --                     |
 \======================\\=========\\=========.--=--.=========//=========//======================/

                                     The RES Center production
*/

/*char getch()
{
    using namespace std;

    char pobierany_znak;
    cin >> pobierany_znak;

    return pobierany_znak;
}
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

    char mapa_oryginalna[wysokosc][szerokosc];
    char zastepowany_element;

    int wspolrzedne_gracza[2] = {wej_wys_gracza, wej_szer_gracza};

/*  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                        WYPELNIANIE MAPY

    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */


	for(int wiersz = 0; wiersz < wysokosc; wiersz++)
	{
		for(int kolomna = 0; kolomna < szerokosc; kolomna++)
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

	for(int wiersz = 0; wiersz < wysokosc; wiersz++)//UPDATE: Poprawione wyswietlanie (< zamiast ==)
	{
		for(int kolomna = 0; kolomna < szerokosc; kolomna++)
		{
			cout << mapa_oryginalna[wiersz][kolomna];
		}
        cout << endl;
	}

/*  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                        STEROWANIE POSTACIA

    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */




}




int wspolrzedne_gracza_po_wcisnieciu_klawisza(char kierunek_poruszania, int aktualna_wysokosc, int aktualna_szerokosc, bool ktore_dane_zwracac) // 0x0 to jest gorny lewy rog terminala! dlatego jest -- oraz ++
{
    using namespace std;

    int obliczone_wspolrzedne_gracza[2]; // indeks 0 to wysokosc a 1 to szerokosc
    kierunek_poruszania = getch();

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

return obliczone_wspolrzedne_gracza[ktore_dane_zwracac];
}

int main()
{
    using namespace std;

	int wysokosc = 20;
	int szerokosc = 2*wysokosc;
    char tekstura = '#';
	const char reprezentacja_gracza = '0';
    int wejsciowa_wysokosc_gracza  = 0;
    int wejsciowa_szerokosc_gracza = 0;
    char kierunek_poruszania_main;
    char kierunek_poruszania_w_funkcji;

    do
    {
        generowanie_i_wyswietlanie_mapy(tekstura, wysokosc, szerokosc, wejsciowa_wysokosc_gracza, wejsciowa_szerokosc_gracza, reprezentacja_gracza);

        getch();

        switch(kierunek_poruszania_main)
        {
            case 'w':
            kierunek_poruszania_w_funkcji = 'f';
            break;

            case 's':
            kierunek_poruszania_w_funkcji = 'd';
            break;

            case 'a':
            kierunek_poruszania_w_funkcji = 'l';
            break;

            case 'd':
            kierunek_poruszania_w_funkcji = 'r';
            break;
        }

        wejsciowa_wysokosc_gracza = wspolrzedne_gracza_po_wcisnieciu_klawisza(kierunek_poruszania_w_funkcji, wejsciowa_wysokosc_gracza, wejsciowa_szerokosc_gracza, 0);
        wejsciowa_szerokosc_gracza = wspolrzedne_gracza_po_wcisnieciu_klawisza(kierunek_poruszania_w_funkcji, wejsciowa_wysokosc_gracza, wejsciowa_szerokosc_gracza, 1);

    }while(1 == 1);

	return 0;
}
