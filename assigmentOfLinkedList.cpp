#include <iostream>
#include <windows.h>
#include <conio.h>
#include <algorithm>

using namespace std;

// ================= NODE STRUCTURE =================
struct Node
{

  float data;
  Node *nextNode;
};

typedef Node *NodePtr;

// ================= GOTOXY FUNCTION =================
void gotoxy(int x, int y)
{

  COORD c;

  c.X = x;
  c.Y = y;

  SetConsoleCursorPosition(
      GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// ================= COLOR FUNCTION =================
void setColor(int color)
{

  SetConsoleTextAttribute(
      GetStdHandle(STD_OUTPUT_HANDLE),
      color);
}

// ================= DRAW BOX =================
void drawBox(int x1, int y1, int x2, int y2)
{

  for (int i = x1; i <= x2; i++)
  {

    gotoxy(i, y1);
    cout << char(205);

    gotoxy(i, y2);
    cout << char(205);
  }

  for (int i = y1; i <= y2; i++)
  {

    gotoxy(x1, i);
    cout << char(186);

    gotoxy(x2, i);
    cout << char(186);
  }

  gotoxy(x1, y1);
  cout << char(201);

  gotoxy(x2, y1);
  cout << char(187);

  gotoxy(x1, y2);
  cout << char(200);

  gotoxy(x2, y2);
  cout << char(188);
}

// ================= INTRODUCTION =================
void Introduction()
{

  system("cls");

  setColor(11);

  drawBox(20, 2, 100, 25);

  gotoxy(42, 4);
  cout << "KINGDOM OF CAMBODIA";

  gotoxy(40, 5);
  cout << "NATION RELIGION KING";

  gotoxy(32, 8);
  cout << "Royal University Of Phnom Penh";

  gotoxy(32, 10);
  cout << "Faculty of Science";

  gotoxy(32, 11);
  cout << "Department: Computer Science";

  gotoxy(32, 12);
  cout << "Subject: Data Structure and Algorithms";

  gotoxy(32, 13);
  cout << "Teacher: Ung Rithy";

  gotoxy(32, 14);
  cout << "Class: M3 Year2";

  gotoxy(48, 16);
  cout << "TEAM MEMBERS";

  gotoxy(38, 18);
  cout << "1. Sarath Visal";

  gotoxy(38, 19);
  cout << "2. Sopheach Viseth";

  gotoxy(38, 20);
  cout << "3. Cheang Chay";

  gotoxy(38, 21);
  cout << "4. Oeun Songvat";

  gotoxy(38, 22);
  cout << "5. Theng Seyha";

  setColor(14);

  gotoxy(38, 24);
  cout << "Press any key to continue...";

  getch();
}

// ================= INITIALIZE =================
void Initialize(NodePtr &head)
{

  head = NULL;
}

// ================= CREATE NODE =================
NodePtr GetNode(float value)
{

  NodePtr newNode = new Node;

  if (newNode == NULL)
  {

    cout << "Memory allocation failed!";
    return NULL;
  }

  newNode->data = value;
  newNode->nextNode = NULL;

  return newNode;
}

// ================= INSERT FIRST =================
void InsertFirst(NodePtr &head, float value)
{

  NodePtr newNode = GetNode(value);

  if (newNode == NULL)
    return;

  newNode->nextNode = head;

  head = newNode;
}

// ================= INSERT LAST =================
void InsertLast(NodePtr &head, float value)
{

  NodePtr newNode = GetNode(value);

  if (newNode == NULL)
    return;

  if (head == NULL)
  {

    head = newNode;
    return;
  }

  NodePtr current = head;

  while (current->nextNode != NULL)
  {

    current = current->nextNode;
  }

  current->nextNode = newNode;
}

// ================= TRAVERSE =================
void Traverse(NodePtr head)
{

  if (head == NULL)
  {

    cout << "\n\tList is empty!\n";
    return;
  }

  NodePtr current = head;

  cout << "\n\tLinked List : ";

  while (current != NULL)
  {

    cout << current->data;

    if (current->nextNode != NULL)
      cout << " -> ";

    current = current->nextNode;
  }

  cout << endl;
}

// ================= COUNT =================
int CountNode(NodePtr head)
{

  int count = 0;

  NodePtr current = head;

  while (current != NULL)
  {

    count++;

    current = current->nextNode;
  }

  return count;
}

// ================= SEARCH =================
NodePtr Search(NodePtr head, float targetValue)
{

  NodePtr current = head;

  while (current != NULL)
  {

    if (current->data == targetValue)
      return current;

    current = current->nextNode;
  }

  return NULL;
}

// ================= DELETE FIRST =================
void DeleteFirst(NodePtr &head)
{

  if (head == NULL)
  {

    cout << "\n\tList is empty!\n";
    return;
  }

  NodePtr tempNode = head;

  head = head->nextNode;

  delete tempNode;
}

// ================= SORT ASCENDING =================
void SortAscending(NodePtr head)
{

  // CHECK EMPTY LIST
  if (head == NULL)
  {

    cout << "\n\tList is empty!\n";
    return;
  }

  bool swapped;

  do
  {

    swapped = false;

    NodePtr current = head;

    while (current->nextNode != NULL)
    {

      if (current->data >
          current->nextNode->data)
      {

        swap(current->data,
             current->nextNode->data);

        swapped = true;
      }

      current = current->nextNode;
    }

  } while (swapped);
}

// ================= DELETE ALL =================
void DeleteAll(NodePtr &head)
{

  while (head != NULL)
  {

    NodePtr tempNode = head;

    head = head->nextNode;

    delete tempNode;
  }
}

// ================= MAIN =================
int main()
{

  NodePtr head;

  Initialize(head);

  int mainChoice;
  int totalNode;

  float value;

  do
  {

    system("cls");

    setColor(11);

    drawBox(20, 2, 90, 22);

    gotoxy(38, 4);
    cout << "SINGLY LINKED LIST MENU";

    setColor(14);

    gotoxy(28, 6);
    cout << "1. Introduction";

    gotoxy(28, 7);
    cout << "2. Create List";

    gotoxy(28, 8);
    cout << "3. Traverse List";

    gotoxy(28, 9);
    cout << "4. Count Nodes";

    gotoxy(28, 10);
    cout << "5. Search Node";

    gotoxy(28, 11);
    cout << "6. Insert First";

    gotoxy(28, 12);
    cout << "7. Insert Last";

    gotoxy(28, 13);
    cout << "8. Delete First";

    gotoxy(28, 14);
    cout << "9. Sort Ascending";

    gotoxy(28, 15);
    cout << "0. Exit Program";

    setColor(10);

    gotoxy(28, 18);
    cout << "Enter choice : ";
    cin >> mainChoice;

    system("cls");

    switch (mainChoice)
    {

    case 1:

      Introduction();
      break;

    case 2:

      cout << "\n\tEnter number of nodes : ";
      cin >> totalNode;

      for (int i = 0; i < totalNode; i++)
      {

        cout << "\tEnter value "
             << i + 1
             << " : ";

        cin >> value;

        InsertLast(head, value);
      }

      cout << "\n\tList Created Successfully!\n";
      break;

    case 3:

      Traverse(head);
      break;

    case 4:

      cout << "\n\tTotal Nodes : "
           << CountNode(head)
           << endl;

      break;

    case 5:

      cout << "\n\tEnter value to search : ";
      cin >> value;

      if (Search(head, value) != NULL)
        cout << "\tValue Found!\n";
      else
        cout << "\tValue Not Found!\n";

      break;

    case 6:

      cout << "\n\tEnter value : ";
      cin >> value;

      InsertFirst(head, value);

      cout << "\tInsert First Success!\n";

      break;

    case 7:

      cout << "\n\tEnter value : ";
      cin >> value;

      InsertLast(head, value);

      cout << "\tInsert Last Success!\n";

      break;

    case 8:

      DeleteFirst(head);

      cout << "\tDelete First Success!\n";

      break;

    case 9:

      SortAscending(head);

      cout << "\tSorted Successfully!\n";

      break;

    case 0:

      cout << "\n\tExiting Program...\n";
      break;

    default:

      cout << "\n\tInvalid choice!\n";
    }

    system("pause");

  } while (mainChoice != 0);

  DeleteAll(head);

  return 0;
}