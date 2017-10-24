#include "AbstractProduct.h"
#include "Book.h"
#include "Product.h"
#include "TravelGuide.h"

/*
 *                 Inheritance chart
 *                 =================
 * 
 *                  AbstractProduct
 *                        |
 *                        V
 *                     Product
 *                        |
 *              ----------+----------
 *              |                   |
 *              V                   V
 *             Book                ...
 *              |
 *              V
 *         Travelguide
 * 
 */

int main()
{
	/* This is the base class ( we can use ) */
	AbstractProduct abs = AbstractProduct_new();
	abs.set_name( &abs, "Super product" );
	abs.set_description( &abs, "Generic description of a product" );
	abs.set_id( &abs, 1 );
	abs.display( &abs );
	
	/* This inherits from AbstractProduct */
	Product p = Product_new();  
	p.set_id( &p, 2 );
	p.set_name( &p, "ATMEL ICE" );
	p.set_description( &p, "AVR/ARM Debugger" );
	p.set_price( &p, 50 );  
	p.display( &p );
	
	/* This inherits from Book */
	TravelGuide tg = TravelGuide_new(); 
	tg.set_id( &tg, 3 );
	tg.set_name( &tg, "Bushcrafter");
	tg.set_description( &tg, "A guide to wild mushrooms");        
	tg.set_price( &tg, 23 );
	tg.set_isbn( &tg, "DOI or ISBN");
	tg.set_author( &tg, "Unknown author" );
	tg.set_title( &tg, "Pelion: Magnesia" );
	tg.set_country( &tg, "Greece" );
	tg.display( &tg );
	
	return 0;
}