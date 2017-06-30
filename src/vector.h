#include <stdlib.h>
#include <math.h>

#ifndef VECTOR_H_
#define VECTOR_H_
typedef struct vector_int{
    int *vec;
    size_t size,ptr;
}vector_int;

//it creates a vector of length len and returns a pointer
vector_int *make_vector_int(size_t len);

//it copies the data of a of size len to a vector and returns its pointer
vector_int  *init_vector_int(int *,size_t);

//resizes the given vector to the given size one will
//loose data if new size is smaller than previous one
void resize_vector_int(vector_int *,size_t);

//appends a given integer to the vector
void pushback_vector_int(vector_int *,int);

//prints the vector upto total size
void print_vector_int(vector_int *);

//deltes the vector and frees memory
void delete_vector_int(vector_int *);
#endif
