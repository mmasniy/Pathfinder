#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
	
	init(argc, argv);

	system("leaks -q pathfinder");
}
