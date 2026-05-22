#include <iostream>
#include <vector>
using namespace std;

// 1. Sequential Search
void sequentialSearch(int a[], int n, int key)
{
  int found = -1;

  for (int i = 0; i < n; i++)
  {
    if (a[i] == key)
    {
      found = i;
      break;
    }
  }

  if (found != -1)
    cout << "Sequential Search: Found at index " << found << endl;
  else
    cout << "Sequential Search: Not found" << endl;
}

// 2. Binary Search
void binarySearch(int a[], int n, int key)
{
  int left = 0, right = n - 1;
  int found = -1;

  while (left <= right)
  {
    int mid = (left + right) / 2;

    if (a[mid] == key)
    {
      found = mid;
      break;
    }
    else if (a[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }

  if (found != -1)
    cout << "Binary Search: Found at index " << found << endl;
  else
    cout << "Binary Search: Not found" << endl;
}

// Print Array
void printArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

// 3. Bubble Sort
void bubbleSort(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
      }
    }
  }

  cout << "Bubble Sort: ";
  printArray(a, n);
}

// 4. Selection Sort
void selectionSort(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;

    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[minIndex])
      {
        minIndex = j;
      }
    }

    swap(a[i], a[minIndex]);
  }

  cout << "Selection Sort: ";
  printArray(a, n);
}

// Heapify function
void heapify(int a[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && a[left] > a[largest])
    largest = left;

  if (right < n && a[right] > a[largest])
    largest = right;

  if (largest != i)
  {
    swap(a[i], a[largest]);
    heapify(a, n, largest);
  }
}

// 5. Heap Sort
void heapSort(int a[], int n)
{

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(a, n, i);

  for (int i = n - 1; i > 0; i--)
  {
    swap(a[0], a[i]);
    heapify(a, i, 0);
  }

  cout << "Heap Sort: ";
  printArray(a, n);
}

// Merge function
void merge(int a[], int left, int mid, int right)
{

  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = a[left + i];

  for (int j = 0; j < n2; j++)
    R[j] = a[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      a[k] = L[i];
      i++;
    }
    else
    {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    a[k] = R[j];
    j++;
    k++;
  }
}

// 6. Merge Sort
void mergeSort(int a[], int left, int right)
{

  if (left < right)
  {

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
  }
}

int main()
{

  int original[6] = {40, 60, 2, 3, 30, 20};
  int a[6];
  int n = 6;

  // Sequential Search
  copy(original, original + n, a);
  sequentialSearch(a, n, 30);

  // Bubble Sort
  copy(original, original + n, a);
  bubbleSort(a, n);

  // Selection Sort
  copy(original, original + n, a);
  selectionSort(a, n);

  // Heap Sort
  copy(original, original + n, a);
  heapSort(a, n);

  // Merge Sort
  copy(original, original + n, a);
  mergeSort(a, 0, n - 1);

  cout << "Merge Sort: ";
  printArray(a, n);

  // Binary Search (need sorted array)
  binarySearch(a, n, 30);

  return 0;
}