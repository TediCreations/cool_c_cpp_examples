#ifndef Book_H
#define Book_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Product.h"

/***********************/

typedef struct Book{

    Product;
    char isbn[1000];
    char author[1000];
    char title[1000];

    void (*set_isbn)();
    void (*set_author)();
    void (*set_title)();    

    char *(*get_isbn)();
    char *(*get_author)();
    char *(*get_title)();   
    // void (*display)();   


} Book;

Book Book_new();
void Book_init(Book *obj);

#endif