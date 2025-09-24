#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* left;
        Node* right;
        int data;
        int height;
        Node(int val){
            this->data = val;
            this->height = 1;
        }
};
// Check for height of left, right tree.
// If it is greater than 1, then it is skewed.
/*
                   p            Right Rotation(p)             c
                  / \      --------------------------->      / \
                 c   t1    <---------------------------    t2   p
                / \            Left Rotation(c)                / \
               t2  t3                                         t3  t1
*/
 /*
      ###### Left Left Case ######
                p                                                          c
               / \            Right Rotation(p)                          /    \
              c   t1      ----------------------------->                g       p
             / \                                                       / \    /  \                      
            g  t2                                                     t3  t4  t2  t1
           / \
          t3  t4 



     ###### Left Right Case ######
                p                                                          p      (this struct is similar to above)                 g
               / \            Left Rotation(c)                            /  \           Right Rotation(p)                         /  \
              c   t1      ----------------------------->                 g    t1  ---------------------------------->             c    p
             / \                                                        / \                                                      / \  / \
            t2  g                                                      c  t4                                                    t2 t3 t4 t1
               / \                                                    / \
              t3  t4                                                 t2  t3        

    ###### Right Right Case ######

                p                                                          c
               / \            Left Rotation(p)                           /    \
              t1  c      ----------------------------->                 p       g
                 / \                                                    / \    /  \                      
                t2  g                                                  t1 t2  t3  t4
                   / \
                  t3  t4
    ###### Right Left Case ######
                p                                                          p      (this struct is similar to above)                     g
               / \            Right Rotation(c)                           /  \           Left Rotation(p)                              / \
              t1  c      ----------------------------->                 t1   g  ---------------------------------->                   p    c
                 / \                                                        / \                                                      / \  / \
                g  t4                                                     t2  c                                                    t1 t2 t3  t4
               / \                                                           / \
              t2  t3                                                        t3  t4
    
 */
class AVLTree{
    public:
        Node* insert(int val){
            return r = insert(val, r);
        }
        Node* deleteNode(int val){
            return r = deleteNode(val, r);
        }
        Node* insert(int data, Node* root){
            if(!root) return new Node(data);
            if(root->data > data) root->left = insert(data, root->left);
            else root->right = insert(data, root->right);
            root->height = getHeight(root);
            return rotate(root);
        }
        int getHeight(Node* root){
            if(!root) return 0;
            return 1 + max({root->left?root->left->height:0, root->right?root->right->height:0});
        }
        Node* rightRotate(Node* p){
           Node* c = p->left;
           Node* t3 = c->right;
           p->left = t3;
           c->right = p;
           // Imp to do p->height first as p is child of c now
           p->height = getHeight(p);
           c->height = getHeight(c);

           return c;
        }
        Node* leftRotate(Node* c){
            Node* p = c->right;
            Node* t3 = p->left;
            p->left = c;
            c->right = t3;
           // Imp to do p->height first as p is child of c now
            c->height = getHeight(c);
            p->height = getHeight(p);

            return p;
        }
        Node* rotate(Node* root){
            int leftTreeHeight = root->left?root->left->height:0;
            int rightTreeHeight = root->right?root->right->height:0;
            // Left skewed tree
            if(leftTreeHeight - rightTreeHeight > 1){
                // left left case (=0 is imp, if we miss, it wont work)
                if(getHeight(root->left->left) - getHeight(root->left->right) >= 0){
                    return rightRotate(root);
                }
                // left right case
                if(getHeight(root->left->left) - getHeight(root->left->right) < 0){
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
            }
            // Right Skewed tree
            if(leftTreeHeight - rightTreeHeight < -1){
                // right right case(=0 is imp, if we miss it wont work)
                if(getHeight(root->right->right) - getHeight(root->right->left) >= 0){
                    return leftRotate(root);
                }
                // right left case
                if(getHeight(root->right->right) - getHeight(root->right->left) < 0){
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
            }
            return root;
        }
        Node* predecessor(Node* root){
            while(root->left) root = root->left;
            return root;
        }
        Node* deleteNode(int data, Node* root){
            if(!root) return NULL;
            if(root->data > data){
                root->left = deleteNode(data, root->left);
            }
            else if(root->data < data){
                root->right = deleteNode(data, root->right);
            }
            // root is the node to delete
            else{
                // Leaf Node
                if(!root->left and !root->right) return NULL;
                // Only left tree is there
                else if(!root->right) return root->left;
                // Only right tree is there
                else if(!root->left) return root->right;
                // Both sub trees are there
                Node* pred = successor(root->right);
                root->data = pred->data;
                root->right = deleteNode(pred->data, root->right);
            }
            root->height = getHeight(root);
            return rotate(root);
        }
    private:
        Node* r;
}