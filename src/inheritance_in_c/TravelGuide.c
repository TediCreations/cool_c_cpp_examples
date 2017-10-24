#include "TravelGuide.h"

/*-------------------------------*/

static void set_country(TravelGuide *this, char *country) {
    strcpy(this->country, country);
}

/*-------------------------------*/

static char *get_country(TravelGuide *this) {
    return this->country;   
}

/*-------------------------------*/

static void display(TravelGuide *this) {

    Book b = Book_new();
    b.display(this);

    printf("-TravelGuide- \n"); 
    printf("country: %s\n", this->get_country(this));   
    printf("\n");
}

/*-------------------------------*/

void TravelGuide_init(TravelGuide *obj) {

    Book_init((Book*)obj);
    obj->set_country = set_country;
    obj->get_country = get_country;
    obj->f = obj->display;
    obj->display = display;

}

/*-------------------------------*/

TravelGuide TravelGuide_new() {

    TravelGuide aux;
    TravelGuide_init(&aux);
    return aux;
}