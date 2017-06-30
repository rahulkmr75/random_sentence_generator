#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/*****************************************************************************
contains necessary fucntion declaration and other headers
******************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//stores the content of a directory
typedef struct dir_content{
    size_t num;	//stores number of files
    char **file_names;	//name of files
}dir_content;

//Stores various sentences in an array
typedef struct book{
    size_t num;
    char **lines;
}book;

typedef struct library{
    size_t num;
    book **books;
}library;

//from the directory ../texts get the content names only
void get_texts_name(dir_content *);

//load the text file after splitting into various sentences
void load_texts(library *,dir_content *);

//load the book i.e one text file from the given path
book *load_book(char *);

//print the entire list of books of sentences
void print_library(library *);

//print the entire list of sentences in a book
void print_book(book *);

//delete the library
void delete_library(library *);

//delete the book
void delete_book(book *);

//delete the directory content
void delete_dir_content(dir_content *);
#endif
