#include "maxHeap.h"
#include <iostream>
#include <vector>
#include <assert.h>
#include <cstdlib>
using namespace std;

void test_stress_remove() {
    srand(time(nullptr));

    //for (int i = 0; i < 100; i++) {
    std::vector<int> values;
    while (values.size() < 200) {
        values.push_back(rand() % 20000 + 1);
    }
    maxHeap tree;

    for (size_t j = 0; j < values.size(); j++) {
        tree.add(values[j]);
        assert(tree.isValidHeap());
    }

    for (size_t j = 0; j < values.size(); j++) {
        tree.remove_max();
        assert(tree.isValidHeap());
    }
}

int main() {
    test_stress_remove();
    maxHeap heap1;

    heap1.add(95);
    heap1.add(52);
    heap1.add(83);
    heap1.add(51);
    heap1.add(24);
    heap1.add(19);
    heap1.add(4);
    heap1.add(27);
    heap1.add(55);
    heap1.add(6);
    assert(heap1.toString() == "95 55 83 52 24 19 4 27 51 6 ");
    assert(heap1.isValidHeap());

    for (int i=0; i<10; i++) {
        try {
            heap1.remove_max();
        }
        catch (out_of_range& e) {
            cerr << e.what() << endl;
            return -1;
        }
        assert(heap1.isValidHeap());
    }
}
