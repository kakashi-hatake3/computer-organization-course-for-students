#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>
#include <stdlib.h>


char inputget() {
    char a = 0;
    _asm {
        MOV AH, 0x07
        INT 0x21
        MOV a, AL
    };
    if (a == 0) {
        char ext = inputget();
        if (ext == 61) {
            return 61;
        } else if (ext == 62) {
            return 62;
        }
    }
    return a;
}

void print_window(int x1, int y1, int x2, int y2) 
{
   _setcursortype(_NOCURSOR);
   int i;
   for (i = y1; i <= y2 + 1; i++) 
   {
      gotoxy(x1 - 1, i);
      cout << "|";
      gotoxy(x2 + 1, i);
      cout << "|";
   }
}


int main() {
   int x1 = 20, y1 = 10, x2 = 60, y2 = 20;
   int movingRight = 0; 
   char code = 0;
   int speed = 50;
   clrscr();
   print_window(x1, y1, x2, y2);
   srand(time(NULL));
   int x = rand() % (x2 - x1 - 1) + x1 + 1;
   srand(x);
   int y = rand() % (y2 - y1 - 1) + y1 + 1;
   srand(y);
   gotoxy(x,y);
   textbackground(5);
   printf("*");
  
   while (code != 27) {
       if (kbhit()) {
           code = inputget();
           if (code == 61 || code == -61) {
               movingRight = -1;
           }
           else if (code == 62) {
               movingRight = 1;
           }
       }

       if (movingRight) {
           delay(speed);

           gotoxy(x, y);
           textbackground(0);
           printf(" ");

           x += movingRight;

           if (x > x2) {
               x = x1;
           }
           else if (x < x1) {
               x = x2;
           }

           gotoxy(x, y);
           textbackground(5);
           printf("*");
       }
   }
   return 0;
}
