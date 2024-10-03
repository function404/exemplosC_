#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[20];
    char cpf[11];
    int age;
};

void fillData(struct Person *people, int amount) {
    for (int i = 0; i < amount; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: ");
        scanf(" %19[^\n]", people[i].name); 
        printf("CPF: ");
        scanf(" %10s", people[i].cpf); 
        printf("Age: ");
        scanf("%d", &people[i].age);
    }
}

void printData(struct Person *people, int amount) {
    for (int i = 0; i < amount; i++) {
        printf("\nPerson %d:\n", i + 1);
        printf("Name: %s\n", people[i].name);
        printf("CPF: %s\n", people[i].cpf);
        printf("Age: %d\n", people[i].age);
    }
}

int main() {
    struct Person *people;

    int amount = 5;
    people = (struct Person*) malloc(amount * sizeof(struct Person));

    if (people == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    fillData(people, amount);

    printData(people, amount);

    free(people);

    return 0;
}
