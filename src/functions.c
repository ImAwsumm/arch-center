#include "header.h"

void init_menu()
{
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

struct timespec install_timer; 
long int time_timer_quarters;
long int time_timer_seconds;

void delay_time(int delay_quarters, int delay_seconds)
{
    if (delay_quarters < 4)
    {
	time_timer_quarters = delay_quarters * 250000000;
	time_timer_seconds = delay_seconds;
    }
    else
    {
	time_timer_quarters = 0;
	time_timer_seconds = delay_seconds + 1;
    }

    install_timer.tv_nsec = time_timer_quarters;
    install_timer.tv_sec = time_timer_seconds;
    nanosleep(&install_timer, NULL);
}
