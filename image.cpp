#include <iostream>
#include <fstream>

int main() {
	char input_filename[64], output_filename[64];
	
	int width, height, max_color, r, g, b;

	std::cout << "Input filename? ";
	std::cin >> input_filename;
	std::cout << "Output filename? ";
	std::cin >> output_filename;

	std::ifstream input_file;
	input_file.open(input_filename);

	input_file >> width;
	input_file >> height;
	input_file >> max_color;

	std::ofstream output_file;
	output_file.open(output_filename, std::ofstream::binary);

	output_file << "P6 " << width << " " << height << " " << max_color << std::endl;

	int i;
	for(i=0; i < (width * height); i++) {
		input_file >> r;
		input_file >> g;
		input_file >> b;
		char values[3] = { (char)r, (char)g, (char)b };
		output_file.write(values, 3);
	}

	input_file.close();
	output_file.close();

	return 0;
}

