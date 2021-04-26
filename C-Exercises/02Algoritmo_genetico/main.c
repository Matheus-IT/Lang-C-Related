#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char weapon[4];     //Blade="100"; Magic="010"; not_use="001";
    char transform[4];  //yes="100"; no="010";
    char age[4];        //young="100"; adult="010"; old="001"; 
    char class[4];      //hero="100"; villain="010";
    float fitness;      //fitness value for each guy
} Character;

int qtt; //Number of heros || villains

void * initialize_population() {
    Character *charac;
    qtt = 20;
    int n = NULL;

    srand(time(NULL));
    charac = (Character *)(malloc(qtt * sizeof(Character)));
    for (int i = 0; i < qtt; i++) {
        n = rand()%3; //Generate a number between 0 and 2
        //Chose weapon:
        switch (n) {
        case 0:
            strcpy(charac[i].weapon, "100"); //Blade
            break;
        case 1:
            strcpy(charac[i].weapon, "010"); //Magic
            break;
        case 2:
            strcpy(charac[i].weapon, "001"); //not_use
            break;
        default:
            break;
        }
        n = rand()%2;
        //Chose transform:
        if (n == 1) {
            strcpy(charac[i].transform, "100"); //yes
        } else {
            strcpy(charac[i].transform, "010"); //no
        }
        n = rand()%3;
        //Chose age:
        switch (n) {
        case 0:
            strcpy(charac[i].age, "100"); //young
            break;
        case 1:
            strcpy(charac[i].age, "010"); //adult
            break;
        case 2:
            strcpy(charac[i].age, "001"); //old
            break;
        default:
            break;
        }
        n = rand()%2;
        //Chose class:
        if (n == 1) {
            strcpy(charac[i].class, "100"); //hero
        } else {
            strcpy(charac[i].class, "010"); //villain
        }
    }
    return charac;
}

void show(Character *charac) {
    for (int i = 0; i < qtt; i++) {
        printf(" %d %s%s%s%s Fitness %.2f \n", i, charac[i].weapon, charac[i].transform, charac[i].age, charac[i].class, charac[i].fitness);
    }
}

void evaluate_each_individual(Character *charac) {
    float fit;

    //This "for" will assign the fitness for each hero || villains:
    for (int i = 0; i < qtt; i++) {
        fit = 0;
        //Chose weapon:
        if (strcmp(charac[i].weapon, "100")) {        //Blade
            fit += 0.20;
        } else if (strcmp(charac[i].weapon, "010")) { //Magic
            fit += 0.25;
        } else {                                //not_use
            fit += 0.10;
        }
        //Chose transform:
        if (strcmp(charac[i].transform, "100")) {    //yes
            fit += 0.25;
        } else {                               //not
            fit += 0.10;
        }
        //Chose age:
        if (strcmp(charac[i].age, "100")) {           //young
            fit += 0.20;
        } else if (strcmp(charac[i].age, "010")) {    //adult
            fit += 0.25;
        } else {                                //old
            fit += 0.10;
        }
        //Chose class:
        if (strcmp(charac[i].class, "100")) {    //hero
            fit += 0.25;
        } else {                           //villain
            fit += 0.15;
        }
        charac[i].fitness = fit;
    }
}

void organize(Character *charac) {
    Character aux;

    for (int i = 1; i < qtt; i++) {
        for (int j = 0; j < i; j++) {
            if (charac[i].fitness < charac[j].fitness) {
                aux = charac[i];
                charac[i] = charac[j];
                charac[j] = aux;
            }
        }
    }
}

void * select_individuals(Character *charac) {
    Character *best_charac = NULL;

    //Select the 10 best characters, based on the tournament selection technique: 
    best_charac = (Character *)(malloc(10 * sizeof(Character)));
    for (int i = 0, a = 0, b = 1; b < qtt; i++, a += 2, b += 2) {
        if (charac[a].fitness > charac[b].fitness) {
            best_charac[i] = charac[a];
        } else {
            best_charac[i] = charac[b];
        }
    }
    qtt -= 10; //Now we just have 10 guys
    charac = (Character *)(realloc(charac, qtt * sizeof(Character)));
    return best_charac;
}

void cross_over(Character *charac) {
    Character *res;

    res = (Character *)(malloc(9 * sizeof(Character)));
    //Will "breed" nine new guys:
    for (int i = 0, a = 0, b = 1; b < qtt; i++, a++, b++) {
        strcpy(res[i].weapon, charac[a].weapon);
        strcpy(res[i].transform, charac[b].transform);
        strcpy(res[i].age, charac[a].age);
        strcpy(res[i].class, charac[b].class);
    }
    qtt += 9; //We have nine new guys from the new generation
    charac = (Character *)(realloc(charac, qtt * sizeof(Character)));
    //Now we assign the result to charac:
    for (int a = 10, b = 0; a < qtt; a++, b++) {
        charac[a] = res[b];
    }
    //Recalculate the fitness of the new guys:
    evaluate_each_individual(charac);
}

void mutation(Character *charac) {
    Character res;

    //Now we mutate using the first and the last one:
    strcpy(res.weapon, charac[qtt-1].weapon);
    strcpy(res.transform, charac[0].transform);
    strcpy(res.age, charac[qtt-1].age);
    strcpy(res.class, charac[0].class);
    //Assign the new character:
    qtt += 1;
    charac = (Character *)(realloc(charac, qtt * sizeof(Character)));
    charac[qtt-1] = res;
    //Recalculate the fitness of the new guy:
    evaluate_each_individual(charac);
}

int main() {
    Character *charac = NULL;
    int generation = 0;

    charac = initialize_population();
    evaluate_each_individual(charac); //Assign fitness
    organize(charac); //Ascending order
    generation = 1;
    printf("%dth Generation:\n", generation);
    show(charac);
    while(generation < 10) {
        charac = select_individuals(charac); //Select the 10 best characters
        cross_over(charac); //Will "breed" nine new guys
        mutation(charac); //One new character from mutation
        organize(charac);
        generation++;
        printf("%dth Generation \n", generation);
        show(charac);
    }
    free(charac);
    return 0;
}
