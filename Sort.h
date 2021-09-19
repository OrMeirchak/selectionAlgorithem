#pragma once
#include "insertionSort.h"
#include "SelectionSort.h"
#include "QuintupletSort.h"
class Sort {
public:
	void operator()(const DoubleArr& arr, int i) {
		if (!legalIndex(i-1, arr.getSize())) {
			throw "wrong input";
		}
		else {
			InsertionSort insertionSort;
			SelectionSort selectionSort;
			QuintupletSort quintupletSort;
			ofstream myfile("Measure.txt");

			insertionSort(arr, i, myfile);
			selectionSort(arr, i, myfile);
			quintupletSort(arr, i, myfile);

			myfile.close();
		}
	}
};

