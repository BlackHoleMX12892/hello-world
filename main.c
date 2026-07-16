#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct machine {
	uint8_t mem[16];
	uint8_t pc;
} Machine;

int main(void) {
	char filename[50];

	printf("Welcome! please input a filename:\n");
	scanf("%49s", filename);

	Machine mymachine;
	mymachine.pc = 0x0;

	// load a file into memory
	FILE *myfile = fopen(filename, "rb");

	int opcode;
	uint8_t offset = 0x0;

	while((opcode = fgetc(myfile)) != EOF) {
		if (offset >= 0x10)
		{
			printf("The program cannot be loaded because it is bigger than the available memory");
			break;
		}
		
		mymachine.mem[offset] = (uint8_t)opcode;
		offset += 0x1;
	}

	fclose(myfile);

	while(true) {
		// define instruction for printing hello world
		if (mymachine.mem[mymachine.pc] == (uint8_t)0x1) {
			printf("Hello, World!");
			fflush(stdout);
			// check if we should increment pc
			if (mymachine.pc < 0x10)
			{
				mymachine.pc += 0x1;
			}
		}

		if (mymachine.mem[mymachine.pc] == (uint8_t)0x2) {
			exit(0);
		}
	}


	return 0;
}
