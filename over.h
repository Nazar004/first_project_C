#include <stdio.h>
#include <string.h>

int over(){
    
    char name[100];
    char gender;
    char rok[100];
    char rajon[100];
    float testy[100];
    float ocenka=1;
    char kopyname;
    int kolvo=0;
    int c;
    int n;
    int cislotesta;

    FILE*file=fopen("studenti.csv", "r");

    if (file == NULL) {
        printf("Its clear");
    } else {
    printf("Write ocenky : ");
    scanf(" %f", &ocenka);

        while (!feof(file)){
            fscanf(file,"%[^;];%c;%[0-9/];%[^;];%f;%f;%f;%f;%f;%f",name,&gender,rok,rajon,&testy[0],&testy[1],&testy[2],&testy[3],&testy[4],&testy[5]);
            c=0;
            printf("%s - ", name);
            for (int i=0;i<6; i++){
                if (ocenka<testy[i]){
                    c=c+1;
                }
            }
            printf("%d ",c);
            if(c==1){
                printf("test, ");
            }
            else if(c<4){
                printf("testy, ");
            }
            else if(c>=4){
                printf("testov, ");
            }
            n=0;
            for (int i=0;i<6; i++){
                if (ocenka<testy[i]){
                    n=i+1;
                    printf("%d",n);
                    printf("( %.2f ) ",testy[i]);
                }
            }
        }
        printf("\n");
    }
    fclose(file);
return main();
}