![Interpreter running a program](.github/assets/image.png)
# Hello, World!
Hi, this is a joke program that let's you use an assembler to create programs that can only print "Hello, World!" using the HELLOWORLD instruction, and execute them inside an interpreter.

## Building:
To build the program you need to run make.
If you are not on MacOS you should use C and C++ compilers for your OS.
You will need to build main.c for the interpreter and assembler/main.cpp for the assembler.

## Instructions:
| Binary | Hex | Assembly | Description |
| :---   | :---| :---     | :---        |
| 00000001 | 0x01    | HELLOWORLD | prints "Hello, World!" to stdout. |
| 00000010 | 0x02    | EXIT | exits execution. |
