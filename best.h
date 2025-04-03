#include <stdio.h>
#include <string.h>

int best(){
    char name[100];
    char gender;
    char rok[100];
    char rajon[100];
    float testy[6];
    float najleps=0;
    int c;
    char kopyname[100];

    FILE*file=fopen("studenti.csv", "r");

    while (!feof(file)) {
        fscanf(file,"%[^;];%c;%[0-9/];%[^;];%f;%f;%f;%f;%f;%f",name,&gender,rok,rajon,&testy[0],&testy[1],&testy[2],&testy[3],&testy[4],&testy[5]);
        for(int i=0;i<6;i++){
            if (najleps<testy[i]){
                najleps=testy[i];
                c=i+1;
                memcpy(kopyname, name, 100);
            }
        }
    }
    printf("\nNajlepsi test :%.2f\n", najleps);
    printf("Student : %s", kopyname);
    printf("\nCislo testu : %d\n", c);
    fclose(file);
return main();
}