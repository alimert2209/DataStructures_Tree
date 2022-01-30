#include <stdio.h>
#include <stdlib.h>

// 191180055 - Ali Mert KOCAMAN


// Tree structure with right and left nodes
struct tree{
	struct tree *leftPtr;
	int data;
	struct tree *rightPtr;
};

typedef struct tree alimert_Tree; // type definition of tree
alimert_Tree *root;


// key is the data of node to add to tree
void insertTree(int key, alimert_Tree **leaf)
{
	if(*leaf == NULL) //if there is no tree yet, it creates root and nulls the left and right nodes
	{
		*leaf = (alimert_Tree *)malloc(sizeof(alimert_Tree));
		(*leaf)->data = key;
		(*leaf)->leftPtr = NULL;
		(*leaf)->rightPtr = NULL;
	} 
	else if(key < (*leaf)->data) // If the data to be added is smaller, it is added to the left side of the tree.
	{
		insertTree(key, &(*leaf)->leftPtr);
	} 
	else if(key > (*leaf)->data) // If the data to be added is bigger, it is added to the right side of the tree.
	{
		insertTree(key, &(*leaf)->rightPtr);
	}
}

void inorderPrint(alimert_Tree *p)
{
	if (p != NULL) // if the tree exists
	{
		inorderPrint(p->leftPtr); // visit the left subtree
		printf("%d ", p->data); // print the data of node
		inorderPrint(p->rightPtr);  // visit the right subtree
	}
}

void preorderPrint(alimert_Tree *p)
{
	if (p != NULL) // if the tree exists
	{
		printf("%d ", p->data); // print the data of node
		preorderPrint(p->leftPtr); // visit the left subtree
		preorderPrint(p->rightPtr); // visit the right subtree
	}	
}

void postorderPrint(alimert_Tree *p)
{
	if (p != NULL) // if the tree exists
	{
		postorderPrint(p->leftPtr); // visit the left subtree
		postorderPrint(p->rightPtr); // visit the right subtree
		printf("%d ", p->data); // print the data of node
	}
}


int main() {
	int i, random;
	
	printf("The numbers being placed in the tree are:\n");
	for(i = 0; i < 10; ++i){
		random = 1 + rand() % 25; // It generates random numbers between 1 and 25 and assigns it to the random variable.
		srand(191180055 + random); // This is the seed of srand() function.
		insertTree(random, &root);
		printf("%d ", random);
	}
	printf("\n\n");
	printf("The preorder traversal is:\n");
    preorderPrint(root);
    printf("\n\n");
    printf("The inorder traversal is:\n");
    inorderPrint(root);
    printf("\n\n");
    printf("The postorder traversal is:\n");
    postorderPrint(root);
	
	
	return 0;
}
