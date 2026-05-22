#include <iostream>
using namespace std;

int main()
{
  int a[6] = {40, 60, 2, 3, 30, 20};

  for (int i = 0; i < 6 - 1; i++)
  {
    int minIndex = i;

    for (int j = i + 1; j < 6; j++)
    {
      if (a[j] < a[minIndex])
      {
        minIndex = j;
      }
    }

    int temp = a[i];
    a[i] = a[minIndex];
    a[minIndex] = temp;
  }

  cout << "Sorted Array: ";
  for (int i = 0; i < 6; i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}