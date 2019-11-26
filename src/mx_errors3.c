#include "../inc/pathfinder.h"

static bool dop_func(t_form *p_find, int i, int j) {
	for (; p_find->line[i][j]; j++)
		if (!((p_find->line[i][j] >= '0' && p_find->line[i][j] <= '9'))) {
			mx_printerr_all_line(i + 1);
			exit(0);
		}
		return 1;
}
// разбить на функции 
bool mx_check_all_line(t_form *p_find) {
	for (int i = 1, j = 0; p_find->line[i]; i++) {
		j = 0;
		for (; p_find->line[i][j] != '-' && p_find->line[i]; j++) {
			if (!(mx_isalpha(p_find->line[i][j]))) {
				mx_printerr_all_line(i + 1);
				return 0;
			}
		}
		j++;
		for (; p_find->line[i][j] != ',' && p_find->line[i]; j++) {
			if (!(mx_isalpha(p_find->line[i][j]))) {
				mx_printerr_all_line(i + 1);
				return 0;
			}
		}
		j++;
		if (!(dop_func(p_find, i, j)))
			return 0;
	}
	return 1;
}

void mx_printerr_all_line(int number) {
	mx_printerr("error: line ");
	mx_printerr(mx_itoa(number));
	mx_printerr(" isn't valid");
	mx_printerr("\n");
}
