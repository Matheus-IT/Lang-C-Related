#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Structures.c"
#define averaging(grade) (float)((grade[0]) + (grade[1]) + (grade[2]))/3

//Global structures:
Greatest_grade greatest_grade;
Greatest_average greatest_average;
Smallest_average smallest_average;

//Functions:
void cleanBuffer() {
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

void remove_br(char n[]) {
	int length = strlen(n)-1;
	n[length] = '\0';
}

void tirar_virgula(char str[]) {
	int length = strlen(str)-1;
	for (int c = 0; c < length; c++) {
		if (str[c] == ',') {
			str[c] = '.';
		}
	}
}

bool isNumber(char str[]) {
	int length = strlen(str)-1;
	tirar_virgula(str); //Trocar virgula por ponto
	for (int c = 0; c < length; c++) {
		if (str[c] == '.') { //Abrir excessão para ponto
			continue;
		} else {
			if (str[c] >= '0' && str[c] <= '9')
				continue;
			else
				return false;
		}
	}
	return true;
}

float getNum(char msg[]) {
	float n = 0;
	char str[256];
	bool firstTime = true;
	
	//Evaluate if it's a number or not:
	do {
		if (!firstTime) 
			cleanBuffer();
		else {
			firstTime = false;
		}
		printf("%s", msg);
		fgets(str, 256, stdin);
		if (isNumber(str)) {
			n = atof(str);
			return n;
		} else {
			printf(" - Invalid input!");
		}
	} while (!isNumber(str));
}
 
int showMenu() {
	int op = NULL;

	printf(" - High School System - \n\
	[1] Register students \n\
	[2] See list of students \n\
	[3] Delete student's registration \n\
	[4] Exit \n");
	while (op != 1 && op != 2 && op != 3 && op != 4) {
		op = getNum("Your option >> ");
	}
	return op;
}

void set_values(Student *std) {
	int qtt;
 
	qtt = getNum(" - How many students do you want to register? ");
	std = (Student *)(malloc(qtt * sizeof(Student)));
	for (int c = 0; c < qtt; c++) {
		//Set the name:
		if (c != 0) cleanBuffer();
		printf(" - Enter the name of the %d student: ", c+1);
		fgets(std[c].name, 40, stdin);
		remove_br(std[c].name); //Removes \n
		std[c].name[0] = toupper(std[c].name[0]);
		//Set the grades:
		for (int count = 0; count < 3; count++) {
			printf(" - Enter the %d grade of %s: ", count+1, std[c].name);
			scanf(" %f", &std[c].grade[count]);
			//Calculate if the first grade of each guy is the greatest:
			if (c == 0) { //O primeiro já vai entrar tendo a maior
				greatest_grade.value = std[c].grade[0];
				strcpy(greatest_grade.name, std[c].name);
			} else if ((count == 0) && (std[c].grade[0] > greatest_grade.value)) {
				greatest_grade.value = std[c].grade[0];
				strcpy(greatest_grade.name, std[c].name);
			}
		}
		std[c].average = averaging(std[c].grade); //Average calculation
		//Calculate if the average of each guy is the greatest or the smallest:
		if (c == 0) { //O primeiro já vai entrar tendo o maior e menor
			greatest_average.value = std[c].average;
			strcpy(greatest_average.name, std[c].name);
			smallest_average.value = std[c].average;
			strcpy(smallest_average.name, std[c].name);
		} else if (std[c].average > greatest_average.value) { //Evaluating if each guy has the greatest_average
			greatest_average.value = std[c].average;
			strcpy(greatest_average.name, std[c].name);
		} else if (std[c].average < smallest_average.value) { //Evaluating if each guy has the smallest_average
			smallest_average.value = std[c].average;
			strcpy(smallest_average.name, std[c].name);
		}
		//Evaluate if each guy has passed or not:
		if (std[c].average >= 6) {
			std[c].result = true; //Passed! :)
		} else {
			std[c].result = false; //Failed! :(
		}
		//Store the current student
		FILE *f = NULL;
		f = fopen("list_student.txt", "r");
		if (f == NULL) {
			f = fopen("list_student.txt", "w");
		} else {
			f = fopen("list_student.txt", "a");
		}
		//Don't forget to place the space between them
		fprintf(f, "\n%s %.2f %.2f %.2f %.2f", std[c].name, std[c].grade[0], std[c].grade[1], std[c].grade[2], std[c].average);
		fclose(f);
		free(std);
	}
}
 
void show_stts() {
	printf("------------------------------\n");
	printf("   Greatest first grade:\n");
	printf("   Name: %s First Grade: %4.2f \n", greatest_grade.name, greatest_grade.value);
	printf("------------------------------\n");
	printf("   Greatest average:\n");
	printf("   Name: %s Average: %4.2f \n", greatest_average.name, greatest_average.value);
	printf("------------------------------\n");
	printf("   Smallest average:\n");
	printf("   Name: %s Average: %4.2f \n", smallest_average.name, smallest_average.value);
	printf("------------------------------\n");
}

void see_list() {
	FILE *f = NULL;
	int std_count = 0;
	int char_per_row = 100;
	char phrase[char_per_row];
	Student *std_local;

	f = fopen("list_student.txt", "r");
	if (f == NULL)
		printf("The file doesn't exist \n");
	else {
		std_local = (Student *)(malloc(0 * sizeof(Student))); //I need the first allocation
		printf("----------------------------------------------------------------------\n");
		printf("                          List of Students                            \n");
		int c = 0;
		while (!feof(f)) {
			std_local = (Student *)(realloc(std_local, (c+1) * sizeof(Student)));
			//Read each student from the file
			fscanf(f, "%s %f %f %f %f", std_local[c].name, &std_local[c].grade[0], &std_local[c].grade[1], &std_local[c].grade[2], &std_local[c].average);
			//Show the current student
			printf("----------------------------------------------------------------------\n");
			printf(" %d Student: %s; Grades: %.2f, %.2f, %.2f; Average: %.2f \n", \
			c+1, std_local[c].name, std_local[c].grade[0], std_local[c].grade[1], std_local[c].grade[2], std_local[c].average);
			c++;
			/* I'm still working on that...
			if (std_local[c].result == true) {
				printf("   Aluno Aprovado! Parabens! \n");
			} else {
				printf("   Aluno Reprovado, Tente novamente :( \n");
			}
			printf("------------------------------\n");
			*/
		}
		printf("----------------------------------------------------------------------\n");
		fclose(f);
	}
}

void registerStudents(students) {
	set_values(students);
	show_stts();
}