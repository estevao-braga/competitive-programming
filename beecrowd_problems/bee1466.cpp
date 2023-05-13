/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/1466
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

    void clear() {
        this->deleteNode(root);
        this->root = nullptr;
    }

    void bfs() {
        queue<Node*> q;
        Node* aux = this->root;

        do {
            if (aux != this->root) cout << " ";

            cout << aux->data;
            
            if (aux->left != nullptr) 
                q.push(aux->left);

            if (aux->right != nullptr)
                q.push(aux->right);

            if (q.empty())
                break;

            aux = q.front();
            q.pop();
        } while(true);
    }
};

void solve() {
    BinarySearchTree b;

    int n, x;
    cin >> n;

    while (n--) {
        cin >> x;
        b.add(x);
    }


    b.bfs();
    cout << "\n\n";

    b.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }


    return 0;
}