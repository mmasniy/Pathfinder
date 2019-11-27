#include "../inc/pathfinder.h"

static void print_dist(t_form *p_find, int *ways, int x, int y) {
	int index = 0;

	while (ways[index] != -1) {
		index++;
	}
	for (int i = 0; i <= index; i++, index--) {
		mx_printint(p_find->path[ways[index - 1]][ways[index - 2]]);
		if (i < index - 1)
			mx_printstr(" + ");
	}
	mx_printstr(" = ");
	mx_printint(p_find->dist[x][y]);
}

static void print_ways(t_form *p_find, int *path_in_way, int i, int j) {
	mx_printstr("========================================\nPath: ");
	mx_printstr(p_find->roads_name[i]);
	mx_printstr(" -> ");
	mx_printstr(p_find->roads_name[j]);
	mx_printstr("\nRoute: ");
	mx_print_strarr(p_find->all_way, " -> ");
	mx_printstr("Distance: ");
	if (mx_arr_size(p_find->all_way) == 2)
		mx_printint(p_find->dist[i][j]);
	else
		print_dist(p_find, path_in_way, i, j);
	mx_printstr("\n========================================\n");
}

static int **path_from_to(t_form *p_find, int count, int x, int y) {
	int **way = mx_negative_mass(p_find, count);
	int end = 0;
	int temp = 0;

	for (int i = 0, index = 1; i < count; i++) {
		end = y;
		way[i][index - 1] = y;
		while(end != x) {
			way[i][index] = mx_check_all_top(p_find, x, end);
			if (i > 0 && way[i][index] == way[i - 1][index]) {
				temp = mx_check_all_top1(p_find, x, end, way[i][index] + 1);
				if (temp != -2)
					way[i][index] = temp;
			}
			end = way[i][index];
			index++;
		}
		index = 1;
	}
	return way;
}

void mx_print_path(t_form *p_find) {
	int count  = 0;
	int **path_in_way;

	for (int i = 0; i < p_find->islands; i++) {
		for (int j = i + 1; j < p_find->islands; j++) {
			count = mx_count_other_way(p_find, i, j);
			path_in_way = path_from_to(p_find, count, i, j);
			for (int k = 0; k < count; k++) {
				mx_add_top(p_find, path_in_way, k);
				print_ways(p_find, path_in_way[k], i, j);
				mx_del_strarr(&p_find->all_way);
			}
		mx_del_int_arr(path_in_way, count);
		}
	}
}












































