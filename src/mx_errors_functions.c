#include "../inc/pathfinder.h"

bool mx_check_number_args(int argc) {
	if (argc == 2)
		return 1;

	mx_printerr(USAGE);

	return 0;
}

bool mx_check_file(char *filename) {
	int fd = open(filename, O_RDONLY);

	if (fd > 0)
		return 1;

	mx_printerr("error: file ");
	mx_printerr(filename);
	mx_printerr(" doesn't exist");
	mx_printerr("\n");

	close(fd);

	return 0;
}

bool mx_empty_file(char *filename) {
	int fd = open(filename, O_RDONLY);
	char buffer;
	int sz = read(fd, &buffer, 1);

	if (sz > 0)
		return 1;

	mx_printerr("error: file ");
	mx_printerr(filename);
	mx_printerr(" is empty");
	mx_printerr("\n");

	close(fd);

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

bool mx_check_all_line(char **lines) {
	int i = 1;
	int j = 0;

	for (; lines[i]; i++) {
		printf("%s\n", lines[i]);
		j++;
		for (; lines[i][j] != '-' && lines[i]; j++) {
			printf("%c\n", lines[i][j]);
			if (!(mx_isalpha(lines[i][j]))) {
				mx_printerr_all_line(i);
				return 0;
			}
		}
		j++;

		for (; lines[i][j] != ',' && lines[i]; j++) {
			printf("%c\n", lines[i][j]);
			if (!(mx_isalpha(lines[i][j]))) {
				mx_printerr_all_line(i);
				return 0;
			}
		}
		j++;

		for (;lines[i][j];j++) {
			printf("%c\n", lines[i][j]);
			if (!((lines[i][j] >= '0' && lines[i][j] <= '9'))) {
				mx_printerr_all_line(i);
				return 0;
			}
		}
	}
	return 1;
}	

void mx_printerr_all_line(int number) {
	mx_printerr("error: line ");
	mx_printerr(mx_itoa(number));
	mx_printerr(" isn't valid");
	mx_printerr("\n");
}

bool mx_chaeck_valid_isl(int number, int islands) {
	if (number == islands)
		return 1;

	mx_printerr(INVALID_NUMBER);
	return 0;
}

