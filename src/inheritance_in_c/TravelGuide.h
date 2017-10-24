#ifndef TravelGuide_H
#define TravelGuide_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Book.h"

/***********************/

typedef struct TravelGuide{

    Book;
    char country[1000];
    void (*f)();

    void (*set_country)();
    char *(*get_country)();
    // void *(*display)();

} TravelGuide;

TravelGuide TravelGuide_new();
void TravelGuide_init(TravelGuide *obj);

#endif