/*
  ***************************************************************************************************

    RNA Hash Example
   
    @date: 29. September 2022.
    
    Copyright (c) 2022 Gavrilo Palalic 
  
  ***************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "rna.h" // external RNA hash implementation

int main(int argc, char* argv[]){ 
    
   char * test_encode = "The quick brown fox jumps over the lazy dog.";
   char *encoded = RNA(test_encode);
   //writing RNA hash to file.
   FILE *a = fopen("key.key","wb");
   fwrite(encoded,sizeof(char),BLOCK_SIZE,a);
   fclose(a);
   printf("\n**** hash successfully created. ****");

}
