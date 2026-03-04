#include <ncurses.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

extern int highlight;
extern int choice;
extern int c;

extern int delay_quarters; // max is 4 
extern int delay_seconds;
extern struct timespec install_timer;

void init_menu();
void delay(int delay_quarters, int delay_seconds);
