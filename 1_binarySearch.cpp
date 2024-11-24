#include <iostream>
using namespace std;

int main()
{
    int i, num, first, last, middle;
    int x, y, size, temp;
    int sz;

    cout << "Enter the size of array: ";
    cin >> sz;

    int arr[sz];

    for (int i = 0; i < sz; i++)
        arr[i] = 1 + rand() % 10000;

    cout << "The generated array: ";
    for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;

    for (x = 0; x < sz; x++)
    {
        for (y = 0; y < sz - 1 - x; y++)
        {
            if (arr[y] > arr[y + 1])
            {
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }

    cout << "Elements sorted in ascending order: ";
    for (x = 0; x < sz; x++)
        cout << arr[x] << " ";
    cout << endl;

    cout << "Enter the element to be searched: ";
    cin >> num;

    first = 0;
    last = sz - 1;

    while (first <= last)
    {
        middle = (first + last) / 2;

        if (arr[middle] < num)
        {
            first = middle + 1;
        }
        else if (arr[middle] == num)
        {
            cout << "The number, " << num << " was found at position " << middle << endl;
            break;
        }
        else
        {
            last = middle - 1;
        }
    }

    if (first > last)
        cout << "The number, " << num << " was not found in the given array." << endl;

    return 0;
}
