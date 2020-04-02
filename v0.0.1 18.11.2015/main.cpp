#include <iostream> //Wersja Linux
#include <cstdlib>
#include <string>
//rozdzielczosc nalezy zmieniac zachowując proporcje 1:2

void tworzenie_mapy(char tab[20][40], int wysokosc, int szerokosc, int tekstura)//przypisuje teksture do elementow tabeli
{
	for(int wiersz = 0; wiersz < wysokosc; wiersz++)
	{
		for(int kolomna = 0; kolomna < szerokosc; kolomna++)
		{
			tab[wiersz][kolomna] = tekstura;
		}
	}
}


void wypisanie_tabeli(char tab[20][40], int wysokosc, int szerokosc)
{
	system("clear");
	for(int wiersz = 0; wiersz < wysokosc; wiersz++)
	{
		for(int kolomna = 0; kolomna < szerokosc; kolomna++)
		{
			std::cout << tab[wiersz][kolomna];
		}
	
		std::cout << std::endl;
	}
}

void pozycja(char tab[20][40], char gracz, int wysokosc, int szerokosc)
{
	tab[5][10] = gracz;
	wypisanie_tabeli(tab, wysokosc, szerokosc);
}

int main()
{
	int wysokosc = 20;
	int szerokosc = 40;
	char gracz;
	gracz = '0';
	
	std::cout << "Podaj teksture" << std::endl;
	char tekstura;
	std::cin >> tekstura;
	char tab[20][40];
	tworzenie_mapy(tab, wysokosc, szerokosc, tekstura);
	wypisanie_tabeli(tab, wysokosc, szerokosc);
	pozycja(tab, gracz, wysokosc, szerokosc);
	return 0;
}