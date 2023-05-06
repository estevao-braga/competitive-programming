/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/1195
*/

#include <bits/stdc++.h>
using namespace std;

class BinarySearchTree {
private:

    typedef struct node{
        int data;
        node *left, *right;

        void setData(int data) {
            this->data = data;
        }
    } Node ;


    Node* createNode(int x) {
        Node* n = new BinarySearchTree::Node();
        n->left = nullptr;
        n->right = nullptr;
        n->setData(x);
        return n;
    }

    Node *root;
    
    void _prefix(Node* node) {
        if (node == nullptr) return;
        cout << ' ' << node->data;
        this->_prefix(node->left);
        this->_prefix(node->right);
    }

    void _infix(Node* node) {
        if (node == nullptr) return;
        this->_infix(node->left);
        cout << ' ' << node->data;
        this->_infix(node->right);
    }

    void _postfix(Node* node) {
        if (node == nullptr) return;
        this->_postfix(node->left);
        this->_postfix(node->right);
        cout << ' ' << node->data;
    }

    void deleteNode(Node* node) {
        if (node == nullptr) return;
        this->deleteNode(node->left);
        this->deleteNode(node->right);
        delete node;
    }

public:
    BinarySearchTree() {
        this->root = nullptr;
    }

    void add(int x) {
        if (this->root == nullptr) {
            this->root = this->createNode(x);
            return;
        }

        Node* aux = this->root;

        while (true) {
            if (x < aux->data) {
                if (aux->left == nullptr) {
                    aux->left = this->createNode(x);
                    break;
                }
                aux = aux->left;
                continue;
            }

            if (aux->right == nullptr) {
                aux->right = this->createNode(x);
                break;
            }
            aux = aux->right;
        } 
    }

    BinarySearchTree find(int x) {
        BinarySearchTree b = BinarySearchTree();
        
        Node* aux = this->root;

        while (true) {
            if (aux == nullptr) {
                break;
            }

            if (x == aux->data){
                b.root = aux;
                break;
            } else if (x < aux->data) {
                aux = aux->left;
            } else {
                aux = aux->right;
            }
        }

        return b;
    }

    void prefix() {
        this->_prefix(this->root);
    }

    void postfix() {
        this->_postfix(this->root);
    }

    void infix() {
        this->_infix(this->root);
    }

    void clear() {
        this->deleteNode(root);
        this->root = nullptr;
    }
};

BinarySearchTree b;

void solve() {
    b.clear();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.add(x);    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve();
        cout << "Case " << i << ":\n";
        cout << "Pre.:";
        b.prefix();
        cout << "\n";
        cout << "In..:";
        b.infix();
        cout << "\n";
        cout << "Post:";
        b.postfix();
        cout << "\n\n";
    }

    return 0;
}