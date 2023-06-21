#include <bits/stdc++.h>
using namespace std;

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


int main() {
    int N, M;
    cin >> N >> M;

    vector<int> processingTime(N);
    for (int i = 0; i < N; i++) {
        cin >> processingTime[i];
    }

    Queue<int> customers;
    for (int i = 0; i < M; i++) {
        int items;
        cin >> items;
        customers.enqueue(items);
    }

    vector<int> timeTaken(N, 0);
    int totalTime = 0;

    while (!customers.isEmpty()) {
        int availableCashier = 0;
        for (int i = 1; i < N; i++) {
            if (timeTaken[i] < timeTaken[availableCashier])
                availableCashier = i;
        }

        int items = customers.getTop();
        customers.dequeue();

        timeTaken[availableCashier] += processingTime[availableCashier] * items;
        if (timeTaken[availableCashier] > totalTime)
            totalTime = timeTaken[availableCashier];
    }

    cout << totalTime << endl;

    return 0;
}