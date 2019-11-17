#include "../inc/pathfinder.h"

char **mx_file_to_lines(const char *filename, int *islands) {
	char *all_lines = mx_file_to_str(filename);
	char **all_isl = NULL;
	char **lines_isl = NULL;

	*islands = 0;
	
	lines_isl = mx_strsplit(all_lines, '\n');
	mx_strdel(&all_lines);

	if (!(mx_check_first_line(lines_isl[0])))
		exit(0);

	*islands = mx_atoi(lines_isl[0]);

	if (!(mx_check_all_line(lines_isl)))
		exit(0);

	all_isl = isl_in_lines(lines_isl); 

	return lines_isl;
}

char **isl_in_lines(char **lines_isl) {
	char *new_all_lines;
	char **no_repeat = NULL;

	for (int i = 1; lines_isl[i]; i++) {
		for (int j = 0; lines_isl[i][j]; j++) {
			if (lines_isl[i][j] == ','){
				lines_isl[i][j] = '\0';
			}
		}
	}

	if (!(new_all_lines = mx_strnew(get_2_len(lines_isl))))
		return NULL;

	for (int i = 1, a = 0; lines_isl[i]; i++) {
		if (i > 1) {
			new_all_lines[a++] = '-';
		}
		for (int j = 0; lines_isl[i][j]; j++, a++) {
			new_all_lines[a] = lines_isl[i][j];
		}
	}
	mx_del_strarr(&lines_isl);
	no_repeat = one_line_to_mass(new_all_lines);
	
	return no_repeat;
}

int get_2_len(char **lines_isl) {
	int len = 0;

	for (int i = 1; lines_isl[i]; i++) {
		len += mx_strlen(lines_isl[i]);
		len++;
	}
	return len;
}

char **one_line_to_mass(char *new_all_lines) {
	char **with_repeat = NULL;
	//char **no_repeat = NULL;

	with_repeat = mx_strsplit(new_all_lines, '-');

	for (int i = 0; with_repeat[i]; i++) {
		for (int j = 0; with_repeat[j]; j++) {
			if ((i != j) && (mx_strcmp(with_repeat[i], with_repeat[j]) == 0))
				with_repeat[j] = "0";
		}
	}
	return with_repeat;
}
















