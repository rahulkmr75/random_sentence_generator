#include "vector.h"
#include <stdio.h>

//it creates a vector of length len and returns a pointer
vector_int *make_vector_int(size_t len){
    vector_int *v = malloc(sizeof(vector_int));
    v->size = len;
    v->vec = malloc(sizeof(int)*len);
    v->ptr = 0;
    return v;
}
//it copies the data of a of size len to a vector and returns its pointer
vector_int  *init_vector_int(int *a,size_t len){
    vector_int *v = malloc(sizeof(vector_int));

    v->size = len;
    v->vec = malloc(sizeof(int)*len);
    
    size_t i = 0;
    for(; i<len ; i++) *(v->vec+i) = *(a+i);
    v->ptr = len;
    return v;
}

void resize_vector_int(vector_int *v,size_t new_size){

    int *n_vec = malloc(sizeof(int)*new_size);

    size_t i,min = (new_size < v->ptr)?new_size:v->size;

    for(i=0; i<min;i++) *(n_vec+i) = *(v->vec+i);
    
    free(v->vec);
    v->vec = n_vec;
    v->ptr = min;
    v->size = new_size; 
}

void pushback_vector_int(vector_int *v,int n){

    if(v->ptr >= v->size)
        resize_vector_int(v,2*v->size);
    *(v->vec+v->ptr) = n;
    v->ptr++;
}

void print_vector_int(vector_int *v){
    for (size_t i = 0; i < v->size ; i++) printf("%d\n", *(v->vec+i));
}

void delete_vector_int(vector_int *v){
    free(v->vec);
    free(v);
}
