#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
	
	parse(argc, argv);

	//system("leaks -q pathfinder");
}

bool parse(int argc, char **argv) {
	int islands;
	char **line = NULL;
	char **roads_name = NULL;
	int **path = NULL;
	// первые 3 проверки
	if (!(mx_check_errors(argc, argv[1])))
		return 0;
	// заносим в мас имена островов и в мас вес дорог
	if (!(roads_name = mx_file_to_lines(argv[1], &islands, &line)))
		return 0;
	path = mx_create_mass(islands);
	for (int i= 0; line[i]; i++) {
		printf("%s\n", line[i][j]);
	}

	mx_del_strarr(&roads_name);
	return 1;

}
