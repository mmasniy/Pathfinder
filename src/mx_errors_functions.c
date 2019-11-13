#include "../inc/pathfinder.h"

bool mx_check_number_args(int argc) {
	if (argc == 2)
		return 1;

	mx_printeer(USAGE);

	return 0;
}

bool mx_check_file(char *filename) {
	int fd = open(filename, O_RDONLY);

	if (fd > 0)
		return 1;

	mx_printeer("error: file ");
	mx_printeer(filename);
	mx_printeer(" doesn't exist");
	mx_printeer("\n");

	close(fd);

	return 0;
}

bool mx_empty_file(char *filename) {
	int fd = open(filename, O_RDONLY);
	char buffer;
	int sz = read(fd, &buffer, 1);

	if (sz > 0)
		return 1;

	mx_printeer("error: file ");
	mx_printeer(filename);
	mx_printeer(" is empty");
	mx_printeer("\n");

	close(fd);

	return 0;
}

bool mx_check_first_line(int number) {
	if (mx_isdigit(number))
		return 1;

	mx_printeer(LINE_1);

	return 0;
}
// дописать ф-ю)
bool mx_check_all_line(char **lines) {
	int i = 0;
	int j = 0;
	int weight = 0;

	for (; lines[i]; i++) {
		for (; lines[i][j] != '-' && lines[i]; j++) {
			if (!(mx_isalpha(lines[i][j]))) {
				mx_printeer_all_line(lines[i]);
				return 0;
			}
		}
		j++;

		for (; lines[i][j] != ',' && lines[i]; j++) {
			if (!(mx_isalpha(lines[i][j]))) {
				mx_printeer_all_line(lines[i]);
				return 0;
			}
		}
		j++;
// чекни здесь, если есть ошибки
		if ((weight = mx_atoi(lines[i][j]))) {
			mx_printeer_all_line(lines[i]);
				return 0;
		}
	}
	return 1;
}	

bool mx_printeer_all_line(char *line) {
	mx_printeer("error: line ");
	mx_printeer(lines[i]);
	mx_printeer("isn't valid");
	mx_printeer("\n");
	return 0;
}

bool mx_chaeck_valid_isl(int number, int islands) {
	if (number == islands)
		return 1;

	mx_printeer(INVALID_NUMBER);
	return 0;
}

