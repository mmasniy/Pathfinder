#include "../inc/pathfinder.h"

static void mx_print_one_way(char *first, char *second, int dist) {
				mx_printstr("========================================\n");
				mx_printstr("Path: ");
				mx_printstr(first);
				mx_printstr(" -> ");
				mx_printstr(second);
				mx_printchar('\n');
				mx_printstr("Route: ");
				mx_printstr(first);
				mx_printstr(" -> ");
				mx_printstr(second);
				mx_printchar('\n');
				mx_printstr("Distance: ");
				mx_printint(dist);
				mx_printstr("\n========================================\n");
}

static void mx_print_other_way1(t_form *p_find, int i, int j, int out) {
	if (out == 1) {
		mx_printstr("========================================\n");
		mx_printstr("Path: ");
		mx_printstr(p_find->roads_name[i]);
		mx_printstr(" -> ");
		mx_printstr(p_find->roads_name[j]);
		mx_printchar('\n');
		mx_printstr("Route: ");
		mx_printstr(p_find->roads_name[i]);
		mx_printstr(" -> ");
	}
	else if (out == 2) {
		mx_printint(p_find->dist[i][index]);
		mx_printstr(" + ");
		mx_printint(p_find->dist[index][j]);
		mx_printstr(" = ");
		mx_printint(p_find->dist[i][j]);
		mx_printstr("\n========================================\n");
	}
}

static void mx_print_other_way(t_form *p_find, int i, int j) {
	int city = p_find->next_top[i][j];
	int index = p_find->next_top[i][j];
	int index1 = 0;

	mx_print_other_way1(p_find, i, j, 1);

	if(p_find->next_top[i][city] != 0) {
		mx_diffroad();
	}
	else {
		mx_printstr(p_find->roads_name[index]);
		mx_printstr(" -> ");
	}

	mx_printstr(p_find->roads_name[j]);
	mx_printchar('\n');
	mx_printstr("Distance: ");

	if(p_find->next_top[i][city] != 0) {
		//поменял int y1 = j; на index1 = j;
		index1 = j;
		mx_diffroad_len(i, j, index1, p_find->islands, p_find->dist, p_find->next_top, p_find->roads_name);
	}
	else
		mx_print_other_way1(p_find, i, j, 2);
}

void mx_print_path(t_form *p_find) {
	// int *way = mx_mass(p_find->islands);
	// int *way1;

	for (int i = 0; i < p_find->islands; i++) {
		for (int j = i; j < p_find->islands; j++) {
			if (i != j) {
				if(p_find->next_top[i][j] == 0) {
				mx_print_one_way(p_find->roads_name[i], p_find->roads_name[j], 
														  p_find->dist[i][j]);
				}
				else {
				mx_print_other_way(p_find, i, j);
				}
			}
		}
	}
}
