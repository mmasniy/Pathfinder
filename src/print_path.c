#include "../inc/pathfinder.h"

static int my_arr_size(char **str) {
	int size = 0;

	for (int i = 0; str[i]; i++)
		size++;

	return size;
}

static void mx_print_ways(t_form *p_find, int *path_in_way, int i, int j) {
	mx_printstr("===============================================\nPath: ");
	mx_printstr(p_find->roads_name[i]);
	mx_printstr(" -> ");
	mx_printstr(p_find->roads_name[j]);
	mx_printstr("\nRoute: ");
	mx_print_strarr(p_find->next_top, "->");
	mx_printstr("Distance: ");
	if (mx_arr_size(p_find->next_top) == 2) // чекнуть эту ф-цию;
		mx_printint(p_find->dist[i][j]);
	else
		mx_print_dist(p_find, path_in_way, i, j);
	mx_printstr("===============================================\n");
}

static int **mx_path_from_to(t_form *p_find, int count, int x, int y) {
	int **path_in_way = mx_negative_mass(p_find, count);
	int index = 1;
	int end = 0;
	int temp = 0;

	for (int i = 0, index = 0; i < count; i++) {
		end = y;
		path_in_way[i][index - 1] = y;

		while(end != x) {
			path_in_way[i][index] = //ф-ция предыдущей вершины;
			if (i > 0 && path_in_way[i][index] == path_in_way[i - 1][index]) {
				temp = //ф-ция следующей вершины;
				if (temp == -2)
					path_in_way[i][index] = temp;
			}
			end = path_in_way[i][index];
			index++;
		}
	}
	return path_in_way;
}

void mx_print_path(t_form *p_find) {
	int count  = 0;
	int **path_in_way;

	for (int i = 0; i < p_find->islands; i++) {
		for (int j = i + 1; j < p_find->islands; j++) {
			count = mx_count_other_way(p_find, i, j);
			path_in_way = mx_path_from_to(p_find, count, i, j);

			for (int k = 0; k < num; k++) {
				p_find->next_top = mx_add_top(p_find, path_in_way, k);
				mx_print_ways(p_find, path_in_way[k], i, j);
				mx_del_strarr(&p_find->next_top);
			}
		}
	}
}



























































































// static void mx_print_one_way(char *first, char *second, int dist) {
// 				mx_printstr("========================================\n");
// 				mx_printstr("Path: ");
// 				mx_printstr(first);
// 				mx_printstr(" -> ");
// 				mx_printstr(second);
// 				mx_printchar('\n');
// 				mx_printstr("Route: ");
// 				mx_printstr(first);
// 				mx_printstr(" -> ");
// 				mx_printstr(second);
// 				mx_printchar('\n');
// 				mx_printstr("Distance: ");
// 				mx_printint(dist);
// 				mx_printstr("\n========================================\n");
// }

// static void mx_print_other_way1(t_form *p_find, int i, int j, int out) {
// 	if (out == 1) {
// 		mx_printstr("========================================\n");
// 		mx_printstr("Path: ");
// 		mx_printstr(p_find->roads_name[i]);
// 		mx_printstr(" -> ");
// 		mx_printstr(p_find->roads_name[j]);
// 		mx_printchar('\n');
// 		mx_printstr("Route: ");
// 		mx_printstr(p_find->roads_name[i]);
// 		mx_printstr(" -> ");
// 	}
// 	else if (out == 2) {
// 		mx_printint(p_find->dist[i][index]);
// 		mx_printstr(" + ");
// 		mx_printint(p_find->dist[index][j]);
// 		mx_printstr(" = ");
// 		mx_printint(p_find->dist[i][j]);
// 		mx_printstr("\n========================================\n");
// 	}
// }

// void mx_otherway(int i, int j, t_form *p_find) {
// 	int city = p_find->next_top[i][j];

// 	if (p_find->next_top[i][j] != 0 && p_find->next_top[i][city] != 0)
// 		mx_otherway(i, city, p_find);

// 	mx_printstr(p_find->roads_name[city]);
// 	mx_printstr(" -> ");
// }

// static void mx_print_other_way(t_form *p_find, int i, int j) {
// 	int city = p_find->next_top[i][j];
// 	int index = p_find->next_top[i][j];
// 	int index1 = 0;

// 	mx_print_other_way1(p_find, i, j, 1);

// 	if(p_find->next_top[i][city] != 0) {
// 		mx_otherway();

// 	}
// 	else {
// 		mx_printstr(p_find->roads_name[index]);
// 		mx_printstr(" -> ");
// 	}

// 	mx_printstr(p_find->roads_name[j]);
// 	mx_printchar('\n');
// 	mx_printstr("Distance: ");

// 	if(p_find->next_top[i][city] != 0) {
// 		//поменял int y1 = j; на index1 = j;
// 		index1 = j;
// 		mx_diffroad_len(i, j, index1, p_find->islands, p_find->dist, p_find->next_top, p_find->roads_name);
// 	}
// 	else
// 		mx_print_other_way1(p_find, i, j, 2);
// }

// void mx_print_path(t_form *p_find) {
// 	// int *way = mx_mass(p_find->islands);
// 	// int *way1;

// 	for (int i = 0; i < p_find->islands; i++) {
// 		for (int j = i; j < p_find->islands; j++) {
// 			if (i != j) {
// 				if(p_find->next_top[i][j] == 0) {
// 				mx_print_one_way(p_find->roads_name[i], p_find->roads_name[j], 
// 														  p_find->dist[i][j]);
// 				}
// 				else {
// 				mx_print_other_way(p_find, i, j);
// 				}
// 			}
// 		}
// 	}
// }
