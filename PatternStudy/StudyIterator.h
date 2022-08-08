#pragma once
#include <iostream>
#include <vector>

// Pattern studies: iterator

using namespace std;

class VectorIterator {
private:
	int current = 0;
	vector<int> values;
public:
	VectorIterator(vector<int> vector) {
		values = vector;
	};

	int first() {
		current = 0;
		return values[current];
	};

	int last() {
		current = values.size() - 1;
		return values[current];
	};

	int getCurrentValue() {
		return values[current];
	};

	int getCurrentIndex() {
		return current;
	};

	int prev() {
		if (current > 0) {
			return values[current--];
		}
		return values[current];
	};

	int next() {
		if (hasNext()) {
			return values[current++];
		}
		return values[current];
	};

	int hasNext() {
		return current < values.size();
	};
};



