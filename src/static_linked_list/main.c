#include <stdio.h>
#include <stdint.h>

typedef struct node
{
	void* data;
	struct node* child;
} node_t;

int main( void )
{
	/* Create nodes */
	node_t node1;
	node_t node2;
	node_t node3;
	node_t node4;
	
	/* Initialize them */
	node1.data = "node 1";
	node1.child = &node2;
	
	node2.data = "node 2";
	node2.child = &node3;
	
	node3.data = "node 3";
	node3.child = &node4;
	
	node4.data = "node 4";
	node4.child = NULL;
	
	/* Travel in the list */
	printf( "Static linked list first node...\n" );
	node_t* currNode = &node1;
	while( currNode != NULL )
	{
		if( currNode->child != NULL )
		{
			printf( "%s -> %s\n", (char*)currNode->data, (char*)currNode->child->data );
		}
		else
		{
			printf( "Static linked list final node...\n" );
		}
		
		currNode = currNode->child;
	}
	
	/* Exit with success */
	return 0;
}
