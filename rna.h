/*
  ***************************************************************************************************

    RNA Hash implementation

    RNA hash is a cryptographic hash made for signature checking.
    RNA hash cannot be reversed, which means , once created, cannot be replicated or decyphered, ever.

    @ author: nitrodegen
    @ date: 29. September 2022.

    Copyright (c) 2022 Gavrilo Palalic

  ***************************************************************************************************
*/
#ifndef RNA_H
#define RNA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

#define BLOCK_SIZE 129
#define IRNA_SIZE 129

typedef struct {

  int value;
  unsigned int previous;
  unsigned int  stack_cookie;

}c_block;

int * initialize_irna(){

  FILE *a = fopen("irna.data","rb");
  fseek(a,0,SEEK_END);
  long size = ftell(a);
  fseek(a,0,SEEK_SET);
  int *content = (int*)malloc(size);
  fread(content,sizeof(int),size,a);
  fclose(a);

  int  * mem = (int*)malloc(IRNA_SIZE);
  memset((void*)mem,0,IRNA_SIZE);
  srand(time(NULL));
  for(int i = 0; i< IRNA_SIZE;i++){
      mem[i]= content[i];
  }
  return mem;

}

char* RNA(char *input){
  
  //padding the input string to match 128.
  char *padded =(char*)malloc(BLOCK_SIZE);
  for(int i = 0; i<BLOCK_SIZE;i++){
    if(strlen(input) >=BLOCK_SIZE){
        padded[i] = input[i]; 
    }
    else{
        if(i >=strlen(input)){
            padded[i] = input[0];
        }else{
          padded[i] = input[i];
        }
    }
  }
  //initializing Informational RNA.
  int  *irna = initialize_irna();
  char *result_string = (char*)malloc(BLOCK_SIZE);
  //Calculating RNA C blocks and adding results to string.
  int pad=0; 
  for(int i = 1;i<IRNA_SIZE;i++){
      c_block* blck = (c_block*)malloc(sizeof(c_block));
      int prev = irna[i-1];
      int addr = irna[i];
      blck->value= irna[i];
      blck->previous=(((((int)prev >>4)) >> 8 )  & input[i])%256;
      blck->stack_cookie=(((int)addr  |prev & (addr>>2))%256);
      int calculation = (int)((((blck->value ^ input[i])*blck->previous & input[i]))* (sqrt((double)blck->stack_cookie) * input[2]))%256;
      //printf("\n%d",calculation);
      char res = (char)calculation;
      padded[pad] = res;
      pad++;
 }
  //Converting string from big-endian to little-endian.
  pad=0;
  for(int i = BLOCK_SIZE;i>=0;i--){
    result_string[pad]=  padded[i];
    pad++;
  }
  free(padded);
  return result_string;
  
}

#endif
