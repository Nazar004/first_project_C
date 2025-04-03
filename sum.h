#include <stdio.h>
#include <string.h>

int sum(){

    char size;
    char name[109];
    char gender;
    char rok[100];
    char rajon[100];
    char testy[100];

    FILE*file=fopen("studenti.csv", "r");

    int c = fgetc(file);
    if (c == EOF) {
        printf("file is empty\n");
        printf("If you want to add student write 'n'");
    } else {
        ungetc(c, file);
    }
    while (!feof(file)){
        fscanf(file,"%[^;];%c;%[0-9/];%[^;];%[0-9.;]", name,&gender,rok,rajon,testy);
        printf("%s", name);
        if (gender=='m'){
            printf(" gender:muz ");
        } else {
            printf(" gender:zena ");
        }
        printf(" rok:%c%c%c%c", rok[0], rok[1], rok[2], rok[3]);
        printf(" rajon:%s", rajon);
        printf("\n Vysledky testov:%s", testy);

    } 
    fclose(file);
    printf("\n");
    return main();
}