#include "functions.h"
#include "vector.h"

void get_texts_name(dir_content *dc){

    DIR *d;
    struct dirent *dir;
    
    //contains all the texts in .txt format
    d = opendir("../texts");

    int num = 0;
    if(d){

	//find number of files; it will also include . and ..
        while((dir = readdir(d)) != NULL){
            num++;
        }
    
        //make space for file names, -2 is done to remove . and .. 
        dc->file_names = malloc(sizeof(char *) * (num-2));
        dc->num = num-2;
 
        int tr = 0;

        //copy the file to the structure 
        seekdir(d,0);
        while((dir = readdir(d)) != NULL){
            if(strcmp(dir->d_name,".") != 0 && strcmp(dir->d_name,"..") !=0 ){
                *(dc->file_names+tr) = malloc(sizeof(char)*(strlen(dir->d_name)+1));
                strcpy(*(dc->file_names+tr++) , dir->d_name);
            }
        }
    }
    closedir(d);
}


void load_texts(library *lib , dir_content *dc){

    lib->num = dc->num;	//number of books in library
    lib->books = malloc(sizeof(book *)*lib->num);

    size_t i = 0;
    for(;i < lib->num;i++){

        char temp[strlen(dc->file_names[i])+10];
        //10 is to incorporate length of "../texts/" and '\0' as well

        //make pathname to the book
        sprintf(temp,"../texts/%s",dc->file_names[i]);
        //temp[strlen(dc->file_names[i])+9]= '\0'; 
        //printf(temp);


        //load books
        lib->books[i] = load_book(temp);
    }
}

book *load_book(char *book_path){
     
    FILE *fp = fopen(book_path,"r");
    book *b = malloc(sizeof(book));

    if(fp){
        //count number of sentences
        size_t n_sentence = 0;

        //a vector to keep track of full stops 
        vector_int *v = make_vector_int(1);
        pushback_vector_int(v,-1);	//the first full stop at -1
          
        int ch;
        while((ch = fgetc(fp)) != EOF ){
            if(ch == '.'){
                n_sentence++;
                pushback_vector_int(v,ftell(fp));
            }
        }

        //set the pointer to start
        fseek(fp,0,SEEK_SET);
        if(v->ptr == 1)printf("No complete sentence found in %s\n",book_path);
        else{
            b->num = n_sentence;
            b->lines = malloc(sizeof(char *)*b->num);
            
            size_t i=0;
            for(; i<n_sentence;i++){
                int nc = v->vec[i+1] - v->vec[i];
		*(b->lines + i) = malloc(sizeof(char) *(nc+1));

                for(int j=0; j < nc ; j++)b->lines[i][j] = fgetc(fp);
                b->lines[i][nc]='\0';
                    
           }
        }
        delete_vector_int(v);
    }
    fclose(fp);
    return b;
}

void print_book(book *bk){

    size_t i = 0;
    for (;i < bk->num;i++)printf("%s\n",bk->lines[i]);
}

void print_library(library *lib){

    size_t i = 0;
    for(;i < lib->num ; i++)print_book(lib->books[i]);
}

void delete_library(library *lib){
    for(size_t i = 0; i < lib->num;i++)
        delete_book(lib->books[i]);
    free(lib->books);
    free(lib);
}

void delete_book(book *bk){
    for(size_t i = 0; i< bk->num;i++)
        free(bk->lines[i]);
    free(bk->lines);
    free(bk);
}
void delete_dir_content(dir_content *dir){
    for(size_t i = 0; i < dir->num;i++)
        free(dir->file_names[i]);
    free(dir->file_names);
    free(dir);
}
