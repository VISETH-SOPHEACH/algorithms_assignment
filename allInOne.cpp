#include <algorithm>
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

void sequentialSearch(int a[], int n, int key)
{
  cout << "\n=== Sequential Search Step by Step ===" << endl;
  cout << "Array: ";
  printArray(a, n);

  int found = -1;
  for (int i = 0; i < n; i++)
  {
    cout << "Step " << i + 1 << ": check a[" << i << "]=" << a[i];
    if (a[i] == key)
    {
      found = i;
      cout << " -> found" << endl;
      break;
    }
    cout << " -> not a match" << endl;
  }

  if (found != -1)
    cout << "Result: Found " << key << " at index " << found << endl;
  else
    cout << "Result: " << key << " not found" << endl;
}

void binarySearch(int a[], int n, int key)
{
  cout << "\n=== Binary Search Step by Step ===" << endl;
  cout << "Array must be sorted: ";
  printArray(a, n);

  int left = 0, right = n - 1, found = -1, step = 1;

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
    cout << "Result: Found " << key << " at index " << found << endl;
  else
    cout << "Result: " << key << " not found" << endl;
}

void bubbleSort(int a[], int n)
{
  cout << "\n=== Bubble Sort Step by Step ===" << endl;
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
        swap(a[j], a[j + 1]);
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
}

void selectionSort(int a[], int n)
{
  cout << "\n=== Selection Sort Step by Step ===" << endl;
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
      swap(a[i], a[minIndex]);
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
}

void heapify(int a[], int heapSize, int i, int fullSize)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  cout << "    Heapify index " << i << " with heap size " << heapSize << endl;

  if (left < heapSize)
  {
    cout << "      Left child a[" << left << "]=" << a[left] << endl;
    if (a[left] > a[largest])
      largest = left;
  }

  if (right < heapSize)
  {
    cout << "      Right child a[" << right << "]=" << a[right] << endl;
    if (a[right] > a[largest])
      largest = right;
  }

  if (largest != i)
  {
    cout << "      Swap a[" << i << "]=" << a[i]
         << " with a[" << largest << "]=" << a[largest] << endl;
    swap(a[i], a[largest]);
    cout << "      Array: ";
    printArray(a, fullSize);
    heapify(a, heapSize, largest, fullSize);
  }
  else
  {
    cout << "      No swap needed." << endl;
  }
}

void heapSort(int a[], int n)
{
  cout << "\n=== Heap Sort Step by Step ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);

  cout << "\nPhase 1: Build max heap" << endl;
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(a, n, i, n);
    cout << "  After heapify at index " << i << ": ";
    printArray(a, n);
  }

  cout << "\nPhase 2: Move max to the end and heapify again" << endl;
  for (int i = n - 1; i > 0; i--)
  {
    cout << "  Swap max a[0]=" << a[0]
         << " with a[" << i << "]=" << a[i] << endl;
    swap(a[0], a[i]);
    cout << "  Array after moving max: ";
    printArray(a, n);
    heapify(a, i, 0, n);
    cout << "  Array after heapify: ";
    printArray(a, n);
  }

  cout << "\nSorted Array: ";
  printArray(a, n);
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
    cout << "  Copy remaining left value " << L[i] << " to index " << k << endl;
    a[k++] = L[i++];
  }

  while (j < n2)
  {
    printIndent(depth);
    cout << "  Copy remaining right value " << R[j] << " to index " << k << endl;
    a[k++] = R[j++];
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

void runMergeSort(int a[], int n)
{
  cout << "\n=== Merge Sort Step by Step ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);
  mergeSort(a, 0, n - 1);
  cout << "\nSorted Array: ";
  printArray(a, n);
}

void displayMenu()
{
  cout << "\n+--------------------------------------+" << endl;
  cout << "|     Sorting & Searching Algorithms   |" << endl;
  cout << "+--------------------------------------+" << endl;
  cout << "|  1. Sequential Search                |" << endl;
  cout << "|  2. Binary Search (uses sorted data) |" << endl;
  cout << "|  3. Bubble Sort                      |" << endl;
  cout << "|  4. Selection Sort                   |" << endl;
  cout << "|  5. Heap Sort                        |" << endl;
  cout << "|  6. Merge Sort                       |" << endl;
  cout << "|  7. Run all six step by step         |" << endl;
  cout << "|  0. Exit                             |" << endl;
  cout << "+--------------------------------------+" << endl;
  cout << "Choose an option: ";
}

int main()
{
  int original[6] = {40, 60, 2, 3, 30, 20};
  int sortedForBinary[6] = {2, 3, 20, 30, 40, 60};
  int a[6];
  int n = 6;
  int choice;

  do
  {
    displayMenu();
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      int key;
      cout << "Enter search key: ";
      cin >> key;
      copy(original, original + n, a);
      sequentialSearch(a, n, key);
      break;
    }
    case 2:
    {
      int key;
      cout << "Enter search key: ";
      cin >> key;
      copy(sortedForBinary, sortedForBinary + n, a);
      binarySearch(a, n, key);
      break;
    }
    case 3:
      copy(original, original + n, a);
      bubbleSort(a, n);
      break;
    case 4:
      copy(original, original + n, a);
      selectionSort(a, n);
      break;
    case 5:
      copy(original, original + n, a);
      heapSort(a, n);
      break;
    case 6:
      copy(original, original + n, a);
      runMergeSort(a, n);
      break;
    case 7:
      sequentialSearch(original, n, 30);
      binarySearch(sortedForBinary, n, 30);
      copy(original, original + n, a);
      bubbleSort(a, n);
      copy(original, original + n, a);
      selectionSort(a, n);
      copy(original, original + n, a);
      heapSort(a, n);
      copy(original, original + n, a);
      runMergeSort(a, n);
      break;
    case 0:
      cout << "\nGoodbye!" << endl;
      break;
    default:
      cout << "\nInvalid option. Please choose 0-7." << endl;
    }
  } while (choice != 0);

  return 0;
}
