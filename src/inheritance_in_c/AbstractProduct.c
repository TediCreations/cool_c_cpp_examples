#include "AbstractProduct.h"

/*-------------------------------*/

static void set_id(AbstractProduct *this, int id) {
    this->id = id;
}

/*-------------------------------*/

static void set_name(AbstractProduct *this, char *name) {
    strcpy(this->name, name);
}

/*-------------------------------*/

static void set_description(AbstractProduct *this, char *description) {
    strcpy(this->description, description);
}

/*-------------------------------*/

static int get_id(AbstractProduct *this) {
    return this->id;    
}

/*-------------------------------*/

static char *get_name(AbstractProduct *this) {
    return this->name;  
}

/*-------------------------------*/

static char *get_description(AbstractProduct *this) {
    return this->description;   
}

/*-------------------------------*/

static void display(AbstractProduct *this) {

    printf("-AbstractProduct- \n"); 
    printf("id: %d\n", this->get_id(this)); 
    printf("name: %s\n", this->get_name(this)); 
    printf("description: %s\n", this->get_description(this));   
    printf("\n");
}

/*-------------------------------*/

void AbstractProduct_init(AbstractProduct *obj) {

    obj->set_id = set_id;
    obj->set_name = set_name;
    obj->set_description = set_description; 
    obj->get_id = get_id;
    obj->get_name = get_name;
    obj->get_description = get_description;
    obj->display = display;

}

/*-------------------------------*/

AbstractProduct AbstractProduct_new() {

    AbstractProduct aux;
    AbstractProduct_init(&aux);
    return aux;
}