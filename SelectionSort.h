#pragma once
#include "Header.h"
#include "DoubleArr.h"
class SelectionSort {
public:
	void operator()(const DoubleArr& arr, int i,ofstream& f) {
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		DoubleArr newArr = arr;
		int index=sort(newArr,0,newArr.getSize()-1,i);
		cout << "Selection i'th element: ";
		newArr.printDouble(index);
		cout << endl;

		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		f << "Time taken by function Selection sort is : " << fixed << time_taken << setprecision(9);
		f << " sec" << endl;
	}
private:
	int sort(DoubleArr& arr,const int begin,const int end,int i) {
		
		int pivot = partition(arr, begin, end);

		int leftPartSize = pivot - begin + 1;

		if (i == leftPartSize) {
			return pivot;
		}
		else if (i < leftPartSize) {
			return sort(arr, begin, pivot - 1, i);
		}
		else {
			return sort(arr, pivot + 1, end, i - leftPartSize);
		}
	}

	int partition(DoubleArr& arr,const int begin,const int end) {
		int pivot = begin;
		int p = end;

		while (p != pivot) {
			while (p > pivot && arr[p] > arr[pivot]) {
				p--;}

			if (p != pivot) {
				arr.swap(p, pivot);
				swapInt(p, pivot);
			}
 while (p < pivot && arr[p] < arr[pivot]) {
	p++;	}

 if (p != pivot) {
	 arr.swap(p, pivot);
	 swapInt(p, pivot);
}}
		return pivot;
	}
};
