#include <vector>
using namespace std;

// Пузырьковая сортировка
template <class T>
void BubbleSort(vector<T> &arr)
{
	size_t s = arr.size();
	for (size_t i = 0; i < s; i++)
		for (size_t j = i; j < s; j++)
			if (arr[j] < arr[i]) swap(arr[i], arr[j]);
}

// Выборочная сортировка (сортировка выбором)
template <class T>
void SelectionSort(vector<T> &arr)
{
	size_t s = arr.size();
	size_t min_ind = 0;
	for (size_t i = 0; i < s; i++)
	{
		for (size_t j = i; j < s; j++)
			if (arr[j] < arr[min_ind]) min_ind = j;
		swap(arr[i], arr[min_ind]);
	}
}

// Сортировка вставками
template <class T>
void InsertionSort(vector<T> &arr)
{
	size_t s = arr.size();
	for (size_t i = 1; i < s; i++)
	{
		T current = arr[i];
		size_t j = i;
		while (j && current < arr[j - 1]) arr[j] = arr[j - 1], j--;
		arr[j] = current;
	}
}

// Сортировка Шелла
template <class T>
void ShellSort(vector<T> &arr)
{
	size_t s = arr.size();
	for (size_t i = s >> 1; i; i >>= 1)
		for (size_t j = i; j < s; j++)
			for (size_t k = j; k >= i && (arr[k] < arr[k-i]); k -= i)
				swap(arr[k], arr[k - i]);
}

// Шейкерная сортировка (сортировка перемешиванием)
template <class T>
void CockTailSort(vector<T> &arr)
{
	size_t s = arr.size();
	for (size_t l = 0, r = s - 1; l < r;)
	{
		for (size_t i = l; i < r; i++)
			if (arr[i + 1] < arr[i]) swap(arr[i], arr[i + 1]);
		r--;
		for (size_t i = r; i > l; i--)
			if (arr[i] < arr[i - 1]) swap(arr[i], arr[i - 1]);
		l++;
	}
}

// Сортировка слияниями
template <class T>
void merge(vector<T> &arr, size_t &l, size_t &m, size_t &r) 
{
	size_t it1 = 0, it2 = 0;
	vector<T> result(r - l);
	while ((l + it1 < m) && (m + it2 < r))
	{
		if (arr[l + it1] < arr[m + it2])
		{
			result[it1 + it2] = arr[l + it1];
			it1++;
		}
		else
		{
			result[it1 + it2] = arr[m + it2];
			it2++;
		}
	}
	while (l + it1 < m)
	{
		result[it1 + it2] = arr[l + it1];
		it1++;
	}
	while (m + it2 < r)
	{
		result[it1 + it2] = arr[m + it2];
		it2++;
	}
	for (size_t i = 0; i < it1 + it2; i++) 
		arr[l + i] = result[i];
}
template <class T>
void merge_rec(vector<T> &arr, size_t l, size_t r)
{
	if (l + 1 >= r) return;
	size_t m = (l + r) >> 1;
	merge_rec(arr, l, m);
	merge_rec(arr, m, r);
	merge(arr, l, m, r);
}
template <class T>
void MergeSort(vector<T> &arr)
{
	merge_rec(arr, 0, arr.size());
}

// Быстрая сортировка (сортировка Хоара)
template <class T>
void quick(vector<T> &arr, size_t l, size_t r)
{
	if (l >= r) return;
	T support = arr[(l + r) >> 1];
	size_t i = l, j = r;
	do
	{
		while (arr[i] < support) i++;
		while (support < arr[j]) j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (i <= j);
	quick(arr, l, j);
	quick(arr, i, r);
}
template <class T>
void QuickSort(vector<T> &arr)
{
	quick(arr, 0, arr.size() - 1);
}

// Блочная сортировка (черпаковая, корзинная, ведерная)
template <class T>
void BucketSort(vector<T> &arr)
{
	struct Node
	{
		T data;
		Node* next;
		Node(T _data, Node *_next): data(_data), next(_next){}
	};
	size_t s = arr.size();
	Node **mass = new Node*[s];
	for (size_t i = 0; i < s; i++) mass[i] = nullptr;
	T max_el = arr[0];
	for (size_t i = 0; i < s; i++)
		if (arr[i] > max_el) max_el = arr[i];
	max_el++;
	for (size_t i = 0; i < s; i++)
	{
		size_t k = (arr[i] * s) / max_el;
		if (!mass[k]) mass[k] = new Node(arr[i], nullptr);
		else if (arr[i] <= mass[k]->data) mass[k] = new Node(arr[i], mass[k]);
		else 
		{
			Node *p = mass[k];
			while (p->next && arr[i] >= p->next->data) p = p->next;
			p->next = new Node(arr[i], p->next);
		}
	}
	for (size_t i = 0, j = 0; i < s; i++)
	{
		if (!mass[i]) continue;
		Node *p = mass[i];
		while (p)
		{
			arr[j] = p->data;
			j++;
			Node *k = p;
			p = p->next;
			delete k;
		}
	}
	delete[] mass;
}

// Сортировка подсчетом
template <class T>
void CountingSort(vector<T> &arr)
{
	size_t s = arr.size();
	T min_val = arr[0], max_val = arr[0];
	for (size_t i = 0; i < s; i++)
	{
		if (arr[i] < min_val) min_val = arr[i];
		else if (arr[i] > max_val) max_val = arr[i];
	}
	size_t l = (size_t)(max_val - min_val + 1), k = 0;
	size_t *mass = new size_t[l];
	for (size_t i = 0; i < l; i++) mass[i] = (T)0;
	for (size_t i = 0; i < s; i++) mass[arr[i] - min_val]++;
	for (T i = min_val; i <= max_val; i++)
		for (size_t j = mass[i - min_val]; j--;)
			arr[k++] = i;
	delete[] mass;
}

// Позарядная сортировка
template <class T>
void RadixSort(vector<T> &arr)
{
	size_t s = arr.size();
	size_t max_digit = 0, d1 = 1;
	for (size_t i = 0; i < s; i++)
		while (arr[i] / d1) { max_digit++; d1 *= 10; }
	d1 = 1;
	size_t digits[10];
	vector<T> new_arr(s);
	while (max_digit--)
	{
		for (size_t i = 0; i < 10; i++) digits[i] = 0;
		for (size_t i = 0; i < s; i++) digits[(arr[i] / d1) % 10]++;
		for (size_t i = 1; i < 10; i++) digits[i] += digits[i - 1];
		for (size_t i = s - 1; i < s; i--) new_arr[--digits[(arr[i] / d1) % 10]] = arr[i];
		arr = new_arr;
		d1 *= 10;
	}
}

// Сортировка кучей (пирамидальная сортировка)
template <class T>
void HeapSort(vector<T> &arr)
{
	// Смотри описание
}