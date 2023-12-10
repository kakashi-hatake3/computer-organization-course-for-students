#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

volatile long ticker;

void interrupt (*old8)(...);

int frequency = 400;
int max_freq = 2000;
int min_freq = 200;
int signal_delay = 20;
int char_delay = 40;
int dot_delay = 200;
int line_delay = 400;

void randomizeFrequency()
{
  frequency = rand() % (max_freq + 1 - min_freq) + min_freq;
}

void dot()
{
  sound(frequency);
  delay(dot_delay);
  nosound();
}

void line()
{
  sound(frequency);
  delay(line_delay);
  nosound();
}

void sos()
{
  dot();
  delay(signal_delay);
  dot();
  delay(signal_delay);
  dot();
  delay(char_delay);
  line();
  delay(signal_delay);
  line();
  delay(signal_delay);
  line();
  delay(char_delay);
  dot();
  delay(signal_delay);
  dot();
  delay(signal_delay);
  dot();
  delay(char_delay);
}

void interrupt far new8(...)
{
  ticker++;
  if(ticker % 100 == 0)
  {
    ticker = 0L;
    randomizeFrequency();
    sos();
  }
  _chain_intr(old8);
}

void main()
{
  clrscr();
  ticker = 0L;
  old8=_dos_getvect(0x8);

  _dos_setvect(0x8, new8);

 while(getch() != 13){};

  _dos_setvect(0x8,old8);

  exit(0);
}