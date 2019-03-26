/*
Author: Wanying Cao
Cite: Christian Jensen

 https://en.wikipedia.org/wiki/STL_(file_format)
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Cube{

};
class Cylinder{

};
class Sphere{

};

int main() {
	Design d;
	double s = 10;
	Cube c(s);
	c.translate(x,y,z);
	// rotate??
	cout << c.volume() << '\n';
	c.write("out.stl"); // how to get all my shapes into the same file
  d.add(c);
	double r = 10, height  = 20;
	Cylinder cyl(r, height);
	d.add(c);
	d.write("test.stl");
}
