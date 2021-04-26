#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


typedef struct {
	unsigned month;
	unsigned day;
	unsigned year;
} Date;

typedef struct {
	unsigned id;
	Date birthDate;
	unsigned gender; // 0-não informado, 1-masculino, 2-feminino
	float weight;
	float height;
	float bmi;
} Person;


unsigned getCurrentYear() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_year + 1900;
}

void showHeader() {
	puts(" ---------- Senso do IMC ---------- ");
}

void presentPerson(Person p) {
	printf("Pessoa com CPF %u\n", p.id);
	printf("Nasceu na data: %u/%u/%u\n",
							p.birthDate.day,
							p.birthDate.month,
							p.birthDate.year);
	printf("Tem sexo ");
	switch (p.gender) {
		case 0:
			printf("nao informado\n");
			break;
		case 1:
			printf("masculino\n");
			break;
		case 2:
			printf("feminino\n");
			break;
		default:
			printf("Error: sex value incorrect!");
	}
	printf("Pesa %.2fkg\n", p.weight);
	printf("Mede %.2fm de altura\n", p.weight);
}

float calcBmi(float weight, float height) {
	return weight / (height * height);
}

const char * classifyBmi(float bmi) {
	if (bmi < 18.5)
		return "Magreza 0";
	else if (bmi <= 24.9)
		return "Normal 0";
	else if (bmi <= 29.9)
		return "Sobrepeso 1";
	else if (bmi <= 39.9)
		return "Obesidade 2";
	else if (bmi > 39.9)
		return "Obesidade Grave 3";
}

int main() {
	const unsigned CURRENT_YEAR = getCurrentYear();
	Person people[800];

	int peopleLength = 0;
	while (1) {
		system("cls");
		showHeader();
		puts("Cadastro de usuario");
		printf("Digite o cpf: ");
		scanf("%u", &people[peopleLength].id);

		printf("Digite sua data de nascimento [dd/mm/aaaa]: ");
		scanf("%u %u %u",
			   &people[peopleLength].birthDate.day,
			   &people[peopleLength].birthDate.month,
			   &people[peopleLength].birthDate.year);
		
		int sex;
		while (1) {
			printf("Informe o sexo (0-não informado, 1-masculino, 2-feminino): ");
			scanf("%d", &sex);
			if (sex == 0 || sex == 1 || sex == 2) {
				people[peopleLength].gender = sex;
				break;
			}
			puts("Erro: informe uma das opcoes");
		}

		printf("Informe o seu peso: ");
		scanf("%f", &people[peopleLength].weight);

		printf("Por ultimo, informe sua altura: ");
		scanf("%f", &people[peopleLength].height);

		peopleLength++;
		
		char op;
		printf("Cadastrar mais uma pessoa? [S/N]: ");
		scanf(" %c", &op);
		op = toupper(op);
		
		if (op == 'N' || op == '0')
			break;
	}

	system("cls");
	showHeader();

	unsigned sumOfAges = 0;
	for (int i = 0; i < peopleLength; i++) {
		presentPerson(people[i]);
		printf("\n");
		
		// Perform some calculations
		sumOfAges += CURRENT_YEAR - people[i].birthDate.year;
	}
	printf("%u\n", sumOfAges);
	printf("Media das idades das pessoas %f\n", (float) sumOfAges / (float) peopleLength-1);
	
	return 0;
}
