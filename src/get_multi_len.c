#include "../inc/pathfinder.h"

int get_multiarr_len(char **lines_isl) {
	int len = 0;//длина всего двумрн мас

	for (int i = 1; lines_isl[i]; i++) {
		len += mx_strlen(lines_isl[i]);
		len++;
	}
	return len;
}

int get_multiarr_zeroElement(char **lines_isl) {
	int len = 0;//кол елементов

	for (int i = 0; lines_isl[i]; i++) {
		if (!(mx_strcmp(lines_isl[i], "0") == 0))
			len++;
	}

	return len;
}

int get_multiarr_element(char **lines_isl) {
	int len = 0;//кол елементов

	for (int i = 0; lines_isl[i]; i++)
			len++;

	return len;
}
