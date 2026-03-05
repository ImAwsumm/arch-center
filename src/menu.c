#include "header.h"

int very_safe_code() 
{
    const char *choices[] = 
    {
        "Option 0",
        "Option 1",
        "Settings",
        "Exit",
    };

    int n_choices = ARRAY_SIZE(choices);

    // initialize ncurses
    init_menu();

    choice = -1;
    highlight = 0;
    while (1) 
    {
        clear();
        mvprintw(0, 2, "Main menu");
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
                return 0;
	    default:
		choice = -1;
		break;
        }

	if (choice == 3)
	{
	    endwin();
	    return 0;
	}
	else if (choice == 0)
	{
	    //settings_menu();
	    // (aka nothing)
	}
	else if (choice == 1)
	{
	    //settings_menu();
	    // (aka nothing)
	}
	else if (choice == 2)
	{
	    settings_menu();
	    choice = -1;
	    highlight = 0;
	}
	else
	{
	    choice = -1;
	}
    }
    endwin();
    return 0;
}

int settings_menu()
{
    highlight = 0;
    while(1)
    {
	const char *settings_menu_choices[] = 
    	{
    	    "Configure this program",
    	    "Packages",
    	    "configure dotfiles",
    	    "Back",
    	};

    	clear();

    	mvprintw(0, 2, "Settings");
    	mvprintw(1, 2, "Press \"b\" to go back");

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

    	    case 'b':
    	        endwin();
		return 0;
    	}

	if (choice == 3)
	{
	    endwin();
	    return 0;
	}
	else if (choice == 0)
	{
	    //settings_menu();
	    // (aka nothing)
	}
	else if (choice == 1)
	{
	    //settings_menu();
	    // (aka nothing)
	}
	else if (choice == 2)
	{
	    //settings_menu();
	    // (aka nothing)
	}
	else
	{
	    choice = -1;
	}
    }
    endwin();
    return 0;
}
