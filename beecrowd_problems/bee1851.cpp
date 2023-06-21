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

struct Dragao{

    pair<int, int> values;

    Dragao(int t, int f) {
        values.first = t;
        values.second = f;
    }

    bool operator<(const Dragao &d) {
        double pt = (double) values.second / values.first;
        double pd = (double) d.values.second / d.values.first;
        return pt > pd;
    }

    bool operator>(const Dragao &d) {
        double pt = (double) values.second / values.first;
        double pd = (double) d.values.second / d.values.first;
        return pt < pd;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, f;
    long long ans = 0, multadiaria = 0;
    bool treinando = false;
    int diasr;

    BinaryHeap<Dragao> fila;

    while (cin >> t >> f) {
        fila.insert(Dragao(t, f));
        multadiaria += f;

        if (!treinando || !diasr) {
            diasr = fila.getTop().values.first;
            multadiaria -=fila.getTop().values.second;
            fila.extractMin();
            treinando = true;
        }
        ans += multadiaria;
        diasr--;
    }

    if (treinando) ans += diasr * multadiaria;

    while (!fila.isEmpty()) {
        multadiaria -= fila.getTop().values.second;
        ans += multadiaria * fila.getTop().values.first;
        fila.extractMin();
    } 

    cout << ans << endl;

    return 0;
}