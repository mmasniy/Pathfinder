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

bool mx_check_all_line(char **lines) {
	for (int i = 1, j = 0; lines[i]; i++) {
		j = 0;
		for (; lines[i][j] != '-' && lines[i]; j++) {
			if (!(mx_isalpha(lines[i][j]))) {
				mx_printerr_all_line(i + 1);
				return 0;
			}
		}
		j++;

		for (; lines[i][j] != ',' && lines[i]; j++) {
			if (!(mx_isalpha(lines[i][j]))) {
				mx_printerr_all_line(i + 1);
				return 0;
			}
		}
		j++;

		for (;lines[i][j];j++) {
			if (!((lines[i][j] >= '0' && lines[i][j] <= '9'))) { //|| lines[i][j] == '\n')
				mx_printerr_all_line(i + 1);
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
