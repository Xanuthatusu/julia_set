#include <iostream>
#include <fstream>
#include <cmath>

void fillData(double *args) {
	std::cout << "Grid width? ";
	std::cin >> args[0];
	std::cout << "Grid height? ";
	std::cin >> args[1];
	std::cout << "Parameter a? ";
	std::cin >> args[2];
	std::cout << "Parameter b? ";
	std::cin >> args[3];
	std::cout << "Maximum iterations? ";
	std::cin >> args[4];
}

int julia(double x, double y, double max_iter, double a, double b) {
	double distance = 0;
	int count;
	for (count=-1; count < max_iter && distance < 2.0; count++) {
		distance = std::sqrt(x*x + y*y);
		double new_x = x*x - y*y + a;
		y = 2*x*y + b;
		x = new_x;
	}
	return count;
}

int main() {
	double args[5];
	char filename[64];
	fillData(args);
	std::cout << "Output filename? ";
	std::cin >> filename;
	std::ofstream fout(filename);

	fout << args[0] << " " << args[1] << " " << args[4] << std::endl;

	double delta_x = 4.0/(args[0] - 1);
	double delta_y = 4.0/(args[1] - 1);

	double y;
	for(y=0; y < args[1]; y++) {
		double x;
		for(x=0; x < args[0]; x++) {
			fout << julia((-2 + (delta_x * x)), (2 - (delta_y * y)), args[4], args[2], args[3]) << " ";
		}
		fout << std::endl;
	}

	fout.close();

	return 0;
}

