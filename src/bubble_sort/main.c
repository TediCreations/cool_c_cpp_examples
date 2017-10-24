#include <stdio.h>

/* The classic bubble sort algorithm */
void bubbleSort( int data[], const int len )
{
    for( int i=0 ; i<(len-1); i++ )
    {
        for( int j=0; j<(len-i-1); j++ )
        {
            if( data[j]>data[j+1] )
            {
                /* Swapping */
                int swap    = data[j];
                data[j]     = data[j+1];
                data[j+1]   = swap;
            }
        }
    }
}

void display( int data[], const int len )
{
    printf( "Data = [ " );
    for( int i = 0; i<len-1; i++ )
    {
        printf( "%i, ", data[i] );
    }

    /* Last element */
    printf( "%i ]\n", data[len-1] );
}

int main( void )
{
    int data[] = { 9, 5, -7, 2, 5, 5, 13, 0, 9, 7, 8, 13, 15, -2, -5, 3 };
    const int len = sizeof(data)/sizeof(data[0]);

    printf( "Before\n" );
    display( data, len );

    printf( "After\n" );
    bubbleSort( data, len );
    display( data, len );

    return 0;
}