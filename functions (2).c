#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fun.h"


int search(const char *input_name, char *max_word){
    char string[512], *word;
    int max=0, ord=0, lenght;
    FILE* input;
    input = fopen(input_name, "r");
    word = (char*)malloc(512*sizeof(char));
    free(word);
    if(!input){
       return -1;
    }
    else{
       while(fgets(string, 512, input)){
          for(unsigned int i=0; i<strlen(string); i++){
              if(string[i] >= 'A' && string[i] <= 'Z' && i != strlen(string)-1){
                  word[ord]=string[i];
                  ord++;
              }
              else{
                  if(string[i] >= 'A' && string[i] <= 'Z' && i == strlen(string)-1){
                     word[ord]=string[i];
                  }
                  if(word[ord]='A'&& ord > max){
                          max=ord;
                          for(int j=0; j<max; j++){
                              max_word[j]=word[j];
                          }
                  }

                  ord=0;
                  free(word);
                  word = (char*)malloc(512*sizeof(char));
              }
          }
       }
    }
    free(word);
    fclose(input);
    return max;
}








int autotest_1(void){
    int k;
    char word[512];
    k=search("test_1.txt", word);
    if(word[0]=='S' && word[1]=='D' && word[2]=='E' && word[3]=='W' && word[4]=='T' && word[5]=='A'){
        return k;
    }
    else{
        return 1;
    }
}

int autotest_2(void){
    int k;
    char word[512];
    k=search("myth.txt", word);
    if(k == 0){
        return 0;
    }
    else{
        return 1;
    }
}




