#ifndef TEXTFIND
#define TEXTFIND
#include <stdio.h>
#include <string.h>
#define WORD 30
#define LINE 256
int getlinef(char *s);
int getword(char *w);
int substring(char * str1 , char * str2);
int similar(char *s,char *t , int n);
void print_lines(char * str);
void print_similar_words(char * str);
#endif 