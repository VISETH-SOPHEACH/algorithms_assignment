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

  cout << "=== Selection Sort Step by Step ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);

  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;

    cout << "\nPass " << i + 1 << ": find minimum from index "
         << i << " to " << n - 1 << endl;
    cout << "  Current minimum: a[" << minIndex << "]=" << a[minIndex] << endl;

    for (int j = i + 1; j < n; j++)
    {
      cout << "  Check a[" << j << "]=" << a[j];
      if (a[j] < a[minIndex])
      {
        minIndex = j;
        cout << " -> new minimum" << endl;
      }
      else
      {
        cout << " -> keep current minimum" << endl;
      }
    }

    if (minIndex != i)
    {
      cout << "  Swap a[" << i << "]=" << a[i]
           << " with a[" << minIndex << "]=" << a[minIndex] << endl;
      int temp = a[i];
      a[i] = a[minIndex];
      a[minIndex] = temp;
    }
    else
    {
      cout << "  Minimum already in correct position." << endl;
    }

    cout << "  Array now: ";
    printArray(a, n);
  }

  cout << "\nSorted Array: ";
  printArray(a, n);

  return 0;
}
