#include "../inc/pathfinder.h"

bool parse(int argc, char **argv);

int main(int argc, char **argv) {
	
	parse(argc, argv);
}

bool parse(int argc, char **argv) {
	int islands;
	char **roads_name = NULL;
	//char **road = NULL;

	if (!(mx_check_errors(argc, argv[1])))
		return 0;

	if (!(roads_name = mx_file_to_lines(roads_name, argv[1], &islands)))
	return 0;

	printf("validation - YES");
	return 1;
}

/*
int main()
{
	//parse
	//find paths
	//print
}

void pase()
{
	//parse cound isl +
	//parse islands
}

void count_parse()
{
	//считал
	//isdigit
	//atoi
	// n > 0
}

void parse_islands()
{
	//while
	//{
	//считал str
	//check
	//save isl
	//free str
	//}
}

bool check()
{
	//проверить валидность
}

void save_isl()
{
	//first = getstr()
	//second = getstr()
	//width = getstr()
	
}

*/
