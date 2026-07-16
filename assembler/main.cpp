#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main() {
	std::string filename;
	std::cout << "Please provide a filename:\n";
	std::cin >> filename;

	std::ifstream file(filename);

	std::string line;

	std::ofstream output("out.bin", std::ios::binary);

	while(std::getline(file, line)) {
		if (line == "HELLOWORLD") {
			output.put(0x1);
		}
	}

	file.close();
	output.close();

	return 0;
}
