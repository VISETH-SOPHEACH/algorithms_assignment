#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
  cout << "[ ";
  for (int i = 0; i < n; i++)
    cout << a[i] << (i < n - 1 ? ", " : " ");
  cout << "]" << endl;
}

int main()
{
  int a[6] = {40, 60, 2, 3, 30, 20};
  int n = 6;

  cout << "=== Bubble Sort Step by Step ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);

  for (int i = 0; i < n - 1; i++)
  {
    bool swapped = false;
    cout << "\nPass " << i + 1 << ":" << endl;

    for (int j = 0; j < n - i - 1; j++)
    {
      cout << "  Compare a[" << j << "]=" << a[j]
           << " and a[" << j + 1 << "]=" << a[j + 1];

      if (a[j] > a[j + 1])
      {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
        cout << " -> swap -> ";
        printArray(a, n);
      }
      else
      {
        cout << " -> no swap" << endl;
      }
    }

    if (!swapped)
    {
      cout << "  No swaps in this pass, so the array is sorted." << endl;
      break;
    }
  }

  cout << "\nSorted Array: ";
  printArray(a, n);

  return 0;
}
