#include "../inc/pathfinder.h"

static t_list *mx_create_n(int **data, t_form *p_find) {
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	new_node->all_path = (int **)malloc(sizeof(int *) * 3);

	for (int i = 0; i < p_find->islands; i++) {
		new_node->all_path[i] = (int *)malloc(sizeof(int) * p_find->islands);
		for (int j = 0; j < p_find->islands; j++)
			new_node->all_path[i][j] = data[i][j];
	}

	if (new_node) {
	 	new_node->next = NULL;
	}
	free(data);
	return new_node;
}

static void mx_push_b(t_list **list, int **data, t_form *p_find) {
	t_list *temp = NULL;
	t_list *new_node = NULL;

	if (list && (new_node = mx_create_node(data)) != NULL) {
		if (*list) {
			temp = *list;

			while (temp->next)
				temp = temp->next;

			temp->next = new_node;
		}
		else
			*list = new_node;
	}
}

void mx_check_path(t_list **l_path, t_form *p_find, int top) {
	int end_mass = mx_end_zero_mass(p_find->islands);
	int check = top;
	int d = 0;

	while (d != i) {
		
	}
}

static bool init2(int argc, char **argv, t_form *p_find, t_list *l_path) {

	if (!(mx_check_errors(argc, argv[1])))
		exit(0);

	if (!(p_find->roads_name = mx_file_to_lines(argv[1], p_find)))
		return 0;

	p_find->path = mx_create_mass(p_find);
	
	if (!(mx_check_valid_isl(get_multiarr_element(p_find->roads_name),
													p_find->islands)))
		exit(0);

}

bool init(int argc, char **argv) {
	t_form *p_find = (t_form *)malloc(sizeof(t_form));
	t_list *l_path = (t_list *)malloc(sizeof(t_list));

	p_find->islands = 0;
	p_find->line = NULL;
	p_find->full_line = NULL;
	p_find->roads_name = NULL;
	p_find->path = NULL;
	l_path->next = NULL;
	l_path->path = NULL;

	init2(argc, argc, p_find, l_path);
	// if (!(mx_check_errors(argc, argv[1])))
	// 	exit(0);

	// if (!(p_find->roads_name = mx_file_to_lines(argv[1], p_find)))
	// 	return 0;

	// p_find->path = mx_create_mass(p_find);
	
	// if (!(mx_check_valid_isl(get_multiarr_element(p_find->roads_name),
	// 												p_find->islands)))
	// 	exit(0);

	mx_del_strarr(&p_find->roads_name);
	mx_del_strarr(&p_find->line);
	mx_del_strarr(&p_find->full_line);
	free(p_find->path);
	free(p_find);
	return 1;

}

	//for (int i = 0; i < p_find->islands; i++) {
	// 	for (int j = 0; j < p_find->islands; j++) {
	// 		if (p_find->path[i][j] == 2147483647) {
	// 			printf("0 ");
	// 		}
	// 		else
	// 			printf("%d ", p_find->path[i][j]);
	// 	}
	// 	printf("\n");
	// }
