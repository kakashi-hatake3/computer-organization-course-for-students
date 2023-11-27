#include <dos.h>
#include <conio.h>

void colorOutput(int i, int type)
{
	switch(i)
	{
		case BLACK:
			if(type) {
				cputs("black");
			} else {
				cputs("0");
			}
	    		
			break;
		case BLUE:
			if(type) {
				cputs("blue");
			} else {
				cputs("1");
			}
			break;
		case GREEN:
			if(type) {
				cputs("green");
			} else {
				cputs("2");
			}
			break;
		case CYAN:
			if(type) {
				cputs("cyan");
			} else {
				cputs("3");
			}
			break;
		case RED:
			if(type) {
				cputs("red");
			} else {
				cputs("4");
			}
			break;
		case MAGENTA:
			if(type) {
				cputs("magneta");
			} else {
				cputs("5");
			}
			break;
		case BROWN:
			if(type) {
				cputs("brown");
			} else {
				cputs("6");
			}
			
			break;
		case LIGHTGRAY:
			if(type) {
				cputs("lightgray");
			} else {
				cputs("7");
			}
			break;
		case DARKGRAY:
			cputs("darkgray");
			break;
		case LIGHTBLUE:
			cputs("lightblue");
			
			break;
		case LIGHTGREEN:
			cputs("lightgreen");
			break;
		case LIGHTCYAN:
			cputs("lightcyan");
			break;
		case LIGHTRED:
			cputs("lightred");
			break;
		case LIGHTMAGENTA:
			cputs("lightmagneta");
			break;
		case YELLOW:
			cputs("yellow");
			break;
		case WHITE:
			cputs("white");
			break;
		default:
			break;
	}
}

int main()	
{
 	int x1 = 20;
	int x2 = 60;
	int y1 = 8;
	int y2 = 18;
	int T = 900;
	clrscr();
	window(x1, y1, x2, y2);
	for(int i = 0; i < 88; i++) {
		for(int j = 0; j < 156; j++) {
			insline();
			textbackground(i);
			textcolor(j);
			cputs("background color:");
			colorOutput(i, 0);
			cputs(" text color:");
			colorOutput(j, 1);
			cputs("\n\r\n\r");
			delay(1000);

			if (kbhit())
			{
				if (getch() == 13)
				{
					return 0;
				}
			}
		}
	}
}
