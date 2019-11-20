#include "../inc/pathfinder.h"

void mx_algorithm(t_form *p_find) {
	int MAX = 999999999;
	p_find->dist = mx_create_zero_mass(p_find->islands);

	for (int i = 0; i < p_find->islands; i++) {
		for (int j = 0; j < p_find->islands; j++) {
			p_find->dist[i][j] = p_find->path[i][j];
		}
	}

	for(int k = 0; k < p_find->islands; k++) {
		for (int j = 0; j < p_find->islands; j++) {
			for (int i = 0; i < p_find->islands; i++) {
				if (p_find->dist[i][k] < MAX && p_find->dist[i][k] + p_find->dist[k][j] < p_find->dist[i][j]) {
					p_find->dist[i][j] = p_find->dist[i][k] + p_find->dist[k][j];
				}
			}
		}
	}
	for (int i = 0; i < p_find->islands; i++) {
		for (int j = 0; j < p_find->islands; j++) {
			printf("%d ", p_find->path[i][j]);
		}
		printf("\n");
	}
	printf("====================================\n");
	for (int i = 0; i < p_find->islands; i++) {
		for (int j = 0; j < p_find->islands; j++) {
			printf("%d ", p_find->dist[i][j]);
		}
		printf("\n");
	}
	printf("====================================\n");
}

static bool init2(int argc, char **argv, t_form *p_find) {
	if (!(mx_check_errors(argc, argv[1])))
		exit(0);

	if (!(p_find->roads_name = mx_file_to_lines(argv[1], p_find)))
		return 0;

	p_find->path = mx_create_mass(p_find);
	
	if (!(mx_check_valid_isl(get_multiarr_element(p_find->roads_name),
													p_find->islands)))
		exit(0);

	mx_algorithm(p_find);
	return 1;
}

bool init(int argc, char **argv) {
	t_form *p_find = (t_form *)malloc(sizeof(t_form));

	p_find->islands = 0;
	p_find->line = NULL;
	p_find->full_line = NULL;
	p_find->roads_name = NULL;
	p_find->path = NULL;
	p_find->dist = NULL;

	init2(argc, argv, p_find);

	mx_del_strarr(&p_find->roads_name);
	mx_del_strarr(&p_find->line);
	mx_del_strarr(&p_find->full_line);
	free(p_find->path);
	free(p_find);
	return 1;
}
