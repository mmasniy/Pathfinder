#include "../inc/pathfinder.h"

void mx_add_top(t_form *p_find, int **path_in_way, int k) {
	p_find->all_way = (char **)malloc(sizeof(char *) * (p_find->islands + 1));
	int index = 0;
	int j = 0;

	for (; path_in_way[k][index] != -1; index++);

	for (int i = index - 1; i >= 0; i--, j++) {
		p_find->all_way[j] = mx_strdup(p_find->roads_name[path_in_way[k][i]]);
	}
	p_find->all_way[j] = NULL;
}

int mx_count_other_way(t_form *p_find, int x, int y) {
	int content = p_find->dist[y][x];
	int count = 0;
	int temp;

	for (int i = 0; i < p_find->islands; i++) {
		if (p_find->dist[y][i] != 0 && p_find->dist[y][i] != 100000000) {
			temp = content - p_find->path[y][i];
			if (temp == p_find->dist[i][x])
				count++;
		}
		if (content - p_find->path[y][i] == 0)
			x++;
	}
	y--;
	if (x <= y)
		count += (mx_count_other_way(p_find, x, y) - 1);
	return count;
}

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
	if (mx_arr_size(p_find->all_way) == 2) // чекнуть эту ф-цию;
		mx_printint(p_find->dist[i][j]);
	else
		print_dist(p_find, path_in_way, i, j); // проверить !!!
	mx_printstr("\n========================================\n");
}

int mx_check_all_top1(t_form *p_find, int x, int y, int nbr_of_path) {
	int temp;
	int content = p_find->dist[y][x];

	for (int i = nbr_of_path; i < p_find->islands; i++) {
		if (p_find->path[y][i] != 0 && p_find->path[y][i] != 100000000) {
			temp = content - p_find->path[y][i];
			if (temp == p_find->dist[i][x])
				return i;
			}
		}
		return -2;
}

int mx_check_all_top(t_form *p_find, int x, int y) {
	int temp;
	int content = p_find->dist[y][x];

	for (int i = 0; i < p_find->islands; i++) {
		if (p_find->path[y][i] != 0 && p_find->path[y][i] != 100000000) {
			temp = content - p_find->path[y][i];
			if (temp == p_find->dist[i][x])
				return i;
		}
	}

	return -2;
}

static int **path_from_to(t_form *p_find, int count, int x, int y) {
	int **way = mx_negative_mass(p_find, count);
	int index = 1;
	int end = 0;
	int temp = 0;

	for (int i = 0; i < count; i++) {
		end = y;
		way[i][index - 1] = y;

		while(end != x) {
			way[i][index] = mx_check_all_top(p_find, x, end); //проверка предыдущего пути;
			if (i > 0 && way[i][index] == way[i - 1][index]) {
				temp = mx_check_all_top1(p_find, x, end, way[i][index] + 1); //проверка след пути;
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
	int **path_in_way; // вершини, по ктором мы ведем путь

	for (int i = 0; i < p_find->islands; i++) {
		for (int j = i + 1; j < p_find->islands; j++) {
			count = mx_count_other_way(p_find, i, j);
			path_in_way = path_from_to(p_find, count, i, j); // arr path in one top
			for (int k = 0; k < count; k++) {
				mx_add_top(p_find, path_in_way, k); // check function
				print_ways(p_find, path_in_way[k], i, j);
				mx_del_strarr(&p_find->all_way);
			}
		mx_del_int_arr(path_in_way, count);
		}
	}
}
