#include <iostream>
#include <fstream>

int main() {
	int width, height, max_color, r, g, b;

	std::ifstream input_file;
	input_file.open("colors.colors");

	input_file >> width;
	input_file >> height;
	input_file >> max_color;

	std::ofstream output_file;
	output_file.open("image.ppm", std::ofstream::binary);

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

