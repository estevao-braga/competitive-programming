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

typedef pair<long long, long long> processo;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    while (cin >> n) {
        BinaryHeap<processo> tempo, custo;
        long long espera = 0, tempoExec = 0;
        bool processando = false;
        long long t, c; 

        while (n--) {
            cin >> t >> c;
            tempo.insert(make_pair(t, c));
        }

        tempoExec = tempo.getTop().first;

        while (!tempo.isEmpty()) {
            processo p = tempo.getTop();
            tempo.extractMin();

            if (p.first > tempoExec) {
                if (custo.getTop().second <= tempoExec) {
                    espera += tempoExec - custo.getTop().second;
                } else {
                    tempoExec = custo.getTop().second;
                }
                tempoExec += custo.getTop().first;
                custo.extractMin();
            }
            custo.insert(make_pair(p.second, p.first));
        }

        while (!custo.isEmpty()) {
            if(custo.getTop().second <= tempoExec)
                    espera += tempoExec - custo.getTop().second;
                else
                    tempoExec = custo.getTop().second;
            tempoExec += custo.getTop().first;

            custo.extractMin();
        }

        cout << espera << endl;

    }


    return 0;
}