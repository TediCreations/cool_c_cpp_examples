#ifndef AbstractProduct_H
#define AbstractProduct_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* This is an abstract class */
typedef struct AbstractProduct{

    int id;
    char name[1000];
    char description[1000];

    void (*set_id)();
    void (*set_name)();
    void (*set_description)();  
    int (*get_id)();    
    char *(*get_name)();    
    char *(*get_description)(); 
    void (*display)();  

} AbstractProduct;

AbstractProduct AbstractProduct_new();
void AbstractProduct_init(AbstractProduct *obj);

#endif