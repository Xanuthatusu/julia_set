#include <iostream>
#include <fstream>

int main() {
	int width, height, value;
	int count = 0;

	float change, max_iter;

	std::ifstream input_file;
	input_file.open("escape.escape");

	input_file >> width;
	input_file >> height;
	input_file >> max_iter;

	std::ofstream output_file;
	output_file.open("colors.colors");

	output_file << width << " " << height << " " << "255" << std::endl;

	change = 255.0 / max_iter;

	while(input_file >> value) {
		if(value == max_iter) {
			output_file << "0 0 0 ";
		} else {
			output_file << (int)(value * change) << " 77 255 ";
		}

		count++;
		if(count % width == 0) {
			output_file << std::endl;
		}
	}
	
	return 0;
}
