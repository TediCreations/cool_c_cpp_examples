#include "Book.h"

/*-------------------------------*/

static void set_isbn(Book *this, char *isbn) {
    strcpy(this->isbn, isbn);
}

/*-------------------------------*/

static void set_author(Book *this, char *author) {
    strcpy(this->author, author);
}

/*-------------------------------*/

static void set_title(Book *this, char *title) {
    strcpy(this->title, title);
}

/*-------------------------------*/

static char *get_isbn(Book *this) {
    return this->isbn;  
}

/*-------------------------------*/

static char *get_author(Book *this) {
    return this->author;    
}

/*-------------------------------*/

static char *get_title(Book *this) {
    return this->title; 
}

/*-------------------------------*/

static void display(Book *this) {

    Product p = Product_new();
    p.display(this);    

    printf("-Book- \n");
    printf("isbn: %s\n", this->get_isbn(this)); 
    printf("author: %s\n", this->get_author(this)); 
    printf("title: %s\n", this->get_title(this));   
    printf("\n");
}

/*-------------------------------*/

void Book_init(Book *obj) {

    Product_init((Product*)obj);

    obj->set_isbn = set_isbn;
    obj->set_author = set_author;
    obj->set_title = set_title; 
    obj->get_isbn = get_isbn;
    obj->get_author = get_author;
    obj->get_title = get_title; 
    obj->display = display;
}
/*-------------------------------*/

Book Book_new() {

    Book aux;   
    Book_init(&aux);
    return aux;
}