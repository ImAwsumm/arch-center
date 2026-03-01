#include <ncurses.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


void init_menu()
{
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}
int main() 
{
    const char *choices[] = 
    {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit",
    };

    int n_choices = ARRAY_SIZE(choices);
    int highlight = 0;
    int choice = -1;
    int c;

    // initialize ncurses
    init_menu();

    while (1) 
    {
        clear();
        mvprintw(1, 2, "Use arrow keys to move and Q to quit");

        for (int i = 0; i < n_choices; i++) 
	{
            if (i == highlight)
	    {
                attron(A_REVERSE);
                mvprintw(3 + i, 4, "%s", choices[i]);
                attroff(A_REVERSE);
            }
	    else 
	    {
                mvprintw(3 + i, 4, "%s", choices[i]);
            }
        }

        c = getch();

        switch (c) 
	{
            case KEY_UP:
                highlight--;
                if (highlight < 0)
                    highlight = n_choices - 1;
                break;

            case KEY_DOWN:
                highlight++;
                if (highlight >= n_choices)
                    highlight = 0;
                break;

            case 10:  // Enter key
                choice = highlight;
                break;

            case 'q':
                endwin();
		// add waiting time
		printw("Hey");
                return 0;
        }

    }

    endwin();
    return 0;
}
