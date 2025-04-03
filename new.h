#include <stdio.h>
#include <string.h>

int news(){
    char name1[100];
    char gender;
    int rok[100];
    char rajon1[100];
    float test[100];

    FILE*file=fopen("studenti.csv", "a");   
    printf("Write name and surname :\n");
    scanf(" %[^\n]", name1);
    printf("Write YYYY/MM/DD of bithday :");
    scanf(" %d/%d/%d", &rok[0],&rok[1],&rok[2]);
    printf("\nWrite gender :");
    scanf(" %c", &gender);
    printf("\nWrite region :");
    scanf("%s", rajon1);
    printf("\nWrite results of test:");
    scanf("%f;%f;%f;%f;%f;%f", &test[0], &test[1],&test[2],&test[3],&test[4],&test[5]);
    fprintf(file,"\n%s;%c;%d/%d/%d;%s;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", name1,gender,rok[0],rok[1],rok[2],rajon1,test[0],test[1],test[2],test[3],test[4],test[5]);
    
    fclose(file);

    return main();
}