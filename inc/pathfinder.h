#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "../Libmx/inc/libmx.h"

#define USAGE "usage: ./pathfinder [filename]\n"
#define LINE_1 "error: line 1 isn't valid\n"
#define INVALID_NUMBER "error: invalid number of islands\n"

typedef struct		s_form {
	int				islands; // кол-во островов
	char 			**line; // сплит строка с островами и вес
	char 			**full_line; // сплит строка с островами и вес
	char 			**roads_name; // уникальные острова
	int 			**path; // массив путей
	int				**dist; // массив кратчайших путей по Флойду
	int				**next_top;// массив вершин от А к Б
	char			**all_way;
} 					t_form;

//Errors
void mx_printerr(const char *s);
void mx_printerr_all_line(int number);

bool check_max_min(char **line);
bool mx_empty_file(char *filename);
bool mx_check_file(char *filename);
bool mx_check_number_args(int argc);
bool mx_check_first_line(char *first);
bool mx_check_file_n(const char *file);
bool mx_check_all_line(t_form *p_find);
bool mx_check_errors(int argv, char *filename);
bool mx_check_valid_isl(int number, int islands);
bool mx_check_island_name(char *line, int number);

//Use
void mx_algorithm(t_form *p_find);
void mx_print_path(t_form *p_find);
void mx_check_path(t_form *p_find, int top);
void mx_add_top(t_form *p_find, int **path_in_way, int k);

bool mx_isalpha(char c);
bool init(int argc, char **argv);

int mx_get_num_from_str(char *line);
int get_multiarr_len(char **lines_isl);
int get_multiarr_element(char **lines_isl);
int get_multiarr_zeroElement(char **lines_isl);
int mx_check_all_top(t_form *p_find, int x, int y);
int mx_count_other_way(t_form *p_find, int x, int y);
int mx_check_all_top1(t_form *p_find, int x, int y, int nbr_of_path);


int *mx_mass(int size);

int **mx_create_zero_mass(int N);
int **mx_create_mass(t_form *p_find);
int **mx_negative_mass(t_form *p_find, int count);

char *mx_zero(char *str);

char **isl_in_lines(t_form *p_find);
char **one_line_to_mass(char *new_all_lines);
char **mx_file_to_lines(const char *filename, t_form *p_find);

#endif
