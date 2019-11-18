#include "../inc/pathfinder.h"

char **mx_file_to_lines(const char *filename, t_form *p_find) {
	char *all_lines = mx_file_to_str(filename);
	char **all_isl = NULL;
	//char **lines_isl = NULL;
	
	p_find->line = mx_strsplit(all_lines, '\n');
	mx_strdel(&all_lines);

	if (!(mx_check_first_line((p_find->line)[0])))
		exit(0);

	p_find->islands = mx_atoi((p_find->line)[0]);

	if (!(mx_check_all_line(p_find)))
		exit(0);

	all_isl = isl_in_lines(p_find); 

	return all_isl;
}

char **isl_in_lines(t_form *p_find) {
	char *new_all_lines;
	char **no_repeat = NULL;

	for (int i = 1; p_find->line[i]; i++) {
		for (int j = 0; p_find->line[i][j]; j++) {
			if (p_find->line[i][j] == ','){
				p_find->line[i][j] = '\0';
			}
		}
	}

	if (!(new_all_lines = mx_strnew(get_multiarr_len(p_find->line))))
		return NULL;

	for (int i = 1, a = 0; p_find->line[i]; i++) {
		if (i > 1) {
			new_all_lines[a++] = '-';
		}
		for (int j = 0; p_find->line[i][j]; j++, a++) {
			new_all_lines[a] = p_find->line[i][j];
		}
	}
	no_repeat = one_line_to_mass(new_all_lines);
	
	return no_repeat;
}

char **one_line_to_mass(char *new_all_lines) {
	char **with_repeat = NULL;
	char **no_repeat = NULL;
	int a = 0;

	with_repeat = mx_strsplit(new_all_lines, '-');
	mx_strdel(&new_all_lines);

	for (int i = 0; with_repeat[i]; i++) {
		for (int j = 0; with_repeat[j]; j++) {
			if ((i != j) && (mx_strcmp(with_repeat[i], with_repeat[j]) == 0))
				with_repeat[j] = mx_zero(with_repeat[j]);
		}
	}
	
	no_repeat = (char **)malloc(sizeof(*no_repeat) * 
									(get_multiarr_element(with_repeat) + 1));
	
	for (int i = 0; with_repeat[i];) {
		if (mx_strcmp("0", with_repeat[i]) == 0)
			i++;
		else {
			no_repeat[a++] = mx_strdup(with_repeat[i++]);
		}
	}
	
	no_repeat[a] = NULL;
	mx_del_strarr(&with_repeat);
	return no_repeat;
}

char *mx_zero(char *str) {
	char *zero = mx_strnew(1);

	zero = mx_strcpy(zero, "0");
	mx_strdel(&str);
	return zero;
}















