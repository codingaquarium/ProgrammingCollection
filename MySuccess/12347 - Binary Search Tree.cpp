/*
http://codingaquarium.wordpress.com/
Shaikh shiam Rahman
Khunla University of Engineering and Technology(KUET)

*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

/*** typedef ***/

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define ii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vii vector<ii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;

/** function **/

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAX 20010

/**
   Binary Search Tree

   Operation        Best Case Running Time      Worst Case Running Time
__________________________________________________________________________

     Search                  log2 n                     n
     Insert                  log2 n                     n
     Delete                  log2 n                     n
     Preorder Traversal         n                       n
     Inorder Traversal          n                       n
     Postorder Traversal        n                       n

     Operations :
     _____________

       insert(key)
       remove(key)
       search(key)
       max()
       min()
       traversePreorder()
       traversePostorder()
       traverseInorder()
       size()
       isEmpty()
       sort()

**/

struct treeNode {
    treeNode* left;
    treeNode* right;
    int key;
}*root;

template <class Object>
class BinarySearchTree {
    int count;
public:
    BinarySearchTree() {
        root = NULL;
    }

    bool isEmpty() const {
        return root == NULL;
    }
    void inorder(treeNode*);
    void traverseInorder();

    void preorder(treeNode*);
    void traversePreorder();

    void postorder(treeNode*);
    void traversePostorder();

    void insert(Object);

    void remove(Object);

    treeNode* search(const Object &);

    treeNode* findHelper(const Object &, treeNode* &);
    treeNode* find(const Object &);

    treeNode* minHelper(treeNode* &);
    treeNode* min();

    treeNode* maxHelper(treeNode* &);
    treeNode* max();

    int sizeHelper(treeNode*);
    int size();

    void sort();
};

// Smaller elements go left
// larger elements go right
template <class Object>
void BinarySearchTree<Object>::insert(Object d) {
    treeNode* t = new treeNode;
    treeNode* parent;
    t->key = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;

    // is this a new tree?
    if(isEmpty()) root = t;
    else {
        //Note: ALL insertions are as leaf nodes
        treeNode* curr;
        curr = root;
        // Find the Node's parent
        while(curr) {
            parent = curr;
            if(t->key > curr->key) curr = curr->right;
            else curr = curr->left;
        }

        if(t->key < parent->key)
            parent->left = t;
        else
            parent->right = t;
    }
}

template <class Object>
void BinarySearchTree<Object>::remove(Object d) {
    //Locate the element
    bool found = false;
    if(isEmpty()) {
        cout<<" This Tree is empty! "<<endl;
        return;
    }

    treeNode* curr;
    treeNode* parent;
    curr = root;

    // root to leaf search (top-down)
    while(curr) {
        if(curr->key == d) {
            found = true;
            break;
        } else {
            parent = curr;
            if(d > curr->key) curr = curr->right;
            else curr = curr->left;
        }
    }

    if(!found) {
        cout<<" key not found! "<<endl;
        return;
    }


    // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children


    //We're looking at a leaf node
    if( curr->left == NULL && curr->right == NULL) {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
        delete curr;
        return;
    }

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
            && curr->right == NULL)) {
        if(curr->left == NULL && curr->right != NULL) {
            if(parent->left == curr) {
                parent->left = curr->right;
                delete curr;
            } else {
                parent->right = curr->right;
                delete curr;
            }
        } else { // left child present, no right child
            if(parent->left == curr) {
                parent->left = curr->left;
                delete curr;
            } else {
                parent->right = curr->left;
                delete curr;
            }
        }
        return;
    }

    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL) {
        treeNode* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL)) {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        } else { // right child has children
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL) {
                treeNode* lcurr;
                treeNode* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL) {
                    lcurrp = lcurr;
                    lcurr = lcurr->left;
                }
                curr->key = lcurr->key;
                delete lcurr;
                lcurrp->left = NULL;
            } else {
                treeNode* tmp;
                tmp = curr->right;
                curr->key = tmp->key;
                curr->right = tmp->right;
                delete tmp;
            }

        }
        return;
    }

}

template <class Object>
treeNode* BinarySearchTree<Object>::search(const Object &d) {
    treeNode* current = root;
    while (current) {
        if(current -> key == d) {
            return current;
        } else if(d < current -> key) {
            current = current -> left;
        } else current = current -> right;
    }
    return NULL;
}

template <class Object>
treeNode* BinarySearchTree <Object> :: findHelper(const Object &d, treeNode* &node) {
    if (!node || node -> key == d) return node;
    else if(d < node -> key) return findHelper(d, node -> left);
    else return findHelper(d, node -> right);
}

template <class Object>
treeNode* BinarySearchTree <Object> :: find(const Object &d) {
    return findHelper(d, root);
}

template <class Object>
treeNode* BinarySearchTree <Object> :: minHelper(treeNode* &node) {
    if(node -> left == NULL) return node;
    return minHelper(node -> left);
}

template <class Object>
treeNode* BinarySearchTree <Object> :: min() {
    return minHelper(root);
}

template <class Object>
treeNode* BinarySearchTree <Object> :: maxHelper(treeNode* &node) {
    if(node -> right == NULL) return node;
    return maxHelper(node -> right);
}

template <class Object>
treeNode* BinarySearchTree <Object> :: max() {
    return maxHelper(root);
}

template<class Object>
int BinarySearchTree<Object>::sizeHelper(treeNode* p) {
    if(p != NULL) {
        if(p->left) sizeHelper(p->left);
        if(p->right) sizeHelper(p->right);
        count++;
    } return count;
}

template<class Object>
int BinarySearchTree<Object>::size() {
    count = 0;
    return sizeHelper(root);
}


/**
  in-order - leftChild, root, rightChild
  pre-order - root, leftChild, rightChild
  post-order - leftChild, rightChild, root
**/
template<class Object>
void BinarySearchTree<Object>::inorder(treeNode* p) {
    if(p != NULL) {
        if(p->left) inorder(p->left);
        cout<<" "<<p->key<<" ";
        if(p->right) inorder(p->right);
    } else return;
}

template<class Object>
void BinarySearchTree<Object>::traverseInorder() {
    inorder(root);
}

template<class Object>
void BinarySearchTree<Object>::sort() {
    inorder(root);
}

template<class Object>
void BinarySearchTree<Object>::preorder(treeNode* p) {
    if(p != NULL) {
        cout<<" "<<p->key<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    } else return;
}

template<class Object>
void BinarySearchTree<Object>::traversePreorder() {
    preorder(root);
}

template<class Object>
void BinarySearchTree<Object>::postorder(treeNode* p) {
    if(p != NULL) {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<p->key<<"\n";
    } else return;
}

template<class Object>
void BinarySearchTree<Object>::traversePostorder() {
    postorder(root);
}

int main() {
    BinarySearchTree <int> btree;
    int choice ;
    while(~SDi(choice)){
        btree.insert(choice);
    }
    btree.traversePostorder();
}
