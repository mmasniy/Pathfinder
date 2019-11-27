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
	if (x < y)
		count += (mx_count_other_way(p_find, x, y) - 1);
	return count;
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
