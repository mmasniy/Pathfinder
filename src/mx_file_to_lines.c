#include "../inc/pathfinder.h"

char **mx_create_mass(int *islands, char **lines_isl) {
	int first_name;
	int second_name;

	char **roads_name = (char **)malloc(sizeof(*roads_name) * islands);

	for (int i = 1; lines[i]; i++) {
		for (int j = 0; lines[i][j]; j++) {
			if (mx_strcmp())
		}
	}
}

char **mx_file_to_lines(char **lines_isl, const char *filename, int *islands) {
	char *all_lines;
	char **roads_name = NULL;
	all_lines = mx_file_to_str(filename);
	*islands = 0;
	
	lines_isl = mx_strsplit(all_lines, '\n');

	if (!(mx_check_first_line(lines_isl[0])))
		return NULL;

	*islands = mx_atoi(lines_isl[0]);

	mx_strdel(&all_lines);

	if (!(mx_check_all_line(lines_isl)))
		return NULL;

	roads_name = mx_create_mass(&islands, lines_isl);
	//free lines_isl
	return roads_name;
}

