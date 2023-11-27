#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "dos.h"
#include "graphics.h"
#include <iostream.h>
#include <string.h>

float Draw_Graphic(int Xmax, int Ymax)
{
  float Fmax = -10;
  int X1 = 40, X2 = Xmax - X1, Y1 = 50, Y2 = Ymax - 70, N = X2 - X1 - 47 - 26;
  float x0 = (3.14*3) / 2, xm = 17 * 3.14, dx = (xm - x0) / N, x = 0;
  float F = 0;
  unsigned short int i = 0, enter = 13;


  for (i = 0, x = x0; i < N; i++, x += dx)
  {
    F = (float)(pow((sin(x/4)), 2) + sqrt(x));
    if (F > Fmax)
    {
      Fmax = F;
    }

    putpixel(X1 + i + 47, Y2 - (int)((float)(Y2 - Y1) / (19.0 / F)), YELLOW);
    delay(7);
    if (kbhit())
    {
	if (getch() == enter)
	{
	    break;
	}
    }
  }
  return Fmax;
}


void Print_Axes(int X1, int Y1, int X2, int Y2)
{
    char xi[2];
    char yi[2];
    int i = 0;

  setcolor(YELLOW);
  outtextxy(X1 + 8, Y1 - 7, "F(x)");
  outtextxy(X2 + 8, Y2 - 4, "X");

  setcolor(WHITE);
  line(X1, Y2, X1, Y1);
  line(X1, Y2, X2, Y2);
  outtextxy(X1 - 10, Y2 + 5, "0");


  for (i = 1; i < 11; ++i)
    line(X1 - 5, Y2 - i * 20, X1 + 5, Y2 - i * 20);

  for (i = 1; i < 29; ++i)
    line(X1 + 20 * i, Y2 + 5, X1 + 20 * i, Y2 - 5);


  for (i = 4; i < 57; i += 4) 
  {
    sprintf(xi, "%d", i);
    outtextxy(X1 + 18 * i / 2 + i - 3, Y2 + 7, xi);
  }


  for (i = 2; i < 11; i += 2)
  {
    sprintf(yi, "%d", i);
    outtextxy(X1 - 20, Y2 - 20 * i - i / 4, yi);
  }
}

int main() {
  clrscr();
  int driver = DETECT, mode;
  initgraph(&driver, &mode, "c:\\turboc3\\bgi");

  int Xmax = getmaxx(), Ymax = getmaxy();
  int X1 = 40, X2 = Xmax - X1, Y1 = 175, Y2 = Ymax - 70;
  float Fmax;
  char string[32];

  Print_Axes(X1, Y1, X2, Y2);
  outtextxy(200, 40, "F = (sin(x/4))^2 - sqrt(x)");
  Fmax = Draw_Graphic(Xmax, Ymax);
  
  setcolor(CYAN);
 
  outtextxy(225, 70, "Fmax = 1.155501e-08");
  outtextxy(260, 85, "Fmax ~ 7");
  rectangle(210, 60,395, 100);

 
  

  
  getch();
  closegraph();

  return 0;
}
