#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


/*
 * ----------------------- INTEGRANTES DO TRABALHO -----------------------
 * Matheus da Costa da Silva
 * Henrique Gleison Silva
 * Victor Cavalcante Vieira
 * -----------------------------------------------------------------------
*/


/*
 * Structs:
 */
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
	float bmiValue;
	char bmiClass[20]; // "Magreza" "Normal" "Sobrepeso" 
					 //	"Obesidade" "Obesidade Grave"
} Person;

typedef struct {
	unsigned quantity;
	float sumOfHeights;
	float sumOfWeights;
	unsigned sumOfAges;
} WomenStatistics;

typedef struct {
	unsigned quantity;
	float sumOfHeights;
	float sumOfWeights;
	unsigned sumOfAges;
} MenStatistics;

typedef struct {
	unsigned quantity;
	float sumOfHeights;
	float sumOfWeights;
	unsigned sumOfAges;
} GenderNotInformedStatistics;

typedef struct {
	unsigned peopleBetween18And39;
	unsigned peopleBetween18And39HaveObesity;
	unsigned peopleBetween18And39HaveSevereObesity;

	unsigned peopleBetween40And59;
	unsigned peopleBetween40And59HaveObesity;
	unsigned peopleBetween40And59HaveSevereObesity;
	
	unsigned peopleMoreThan60;
	unsigned peopleMoreThan60HaveObesity;
	unsigned peopleMoreThan60HaveSevereObesity;
} QuantityOfPeopleByAge;
/*
 * Scructs End
 */


/*
 * Utility Functions:
 */
void clearScreen() {
	system("clear");
}

unsigned getCurrentYear() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_year + 1900;
}

void showHeader() {
	puts(" ---------- Senso do IMC ---------- ");
}
/*
 *  Utility Functions End
 */


/*
 * Features:
 */
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
			puts("\nError: sex value incorrect!");
	}
	printf("Pesa %.2fkg\n", p.weight);
	printf("Mede %.2fm de altura\n", p.height);
	printf("Com IMC %.2f - %s\n", p.bmiValue, p.bmiClass);
}

const char * classifyBmi(float bmi) {
	if (bmi < 18.5)
		return "Magreza";
	else if (bmi <= 24.9)
		return "Normal";
	else if (bmi <= 29.9)
		return "Sobrepeso";
	else if (bmi <= 39.9)
		return "Obesidade";
	else
		return "Obesidade Grave";
}

unsigned calcAge(Person p) {
	const unsigned CURRENT_YEAR = getCurrentYear();
	return CURRENT_YEAR - p.birthDate.year;
}

float calcMean(float sumOfAttribute, unsigned numOfPeople) {
	/* Média do atributo de um número de pessoas */
	return (float) sumOfAttribute / numOfPeople;
}

void storeStatsOfPerson(Person p,
						MenStatistics *menStats,
						WomenStatistics *womenStats,
						GenderNotInformedStatistics *outroStats) {

	switch (p.gender) {
		case 1:
			menStats->quantity++;
			menStats->sumOfHeights += p.height;
			menStats->sumOfWeights += p.weight;
			menStats->sumOfAges += calcAge(p);
			break;
		case 2:
			womenStats->quantity++;
			womenStats->sumOfHeights += p.height;
			womenStats->sumOfWeights += p.weight;
			womenStats->sumOfAges += calcAge(p);
			break;
		case 0:
			outroStats->quantity++;
			outroStats->sumOfHeights += p.height;
			outroStats->sumOfWeights += p.weight;
			outroStats->sumOfAges += calcAge(p);
			break;
		default:
			puts("Error: gender value invalid!");
	}
}

void quantifyPeopleByAgeAndObesity(Person p, QuantityOfPeopleByAge *peopleByAge) {
	unsigned age = calcAge(p);

	if (age >= 18 && age <= 39) {
		peopleByAge->peopleBetween18And39++;
		
		if (strcmp(p.bmiClass, "Obesidade") == 0)
			peopleByAge->peopleBetween18And39HaveObesity++;
		else if (strcmp(p.bmiClass, "Obesidade Grave") == 0)
			peopleByAge->peopleBetween18And39HaveSevereObesity++;
	} else if (age >= 40 && age <= 59) {
		peopleByAge->peopleBetween40And59++;

		if (strcmp(p.bmiClass, "Obesidade") == 0)
			peopleByAge->peopleBetween40And59HaveObesity++;
		else if (strcmp(p.bmiClass, "Obesidade Grave") == 0)
			peopleByAge->peopleBetween40And59HaveSevereObesity++;
	} else if (age > 60) {
		peopleByAge->peopleMoreThan60++;

		if (strcmp(p.bmiClass, "Obesidade") == 0)
			peopleByAge->peopleMoreThan60HaveObesity++;
		else if (strcmp(p.bmiClass, "Obesidade Grave") == 0)
			peopleByAge->peopleMoreThan60HaveSevereObesity++;
	}
}

float calcBmi(Person p) {
	return p.weight / (p.height * p.height);
}

float quantifyInPorcentage(unsigned numOfCases, unsigned numOfPeople) {
	return ((float)numOfCases /  numOfPeople) * 100;
}
/*
 * Features End
 */


int main() {
	const unsigned CURRENT_YEAR = getCurrentYear();
	Person people[800];
	int numOfPeople = 0;

	// Usado para guardar alguns dados relevantes
	unsigned sumOfAllAges = 0;
	MenStatistics menStats = {0, 0, 0, 0};
	WomenStatistics womenStats = {0, 0, 0, 0};
	GenderNotInformedStatistics outroStats = {0, 0, 0, 0};
	QuantityOfPeopleByAge peopleByAge = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	/* Section for registration */
	while (1) {
		showHeader();
		puts("Cadastro de usuario");
		printf("Digite o cpf: ");
		scanf(" %u", &people[numOfPeople].id);

		printf("Digite sua data de nascimento [dd mm aaaa]: ");
		scanf(" %u %u %u",
			   &people[numOfPeople].birthDate.day,
			   &people[numOfPeople].birthDate.month,
			   &people[numOfPeople].birthDate.year);

		int sex;
		while (1) {
			printf("Informe o sexo (0-não informado, 1-masculino, 2-feminino): ");
			scanf(" %d", &sex);
			if (sex == 0 || sex == 1 || sex == 2) {
				people[numOfPeople].gender = sex;
				break;
			}
			puts("Erro: informe uma das opcoes");
		}

		printf("Informe o seu peso: ");
		scanf(" %f", &people[numOfPeople].weight);

		printf("Por ultimo, informe sua altura: ");
		scanf(" %f", &people[numOfPeople].height);

		// Guardar alguns dados para efetuar os cálculos
		sumOfAllAges += calcAge(people[numOfPeople]);
		storeStatsOfPerson(people[numOfPeople], &menStats, &womenStats, &outroStats);
		people[numOfPeople].bmiValue = calcBmi(people[numOfPeople]);
		strcpy(people[numOfPeople].bmiClass, classifyBmi(people[numOfPeople].bmiValue));
		quantifyPeopleByAgeAndObesity(people[numOfPeople], &peopleByAge);

		numOfPeople++;

		char op;
		printf("Cadastrar mais uma pessoa? [S/N]: ");
		scanf(" %c", &op);
		op = toupper(op);
		
		if (op == 'N' || op == '0')
			break;
	}
	/* End registration */
	
	/* Section for menu */
	int option;

	do {
		clearScreen();
		puts(" ---------- Menu de opcoes ----------");
		puts("1 - Media das idades de todos");
		puts("2 - Media das idades por genero");
		puts("3 - Media das alturas por genero");
		puts("4 - Media dos pesos por genero");
		puts("5 - Quantidade e percentual por idade");
		puts("6 - Quantidade e percentual por idade e que tem obesidade");
		puts("7 - Quantidade e percentual por idade e que tem obesidade severa");
		puts("8 - Mostrar todos");
		puts("0 - sair");
		printf("Sua escolha >> ");
		scanf(" %u", &option);

		puts(" --------------------------------------------------------- ");

		switch (option) {
			case 1:
				printf("Media das idades de todas as pessoas %.2f\n", 
					calcMean(sumOfAllAges, numOfPeople));
				break;
			case 2:
				printf("Media das idades das mulheres %.2f\n",
					calcMean(womenStats.sumOfAges, womenStats.quantity));
				printf("Media das idades dos homens %.2f\n", 
					calcMean(menStats.sumOfAges, menStats.quantity));
				printf("Media das idades dos que não informaram o sexo %.2f\n", 
					calcMean(outroStats.sumOfAges, outroStats.quantity));
				break;
			case 3:
				printf("Media das alturas das mulheres %.2f\n",
					calcMean(womenStats.sumOfHeights, womenStats.quantity));
				printf("Media das alturas dos homens %.2f\n",
					calcMean(menStats.sumOfHeights, menStats.quantity));
				printf("Media das alturas dos que não informaram o sexo %.2f\n",
					calcMean(outroStats.sumOfHeights, outroStats.quantity));
				break;
			case 4:
				printf("Media dos pesos das mulheres %.2f\n",
					calcMean(womenStats.sumOfWeights, womenStats.quantity));
				printf("Media dos pesos dos homens %.2f\n",
					calcMean(menStats.sumOfWeights, menStats.quantity));
				printf("Media dos pesos dos que não informaram o sexo %.2f\n",
					calcMean(outroStats.sumOfWeights, outroStats.quantity));
				break;
			case 5:
				printf("Quantidade e percentual das pessoas com idade entre 18 e 39 anos %u - %.2f%%\n",
					peopleByAge.peopleBetween18And39,
					quantifyInPorcentage(peopleByAge.peopleBetween18And39, numOfPeople));

				printf("Quantidade e percentual das pessoas com idade entre 40 e 59 anos %u - %.2f%%\n",
					peopleByAge.peopleBetween40And59,
					quantifyInPorcentage(peopleByAge.peopleBetween40And59, numOfPeople));

				printf("Quantidade e percentual das pessoas com idade mais de 60 anos %u - %.2f%%\n",
					peopleByAge.peopleMoreThan60,
					quantifyInPorcentage(peopleByAge.peopleMoreThan60, numOfPeople));
				break;
			case 6:
				printf("Quantidade e percentual das pessoas com idade entre 18 e 39 anos com obesidade %u - %.2f%%\n",
					peopleByAge.peopleBetween18And39HaveObesity,
					quantifyInPorcentage(peopleByAge.peopleBetween18And39HaveObesity, numOfPeople));

				printf("Quantidade e percentual das pessoas com idade entre 40 e 59 anos com obesidade %u - %.2f%%\n",
					peopleByAge.peopleBetween40And59HaveObesity,
					quantifyInPorcentage(peopleByAge.peopleBetween40And59HaveObesity, numOfPeople));

				printf("Quantidade e percentual das pessoas com idade mais de 60 anos com obesidade %u - %.2f%%\n",
					peopleByAge.peopleMoreThan60HaveObesity,
					quantifyInPorcentage(peopleByAge.peopleMoreThan60HaveObesity, numOfPeople));
				break;
			case 7:
				printf("Quantidade e percentual das pessoas com idade entre 18 e 39 anos com obesidade severa %u - %.2f%%\n",
					peopleByAge.peopleBetween18And39HaveSevereObesity,
					quantifyInPorcentage(peopleByAge.peopleBetween18And39HaveSevereObesity, numOfPeople));

				printf("Quantidade e percentual das pessoas com idade entre 40 e 59 anos com obesidade severa %u - %.2f%%\n",
					peopleByAge.peopleBetween40And59HaveSevereObesity,
					quantifyInPorcentage(peopleByAge.peopleBetween40And59HaveSevereObesity, numOfPeople));

				printf("Quantidade e percentual das pessoas com idade mais de 60 anos com obesidade severa %u - %.2f%%\n",
					peopleByAge.peopleMoreThan60HaveSevereObesity,
					quantifyInPorcentage(peopleByAge.peopleMoreThan60HaveSevereObesity, numOfPeople));
				break;
			case 8:
				for (int i = 0; i < numOfPeople; i++) {
					presentPerson(people[i]);
					puts(" ------------------------------ ");
				}
				break;
			case 0:
				puts("tchau!");
				break;
			default:
				puts("Opcao invalida");
		}
		/* If the option was other than 0 it's gonna wait for a user response
		   until cleaning the screen */
		if (option != 0) {
			setbuf(stdin, NULL);
			puts("Digite alguma tecla...");
			getchar();
		}
	} while (option != 0);
	/* End menu */

	return 0;
}
