#include "header.h"

int main() 
{

    const char *choices[] = 
    {
        "Option 1",
        "Option 2",
        "Settings",
        "Exit",
    };

    int n_choices = ARRAY_SIZE(choices);

    // initialize ncurses
    init_menu();

    while (1) 
    {
	choice = -1;
	highlight = 0;
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
		printw("Hey");
                return 0;
        }
	if (choice == 3)
	{
	    endwin();
	    return 0;
	}
	else if (choice == 2)
	{
	    settings_menu();
	}

    }
    endwin();
    return 0;
}

void settings_menu()
{
    const char *settings_menu_choices[] = 
    {
        "Configure this program",
        "Packages",
        "configure dotfiles",
        "Exit",
        "Exit",
    };
    clear();
    mvprintw(1, 2, "Settings");

    int n_choices = ARRAY_SIZE(settings_menu_choices);
    for (int i = 0; i < n_choices; i++) 
    {
        if (i == highlight)
        {
            attron(A_REVERSE);
            mvprintw(3 + i, 4, "%s", settings_menu_choices[i]);
            attroff(A_REVERSE);
        }
        else 
        {
            mvprintw(3 + i, 4, "%s", settings_menu_choices[i]);
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
    	printw("Hey");
            return 0;
    }
}
