#pragma once
#include "Header.h"
#include "DoubleArr.h"
class InsertionSort {
public:
	void operator()(const DoubleArr& arr, int i,ofstream& f) {
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		DoubleArr newArray = arr;
		sort(newArray);
		cout << "Insertion sort i'th element: ";
		newArray.printDouble(i-1);
		cout << endl;

		auto end = chrono::high_resolution_clock::now();
			double time_taken =chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		f << "Time taken by function Insertion sort is : " << fixed<< time_taken << setprecision(9);
		f << " sec" << endl;
	}
private:
	void sort(DoubleArr& arr) {
		for (int theLastElementOfTheSortedArray = 0; theLastElementOfTheSortedArray < arr.getSize() - 1 ;theLastElementOfTheSortedArray++){
			for (int p = theLastElementOfTheSortedArray + 1; (p > 0) && (arr[p] < arr[p - 1]); p--){
				arr.swap(p, p - 1);
			}
			
		}
	}
};