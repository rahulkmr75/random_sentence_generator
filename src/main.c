#include <stdio.h>
#include <math.h>
#include "functions.h"
#include <time.h>
#include <stdlib.h>

void main(int argc,char *argv[]){

    //the parameter given is number of sentences on wants to print
    if(argc !=2){
        printf("Usage: ./main <integer_value>");
    }
    else{
        //convert the argument to integer
        int num = atoi(argv[1]);
        srand(time(NULL));
       
        //the "../texts" directory contatins various .txt files 
        dir_content *dc = malloc(sizeof(dir_content));
        //get the file name from the ../texts directory
        get_texts_name(dc);

        library *lib = malloc(sizeof(library));;
        //load the data 
        load_texts(lib,dc);

        //choose a random number and print a random sentence corresponding to it
        for(int i =0 ;i<num;i++){
            int book_num = rand()%lib->num;
            int line_num = rand()%(lib->books[book_num])->num;
            printf("%s\n",(lib->books[book_num])->lines[line_num]);
        }
        
        //free the memory
        delete_library(lib);
        delete_dir_content(dc);
    }
    
}
