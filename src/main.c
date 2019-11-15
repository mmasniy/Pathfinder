#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
	int islands;
	char **lines_isl = NULL;

	if (!(mx_check_errors(argc, argv[1])))
		return 0;

	lines_isl = mx_file_to_lines(lines_isl, argv[1], &islands);



}
