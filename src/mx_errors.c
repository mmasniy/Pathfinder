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

bool mx_chaeck_valid_isl(int number, int islands) {
	if (number == islands)
		return 1;

	mx_printerr(INVALID_NUMBER);
	return 0;
}


bool mx_check_first_line(char *first) {
	while (*first != '\0') {
		if (!((*first >= '0' && *first <= '9'))) {
			mx_printerr(LINE_1);
			return 0;
		}

		first++;
	}
	return 1;
}

