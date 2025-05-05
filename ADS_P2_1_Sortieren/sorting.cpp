#include "sorting.h"
#include <cmath>


namespace sorting {

	//************
	// QuickSort *
	//************      
	int Partition(vector<int>& arr, int p, int r) {
		int x = arr[r];
		int i = p - 1;

		for (int j = p; j < r; j++) {
			if (arr[j] <= x) {
				i++;
				swap(arr[j], arr[i]);
			}
		}
		swap(arr[i + 1], arr[r]);

		return i + 1;
	}

	int median3(vector<int>& a, int left, int right) {
		int center = (left + right) / 2;
		if (a[center] < a[left])
			swap(a[left], a[center]);
		if (a[right], a[left])
			swap(a[left], a[right]);
		if (a[right] < a[center])
			swap(a[center], a[right]);
		swap(a[center], a[right]);
		return center;
	}

	//Rekursive Funktion
	void QuickSort(vector<int>& arr, int left, int right)
	{
		if (left < right) {
			//Find Pivot
			int q = Partition(arr, left, right);
			QuickSort(arr, left, q - 1);
			QuickSort(arr, q + 1, right);
		}
		
	}

	void InsertionSort(vector<int>& arr)
	{
		for (int i = 1; i < arr.size(); i++) {
			int tmp = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > tmp) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = tmp;
		}
	}

	//************
	// MergeSort *
	//************
	void Merge(vector<int>& a, vector<int>& b, int low, int pivot, int high)
	{
		int leftEnd = pivot - 1,
			tmpPos = low, 
			n = high - low + 1,
			leftPos = low, 
			rightPos = pivot, 
			rightEnd = high;

		//Iterate left and right pos until right and left end
		while (leftPos <= leftEnd && rightPos <= rightEnd) {
			//Compare left and right pos
			if (a[leftPos] <= a[rightPos]) {
				//If leftpos is smaller, place element on array b and increment leftpos
				b[tmpPos] = a[leftPos];
				leftPos++;

			} else {
				//If rightpos is smaller, place element on array b and increment rightpos
				b[tmpPos] = a[rightPos];
				rightPos++;
			}
			//Update index array b
			tmpPos++;
		}

		//If right is finished, the left is from left
		while (leftPos <= leftEnd) {
			b[tmpPos] = a[leftPos];
			tmpPos++;
			leftPos++;
		}

		//If left is finished, the left is from right
		while (rightPos <= rightEnd) {
			b[tmpPos] = a[rightPos];
			rightPos++;
			tmpPos++;
		}

		//Copy
		int i = rightEnd - n + 1;
		while (i <= rightEnd) {
			a[i] = b[i];
			i++;
		}
	}

	//Rekursive Funktion
	//Divides the Array into 2 equal size arrays
	void MergeSort(vector<int>& a, vector<int>& b, int low, int high)
	{
		if (low < high) {
			size_t middle = size_t((low+high)/2);
			MergeSort(a, b, low, middle);
			MergeSort(a, b, middle + 1, high);
			Merge(a, b, low, middle + 1, high);
		}
	}

	void natMerge(vector<int> &a, vector<int> &b, int left, int middle, int right) 
	{
		int leftEnd = middle - 1, 
		tmpPos = left, 
		n = right - left + 1,
		leftPos = left, 
		rightPos = middle, 
		rightEnd = right;
		
		while (leftPos <= leftEnd && rightPos <= rightEnd) {
			if (a[leftPos] <= a[rightPos]) {
				b[tmpPos] = a[leftPos];
				leftPos++;
			}
			else {
				b[tmpPos] = a[rightPos];
				rightPos++;
			}
			tmpPos++;
		}
		while (leftPos <= leftEnd) {
			b[tmpPos] = a[leftPos];
			tmpPos++;
			leftPos++;
		}
		while (rightPos <= rightEnd) {
			b[tmpPos] = a[rightPos];
			rightPos++;
			tmpPos++;
		}
		int i = 0;
		while (i < n) {
			a[rightEnd] = b[rightEnd];
			rightEnd--;
			i++;
		}
	}

	void natMergeSort(vector<int> &a, vector<int> &b)
	{
		int run = 0;
		vector<int> section(a.size() + 1);
		section[0] = 0;
		for (int i = 1; i <= a.size(); i++) {
			//Save index of section end
			if (i == a.size()) {
				run++;
				section[run] = i;
			}
			else if (a[i] < a[i - 1]) {
				run++;
				section[run] = i;
			}
		}
		//Merge sections
		while (run > 1) {
			int newrun = 0;
			for (int i = 0; i < run; i += 2) {
				natMerge(a, b, section[i], section[i + 1], section[i + 2] - 1);
				section[newrun] = section[i];
				newrun++;
			}
			section[newrun] = section[run];
			run = newrun;
			
		}
	}


	//************
	// Heapsort  *
	//************

	//Find the left child of a node
	int leftChild(int const i) {
		return 2 * i + 1;
	}

	//Maintain max heap
	void heapify(vector<int> &a, int n, int i)
	{
		int child = i;
		int tmp = a[i];

		//Iterate as long as leftchild(i) is < n
		for (tmp = a[i]; leftChild(i) < n; i = child) {
			//Update child as the leftchild(i)
			child = leftChild(i);

			//If right child exists and is > leftchild, child is the right child
			if (child != n - 1 && a[child] < a[child + 1]) {
				child++;
			}
			//If tmp is smaller than the larger child, swap
			if (tmp < a[child]) {
				a[i] = a[child];
			}
			else
				break;
		}
		//Place tmp on the correct position
		a[i] = tmp;
	}

	//Using max heap
	void HeapSort(vector<int> &a, int n) 
	{
		//Build the max heap
		int i = n/2;
		while (i >= 0) {
			heapify(a, n, i);
			i--;
		}
		
		//Swap root with last element, then heapify
		int j = n - 1;
		while (j > 0){
			swap(a[0],a[j]);
			heapify(a, j, 0);
			j--;
		}
	}

	//************
	// Shellsort *
	//************
	// Hier soll Hibbard implementiert werden
	void ShellSort_2n(vector<int> &a, int n)
	{
		//Feldgroesse
		n = a.size();

		//H(0) von Hibbard Folge = 0
        int hibbard = 1;

		//Find to the max hibbard sequence value
        do {
            hibbard = (2*hibbard) + 1;
        } while(((2*hibbard) + 1) < n);

		//Start with max. element of the sequence and go down
        for(int gap = hibbard; gap > 0; gap = (gap-1)/2) {
			//Insertion Sort von Elementen mit Abstand gap
            for(int i = gap; i < n; i++) {
                int tmp = a[i];
                int j = i;
                
				for(; j >= gap && tmp < a[j-gap]; j -= gap){
                    a[j] = a[j-gap];
                }
                
				a[j] = tmp;
            }
        }
	}

	void ShellSort_3n(vector<int>& a, int n)
	{
		int folge = 1, gap = 1, tmp, j;
		while (folge < n) {
			gap = folge;
			folge = (3 * folge) + 1;
		}
		for (; gap > 0; gap /= 3) {
			for (int i = gap; i < n; i++) {
				tmp = a[i];
				for (j = i; j >= gap; j -= gap) {
					if (tmp < a[j - gap])
						a[j] = a[j - gap];
					else
						break;
				}
				a[j] = tmp;
			}
		}
	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}





