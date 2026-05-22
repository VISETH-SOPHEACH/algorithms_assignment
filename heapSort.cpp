#include <iostream>
using namespace std;

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
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;

    heapify(a, n, largest);
  }
}

int main()
{
  int a[6] = {40, 60, 2, 3, 30, 20};
  int n = 6;

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(a, n, i);

  for (int i = n - 1; i > 0; i--)
  {
    int temp = a[0];
    a[0] = a[i];
    a[i] = temp;

    heapify(a, i, 0);
  }

  cout << "Sorted Array: ";
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  return 0;
}