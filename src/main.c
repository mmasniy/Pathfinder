#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
	
	parse(argc, argv);

	//system("leaks -q pathfinder");
}

bool parse(int argc, char **argv) {
	int islands;
	char **roads_name = NULL;
	// первые 3 проверки
	if (!(mx_check_errors(argc, argv[1])))
		return 0;
	// заносим в мас имена островов и в мас вес дорог
	roads_name = mx_file_to_lines(argv[1], &islands);
	//проверка на сущ массивов

	printf("validation - YES");
	return 1;
}
