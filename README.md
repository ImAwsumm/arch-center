# arch-center
a TUI utility aiming to unify system configuration and management into a single program

This programs is in C. Therefore it needs to be compiled before being executed.  

# Install
In order to install the program, you first have to download it.
```bash
git clone https://github.com/imawsumm/arch-center
cd arch-center/
```

Then you have to to compile it.

Compile using make:
```bash
make archc
```

## Features
At the moment it can only execute simple programs like htop or btop

*(doesn't have any features)*

## Commands for system maintenance
```sh
systemctl --failed
journalctl -b
```
Remove unused dependency
```sh
pacman -Qtd
```

# Credits
Me
