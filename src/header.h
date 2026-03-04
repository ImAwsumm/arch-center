#include <ncurses.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

extern int highlight;
extern int choice;
extern int c;
extern int indent_left;
extern int lines_from_top;
extern int amount_of_options;

extern int delay_quarters; // max is 4 
extern int delay_seconds;
extern struct timespec install_timer;

int settings_menu();

void init_menu();
void delay(int delay_quarters, int delay_seconds);
