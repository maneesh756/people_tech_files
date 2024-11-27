#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// Function to print a widget
void printWidget(const string& widget) {
    cout << widget << endl;
}

// Function to find a widget in a set
bool findWidgetInSet(const set<string>& widgets, const string& target) {
    auto it = widgets.find(target);
    if (it != widgets.end()) {
        cout << "Widget '" << target << "' found in static widgets.\n";
        return true;
    } else {
        cout << "Widget '" << target << "' not found in static widgets.\n";
        return false;
    }
}

int main() {
    // Step 1: Initialize containers
    vector<string> dynamicWidgets = {"Speedometer", "Tachometer", "FuelGauge", "Odometer"};
    set<string> staticWidgets = {"Logo", "WarningLights", "TurnSignals"};

    int choice;
    do {
        // Menu for operations
        cout << "\nChoose an operation:\n";
        cout << "1. Print all dynamic widgets\n";
        cout << "2. Check if a specific static widget exists\n";
        cout << "3. Combine dynamic and static widgets into a single list\n";
        cout << "4. Search for a specific widget in the combined list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Print all dynamic widgets using an iterator
            cout << "Dynamic Widgets:\n";
            for (auto it = dynamicWidgets.begin(); it != dynamicWidgets.end(); ++it) {
                cout << *it << endl;
            }
            break;
        }
        case 2: {
            // Check if a specific static widget exists
            string target;
            cout << "Enter the widget to search in static widgets: ";
            cin >> target;
            findWidgetInSet(staticWidgets, target);
            break;
        }
        case 3: {
            // Combine both containers into a single vector
            vector<string> combinedWidgets(dynamicWidgets);
            combinedWidgets.insert(combinedWidgets.end(), staticWidgets.begin(), staticWidgets.end());
            
            cout << "Combined Widget List:\n";
            for_each(combinedWidgets.begin(), combinedWidgets.end(), printWidget);
            break;
        }
        case 4: {
            // Search for a specific widget in the combined list
            string target;
            cout << "Enter the widget to search in the combined list: ";
            cin >> target;

            vector<string> combinedWidgets(dynamicWidgets);
            combinedWidgets.insert(combinedWidgets.end(), staticWidgets.begin(), staticWidgets.end());

            auto it = find(combinedWidgets.begin(), combinedWidgets.end(), target);
            if (it != combinedWidgets.end()) {
                cout << "Widget '" << target << "' found in the combined list.\n";
            } else {
                cout << "Widget '" << target << "' not found in the combined list.\n";
            }
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
