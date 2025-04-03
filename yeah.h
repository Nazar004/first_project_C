#include <stdio.h>
#include <string.h>

int yeah(){

    int kolvo=0;
    char name[100];
    char gender;
    char rok[100];
    char rajon[100];
    float testy[6];
    float najleps=0;
    int records=0;
    int c;
    char kopyname[100];
    int rok2;
    char rok3[100];

    FILE*file=fopen("studenti.csv", "r");

    printf("Write yeah of bithday : ");
    scanf("%d", &rok2);
    while (!feof(file)) {
        fscanf(file,"%[^;];%c;%[0-9/];%[^;];%f;%f;%f;%f;%f;%f",name,&gender,rok,rajon,&testy[0],&testy[1],&testy[2],&testy[3],&testy[4],&testy[5]);
        if ( ( ((int)rok[0]-48) > rok2 / 1000 ) || ((((int)rok[0]-48) == rok2 / 1000) && (((int)rok[1]-48) > rok2 / 100 % 10 )) || ((((int)rok[0]-48) == rok2 / 1000) && (((int)rok[1]-48) == rok2 / 100 % 10) && (((int)rok[2]-48) > rok2 / 10 % 10 )) || ((((int)rok[0]-48) == rok2 / 1000) && (((int)rok[1]-48) == rok2 / 100 % 10) && (((int)rok[2]-48) == rok2 / 10 % 10 ) && (((int)rok[3]-48) > rok2 & 10)) ) {
            for(int i=0;i<6;i++){
                if (najleps<testy[i]){
                    najleps=testy[i];
                    c=i+1;
                    memcpy(rok3, rok, 100);
                    memcpy(kopyname, name, 100);
                }
            }
        }
    }
    printf("Student : %s", kopyname);
    printf("\nnar. :%c%c%c%c ", rok3[0], rok3[1], rok3[2], rok3[3]);
    printf("\nNajlepsi test :%.2f\n", najleps);
    printf("Cislo testu : %d\n", c);
    fclose(file);
    return main();
}