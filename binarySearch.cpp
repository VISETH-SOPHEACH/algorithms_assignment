#include <iostream>
using namespace std;

int main()
{
  int a[6] = {2, 3, 20, 30, 40, 60};
  int key;

  cout << "Enter number to search: ";
  cin >> key;

  int left = 0, right = 5;
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
    cout << "Found at index: " << found;
  else
    cout << "Not found";

  return 0;
}