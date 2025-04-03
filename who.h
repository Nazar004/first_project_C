#include <stdio.h>
#include <string.h>

int who(){

    char surname[100] = {0};
    char name[100];
    char gender;
    char rok[100];
    char rajon[100];
    float testy[6];

    FILE*file=fopen("studenti.csv", "r");

    if (file == NULL) {
        printf("Its clear");
    } else {
        printf("Write surname of student :");
        scanf("%s", surname); 
        while (!feof(file)) {
            fscanf(file,"%[^;];%c;%[0-9/];%[^;];%f;%f;%f;%f;%f;%f",name,&gender,rok,rajon,&testy[0],&testy[1],&testy[2],&testy[3],&testy[4],&testy[5]);

            int q;
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
            if (strcmp(e, surname)){
                continue;
            }
            printf(" %s\n", name);
            if (gender=='m'){
                printf(" muz ");
            } else {
                printf(" zena ");
            }
            printf("rok:%c%c%c%c", rok[0],rok[1],rok[2],rok[3]);
            printf("\nrajon: %s \n", rajon);
            printf("\n");
            printf("\nVysledky testov:%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", testy[0],testy[1],testy[2],testy[3],testy[4],testy[5]);
            printf("\n");

            int x=1;
            while(x!=0) {
                x=0;
                float test2=0;
                for(int i=0;i<5;i++){
                    if (testy[i]<testy[i+1]){
                        test2=testy[i];
                        testy[i]=testy[i+1];
                        testy[i+1]=test2;
                        x++;
                    }
                }
            }
            float najleps;
            float najhorsi;
            float priemerni;

            najhorsi=testy[5];
            najleps=testy[0];
            priemerni =(testy[0]+testy[1]+testy[2]+testy[3]+testy[4]+testy[5])/6;

            printf("\nNajlepsi test :%.2f\n", najleps);
            printf("Najhorsi test:%.2f\n", najhorsi);
            printf("Priemerni test:%.2f\n", priemerni);
        }
    }
    fclose(file);
    printf("\n");
    return main();
}