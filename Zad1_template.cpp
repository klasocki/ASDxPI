#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct BSTnode{
    int val;
    struct BSTnode* right;
    struct BSTnode* left;
    struct BSTnode* parent;
} BSTnode;

void add_node(BSTnode* &root, int value){
    BSTnode* tmp = new BSTnode;
    tmp->val=value;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;

    // If root is empty?
    if(root == NULL){
        root=tmp;
        return;
    }

    BSTnode* tmpRoot = root;
    BSTnode* prevRoot = NULL;

    // Find the father of a new node
    while(tmpRoot != NULL){
        prevRoot=tmpRoot;
        if(tmpRoot->val<value) tmpRoot=tmpRoot->right;
        else tmpRoot=tmpRoot->left;
    }

    // Insert the new node
    if(prevRoot->val < value) {
        prevRoot->right=tmp;
    }
    else{
        prevRoot->left=tmp;
    }
    tmp->parent=prevRoot;
    
}

BSTnode* min(BSTnode* root){
    if(root==NULL) return NULL;
    while(root->left!=NULL) root=root->left;
    return root;
}

BSTnode* max(BSTnode* root){
    if (root==NULL) return root;
    while(root->right!=NULL) root=root->right;
    return root;
}

void free_BST(BSTnode* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        free_BST(root->left);
    }
    if(root->right != NULL){
        free_BST(root->right);
    }
    delete root;
    return;
}

void in_order_tree_walk(BSTnode* node){
    if(node->left != NULL){
        in_order_tree_walk(node->left);
    }
    printf("%d\n", node->val);
    if(node->right != NULL){
        in_order_tree_walk(node->right);
    }
}

int main(){
    /*
     * test data:
     * Z - number of test cases
     * N - number of insert values
     * N values to insert
     * Output:
     * min
     * max
     * N-X lines od numberts
    */
    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for(int i = 0 ; i < Z ; i++){
        int N;
        scanf("%d", &N);
        //cout<<"Biore"<<endl;
        BSTnode* tree = NULL;

        int x;
        // insert
        for(int j = 0 ; j < N ; j++) {
            scanf("%d", &x);
            add_node(tree, x);
            //cout<<"Biore"<<endl;
            //in_order_tree_walk(tree);
        }

        printf("%d\n", min(tree)->val);
        printf("%d\n", max(tree)->val);
        in_order_tree_walk(tree);

        // cleanup
        free_BST(tree);
    }
}
