#include <iostream>

// 1 - up
// 2 - down
// 3 - left
// 4 - right

void genMap(char tekstura_mapy, int wys_mapy, int szer_mapy, int wys_gracza, int szer_gracza, char reprezentacja_gracza, int kierunek)
{
   using namespace std;

   cout << "Initialized.." << endl;

   char mapa_oryginalna[wys_mapy][szer_mapy];
   char zastepiony_element;
   bool czy_naniesiono = false;

/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                        WYPELNIANIE MAPY

   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */


   for(int wiersz = 0; wiersz <= wys_mapy; wiersz++)
	{
		for(int kolomna = 0; kolomna <= szer_mapy; kolomna++)
		{
			mapa_oryginalna[wiersz][kolomna] = tekstura_mapy;
		}
	}

   cout << "Wypelnianie mapy zakonczone..." << endl;

/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                    NANOSZENIE IKONY GRACZA

   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */

   int poprzednia_szer_gracza;
   int poprzednia_wys_gracza;

   if(czy_naniesiono == false)
   {
      mapa_oryginalna[wys_gracza][szer_gracza] = reprezentacja_gracza;
      czy_naniesiono = true;

   }else
   {

      switch(kierunek)
      {
         case 1:
         poprzednia_wys_gracza = wys_gracza--;
         break;

         case 2:
         poprzednia_wys_gracza = wys_gracza++;
         break;

         case 3:
         poprzednia_szer_gracza = szer_gracza++;
         break;

         case 4:
         poprzednia_szer_gracza = szer_gracza--;
         break;
      }

      mapa_oryginalna[poprzednia_wys_gracza][poprzednia_szer_gracza] = zastepiony_element;

      zastepiony_element = mapa_oryginalna[wys_gracza][szer_gracza];
      mapa_oryginalna[wys_gracza][szer_gracza] = reprezentacja_gracza;

      czy_naniesiono = true;
   }

   cout << "Nanoszenie zakonczone..." << endl;

/* xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

                                                                        WYSWIETLANIE MAPY

   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   */

   for(int wiersz = 0; wiersz <= wys_mapy; wiersz++)
	{
		for(int kolomna = 0; kolomna <= szer_mapy; kolomna++)
		{
			cout << mapa_oryginalna[wiersz][kolomna];
		}

      cout << endl;
	}


   cout << "Wyswietlanie mapy zakonczone..." << endl;

}


int wspolrzedne(int ktoraWartosc)
{
   int szerokosc = 10;
   int wysokosc = 10;
   int kierunek = 1;

   switch(ktoraWartosc)
   {
      case 1:
      return wysokosc;
      break;

      case 2:
      return szerokosc;
      break;

      case 3:
      return kierunek;
      break;

      default:
      return 0;
      break;
   }
}


int main()
{
   using namespace std;

   do
   {
      genMap('.', 10, 10, wspolrzedne(1), wspolrzedne(2), '#', wspolrzedne(3));

   }while(true);

   return 0;
}






























