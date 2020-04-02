#include <iostream> //Wersja Linux
#include <cstdlib>
#include <string>

/* About Studio
                         _________________________________________________
 /======================//=========//== LABIRYNT - the Game ==\\=========\\======================\
 |                       --         --                         --         --                     |
 \======================\\=========\\=========.--=--.=========//=========//======================/

                                     The RES Center production
 -------------------------------------------------------------------------------------------------
 @Dawid Rzenno (PR1V4T3_R)
 @Jan Kocot
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

void c() // UPDATE: Zamiast system("clear")
{
    system("clear"); // bedzie sie trzeba tego pozbyc bo to jest jedna ze zbrodni przeciwko programowaniu zaraz po ulomnym korzystaniu ze zmiennych globalnych :) chyba bylo cos podobnego w libce NewCurses - do ogarniecia
}

//rozdzielczosc nalezy zmieniac zachowując proporcje 1:2                            // EDIT: czyli wzor    ----->    szerokosc = 2 * wysokosc

void generowanie_mapy(char tekstura, int wysokosc, int szerokosc)
{
    using namespace std;

    char mapa_oryginalna[wysokosc][szerokosc];  // UPDATE: dalem tutaj tablice bo wtedy mozna podczas wywolywania TEJ funkcji dawac jej wymiary przez uzytkownika lub funkcji np. main(),
                                                // ...podczas gdy pierwotne rozwiazanie zakladalo, ze w argumentach funkcji trzeba by bylo podać wartosci od razu w jednym miejscu w kodzie ;__; fuj!

	for(int wiersz = 0; wiersz == wysokosc; wiersz++)
	{
		for(int kolomna = 0; kolomna == szerokosc; kolomna++)
		{
			mapa_oryginalna[wiersz][kolomna] = tekstura;
		}

	}
}



int wspolrzedne_gracza_po_wcisnieciu_klawisza(string kierunek_poruszania; int aktualna_wysokosc; int aktualna_szerokosc, bool ktore_dane_zwracac) // 0x0 to jest gorny lewy rog terminala! dlatego jest -- oraz ++
{
    using namespace std;

    int obliczone_wspolrzedne_gracza[2]; // indeks 0 to wysokosc a 1 to szerokosc

    switch(kierunek_poruszania)
    {
        case "przod":
        obliczone_wspolrzedne_gracza[0] = aktualna_wysokosc++;
        break;

        case "tyl"
        obliczone_wspolrzedne_gracza[0] = aktualna_wysokosc--;
        break;

        case "lewo"
        obliczone_wspolrzedne_gracza[1] = aktualna_szerokosc--;
        break;

        case "prawo"
        obliczone_wspolrzedne_gracza[1] = aktualna_szerokosc++;
        break;

    }

}return obliczone_wspolrzedne_gracza[ktore_dane_zwracac]; // w innej funkcji zdefiniuje czy chce najpierw szerokosc czy wysokosc




void gracz(char gracz, int wysokosc, int szerokosc)
{
    char tab[wysokosc][szerokosc] // INFO: Patrz: komentarz do wypisanie_tabeli()

	tab[5][10] = gracz;

	wypisanie_tabeli(tab, wysokosc, szerokosc);
}



int main()
{
	int wysokosc = 20;
	int szerokosc = 2*wysokosc; // UPDATE: bo tak wynika z czcionki 8x12 ;)
    char tekstura;
	const char reprezentacja_gracza= '0'; // UPDATE: Mozesz dawac wartosci juz podczas tworzenia zmiennej ;) lepiej dac tez dodatkowo stala

	cout << "Podaj teksture" << endl;
	cin >> tekstura;

        generowanie_mapy(tekstura, wysokosc, szerokosc)


	return 0;
}
