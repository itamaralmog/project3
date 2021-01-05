#include <stdio.h>
#include <string.h>
#include "txtfindh.h"
int main(){
    char w[WORD];
    getword(w);
    //printf("%s\n",w);
    char action;
    scanf("%c",&action);
    //printf("%c\n",action);
    if(action=='a'){
        print_lines(w);
    }
    if(action=='b'){
        print_similar_words(w);
    }
    if(action !='b' && action != 'a'){
        printf("not action.");
        return 1;
    }
    return 0;
}