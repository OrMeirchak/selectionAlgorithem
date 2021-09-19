#pragma once
#include "DoubleArr.h"
class QuintupletSort{
public:
	void operator()(const DoubleArr& arr, int i,ofstream &f) {
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		DoubleArr newArr = arr;
		int index = algorithm(newArr,0,arr.getSize()-1,i);
		cout << "Quintuplet algorithm i'th element: ";
		newArr.printDouble(index);
		cout << endl;

		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		f << "Time taken by function Quintuplet Sort is : " << fixed << time_taken << setprecision(9);
		f << " sec" << endl;
	}

private:
	int algorithm(DoubleArr& arr,int begin,int end, int i){
		
		int arrSize = end - begin + 1;
		if (arrSize<=5) {
			if (arrSize == 1) {
				return begin;
			}
			else {
				bubbleSort(arr,begin,end);
				return(begin + i-1);
			}	
		}
		else{
			DoubleArr mediansArr = makeMediansArray(arr, begin, end);
			int medianOfMediansIndex = algorithm(mediansArr, 0, mediansArr.getSize() - 1,getMid(mediansArr.getSize()));
			double pivotValue = mediansArr[medianOfMediansIndex];
			int pivotIndex = partition(arr, begin, end, pivotValue);
		
			if ((pivotIndex+1)-begin > i) {
				return algorithm(arr, begin,pivotIndex - 1, i);
			}
			else if(((pivotIndex + 1) - begin )<i){
				return algorithm(arr, pivotIndex + 1, end,i - (pivotIndex-begin)-1);
			}
			else {
				return pivotIndex;
			}
		}
	}

	int partition(DoubleArr& arr, const int begin, const int end,const double pivotValue) {
		int pLeft = begin;
		int pRight = end;
		int indexOfPivot;

		while (pLeft < pRight) {
			while (pLeft < end && arr[pLeft] <= pivotValue) {
				if (pivotValue == arr[pLeft]) {
					indexOfPivot = pLeft;
				}

				pLeft++;
			}
			while (pRight >= 0 && arr[pRight] >= pivotValue) {
				if (pivotValue == arr[pRight]) {
					indexOfPivot = pRight;
				}

				pRight--;
			}
			
			if (pLeft < pRight) {
				arr.swap(pLeft, pRight);
			}
		}

		if (indexOfPivot > pLeft) {
			arr.swap(indexOfPivot, pLeft);
			return pLeft;
		}
		else if (indexOfPivot < pRight) {
			arr.swap(indexOfPivot, pRight);
				return pRight;
		}
		else {
			return pRight + 1;
		}
	}

	void bubbleSort(DoubleArr& arr, int begin, int end) {
		int size = end - begin + 1;
		for (int i = 0; i < size; i++) {
			bool swaps = false;
			for (int j = begin; j <= end - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					arr.swap(j, j + 1);
					swaps = true;
				}
			}
			if (!swaps)
				break;
		}
	}

	DoubleArr makeMediansArray(DoubleArr& arr,int begin,int end) {
		DoubleArr res(ceil(float((end-begin + 1) / 5.)));

		for (int idx = 0; idx < res.getSize(); idx++) {
			int left = begin+(idx * 5);
			int right = (left + 4);

			if (right > end) {
				right = end;
			}
			int size = right - left + 1;
			res[idx] = arr[algorithm(arr, left, right, getMid(size))];
		}
		return res;
	}

	static bool odd(int num) {
		return (num % 2);
	}

	static bool even(int num) {
		return !odd(num);
	}

	static int getMid(int size) {
		if (even(size)) {
			return( size / 2);
		}
		else {
			return( (size + 1) / 2);
		}
	}

	static int ceil(float num) {
		int temp = num;
		if (temp < num) {
			return temp + 1;
		}
		else {
			return temp;
		}
	}
};
