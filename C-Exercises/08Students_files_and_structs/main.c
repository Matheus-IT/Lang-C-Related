#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
	int registration;
	char name[64];
	int yearOfBirth;
} Student;

void printStudents(Student *students, int stdLength) {
	puts("Aqui esta a lista de alunos:");
	for (int i = 0; i < stdLength; i++) {
		printf(" Matricula %d , Nome %s , Ano Nasc %d\n",
			students[i].registration, students[i].name, students[i].yearOfBirth
		);
	}
}

void writeToFile(char *filename, Student *students, int stdLength) {
	FILE *f = fopen(filename, "w");

	if (f) {
		for (int i = 0; i < stdLength; i++) {
			if (i == 0)
				fprintf(f, "%d\n", students[i].registration);
			else
				fprintf(f, "\n%d\n", students[i].registration);

			fprintf(f, "%s\n", students[i].name);
			fprintf(f, "%d", students[i].yearOfBirth);
		}
		Sleep(1000);
		puts(" Informacoes gravadas com sucesso!");
	} else {
		printf("File error!");
		exit(-1);
	}
	fclose(f);
}

void remove_row_break(char str[]) {
	int length = strlen(str)-1;
	if (str[length] == '\n')
		str[length] = '\0';
}

int fgetInt(FILE *f) {
	/* This function returns the int from the current line of an open file */
	char output[256];

	fgets(output, 256, f);
	return atoi(output);
}

Student * readFromFile(char *filename, Student *students, int *stdLength, bool needsToReallocate) {
	FILE *f = fopen(filename, "r");

	if (f) {
		const int MAX_OUTPUT = 64;
		char output[MAX_OUTPUT];
		int i = 0;
		
		puts("Lendo informacoes gravadas...");
		while (!feof(f)){
			if (needsToReallocate) {
				// reallocate and store in students until the end of the file
				(*stdLength)++;
				students = (Student *) realloc(students, (*stdLength) * sizeof(Student));
			}
			
			students[i].registration = fgetInt(f);

			fgets(output, MAX_OUTPUT, f);
			remove_row_break(output);
			strcpy(students[i].name, output);

			students[i].yearOfBirth = fgetInt(f);
			i++;
		}
		Sleep(1000);
		puts("Ok");
	} else {
		printf("File error");
		exit(-1);
	}
	fclose(f);
	return students;
}

int main() {
	int stdLength = 0;
	Student *students = NULL;

	char filename[] = ".\\StudentsData.txt";
	FILE *f = fopen(filename, "r");

	puts("==================== UESPI phb - computacao ====================");
	if (f) {
		students = readFromFile(filename, students, &stdLength, true);
		printStudents(students, stdLength);	
	
		char option;
		puts(" - Voce quer cadastrar mais alunos? [S/N]");
		printf(" => ");
		scanf("%c", &option);

		option = toupper(option);
		if (option == 'N' || option == '2') {
			puts("Saindo do sistema...");
			Sleep(1000);
			return 0;
		}
	}

	int stdLengthBefore = stdLength;
	int additional = 0;
	puts(" - Vamos cadastrar alguns alunos no sistema");
	printf(" - Quantos alunos cadastrar: ");
	scanf(" %d", &additional);

	stdLength = stdLengthBefore + additional;

	students = (Student *) realloc(students, stdLength * sizeof(Student));

	puts("\n - Agora voce pode entrar com as informacoes dos alunos");
	for (int i = stdLengthBefore; i < stdLength; i++) {
		printf(" = Aluno %d \n", i+1);
		printf(" N Matricula: ");
		scanf(" %d", &students[i].registration);

		printf(" Nome: ");
		scanf(" %[^\n]", students[i].name);

		printf(" Ano de nascimento: ");
		scanf(" %d", &students[i].yearOfBirth);
	}

	writeToFile(filename, students, stdLength);
	students = readFromFile(filename, students, &stdLength, false);
	
	printStudents(students, stdLength);

	free(students);
	return 0;
}
