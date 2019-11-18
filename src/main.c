#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
	
	parse(argc, argv);

	//system("leaks -q pathfinder");
}

bool parse(int argc, char **argv) {
	t_form *p_find = (t_form *)malloc(sizeof(t_form));

	p_find->islands = 0;
	p_find->line = NULL;
	p_find->roads_name = NULL;
	p_find->path = NULL;
	
	if (!(mx_check_errors(argc, argv[1])))
		return 0;
	// заносим в мас имена островов и в мас вес дорог
	if (!(p_find->roads_name = mx_file_to_lines(argv[1], p_find)))
		return 0;
	p_find->path = mx_create_mass(p_find->islands);
	// for (int i= 0; line[i]; i++) {
	// 	printf("%s\n", line[i][j]);
	// }
	printf("vse");
	mx_del_strarr(&p_find->roads_name);
	return 1;

}
