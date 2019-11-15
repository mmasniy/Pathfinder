#include "../inc/pathfinder.h"

char **mx_file_to_lines(char **lines_isl, const char *filename, int *islands) {
	char *all_lines;

	all_lines = mx_file_to_str(filename);
	*islands = 0;
	
	lines_isl = mx_strsplit(all_lines, '\n');

	if (!(mx_check_first_line(lines_isl[0])))
		return NULL;
	
	*islands = mx_atoi(lines_isl[0]);

	mx_strdel(&all_lines);
	return lines_isl;

}

