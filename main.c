#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct machine {
	uint8_t mem[16];
	uint8_t pc;
} Machine;

int main() {
	char filename[20];

	printf("Welcome! please input a filename:\n");
	scanf("%19s", filename);

	Machine mymachine;
	mymachine.pc = 0x0;

	// load a file into memory
	FILE *myfile = fopen(filename, "rb");

	int opcode;
	uint8_t offset = 0x0;

	while((opcode = fgetc(myfile)) != EOF) {
		mymachine.mem[offset] = (uint8_t)opcode;
		offset += 0x1;
	}

	fclose(myfile);

	while(true) {
		// define instruction for printing hello world
		if (mymachine.mem[mymachine.pc] == (uint8_t)0x1) {
			printf("Hello, World!");
			fflush(stdout);
			mymachine.pc += 0x1;
		}
	}


	return 0;
}
