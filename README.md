# edlin

RUNNING IN LINUX OS

    to run edlin include 'file.h' in your include directory in admin mode
    1) Download the file 'file.h'
    2) open your shell 
    3) move 'file.h' in /usr/include/ ->  sudo mv file.h /usr/include/
    then you must compile 'edlin.c'
    1) Download the file 'edlin.c'
    2) Download, if you don't have a compiler, the build-essential -> sudo apt install build-essential
    3) compile 'edlin.c' -> gcc -o edlin edlin.c
    4) Run edlin -> ./edlin . 
    If you want, you can run edlin everywhere moving edlin in /usr/bin/ in admin mode -> sudo mv edlin /usr/bin/. 
    In this case, to run edlin, you must type only 'edlin'.
