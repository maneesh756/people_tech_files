/*#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
struct Control
{
    int id;
    string type;
    string state;
};
void print(const Control& c1)
 { cout << c1.id << endl; 
 cout << c1.type << endl; 
 cout << c1.state <<endl; 
 }
 bool findif(const Control& c1)
 {
    if(c1.type=="button")
    {
        cout<<c1.id<<endl;
        cout<<c1.state<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }

 }

int main()
{
    vector<Control> v1;
    int n;
    cin>>n;
    Control c1;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the details of controls :";
        cin>>c1.id;
        cin>>c1.type;
        cin>>c1.state;
        v1.push_back(c1);
    }
    
    for_each(v1.begin(),v1.end(),print);
    cout<<"printing the find if"<<endl;
    find_if(v1.begin(),v1.end(),findif);
    cout<<"Eneter the value to find  using the adjacent_find function"<<endl;
     auto adjacent = std::adjacent_find(v1.begin(), v1.end(), [](const Control& a, const Control& b) {
        return a.state == b.state;
    });
    if (adjacent != v1.end()) {
        std::cout << "Consecutive controls with the same state found: ID " << adjacent->id << " and ID " << (adjacent + 1)->id << '\n';
    }
    
    
}*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Control {
    int id;
    string type;   // "button" or "slider"
    string state;  // "visible", "invisible", or "disabled"
};

// Function to print details of a control
void print(const Control& c) {
    cout << "ID: " << c.id << ", Type: " << c.type << ", State: " << c.state << endl;
}

// Predicate function to find a button
bool findif(const Control& c) {
    return c.type == "button"; // Returns true if the control is a button
}

int main() {
    vector<Control> v1;
    int n;

    // Step 1: User inputs the number of controls
    cout << "Enter the number of controls: ";
    cin >> n;

    // Step 2: Populate the vector with user input
    Control c;
    for (int i = 0; i < n; i++) {
        cout << "Enter the details of control " << i + 1 << " (ID, Type, State): ";
        cin >> c.id >> c.type >> c.state;
        v1.push_back(c);
    }

    int choice;
    do {
        // Step 3: Menu for operations
        cout << "\nChoose an operation:\n";
        cout << "1. Print all controls\n";
        cout << "2. Find the first button (using find_if)\n";
        cout << "3. Find consecutive controls with the same state (using adjacent_find)\n";
        cout << "4. Count the visible controls\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Print all controls
            cout << "Control details:\n";
            for_each(v1.begin(), v1.end(), print);
            break;
        }
        case 2: {
            // Find the first button
            auto it = find_if(v1.begin(), v1.end(), findif);
            if (it != v1.end()) {
                cout << "First button found: ";
                print(*it);
            } else {
                cout << "No button found.\n";
            }
            break;
        }
        case 3: {
            // Find consecutive controls with the same state
            auto adjacent = adjacent_find(v1.begin(), v1.end(), [](const Control& a, const Control& b) {
                return a.state == b.state;
            });
            if (adjacent != v1.end()) {
                cout << "Consecutive controls with the same state found:\n";
                print(*adjacent);
                print(*(adjacent + 1));
            } else {
                cout << "No consecutive controls with the same state found.\n";
            }
            break;
        }
        case 4: {
            // Count visible controls
            int visibleCount = count_if(v1.begin(), v1.end(), [](const Control& c) {
                return c.state == "visible";
            });
            cout << "Number of visible controls: " << visibleCount << endl;
            break;
        }
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
