#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Functions.c"

int main() {
	Student *students;
	int option = 0;

	while (option != 4) {
		option = showMenu();
		switch (option) {
			case 1:
				registerStudents(students);
				break;
			case 2:
				see_list();
				break;
			case 3:
				see_list();
				// Delete a register
				break;
			case 4:
				break;
			default:
				break;
		}
	}
	printf("See ya! :)");
	return 0;
}
