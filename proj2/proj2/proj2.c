/********************************************************
* Name: Swapnil Gupta     								*
* Date: 02/25/2018										*
* Assignment: Project 2 - Sequence and Order validation *
*********************************************************
* This program uses the console to input numbers,		*
* search, and display a binary search tree.			    *
********************************************************/

#include "bst.h"
#include "io.h"

int main()
{
	struct NODE head;
	head.key = 0;
	head.left = malloc(sizeof(struct NODE));
	head.right = malloc(sizeof(struct NODE));

	char result = MainMenu();

	while (result != 'q')
	{
		if (result != 'i' && result != 's' && result != 't' && result != 'q')
		{
			printf_s("Please enter a valid character...");
			result = MainMenu();
		}
		else {
			if (result == 'i')
			{
				int key = Insert();
				struct NODE newNode;
				newNode.key = key;
				struct NODE * addedNode = malloc(sizeof(struct NODE));
				addedNode = InsertNode(&newNode, &head);
				addedNode->key = key;
			}
			else if (result == 's')
			{
				int target = Search();
				int result = SearchTree(target, &head);
				PrintSearchResults(result, target);
			}
			else if (result == 't')
			{
				char it = PrintTree(&head);
				InorderTraversal(&it);
			}
			result = MainMenu();
		}
	}

	ReleaseMemory(&head);
	return 0;
}