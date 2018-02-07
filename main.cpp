#include "vld.h"
#include "Sorting.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand((size_t)time(NULL));
	vector<int> arr, a;
	unsigned long long t1 = 0, t2 = 0;
	size_t n;
	cout << "Enter quantity of elements: ";
	cin >> n;
	for (size_t i = 0; i < n; i++) arr.push_back(rand() % 10000);

	a = arr;
	t1 = clock();
	BubbleSort(a);
	t2 = clock();
	cout << "BubbleSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	SelectionSort(a);
	t2 = clock();
	cout << "SelectionSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	InsertionSort(a);
	t2 = clock();
	cout << "InsertionSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	ShellSort(a);
	t2 = clock();
	cout << "ShellSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	CockTailSort(a);
	t2 = clock();
	cout << "CockTailSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	MergeSort(a);
	t2 = clock();
	cout << "MergeSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	QuickSort(a);
	t2 = clock();
	cout << "QuickSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	BucketSort(a);
	t2 = clock();
	cout << "BucketSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	CountingSort(a);
	t2 = clock();
	cout << "CountingSort\t" << t2 - t1 << endl;

	a = arr;
	t1 = clock();
	RadixSort(a);
	t2 = clock();
	cout << "RadixSort\t" << t2 - t1 << endl;


	system("pause");
	return 0;
}