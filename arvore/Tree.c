#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _Node
{
	struct _Node* leftSon;
	struct _Node* rightSon;
	struct _Node* father;
	int key;
}*Node;

typedef Node RootBinaryTree;

RootBinaryTree* newBinaryTree();
void insertBinaryTree(RootBinaryTree* root, int key);
void printBinaryTree(RootBinaryTree root);
int heightBinaryTree(RootBinaryTree root);
bool binaryTreeIsEmpty(RootBinaryTree* root);
void freeBinaryTree(RootBinaryTree* root);
void freeBinaryNode(Node node);
int heightLeftSon(RootBinaryTree* root);
int heightRightSon(RootBinaryTree* root);
static int balancingFactor(Node node);
static void rotateRight(Node* node);
static void rotateLeft(Node* node);
static void doubleRightRotate(Node* node);
static void doubleLeftRotate(Node* node);

void balanceBinaryTree(RootBinaryTree* root);


RootBinaryTree* newBinaryTree()
{
	RootBinaryTree* root = NULL;

	root = (RootBinaryTree*)malloc(sizeof(RootBinaryTree));
	if(root != NULL)
		*root = NULL;

	return root;
}

void insertBinaryTree(RootBinaryTree* root, int key)
{
	Node current;
	Node previous;
	Node newNode;

	newNode = (Node)malloc(sizeof(struct _Node));
	newNode->leftSon = NULL;
	newNode->rightSon = NULL;
	newNode->father = NULL;
	newNode->key = key;

	if(*root == NULL)
	{
		*root = newNode;
	}
	else
	{
		current = *root;

		while(current != NULL)
		{
			previous = current;
			
			if(key <= current->key)
			{
				current = current->leftSon;
			}
			else if(key > current->key)
			{
				current = current->rightSon;
			}
		}

		if(key <= previous->key)
		{
			previous->leftSon = newNode;
			newNode->father = previous;
		}
		else if(key >= previous->key)
		{
			previous->rightSon = newNode;
			newNode->father = previous;
		}
	}
}

void printBinaryTree(RootBinaryTree root) //Pré-ordem
{
	if(root == NULL)
		return;

	
	printf("%i\n",root->key);
	printBinaryTree(root->leftSon);
	printBinaryTree(root->rightSon);
}

int heightBinaryTree(RootBinaryTree root)
{
	int heightLeft;
	int heightRight;

	if(root == NULL)
		return -1;

	heightLeft = heightBinaryTree(root->leftSon);
	heightRight = heightBinaryTree(root->rightSon);

	if(heightLeft < heightRight)
		return heightRight + 1;
	else return heightLeft + 1;
}

bool binaryTreeIsEmpty(RootBinaryTree* root)
{
	return 	*root == NULL?true:false;
}

void freeBinaryNode(Node node)
{
	if(node == NULL)
		return;

	freeBinaryNode(node->leftSon);
	freeBinaryNode(node->rightSon);
	free(node);
}

void freeBinaryTree(RootBinaryTree* root)
{
	if(*root == NULL)
		return;

	freeBinaryNode(*root);
	free(root);
}

int heightLeftSon(RootBinaryTree* root)
{
	Node current;
	int counter = -1;
    
    if(*root == NULL || root == NULL)
		return 0;

	current = *root;

	while(current != NULL)
	{
		counter += 1;
		current = current->leftSon;
	}

	return counter;
}

int heightRightSon(RootBinaryTree* root)
{
	Node current;
	int counter = -1;

	if(*root == NULL || root == NULL)
		return 0;

	current = *root;

	while(current != NULL)
	{
		counter += 1;
		current = current->rightSon;
	}

	return counter;

}


static int balancingFactor(Node node)
{
	return heightLeftSon(&node) - heightRightSon(&node);
}

static void rotateLeft(Node* node)
{
	Node tempNode;
	Node auxNode;

	auxNode = (*node)->rightSon;
	tempNode = auxNode->leftSon;
	auxNode->leftSon = *node;
	(*node)->rightSon = tempNode;
	*node = auxNode; 
}

static void rotateRight(Node* node)
{
	Node tempNode;
	Node auxNode;

	auxNode = (*node)->leftSon;
	tempNode = auxNode->rightSon;
	auxNode->rightSon = *node;
	(*node)->leftSon = tempNode;
	*node = auxNode;
}

static void doubleRightRotate(Node* node)
{
 	rotateLeft(&(*node)->leftSon);
 	rotateRight(node);
}

static void doubleLeftRotate(Node* node)
{
	rotateRight(&(*node)->rightSon);
	rotateLeft(node);
}

void balanceBinaryTree(RootBinaryTree* root)
{
	
	
}

int main(int argc, char const *argv[])
{
	RootBinaryTree* binaryTree;

    binaryTree = newBinaryTree();

    /* Arvore que precisa de dupla rotação 
	    insertBinaryTree(binaryTree,8);
	    insertBinaryTree(binaryTree,10);
	    insertBinaryTree(binaryTree,4);
	    insertBinaryTree(binaryTree,6);
	    insertBinaryTree(binaryTree,2);
	    insertBinaryTree(binaryTree,5); */

	insertBinaryTree(binaryTree,8);
    insertBinaryTree(binaryTree,10);
    insertBinaryTree(binaryTree,4);
    insertBinaryTree(binaryTree,9);
    insertBinaryTree(binaryTree,15);
    insertBinaryTree(binaryTree,12);

    balanceBinaryTree(binaryTree);
    printBinaryTree(*binaryTree);
    //freeBinaryTree(binaryTree);

	return 0;
}