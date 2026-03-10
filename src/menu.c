#include "header.h"

int main() 
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

    int choice = -1;
    int highlight = 0;
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

        int c = getch();

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
	    choice = -1;
	    highlight = 0;
	}
	else if (choice == 1)
	{
	    system_monitoring();
	    choice = -1;
	    highlight = 0;
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

int system_monitoring()
{
    int choice = -1;
    int highlight = 0;

    while(1)
    {
	const char *choices[] = 
    	{
    	    "htop",
    	    "btop",
    	    "glances",
    	    "Back",
    	};

    	clear();

    	mvprintw(0, 2, "View system activity using one of the following programs");
	menu_tip(2, 2);

    	int n_choices = ARRAY_SIZE(choices);
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

    	int c = getch();

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

	char cmd[16];
	switch (choice)
	{
	    case 0:
		snprintf(cmd, sizeof(cmd),
			"htop");
		system(cmd);

		choice = -1;
		highlight = 0;

		break;
	    case 1:
		snprintf(cmd, sizeof(cmd),
			"btop");
		system(cmd);

		choice = -1;
		highlight = 0;

		break;
	    case 2:
		snprintf(cmd, sizeof(cmd),
			"glances");
		system(cmd);

		choice = -1;
		highlight = 0;

		break;

	    case 3:
		endwin();
	    	return 0;
	    default:
		break;
	}
    }
    endwin();
    return 0;
}

int settings_menu()
{
    int highlight = 0;
    int choice = -1;

    while(1)
    {
	const char *choices[] = 
    	{
    	    "Configure this program",
    	    "Packages",
    	    "Configure dotfiles",
    	    "Back",
    	};
    	clear();

    	mvprintw(0, 2, "Settings");
	menu_tip(2, 2);

    	int n_choices = ARRAY_SIZE(choices);
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

	int c = getch();

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

	switch (choice)
	{
	    case 0:
		highlight = 0;
		choice = -1;

		break;
	    case 1:
		highlight = 0;
		choice = -1;

		break;
	    case 2:
		highlight = 0;
		choice = -1;

		break;
	    case 3: // back button
		endwin();
	    	return 0;
	    default:
		choice = -1;
		break;
	}
    }
    endwin();
    return 0;
}
