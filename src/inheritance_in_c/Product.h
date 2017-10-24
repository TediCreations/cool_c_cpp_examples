#ifndef Product_H
#define Product_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AbstractProduct.h"

/***********************/

typedef struct Product{

    AbstractProduct;
    double price;

    void (*set_price)();
    double (*get_price)();  
    // void (*display)();   

} Product;

Product Product_new();
void Product_init(Product *obj);

#endif