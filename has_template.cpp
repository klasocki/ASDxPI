#include <iostream>
#include <stdlib.h>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
#define DEBUG 1

using namespace std;


struct Node
{
    string text;
    Node *next;
};

uint32_t hashfunc(string txt) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    int key=0;
    for(int i=0; i<txt.size(); i++)
        key^=txt[i]<<(i%4)*8;
    return key;
}

void add_to_hashtable(Node** hashtable, int n, string txt) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    int ind=hashfunc(txt)%n;
    Node* node=new Node;
    node->text=txt;
    node->next=hashtable[ind];
    hashtable[ind]=node;
}

bool check_if_exists(Node** hashtable, int n, string txt) {
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    //cout<<"robie"<<endl;
    int ind=hashfunc(txt)%n;
    Node* tmp=hashtable[ind];

    //if(tmp!=NULL) cout<<"zyje"<<endl;

    while(tmp!=NULL) {
        if (tmp->text==txt) {
                //cout<<"znajduje"<<endl;
                return true;
        }
        tmp=tmp->next;
    }
    //cout<<"nie znajduje"<<endl;
    return false;
}

void free_memory(Node** hashtable, int n) {
    Node *ptr, *nxt;
    for (int i = 0; i < n; i++) {
        ptr = hashtable[i];
        while (ptr != NULL) {
            /**********************
            * PLACE FOR YOUR CODE *
            **********************/
            nxt=ptr->next;
            delete ptr;
            ptr=nxt;
        }
    }
    delete[](hashtable);
}

void debug_print_hashtable(Node** hashtable, int n) {
    #ifdef DEBUG
        Node* ptr;
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            ptr = hashtable[i];
            while (ptr != NULL) {
                cout << ptr->text << " | ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    #endif
}

int main() {
    ios::sync_with_stdio(false);
    int Z;
    cin >> Z;

    while (Z--) {
        int n, k;
        string tmp;

        cin >> n;
        cin >> k;

        Node** hashtable = new Node*[n]();

        for (int i = 0; i < n; i++)
            hashtable[i] = NULL;

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            add_to_hashtable(hashtable, n, tmp);
        }

        debug_print_hashtable(hashtable, n);

        for (int i = 0; i < k; i++) {
            cin >> tmp;
            if (check_if_exists(hashtable, n, tmp)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        free_memory(hashtable, n);

    }

}
