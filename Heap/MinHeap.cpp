#include<iostream>
#include <vector>

using namespace std;

class MinHeap {
	vector<int> arr;
	int size = 0;
	int leftChildIndex(int rootIndex);
	int rightChildIndex(int rootIndex);
	int parentIndex(int rootIndex);
	void insert(int val);
};

int MinHeap::leftChildIndex(int rootIndex) {
	return (2 * rootIndex + 1);
}

int MinHeap::rightChildIndex(int rootIndex) {
	return (2 * rootIndex + 2);
}

int MinHeap::parentIndex(int rootIndex) {
	return (rootIndex - 1) / 2;
}

void MinHeap::insert(int val) {
	arr[size] = val;
	size++;
	int i = size - 1;
	while ( i != 0 && arr[parentIndex(i)] > arr[i]) {
		swap(arr[i], arr[parentIndex(i)]);
		i = parentIndex(i);
	}
}

int main() {
	vector<int> input;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		input.push_back(k);
	}
	MinHeap heap;
	for (int i = 0; i < N; i++) {
		heap.insert(input[i]);
	}

	return 0;
}