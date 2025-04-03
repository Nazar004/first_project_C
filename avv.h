 #include <stdio.h>
 #include <stdlib.h>

int avv(){
    char najlepsistd[100];
    float priemerni;
    char name[100];
    char gender;
    char rok[100];
    char rajon[100];
    float testy[6];
    float najlepsie=0;
    int records=0;

    FILE*file=fopen("studenti.csv", "r");
    if (file == NULL) {
        printf("Its clear");
    } else{
        while (!feof(file)) {
            fscanf(file,"%[^;];%c;%[0-9/];%[^;];%f;%f;%f;%f;%f;%f",name,&gender,rok,rajon,&testy[0],&testy[1],&testy[2],&testy[3],&testy[4],&testy[5]);
            priemerni= (testy[0]+testy[1]+testy[2]+testy[3]+testy[4]+testy[5])/6;
            printf("%s - ", name);
            printf("%.2f", priemerni);
            if (priemerni>najlepsie){
                najlepsie=priemerni;
                memcpy(najlepsistd, name, 100);
            }
        }
        printf("\nNajlepsie : %s - ", najlepsistd);
        printf("%.2f\n", najlepsie);
    }
    fclose(file);

return main();
}