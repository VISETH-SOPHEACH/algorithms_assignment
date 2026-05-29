#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
  cout << "[ ";
  for (int i = 0; i < n; i++)
    cout << a[i] << (i < n - 1 ? ", " : " ");
  cout << "]" << endl;
}

void heapify(int a[], int heapSize, int i, int fullSize)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  cout << "    Heapify index " << i << " with heap size " << heapSize << endl;

  if (left < heapSize)
  {
    cout << "      Left child a[" << left << "]=" << a[left] << endl;
    if (a[left] > a[largest])
      largest = left;
  }

  if (right < heapSize)
  {
    cout << "      Right child a[" << right << "]=" << a[right] << endl;
    if (a[right] > a[largest])
      largest = right;
  }

  if (largest != i)
  {
    cout << "      Swap a[" << i << "]=" << a[i]
         << " with a[" << largest << "]=" << a[largest] << endl;
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    cout << "      Array: ";
    printArray(a, fullSize);

    heapify(a, heapSize, largest, fullSize);
  }
  else
  {
    cout << "      No swap needed." << endl;
  }
}

int main()
{
  int a[6] = {40, 60, 2, 3, 30, 20};
  int n = 6;

  cout << "=== Heap Sort Step by Step ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);

  cout << "\nPhase 1: Build max heap" << endl;
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(a, n, i, n);
    cout << "  After heapify at index " << i << ": ";
    printArray(a, n);
  }

  cout << "\nPhase 2: Move max to the end and heapify again" << endl;
  for (int i = n - 1; i > 0; i--)
  {
    cout << "  Swap max a[0]=" << a[0]
         << " with a[" << i << "]=" << a[i] << endl;
    int temp = a[0];
    a[0] = a[i];
    a[i] = temp;
    cout << "  Array after moving max: ";
    printArray(a, n);

    heapify(a, i, 0, n);
    cout << "  Array after heapify: ";
    printArray(a, n);
  }

  cout << "\nSorted Array: ";
  printArray(a, n);

  return 0;
}
