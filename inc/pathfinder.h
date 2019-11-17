#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "../Libmx/inc/libmx.h"

#define USAGE "usage: ./pathfinder [filename]\n"
#define LINE_1 "error: line 1 isn't valid\n"
#define INVALID_NUMBER "error: invalid number of islands\n"

// typedef struct s_island {
// 	char			*name;
// 	int				id;
// 	t_link			*link;
// 	t_island		*next;
// }					t_island;

// typedef struct s_link {
// 	int				width;
// 	int				id;
// 	t_link			*next;
// }					t_link;

// typedef struct t_all {
// 	t_island *islands	
// }

//Errors
void mx_printerr(const char *s);
void mx_printerr_all_line(int number);

bool mx_empty_file(char *filename);
bool mx_check_file(char *filename);
bool mx_check_number_args(int argc);
bool mx_check_first_line(char *first);
bool mx_check_all_line(char **lines);
bool mx_check_errors(int argv, char *filename);
bool mx_chaeck_valid_isl(int number, int islands);

//Use


bool mx_isalpha(char c);
bool parse(int argc, char **argv);

int get_2_len(char **lines_isl);

char **isl_in_lines(char **lines_isl);
char **one_line_to_mass(char *new_all_lines);
char **mx_file_to_lines(const char *filename, int *islands);

#endif
