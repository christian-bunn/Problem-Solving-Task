#include <stdio.h>
#include <stdlib.h>
#include "dbl_vector.h"

void dv_init( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
    vec->capacity = DV_INITIAL_CAPACITY, // initial capacity
    vec->size = 0, // making vector size 0
    vec->data = (double*)malloc(vec->capacity * sizeof(double));
    if (!vec->data) { // for errors i check the memory allocation
        fprintf(stderr, "Logging a failed message for this function\n");
        exit(EXIT_FAILURE);
    }

}

void dv_ensure_capacity( dbl_vector_t* vec, size_t new_size ) {
    // INSERT SOLUTION HERE
    if (new_size > vec->capacity) { // if new_size exceeds current 
        size_t new_capacity = vec->capacity * DV_GROWTH_FACTOR; // get new capacity by multiplying old by growth factor
        if (new_size > new_capacity) {
            new_capacity = new_size;
        }
        vec->data = (double*)realloc(vec->data, new_capacity * sizeof(double)); // reallocating memory so increase capacity
        if (!vec->data) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
        vec->capacity = new_capacity;
    }
}

void dv_destroy( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
    free(vec->data); // free the allocated memory
    vec->data = NULL;
    vec->size = 0; 
    vec->capacity = 0;
}

void dv_copy( dbl_vector_t* vec, dbl_vector_t* dest ) {
    // INSERT SOLUTION HERE
    dv_ensure_capacity(dest, vec->size); // checks that destination has enough capactiy to store all elements
    for (size_t i = 0; i < vec->size; i++) { // looping through source vector
        dest->data[i] = vec->data[i]; // copying each element to the destination vector
    }
    dest->size = vec->size;
}

void dv_clear( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
    vec->size = 0;
}

void dv_push( dbl_vector_t* vec, double new_item ) {
    // INSERT SOLUTION HERE
    dv_ensure_capacity(vec, vec->size + 1);
    vec->data[vec->size] = new_item; // adds new item to the end of the vector
    vec->size++; // increase vector size
}

void dv_pop( dbl_vector_t* vec ) {
    // INSERT SOLUTION HERE
    // decrement size of vector when condition is met
    if (vec->size > 0) {
        vec->size--; 
    }
}

double dv_last( dbl_vector_t* vec ) {
    double result = NAN;
    // INSERT SOLUTION HERE
    if (vec->size > 0) {
        return vec->data[vec->size - 1]; // this returns the last element in the vector
    }
    return result;
}

void dv_insert_at( dbl_vector_t* vec, size_t pos, double new_item ) {
    // INSERT SOLUTION HERE
    dv_ensure_capacity(vec, vec->size + 1);
    // if position is greater then the current size, append new item at the end
    if (pos > vec->size) {
        pos = vec->size;
    }
    for (size_t i = vec->size; i > pos; i--) { // shift to the right from pos
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[pos] = new_item;
    vec->size++;
}

void dv_remove_at( dbl_vector_t* vec, size_t pos ) {
    // INSERT SOLUTION HERE
    if (pos < vec->size) {
        for (size_t i = pos; i < vec->size - 1; i++) {
            vec->data[i] = vec->data[i +1]; // same shift as insert but to the left, removing element at pos
        }
        vec->size--;
    }
}

void dv_foreach( dbl_vector_t* vec, void (*callback)(double, void*), void* info ) {
    // INSERT SOLUTION HERE
    for (size_t i = 0; i < vec->size; i++) { // loop
        callback(vec->data[i], info); // callback function call on each element, and info
    }
}