#include <iostream>
using namespace std;

int main()
{
  int a[6] = {40, 60, 2, 3, 30, 20};

  for (int i = 0; i < 6 - 1; i++)
  {
    for (int j = 0; j < 6 - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  cout << "Sorted Array: ";
  for (int i = 0; i < 6; i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}
