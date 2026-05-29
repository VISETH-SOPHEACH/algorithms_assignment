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
  int a[6] = {2, 3, 20, 30, 40, 60};
  int key;

  cout << "Enter number to search: ";
  cin >> key;

  cout << "\n=== Binary Search Step by Step ===" << endl;
  cout << "Array must be sorted: ";
  printArray(a, 6);

  int left = 0, right = 5;
  int found = -1;
  int step = 1;

  while (left <= right)
  {
    int mid = (left + right) / 2;

    cout << "Step " << step++ << ": left=" << left
         << ", mid=" << mid << ", right=" << right
         << " -> a[mid]=" << a[mid];

    if (a[mid] == key)
    {
      found = mid;
      cout << " -> found" << endl;
      break;
    }
    else if (a[mid] < key)
    {
      cout << " -> key is larger, move left to " << mid + 1 << endl;
      left = mid + 1;
    }
    else
    {
      cout << " -> key is smaller, move right to " << mid - 1 << endl;
      right = mid - 1;
    }
  }

  if (found != -1)
    cout << "Result: Found at index " << found << endl;
  else
    cout << "Result: Not found" << endl;

  return 0;
}
