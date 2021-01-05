#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "txtfindh.h"
int getlen(char s[]){
    int len = 0;
    while(s[len]!='\0'){
        len++;
    }
    return len;
}
int getword(char *w){
   char c;
   int i=0;
   while(scanf("%c",&c)==1&&i<WORD){
       if(c==EOF){
           break;
       }
       if(c!='\n'&&c!='\t'&&c!=' '){
           w[i] = c;
           i++;
       }
       else {
           w[i]='\0';
           return ++i;
       }
   }
   return 0;
}

int getlinef(char *s){
   char c;
   int i=0;
   while(scanf("%c",&c)==1&&i<LINE){
       if(c==EOF){
           break;
       }
       if(c!='\n'){
           s[i] = c;
           i++;
       }
       else {
           s[i]='\0';
           return ++i;
       }
   }
   return 0;
}

int substring(char * str1, char * str2){
    int ls = getlen(str1), lw = getlen(str2) ;
    if(ls<lw) return 0;
    int i=0,j;
    for(;i<ls-lw;++i){
        for(j=0;j<lw;++j){
            if(str1[i+j]!=str2[j]){
                break;
            }
        }
        if(j==lw) return 1;
    }
    return 0;
}

int similar(char *s, char *t,int n){
    int ls=getlen(s), lt=getlen(t);
    if(lt>ls) return 0;
    if(n<0) return 0;
    int i=0,j=0;
    while(i<ls){
        if(s[i]==t[j]){
            ++i;
            if(j<lt){
                ++j;
            }
        }
        else{
            ++i;
            --n;
        }
    }
    if(n<0) return 0;
    return 1;
}

void print_lines(char * str){
    char s[LINE];
    while(getlinef(s)!=EOF&&getlen(s) != 0){
        if(substring(s,str)){
            printf("%s\n",s);
        }
        memset(s,0,LINE);
    }
}
void print_similar_words(char * str){
    char w[WORD];
    while(getword(w)!=EOF&& getlen(w) != 0){
        if(similar(w,str,1))
            printf("%s\n",w);
        memset(w,0,WORD);
    }
}