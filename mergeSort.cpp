#include <iostream>
#include <vector>
using namespace std;

void printArray(int a[], int n)
{
  cout << "[ ";
  for (int i = 0; i < n; i++)
    cout << a[i] << (i < n - 1 ? ", " : " ");
  cout << "]" << endl;
}

void printIndent(int depth)
{
  for (int i = 0; i < depth; i++)
    cout << "  ";
}

void merge(int a[], int left, int mid, int right, int depth)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = a[left + i];

  for (int j = 0; j < n2; j++)
    R[j] = a[mid + 1 + j];

  printIndent(depth);
  cout << "Merge indexes [" << left << ".." << mid << "] and ["
       << mid + 1 << ".." << right << "]" << endl;

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    printIndent(depth);
    cout << "  Compare " << L[i] << " and " << R[j];

    if (L[i] <= R[j])
    {
      a[k] = L[i];
      cout << " -> put " << L[i] << " at index " << k << endl;
      i++;
    }
    else
    {
      a[k] = R[j];
      cout << " -> put " << R[j] << " at index " << k << endl;
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    printIndent(depth);
    cout << "  Copy remaining left value " << L[i]
         << " to index " << k << endl;
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    printIndent(depth);
    cout << "  Copy remaining right value " << R[j]
         << " to index " << k << endl;
    a[k] = R[j];
    j++;
    k++;
  }

  printIndent(depth);
  cout << "  Segment after merge: [ ";
  for (int x = left; x <= right; x++)
    cout << a[x] << " ";
  cout << "]" << endl;
}

void mergeSort(int a[], int left, int right, int depth = 0)
{
  if (left < right)
  {
    int mid = (left + right) / 2;

    printIndent(depth);
    cout << "Split [" << left << ".." << right << "] into ["
         << left << ".." << mid << "] and ["
         << mid + 1 << ".." << right << "]" << endl;

    mergeSort(a, left, mid, depth + 1);
    mergeSort(a, mid + 1, right, depth + 1);
    merge(a, left, mid, right, depth);
  }
}

int main()
{
  int a[6] = {40, 60, 2, 3, 30, 20};
  int n = 6;

  cout << "=== Merge Sort Step by Step ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);

  mergeSort(a, 0, n - 1);

  cout << "\nSorted Array: ";
  printArray(a, n);

  return 0;
}
