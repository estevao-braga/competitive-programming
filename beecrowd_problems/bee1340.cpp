#include <bits/stdc++.h>
using namespace std;

template <typename T> class BinaryHeap {
private:
    vector<T> heap;

    void heapifyUp(int index) {
        if (index <= 0) {
            return;
        }

        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    BinaryHeap() {}

    bool isEmpty() const {
        return heap.empty();
    }

    void insert(const T& item) {
        heap.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    T extractMin() {
        if (isEmpty()) {
            return T();
            
        }

        T minItem = heap.front();
        swap(heap.front(), heap.back());
        heap.pop_back();
        heapifyDown(0);

        return minItem;
    }

    T getTop() {
        if (isEmpty()) {
            throw out_of_range("Heap is empty.");
        }
        T minItem = heap.front();
        return minItem;
    }
};

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* front; // aponta para o primeiro elemento da fila
    Node* rear;  // aponta para o último elemento da fila
    int size;    // tamanho atual da fila

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    T getTop() const {
        if (isEmpty()) {
            return T();
        }
        return front->data;
    }

    bool isEmpty() const {
        return (size == 0);
    }

    int getSize() const {
        return size;
    }
};

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* top;  // aponta para o elemento do topo da pilha
    int size;   // tamanho atual da pilha

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "A pilha está vazia." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    T getTop() const {
        if (isEmpty()) {
            std::cout << "A pilha está vazia." << std::endl;
            return T();
        }
        return top->data;
    }

    bool isEmpty() const {
        return (size == 0);
    }

    int getSize() const {
        return size;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    while (cin >> n) {
        Stack<int> stack;
        BinaryHeap<int> heap;
        Queue<int> queue;

        int op, num;
        bool queueN, stackN, pqueue;
        queueN = stackN = pqueue = true;

        for (int i = 0; i < n;i++) {
            cin >> op >> num;
            if (op == 1) {
                stack.push(num);
                heap.insert(-num);
                queue.enqueue(num);
                continue;
            }
            
            if (stack.getTop() != num) stackN = false;
            else stack.pop();

            if (-heap.getTop() != num) pqueue = false;
            else heap.extractMin();

            if (queue.getTop() != num) queueN = false;
            else queue.dequeue();
        }

        if (!stackN && !queueN && !pqueue)
            cout << "impossible\n";
        else if (stackN && pqueue)
            cout << "not sure\n";
        else if (stackN && queueN)
            cout << "not sure\n";
        else if (pqueue && queueN)
            cout << "not sure\n";
        else if (pqueue)
            cout << "priority queue\n";
        else if (queueN)
            cout << "queue\n";
        else if (stackN)
            cout << "stack\n";

    }

    return 0;
}