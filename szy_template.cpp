#include<stdio.h>
#include<stdlib.h>
  
struct Node
{
    int val;
    Node* next;
};
 
/* function declarations */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef);

void MergeSort(Node*& headRef) {
  struct Node* head = headRef;
  struct Node* a;
  struct Node* b;

  if ((head == NULL) || (head->next == NULL)) {
    return;
  }

  // split into two lists in half
  FrontBackSplit(head, a, b); 

  // Recursively sort the sublists
  MergeSort(a);
  MergeSort(b);

  // merge the two sorted lists together
  headRef = SortedMerge(a, b);
}
 
Node* SortedMerge(struct Node* a, struct Node* b) {
  Node* result = NULL;

  if (a == NULL)
     return(b);
  else if (b == NULL)
     return(a);
 
  if (a->val <= b->val) {
    result=a;
    a=a->next;
  } else {
    result=b;
    b=b->next;
  }

  Node* tmp=result;
  while(a != NULL and b != NULL) {
    if (a->val <= b->val) {
      tmp->next=a;
      a=a->next;
      tmp=tmp->next;
  } else {
      tmp->next=b;
      b=b->next;
      tmp=tmp->next;
  }
  }

   while(a!=NULL) {
      tmp->next=a;
      a=a->next;
      tmp=tmp->next;
  }

   while(b!= NULL) {
      tmp->next=b;
      b=b->next;
      tmp=tmp->next;
  }
return result;
}

/* Split the nodes of the given list into front and back halves,
   and return the two lists using the reference parameters.
   Uses the fast/slow pointer strategy - one pointer should
   move by 1 one node, while second one by 2 nodes.  */
void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef) {
  Node *fast;
  Node *slow;
  if (source == NULL || source->next == NULL)
  {
    /* length < 2 cases */
    frontRef = source;
    backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
    while(fast!=NULL) {
      fast=fast->next;
      if(fast!=NULL) {
        fast=fast->next;
        slow=slow->next;
      }
    }
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */

    /**********************************
    * This is the place for your code *
    ***********************************/
 
    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
    frontRef = source;
    backRef = slow->next;
    slow->next = NULL;
  }
}

 
int main() {
    
    int Z;
    scanf("%d", &Z);

    int val;

    while (Z--) {

        Node *head = NULL;
        Node *curr = NULL;
        
        int n, val;
        scanf("%d", &n);

        while (n--) {
            scanf("%d", &val);
            Node *temp = new Node;
            temp->val = val;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
                curr = temp;
            } else {
                curr->next = temp;
                curr = temp;
            }
        }

        Node *pr = head;
        MergeSort(head);

        while (head != NULL) {
            printf("%d\n", head->val);
            curr = head;
            head = head->next;
            /**************************************
            * Hey! Remember not to litter around! *
            **************************************/
        }

    }

}
