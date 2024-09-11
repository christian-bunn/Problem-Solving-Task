#include <stdio.h>
#include <stdlib.h>
#include "dbl_vector.h"

void dv_init( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
    vec->capacity = DV_INITIAL_CAPACITY,
    vec->size = 0,
    vec->data = (double*)malloc(vec->capacity * sizeof(double));
    if (!vec->data) {
        fprintf(stderr, "Logging a failed message for this function\n");
        exit(EXIT_FAILURE);
    }

}

void dv_ensure_capacity( dbl_vector_t* vec, size_t new_size ) {
    // INSERT SOLUTION HERE
    if (new_size > vec->capacity) {
        size_t new_capacity = vec->capacity * DV_GROWTH_FACTOR;
        if (new_size > new_capacity) {
            new_capacity = new_size;
        }
        vec->data = (double*)realloc(vec->data, new_capacity * sizeof(double));
        if (!vec->data) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
        vec->capacity = new_capacity;
    }
}

void dv_destroy( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void dv_copy( dbl_vector_t* vec, dbl_vector_t* dest ) {
    // INSERT SOLUTION HERE
}

void dv_clear( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
}

void dv_push( dbl_vector_t* vec, double new_item ) {
    // INSERT SOLUTION HERE
}

void dv_pop( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
}

double dv_last( dbl_vector_t* vec ) {
    double result = NAN;
    // INSERT SOLUTION HERE
    return result;
}

void dv_insert_at( dbl_vector_t* vec, size_t pos, double new_item ) {
    // INSERT SOLUTION HERE
}

void dv_remove_at( dbl_vector_t* vec, size_t pos ) {
    // INSERT SOLUTION HERE
}

void dv_foreach( dbl_vector_t* vec, void (*callback)(double, void*), void* info ) {
    // INSERT SOLUTION HERE
}