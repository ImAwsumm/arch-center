# arch-center source code
Compile the program before executing it.
You can use make, gcc or zig in order to compile the full program.

# compile using make

```bash
cd ..
make full
```

# compile using gcc
```bash
gcc -lncurses menu.c -o arch-center -Wall -Werror -Wextra
```

# compile using zig
```bash
zig cc -lncurses menu.c -o arch-center -Wall -Werror -Wextra
```
