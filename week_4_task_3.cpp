#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Control {
    int id;
    string type;   // "button" or "slider"
    string state;  // "visible", "invisible", or "disabled"
};

// Function to print control details
void print(const Control& c) {
    cout << "ID: " << c.id << ", Type: " << c.type << ", State: " << c.state << endl;
}

// Function to generate random states
string randomState() {
    const string states[] = {"visible", "invisible", "disabled"};
    return states[rand() % 3];
}

int main() {
    srand(time(0)); // Seed for random state generation
    vector<Control> controls;

    int n;
    cout << "Enter the number of controls: ";
    cin >> n;

    // Step 1: Populate the controls list
    Control c;
    for (int i = 0; i < n; i++) {
        cout << "Enter details for control " << i + 1 << " (ID, Type, State): ";
        cin >> c.id >> c.type >> c.state;
        controls.push_back(c);
    }

    vector<Control> backupControls; // Backup list for operations

    int choice;
    do {
        // Menu for operations
        cout << "\nChoose an operation:\n";
        cout << "1. Create a backup of the control list\n";
        cout << "2. Temporarily disable all controls\n";
        cout << "3. Generate random states for all controls\n";
        cout << "4. Set all sliders to invisible\n";
        cout << "5. Replace 'disabled' with 'enabled'\n";
        cout << "6. Filter out invisible controls\n";
        cout << "7. Reverse the control list\n";
        cout << "8. Group visible controls together\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Backup the control list using std::copy
            backupControls.clear();
            copy(controls.begin(), controls.end(), back_inserter(backupControls));
            cout << "Backup created successfully.\n";
            break;
        }
        case 2: {
            // Set all states to "disabled" using std::fill
            fill(controls.begin(), controls.end(), Control{0, "", "disabled"});
            cout << "All controls temporarily disabled:\n";
            for_each(controls.begin(), controls.end(), print);
            break;
        }
        case 3: {
            // Generate random states using std::generate
            generate(controls.begin(), controls.end(), [&]() {
                return Control{rand() % 100, "slider", randomState()};
            });
            cout << "Random states generated for all controls:\n";
            for_each(controls.begin(), controls.end(), print);
            break;
        }
        case 4: {
            // Change the state of all sliders to "invisible" using std::transform
            transform(controls.begin(), controls.end(), controls.begin(), [](Control& c) {
                if (c.type == "slider") c.state = "invisible";
                return c;
            });
            cout << "All sliders set to 'invisible':\n";
            for_each(controls.begin(), controls.end(), print);
            break;
        }
        case 5: {
            // Replace "disabled" with "enabled" using std::replace
            replace_if(controls.begin(), controls.end(), [](const Control& c) {
                return c.state == "disabled";
            }, Control{0, "", "enabled"});
            cout << "'Disabled' states replaced with 'enabled':\n";
            for_each(controls.begin(), controls.end(), print);
            break;
        }
        case 6: {
            // Filter out invisible controls using std::remove_if
            controls.erase(remove_if(controls.begin(), controls.end(), [](const Control& c) {
                return c.state == "invisible";
            }), controls.end());
            cout << "Invisible controls removed:\n";
            for_each(controls.begin(), controls.end(), print);
            break;
        }
        case 7: {
            // Reverse the control list using std::reverse
            reverse(controls.begin(), controls.end());
            cout << "Control list reversed:\n";
            for_each(controls.begin(), controls.end(), print);
            break;
        }
        case 8: {
            // Group visible controls together using std::partition
            partition(controls.begin(), controls.end(), [](const Control& c) {
                return c.state == "visible";
            });
            cout << "Visible controls grouped together:\n";
            for_each(controls.begin(), controls.end(), print);
            break;
        }
        case 9:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
