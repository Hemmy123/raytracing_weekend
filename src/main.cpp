#include <iostream>
#include <fstream>
#include <vector>
#include "Math.h"

void PrintImage()
{
	// Image
	std::ofstream outputFile("image.ppm");
	std::cout.rdbuf(outputFile.rdbuf()); //redirect std::cout to out.txt!

	const int image_width = 1920	;
	const int image_height = 1080;

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height-1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

		for (int i = 0; i < image_width; ++i) {

			auto r = double(i) / (image_width-1);
			auto g = double(j) / (image_height-1);
			auto b = 0.25;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	std::cerr << "\nDone.\n";
}

void VectorTest()
{
	using namespace std;
	Vector vec1;
	Vector vec2(1.2f,2.0f,3.2f);
	Vector vec3{1.2f,2.2f,3.2f};


	// Vector vec2 = {1,2,3};
//	Vector vec2(1,2,3);

//
//	std::cout << temp.x() << endl;
//	std::cout << temp.y() << endl;
//	std::cout << temp2.w() << endl;

}
int main() {
	VectorTest();




}