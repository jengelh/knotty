#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

struct vec3 { double x, y, z; };

int main(int argc, char **argv)
{
	printf("#include \"colors.inc\"\n");
	printf("#declare thicc = 0.5;\n");
	printf("object {\n\tunion {\n");

	double scene_size = 0;
	std::string line;
	bool had_one = false;
	vec3 last;
	for (std::string line; std::getline(std::cin, line); ) {
		vec3 v;
		if (sscanf(line.c_str(), "%lf %lf %lf", &v.x, &v.y, &v.z) != 3)
			break;
		if (had_one) {
			printf("\t\tcylinder { <%f, %f, %f>, <%f, %f, %f>, thicc }\n",
			       last.x, last.y, last.z, v.x, v.y, v.z);
		}
		printf("\t\tsphere { <%f, %f, %f> thicc }\n", v.x, v.y, v.z);
		last = v;
		had_one = true;
		scene_size = std::max(scene_size, fabs(v.x));
		scene_size = std::max(scene_size, fabs(v.y));
		scene_size = std::max(scene_size, fabs(v.z));
	}

	printf("\t}\n");
	printf("\tpigment { color rgb 0 }\n");
	printf("\tfinish { specular 1 }\n");
	printf("}\n");
	printf("#declare scene_size = %f;\n", scene_size);
	printf("light_source { <-4,-2,-1>*scene_size color 0.5 * White }\n");
	printf("light_source { <2,6,1>*scene_size color 0.5 * White }\n");
	printf("camera { location <0,0,-scene_size>*2 look_at 0 }\n");
	printf("background { color White }\n");
	return EXIT_SUCCESS;
}
