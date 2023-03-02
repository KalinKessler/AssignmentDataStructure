// Nama: Albertus Giovanni Prasetyo
// NIM: 2602076866
// Kelas: LB20
// Assignment Task: Write a program to create a doubly linked list and perform insertions and deletions in the beginning of the lists.
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node* next;
	struct Node* prev;
};

int getLength(struct Node* temp){
	int len = 0;
	while (temp != NULL){
		temp = temp->next;
		len++;
	}
	return len;
}

void insertHead(struct Node **head, int val){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	
	newNode->val = val;
	newNode->next = *head;
	newNode->prev = NULL;
	
	if (*head != NULL)
    (*head)->prev = newNode;
    
	*head = newNode;
}

void startInsert (struct Node **head){
	int val = 0;
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	printf("\nInsert head number: ");
	scanf("%d", &val);
	newNode->val = val;
	newNode->next = *head;
	newNode->prev = NULL;

  	if (*head != NULL)(*head)->prev = newNode;

  	*head = newNode;
}

void display (struct Node *node){
  struct Node *tail = NULL;
  while (node != NULL)
    {
      printf (" %d ", node->val);
      tail = node;
      node = node->next;
    }
}

void deleteHead (struct Node **head){
  struct Node *temp = *head;
  
  if (*head == NULL)
    {
      printf ("\nLinked List empty, nothing to delete\n\n");
      return;
    }

  if (temp->next == NULL)
    {
      printf ("\n%d \n\n", temp->val);
      *head = NULL;
      return;
    }
  
  *head = (*head)->next;
 
  (*head)->prev = NULL;

  printf ("Deleting %d \n\n", temp->val);
  free (temp);
}

int main(){
	struct Node *head = NULL;

 	insertHead (&head, 9);
  	insertHead (&head, 12);
  	insertHead (&head, 80);
  	insertHead (&head, 40);
  	insertHead (&head, 78);
  	display (head);

  	startInsert(&head);
  	printf ("\nLinked List After Insertion\n");
  	display (head);
  
  	printf ("\n\nLinked List Before Deletion\n");
  	display (head);

	printf ("\n\n");
  	deleteHead (&head);
  	printf ("Linked List After Deletion\n");
  	display (head);

	return 0;
}
