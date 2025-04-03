#include "who.h"
#include "sum.h"
#include "x.h"
#include "best.h"
#include "new.h"
#include "avv.h"
#include "gender.h"
#include "yeah.h"
#include "over.h"
#include "del.h"

int main(){
    char bukva;
    printf("What do you want? :");
    scanf(" %c", &bukva);
     switch (bukva){

     case 'a':
          avv();
          break;
     case 's':
         sum();
         break;
     case 'w':
         who();
         break;
     case 'x':
         x1();
         break;
     case 'b':
         best();
         break;
     case 'n':
          news();
          break;
     case 'g':
          gender();
          break;
     case 'y':
          yeah();
          break;
     case 'o':
          over();
          break;   
     case 'd':
          del();
          break;   
     default:
     printf("Try again \n");
     return main();
     }

return 0;
}