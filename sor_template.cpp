#include <stdio.h>

struct Node
{
    int val;
    Node *next;
};

// use if you want implement selection sort
Node* remove_maximum(Node *&head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        Node *tmp = head;
        head = NULL;
        return tmp;
    }
    Node* sentinel=new Node;
    sentinel->next=head;

    int max_val=sentinel->next->val;
    Node* max_pointer=sentinel;

    Node* tmp=sentinel->next;
    while(tmp->next!=NULL){
        int val=tmp->next->val;
        if(val>max_val) {
            max_val=val;
            max_pointer=tmp;
        }
        tmp=tmp->next;
    }
    Node* result=max_pointer->next;
    max_pointer->next=max_pointer->next->next;

    head=sentinel->next;
    delete sentinel;
    return result;

    /*********************************
    * What if list is longer than 1? *
    **********************************/
}

// use if you want implement insertion sort
void insert(Node *&head, Node *item) {
    if (head == NULL || head->val > item->val) {
        item->next = head;
        head = item;
        return;
    }
    Node* tmp=head;
    while(tmp->next!=NULL and tmp->next->val <= item->val) tmp=tmp->next;

    item->next=tmp->next;
    tmp->next=item;


    /*****************************************************
    * What if item should be placed further on the list? *
    *****************************************************/
}

Node* sort(Node *head) {
    /**********************************
    * This is the place for your code *
    **********************************
    Node* result=NULL;
    while(head!=NULL) {
        Node* tmp=remove_maximum(head);
        tmp->next=result;
        result=tmp;
    }
    return result;
*/
    Node* sorted=NULL;
    while(head!=NULL) {
        Node* tmp=head;
        head=head->next;
        insert(sorted, tmp);
    }
    return sorted;
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
        head = sort(head);

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
