#include <iostream>

using namespace std;

void merge(int arr[], int start, int mid, int end) {
	int start2 = mid+1;
	if (arr[mid] <= arr[start2]) {
		return ;
	} else {
		while (start <= mid && start2<=end) {
			if (arr[start] <= arr[start2]) {
				start++;
			} else {
				int value = arr[start2];
				int index = start2;
				while (index != start) {
					arr[index] = arr[index-1];
					index--;
				}
				arr[start] = value;
				merge(arr, start+1, start2, end);
			}
		}
	}
}

void mergesort(int arr[], int start, int end) {
	if (start < end) {
		return ;
	} else {
		int mid = 1 + (end-1)/2;
		int q1 = mid/2;
		int q2 = mid + mid/2;
		
		merge(arr, start, q1, end);
		merge(arr, mid, q2, end);
		merge(arr, start, mid, end);
	}
}

int main() {
	int a[] = {3, 9, 12, 2, 10, 17};
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	merge(a, 0, 2, 5);
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	mergesort(a, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}