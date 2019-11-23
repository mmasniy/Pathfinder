#include "../inc/pathfinder.h"

int **mx_create_zero_mass(int N) {
	int **mass = (int **)malloc(sizeof(int *) * N);
	for (int i = 0; i < N; i++) {
		mass[i] = (int *)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
			mass[i][j] = 999999999;
	}

	for (int i = 0; i < N; i++)
		mass[i][i] = 0;
	
	return mass;
}

int *mx_mass(int size) {
	int *mass = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		mass[i] = 0;
	}

	return mass;
}

// int **mx_create_int_mass(int N) {
// 	int **mass = (int **)malloc(sizeof(int *) * N);
// 	for (int i = 0; i < N; i++) {
// 		mass[i] = (int *)malloc(sizeof(int) * N);
// 		for (int j = 0; j < N; j++)
// 			mass[i][j] = j;
// 	}
// 	return mass;
// }

int **mx_create_mass(t_form *p_find) {
	int **mass = mx_create_zero_mass(p_find->islands);
	char *two = NULL;

	for (int line = 1, i = 0, j = 0; p_find->full_line[line]; line++) {
		i = 0;
		j = 0;

		for (; i < p_find->islands; i++) {
			if (mx_memcmp(p_find->full_line[line], p_find->roads_name[i],
							 mx_strlen(p_find->roads_name[i])) == 0)
				break;
		}

		two = mx_memchr(p_find->full_line[line], '-',
					mx_strlen(p_find->full_line[line]));

		for (; j < p_find->islands; j++) {
			if (mx_memcmp(two + 1, p_find->roads_name[j],
							mx_strlen(p_find->roads_name[j])) == 0)
				break;
		}
		mass[i][j] = mx_get_num_from_str(p_find->full_line[line]);
		mass[j][i] = mass[i][j];
	}
	return mass;
}

int mx_get_num_from_str(char *line) {
	int position = mx_get_char_index(line, ',') + 1;
	return mx_atoi(&line[position]);
}
