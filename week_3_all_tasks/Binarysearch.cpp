#include<iostream>
using namespace std;
#include<vector>
int main()
{
    vector<int> arr;
    int n;
    cout << "Enter the element size of the array: ";
    cin >> n;

    int value;
    cout << "Enter the Values (sorted):" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        arr.push_back(value);
    }

    int target;
    cout << "Enter the value to search for: ";
    cin >> target;

    // Binary Search implementation
    int left = 0;
    int right = arr.size() - 1;
    bool found = false;

    while(left <= right)
    {
        int mid = left + (right - left) / 2; // Calculate mid index

        if(arr[mid] == target) // Target found
        {
            found = true;
            cout << "Element " << target << " found at index: " << mid << endl;
            break;
        }
        else if(arr[mid] < target) // Search in the right half
        {
            left = mid + 1;
        }
        else // Search in the left half
        {
            right = mid - 1;
        }
    }

    if(!found)
    {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
