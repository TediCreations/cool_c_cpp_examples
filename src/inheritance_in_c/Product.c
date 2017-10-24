#include "Product.h"

/*-------------------------------*/

static void set_price(Product *this, double price) {
    this->price = price;
}

/*-------------------------------*/

static double get_price(Product *this) {
    return this->price; 
}

/*-------------------------------*/

static void display(Product *this) {

    AbstractProduct p = AbstractProduct_new();
    p.display(this);    

    printf("-Product- \n"); 
    printf("price: %f\n", this->get_price(this));   
    printf("\n");
}

/*-------------------------------*/

void Product_init(Product *obj) {

    AbstractProduct_init((AbstractProduct*)obj);

    obj->set_price = set_price;
    obj->get_price = get_price; 
    obj->display = display;

}

/*-------------------------------*/

Product Product_new() {

    Product aux;    
    Product_init(&aux);
    return aux;
}