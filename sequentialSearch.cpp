#include <iostream>
using namespace std;

int main()
{
  int a[6] = {40, 60, 2, 3, 30, 20};
  int key, found = -1;

  cout << "Enter number to search: ";
  cin >> key;

  for (int i = 0; i < 6; i++)
  {
    if (a[i] == key)
    {
      found = i;
      break;
    }
  }

  if (found != -1)
    cout << "Found at index: " << found;
  else
    cout << "Not found";

  return 0;
}