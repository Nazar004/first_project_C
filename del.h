#include <stdio.h>
int del() {
    char name[100];
    char gender;
    char rok[100];
    char rajon[100];
    float testy[6];
    char surname[100];
    char c;
    int result;
    char delname;

    FILE*file=fopen("studenti.csv", "r");

    printf("Write surname of student that you want to delete : ");
    scanf("\n%[^\n]", surname); 

    FILE*file2=fopen("abcd.csv", "w");

    while (!feof(file)) {
        fscanf(file,"%[^;];%c;%[0-9/];%[^;];%f;%f;%f;%f;%f;%f",name,&gender,rok,rajon,&testy[0],&testy[1],&testy[2],&testy[3],&testy[4],&testy[5]);
        int q=0;
        int w = 0;
        char e[250];
        while (name[w] != '\0'){
            if (name[w] == ' '){
                q = w;
            }
            w++;
        }
        w = 0;
        while (name[q + 1] != '\0'){
            e[w] = name[q + 1];
            q++, w++;
        }
        e[w] = '\0';
        result=strcmp(e, surname);
        if (result!=0){
        fprintf(file2,"%s;%c;%s;%s;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", name,gender,rok,rajon,testy[0],testy[1],testy[2],testy[3],testy[4],testy[5]);
        } else if (result==0){
            delname=name;
        }
    }
    fclose(file);
    fclose(file2);

    file=fopen("studenti.csv", "w");
    file2=fopen("abcd.csv", "r");

    c = fgetc(file2);
    while (c != EOF){ 
        fputc(c, file);
        c = fgetc(file2);
    }
    printf("student \"%s\" bol vymazany", surname);
    fclose(file);
    fclose(file2);
    remove("abcd.csv");
    printf("\n");

return main();
}