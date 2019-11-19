#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
	
	init(argc, argv);

	//system("leaks -q pathfinder");
}

bool init(int argc, char **argv) {
	t_form *p_find = (t_form *)malloc(sizeof(t_form));

	p_find->islands = 0;
	p_find->line = NULL;
	p_find->full_line = NULL;
	p_find->roads_name = NULL;
	p_find->path = NULL;
	
	if (!(mx_check_errors(argc, argv[1])))
		exit(0);
	// заносим в мас имена островов и в мас вес дорог
	if (!(p_find->roads_name = mx_file_to_lines(argv[1], p_find)))
		return 0;

	p_find->path = mx_create_mass(p_find);
	
	if (!(mx_check_valid_isl(get_multiarr_element(p_find->roads_name),
													p_find->islands)))
		exit(0);

	for (int i = 0; i < p_find->islands; i++) {
		for (int j = 0; j < p_find->islands; j++) {
			if (p_find->path[i][j] == 2147483647) {
				printf("0 ");
			}
			else
				printf("%d ", p_find->path[i][j]);
		}
		printf("\n");
	}

	mx_del_strarr(&p_find->roads_name);
	mx_del_strarr(&p_find->line);
	mx_del_strarr(&p_find->full_line);
	free(p_find->path);
	free(p_find);
	return 1;

}
