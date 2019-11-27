#include "../inc/pathfinder.h"

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

bool mx_check_island_name(char *line, int number) {
	int pos;

	if ((pos = mx_get_char_index(line, '-') - 1) < 0) {
		mx_printerr_all_line(number + 1);
		exit(0);
	}
	pos = mx_get_char_index(line, '-') + 1;
	if (line[pos] == ',') {
		mx_printerr_all_line(number + 1);
		exit(0);
	}
	return 1;
}

bool check_max_min(char **line) {
	int MAX = 2147483647;
	int pos;
		
	for (int i = 1; line[i]; i++) {
			pos = mx_get_char_index(line[i], ',') + 1;
		if (mx_strlen(&line[i][pos]) > 9 || mx_atoi(&line[i][pos]) > MAX) {
			mx_printerr_all_line(i + 1);
			exit(0);
		}
		else if (mx_atoi(&line[i][pos]) == 0) {
			mx_printerr_all_line(i + 1);
			exit(0);
		}
	}
	return 1;
}

bool mx_check_file_n(const char *file) {
	char *all_lines = mx_file_to_str(file);
	int count = 0;

	for (int i = 0; all_lines[i]; i++) {
		if (all_lines[i] == '\n')
			count++;
		if (all_lines[i] == '\n' && all_lines[i + 1] == '\n') {
			mx_printerr_all_line(count + 1);
			exit(0);
		}
	}
	if (all_lines[mx_strlen(all_lines) - 1] != '\n'){
		mx_printerr_all_line(count + 1);
		exit(0);
	}
	return 1;
}
