#include <iostream>
#include <fstream>

int main() {
	int width, height, value;
	int count = 0;

	char input_filename[64], output_filename[64];

	float change, max_iter, max_color;

	std::cout << "Maximum Color? ";
	std::cin >> max_color;
	std::cout << "Input filename? ";
	std::cin >> input_filename;
	std::cout << "Output filename? ";
	std::cin >> output_filename;

	std::ifstream input_file;
	input_file.open(input_filename);

	input_file >> width;
	input_file >> height;
	input_file >> max_iter;

	std::ofstream output_file;
	output_file.open(output_filename);

	output_file << width << " " << height << " " << max_color << std::endl;

	if(max_color > 255.0) {
		change = 255.0 / max_iter;
	} else {
		change = max_color / max_iter;
	}

	while(input_file >> value) {
		if(value == max_iter) {
			output_file << "0 0 0 ";
		} else {
			output_file << (int)value * (int)change << " 77 255 ";
		}

		count++;
		if(count % width == 0) {
			output_file << std::endl;
		}
	}
	
	return 0;
}
