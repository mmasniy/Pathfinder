#include "../inc/pathfinder.h"

int **mx_create_mass(int islands) {
	int **mass = (int **)malloc(sizeof(int *) * islands);

	for (int i = 0; i < islands; i++) {
		mass[i] = (int *)malloc(sizeof(int) * islands);
		for (int j = 0; j < islands; j++)
			mass[i][j] = 0;
	}

	return mass;
}
