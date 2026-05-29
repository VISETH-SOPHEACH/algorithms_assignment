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
  int key, found = -1;

  cout << "Enter number to search: ";
  cin >> key;

  cout << "\n=== Sequential Search Step by Step ===" << endl;
  cout << "Array: ";
  printArray(a, 6);

  for (int i = 0; i < 6; i++)
  {
    cout << "Step " << i + 1 << ": check a[" << i << "]=" << a[i];
    if (a[i] == key)
    {
      found = i;
      cout << " -> found" << endl;
      break;
    }
    else
    {
      cout << " -> not a match" << endl;
    }
  }

  if (found != -1)
    cout << "Result: Found at index " << found << endl;
  else
    cout << "Result: Not found" << endl;

  return 0;
}
