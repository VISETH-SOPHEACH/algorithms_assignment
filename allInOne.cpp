#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ─── Print Array ────────────────────────────────────────────────────────────
void printArray(int a[], int n)
{
  cout << "[ ";
  for (int i = 0; i < n; i++)
    cout << a[i] << (i < n - 1 ? ", " : " ");
  cout << "]" << endl;
}

// ─── 1. Sequential Search ───────────────────────────────────────────────────
void sequentialSearch(int a[], int n, int key)
{
  cout << "\n=== Sequential Search (key = " << key << ") ===" << endl;
  cout << "Array: ";
  printArray(a, n);
  cout << "Start scanning from index 0 to " << n - 1 << "..." << endl;

  int found = -1;
  for (int i = 0; i < n; i++)
  {
    cout << "  Step " << i + 1 << ": Check index " << i
         << " -> a[" << i << "] = " << a[i];

    if (a[i] == key)
    {
      found = i;
      cout << "  [FOUND] MATCH! Stop searching." << endl;
      break;
    }
    else
    {
      cout << "  [MISS] Not a match. Continue." << endl;
    }
  }

  if (found != -1)
    cout << "Result: Found " << key << " at index " << found << endl;
  else
    cout << "Result: " << key << " not found in array." << endl;
}

// ─── 2. Binary Search ───────────────────────────────────────────────────────
void binarySearch(int a[], int n, int key)
{
  cout << "\n=== Binary Search (key = " << key << ") ===" << endl;
  cout << "Array (must be sorted): ";
  printArray(a, n);
  cout << "Using left/mid/right pointers to halve the search range..." << endl;

  int left = 0, right = n - 1, found = -1, step = 1;

  while (left <= right)
  {
    int mid = (left + right) / 2;
    cout << "  Step " << step++ << ": left=" << left
         << ", mid=" << mid << ", right=" << right
         << "  ->  a[mid]=" << a[mid];

    if (a[mid] == key)
    {
      found = mid;
      cout << "  [FOUND] MATCH!" << endl;
      break;
    }
    else if (a[mid] < key)
    {
      cout << "  -> key is LARGER, move left to " << mid + 1 << endl;
      left = mid + 1;
    }
    else
    {
      cout << "  -> key is SMALLER, move right to " << mid - 1 << endl;
      right = mid - 1;
    }
  }

  if (found != -1)
    cout << "Result: Found " << key << " at index " << found << endl;
  else
    cout << "Result: " << key << " not found in array." << endl;
}

// ─── 3. Bubble Sort ─────────────────────────────────────────────────────────
void bubbleSort(int a[], int n)
{
  cout << "\n=== Bubble Sort ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);
  cout << "Repeatedly swap adjacent elements if left > right..." << endl;

  for (int i = 0; i < n - 1; i++)
  {
    cout << "\n  Pass " << i + 1 << ":" << endl;
    bool swapped = false;

    for (int j = 0; j < n - i - 1; j++)
    {
      cout << "    Compare a[" << j << "]=" << a[j]
           << " and a[" << j + 1 << "]=" << a[j + 1];

      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
        swapped = true;
        cout << "  -> SWAP -> Array: ";
        printArray(a, n);
      }
      else
      {
        cout << "  -> No swap" << endl;
      }
    }

    if (!swapped)
    {
      cout << "    No swaps in this pass -> array is already sorted. Stop early." << endl;
      break;
    }
  }

  cout << "Result: ";
  printArray(a, n);
}

// ─── 4. Selection Sort ──────────────────────────────────────────────────────
void selectionSort(int a[], int n)
{
  cout << "\n=== Selection Sort ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);
  cout << "Find the minimum in the unsorted part and swap it to the front..." << endl;

  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    cout << "\n  Pass " << i + 1 << ": Unsorted range [" << i << ", " << n - 1 << "]" << endl;
    cout << "    Assume minimum is a[" << i << "]=" << a[i] << endl;

    for (int j = i + 1; j < n; j++)
    {
      cout << "    Check a[" << j << "]=" << a[j];
      if (a[j] < a[minIndex])
      {
        cout << "  < current min a[" << minIndex << "]=" << a[minIndex]
             << "  -> New min index = " << j << endl;
        minIndex = j;
      }
      else
      {
        cout << "  >= current min, skip." << endl;
      }
    }

    if (minIndex != i)
    {
      cout << "    Swap a[" << i << "]=" << a[i]
           << " with a[" << minIndex << "]=" << a[minIndex] << endl;
      swap(a[i], a[minIndex]);
    }
    else
    {
      cout << "    Minimum already in place, no swap needed." << endl;
    }

    cout << "    Array now: ";
    printArray(a, n);
  }

  cout << "Result: ";
  printArray(a, n);
}

// ─── Heapify (with trace) ────────────────────────────────────────────────────
void heapify(int a[], int n, int i, bool trace = false)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && a[left] > a[largest])
    largest = left;
  if (right < n && a[right] > a[largest])
    largest = right;

  if (largest != i)
  {
    if (trace)
      cout << "      Heapify: swap a[" << i << "]=" << a[i]
           << " with a[" << largest << "]=" << a[largest] << endl;
    swap(a[i], a[largest]);
    heapify(a, n, largest, trace);
  }
}

// ─── 5. Heap Sort ───────────────────────────────────────────────────────────
void heapSort(int a[], int n)
{
  cout << "\n=== Heap Sort ===" << endl;
  cout << "Initial array: ";
  printArray(a, n);

  // Phase 1 – Build max-heap
  cout << "\n  Phase 1: Build Max-Heap (heapify from bottom up)" << endl;
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    cout << "    Heapify subtree rooted at index " << i << " (value=" << a[i] << "):" << endl;
    heapify(a, n, i, true);
    cout << "      Array: ";
    printArray(a, n);
  }

  // Phase 2 – Extract max one by one
  cout << "\n  Phase 2: Extract max element and re-heapify" << endl;
  for (int i = n - 1; i > 0; i--)
  {
    cout << "    Move max a[0]=" << a[0]
         << " to position " << i << ", then heapify size=" << i << endl;
    swap(a[0], a[i]);
    heapify(a, i, 0, true);
    cout << "      Array: ";
    printArray(a, n);
  }

  cout << "Result: ";
  printArray(a, n);
}

// ─── Merge (with trace) ──────────────────────────────────────────────────────
void merge(int a[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = a[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = a[mid + 1 + j];

  cout << "      Merge [" << left << ".." << mid << "] and ["
       << mid + 1 << ".." << right << "]" << endl;
  cout << "        L: [ ";
  for (int x : L)
    cout << x << " ";
  cout << "]  R: [ ";
  for (int x : R)
    cout << x << " ";
  cout << "]" << endl;

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      a[k++] = L[i++];
    }
    else
    {
      a[k++] = R[j++];
    }
  }
  while (i < n1)
    a[k++] = L[i++];
  while (j < n2)
    a[k++] = R[j++];

  cout << "        Merged segment: [ ";
  for (int x = left; x <= right; x++)
    cout << a[x] << " ";
  cout << "]" << endl;
}

// ─── 6. Merge Sort ──────────────────────────────────────────────────────────
void mergeSort(int a[], int left, int right, int depth = 0)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    string indent(depth * 2, ' ');

    cout << indent << "  Split [" << left << ".." << right
         << "] -> left half [" << left << ".." << mid
         << "], right half [" << mid + 1 << ".." << right << "]" << endl;

    mergeSort(a, left, mid, depth + 1);
    mergeSort(a, mid + 1, right, depth + 1);
    merge(a, left, mid, right);
  }
}

// ─── Display Menu ────────────────────────────────────────────────────────────
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
  cout << "|  0. Exit                             |" << endl;
  cout << "+--------------------------------------+" << endl;
  cout << "Choose an option: ";
}

// ─── Main ────────────────────────────────────────────────────────────────────
int main()
{
  int original[6] = {40, 60, 2, 3, 30, 20};
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
      // Copy original then sort it first before binary searching
      copy(original, original + n, a);
      // cout << "\nNote: Binary search requires a sorted array." << endl;
      cout << "Sorting a copy of the array" << endl;
      sort(a, a + n);
      cout << "Sorted array: ";
      printArray(a, n);
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
      cout << "\n=== Merge Sort ===" << endl;
      cout << "Initial array: ";
      printArray(a, n);
      cout << "Recursively split array in half, then merge sorted halves..." << endl;
      mergeSort(a, 0, n - 1);
      cout << "Result: ";
      printArray(a, n);
      break;

    case 0:
      cout << "\nGoodbye!" << endl;
      break;

    default:
      cout << "\nInvalid option. Please choose 0-6." << endl;
    }

  } while (choice != 0);

  return 0;
}