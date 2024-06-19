#include "maxHeap.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

maxHeap::maxHeap(int headVal) {
    heap.push_back(headVal);
}

bool maxHeap::is_empty() {
    if (heap.empty()) {
        return true;
    }
    return false;
}

// Time complexity log(n)
void maxHeap::add(int val) {
    heap.push_back(val);
    int valIndex = heap.size()-1;

    while (val > heap[parentIndex(valIndex)]) {
        swap(valIndex, parentIndex(valIndex));
        valIndex = parentIndex(valIndex);
    }
}

// Time complexity log(n)
int maxHeap::remove_max() {
    if (heap.size() == 0) {
        throw out_of_range("Cannot Remove From Empty Heap");
    }
    int valMax = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    percolateDown(0);
    return valMax;
}

// Time Complexity n
void maxHeap::build_heap(vector<int>& newHeap) {
    this->heap = newHeap;
    for (int i = newHeap.size()-1; i >= 0; i--) {
        percolateDown(i);
    }
}

int maxHeap::get_max() { return heap[0]; }

int maxHeap::size() { return heap.size(); }

// Helper Functions
int maxHeap::rightChild(int indexParent) {
    if ((2*indexParent)+2 >= this->size()) {
        return -1;
    }
    return (2*indexParent)+2;
}

int maxHeap::leftChild(int indexParent) {
    if ((2*indexParent)+1 >= this->size()) {
        return -1;
    }
    return (2*indexParent)+1;
}

int maxHeap::parentIndex(int indexChild) {
    if (indexChild <= 0 || indexChild >= heap.size()) {
        return -1;
    }
    if ((indexChild % 2) == 0) {
        return (indexChild-2)/2;
    }
    return (indexChild-1)/2;
}

void maxHeap::swap(int i, int j) {
    int tempVal = heap[i];
    heap[i] = heap[j];
    heap[j] = tempVal;
}

string maxHeap::toStringPreOrder() {
    string preOrder;
    int i = 0;

    while (i < this->size()) {
        preOrder += std::to_string(heap[i]) + " ";
        if (leftChild(i) != -1) {
            i = leftChild(i);
        }
        else if (rightChild(i) != -1) {
            i = rightChild(i);
        }
    }
    return preOrder;
}

void maxHeap::percolateDown(int valReplaceIndex) {
    int valReplace = heap[valReplaceIndex];
    int rightChildIndex = rightChild(valReplaceIndex);
    int leftChildIndex = leftChild(valReplaceIndex);

    while (leftChildIndex != -1) {
        // Only Left Child
        if (rightChildIndex == -1) {
            // Left Child Swap
            if (valReplace < heap[leftChildIndex]) {
                swap(valReplaceIndex, leftChild(valReplaceIndex));
                valReplaceIndex = valReplaceIndex * 2 + 1;
            }
                // No Swap
            else {
                break;
            }
        }

            // Two Children
        else {
            // No Swap
            if (valReplace >= heap[leftChildIndex] && valReplace >= heap[rightChildIndex]) {
                break;
            }
            // Left Child Swap
            if (heap[leftChildIndex] > heap[rightChildIndex]) {
                swap(valReplaceIndex, leftChild(valReplaceIndex));
                valReplaceIndex = valReplaceIndex * 2 + 1;
            }
                // Right Child Swap
            else {
                swap(valReplaceIndex, rightChild(valReplaceIndex));
                valReplaceIndex = valReplaceIndex * 2 + 2;
            }
        }
        rightChildIndex = rightChild(valReplaceIndex);
        leftChildIndex = leftChild(valReplaceIndex);
    }
}

string maxHeap::toString() {
    string final;
    for (int i=0; i<this->size(); i++) {
        final += std::to_string(heap[i]) + " ";
    }
    return final;
}