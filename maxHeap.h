#ifndef MAXHEAP_MAXHEAP_H
#define MAXHEAP_MAXHEAP_H
#include <vector>
#include <string>

class maxHeap {
private:
    std::vector<int> heap = {};

    int rightChild(int indexParent);
    int leftChild(int indexParent);
    int parentIndex(int indexChild);
    void swap(int i, int j);

public:
    maxHeap() = default;
    maxHeap(int headVal);
    bool is_empty();
    void add(int val);
    int get_max();
    int remove_max();
    int size();
    void build_heap(std::vector<int>& newHeap);
    std::string toStringPreOrder();
    void percolateDown(int valIndex);
    std::string toString();

    bool isValidHeap() {
        if (heap.size() == 0) {
            return true;
        }
        for (int i=0; i<heap.size(); i++) {
            if (rightChild(i) != -1 && heap[rightChild(i)] > heap[i]) {
                return false;
            }
            if (leftChild(i) != -1 && heap[leftChild(i)] > heap[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif //MAXHEAP_MAXHEAP_H
