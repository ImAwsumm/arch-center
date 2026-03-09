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

int indent_left;
int lines_from_top;
int amount_of_options;

void display_menu(int highlight, int amount_of_options, const char **options_text, int lines_from_top, int indent_left)
{
    for (int i = 0; i < amount_of_options; i++) 
    {
        if (i == highlight)
        {
            attron(A_REVERSE);
            mvprintw(lines_from_top + i, indent_left, "%s", options_text[i]);
            attroff(A_REVERSE);
        }
        else 
        {
            mvprintw(lines_from_top + i, indent_left, "%s", options_text[i]);
        }
    }
}

void delay(int delay_quarters, int delay_seconds)
{
    if (delay_quarters < 4)
    {
	time_timer_quarters = delay_quarters * 250000000;
	time_timer_seconds = delay_seconds;
    }
    else if (delay_quarters == 4)
    {
	time_timer_quarters = 0;
	time_timer_seconds = delay_seconds + 1;
    }
    else
    {
	printw("Invalid use of delay function\n"); 
	printw("You're stupid\n"); 
    }

    install_timer.tv_nsec = time_timer_quarters;
    install_timer.tv_sec = time_timer_seconds;
    nanosleep(&install_timer, NULL);
}

void submenu_tip(int line)
{
    mvprintw(1, line, "Press \"b\" to go back");
}
