#include "header.h"

int package_list(void)
{
    endwin();
    //systemctl --failed

    char cmd[64];

    snprintf(cmd, sizeof(cmd),
	    "sudo pacman -Q");
    system(cmd);

    init_menu();
    return 0;
}
