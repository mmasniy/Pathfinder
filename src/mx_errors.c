#include "../inc/pathfinder.h"

bool mx_check_errors(int argc, char *filename) {
	if (!(mx_check_number_args(argc)))
		return 0;

	if (!(mx_check_file(filename)))
		return 0;

	if (!(mx_empty_file(filename)))
		return 0;

	return 1;
}
