#include <iostream>
#include <conio.h>
#include <cstdlib>

int main()
{
   using namespace std;

   int vertical = 0;
   int horizontal = 0;

   char kierunekPoruszaniaPostaci;
   bool yn = 1;



   do
   {
        system("cls");

      cout << "Vertical: " << vertical << " |+| " << "Horizontal: " << horizontal << endl;

      kierunekPoruszaniaPostaci = getch();

      switch(kierunekPoruszaniaPostaci)
      {
         case 'w':
         vertical++;
         break;

         case 's':
         vertical--;
         break;

         case 'd':
         horizontal++;
         break;

         case 'a':
         horizontal--;
         break;

         default:
         horizontal = 0;
         vertical = 0;
         break;
      }

   }while(true);

   return 0;

}
