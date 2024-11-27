#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Control {
    int id;
    string type;   // "button" or "slider"
    string state;  // "visible", "invisible", or "disabled"
};

// Function to print a control
void print(const Control& c) {
    cout << "ID: " << c.id << ", Type: " << c.type << ", State: " << c.state << endl;
}

// Comparator for sorting by ID
bool compareByID(const Control& a, const Control& b) {
    return a.id < b.id;
}

int main() {
    vector<Control> controls1, controls2;

    int n1, n2;
    cout << "Enter the number of controls in the first list: ";
    cin >> n1;
    cout << "Enter details for the first list of controls (ID, Type, State):\n";
    for (int i = 0; i < n1; i++) {
        Control c;
        cin >> c.id >> c.type >> c.state;
        controls1.push_back(c);
    }

    cout << "Enter the number of controls in the second list: ";
    cin >> n2;
    cout << "Enter details for the second list of controls (ID, Type, State):\n";
    for (int i = 0; i < n2; i++) {
        Control c;
        cin >> c.id >> c.type >> c.state;
        controls2.push_back(c);
    }

    int choice;
    do {
        // Menu for operations
        cout << "\nChoose an operation:\n";
        cout << "1. Sort controls by ID (std::sort)\n";
        cout << "2. Stable sort controls by ID (std::stable_sort)\n";
        cout << "3. Binary search for a control by ID\n";
        cout << "4. Merge two sorted lists into a single list\n";
        cout << "5. In-place merge two segments in the same list\n";
        cout << "6. Set operations (Union and Intersection)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Sort using std::sort
            sort(controls1.begin(), controls1.end(), compareByID);
            cout << "First list sorted by ID:\n";
            for_each(controls1.begin(), controls1.end(), print);
            break;
        }
        case 2: {
            // Stable sort using std::stable_sort
            stable_sort(controls1.begin(), controls1.end(), compareByID);
            cout << "First list stable-sorted by ID:\n";
            for_each(controls1.begin(), controls1.end(), print);
            break;
        }
        case 3: {
            // Binary search using std::lower_bound and std::upper_bound
            int searchID;
            cout << "Enter the ID to search for: ";
            cin >> searchID;

            auto lower = lower_bound(controls1.begin(), controls1.end(), Control{searchID, "", ""}, compareByID);
            auto upper = upper_bound(controls1.begin(), controls1.end(), Control{searchID, "", ""}, compareByID);

            if (lower != controls1.end() && lower->id == searchID) {
                cout << "Control found:\n";
                print(*lower);
            } else {
                cout << "Control with ID " << searchID << " not found.\n";
            }
            break;
        }
        case 4: {
            // Merge two sorted lists using std::merge
            vector<Control> mergedList(n1 + n2);
            sort(controls1.begin(), controls1.end(), compareByID);
            sort(controls2.begin(), controls2.end(), compareByID);
            merge(controls1.begin(), controls1.end(), controls2.begin(), controls2.end(), mergedList.begin(), compareByID);

            cout << "Merged list:\n";
            for_each(mergedList.begin(), mergedList.end(), print);
            break;
        }
        case 5: {
            // In-place merge using std::inplace_merge
            vector<Control> combinedList = controls1;
            combinedList.insert(combinedList.end(), controls2.begin(), controls2.end());
            sort(combinedList.begin(), combinedList.end(), compareByID);
            inplace_merge(combinedList.begin(), combinedList.begin() + n1, combinedList.end(), compareByID);

            cout << "In-place merged list:\n";
            for_each(combinedList.begin(), combinedList.end(), print);
            break;
        }
        case 6: {
            // Set operations using std::set_union and std::set_intersection
            sort(controls1.begin(), controls1.end(), compareByID);
            sort(controls2.begin(), controls2.end(), compareByID);

            vector<Control> unionControls, intersectionControls;
            set_union(controls1.begin(), controls1.end(), controls2.begin(), controls2.end(), back_inserter(unionControls), compareByID);
            set_intersection(controls1.begin(), controls1.end(), controls2.begin(), controls2.end(), back_inserter(intersectionControls), compareByID);

            cout << "Union of both lists:\n";
            for_each(unionControls.begin(), unionControls.end(), print);

            cout << "Intersection of both lists:\n";
            for_each(intersectionControls.begin(), intersectionControls.end(), print);
            break;
        }
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
