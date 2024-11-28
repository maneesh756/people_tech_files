#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> v1;
    v1 = {"Settings", "Media", "Exit"};
    vector<string> v2;
    v2 = {"Display Settings", "Audio Settings", "Back"};
    vector<string> v3;
    v3 = {"Radio", "Bluetooth", "Back"};

    int menusize = 0;
    int selection = 0;
    int currentMenu = 0;

    while (1) {
        // Display current menu
        if (currentMenu == 0) {
            cout << "Main Menu" << endl;
        } else if (currentMenu == 1) {
            cout << "Settings Menu" << endl;
        } else {
            cout << "Media Menu" << endl;
        }

        // Determine current menu and size
        vector<string>* c1;
        if (currentMenu == 0) {
            c1 = &v1;
            menusize = v1.size();
        } else if (currentMenu == 1) {
            c1 = &v2;
            menusize = v2.size();
        } else {
            c1 = &v3;
            menusize = v3.size();
        }

        // Display menu options with selection highlight
        for (int i = 0; i < menusize; i++) {
            if (i == selection) {
                cout << " > ";  // Highlight selected option
            } else {
                cout << "   ";
            }
            cout << (*c1)[i] << endl;  // Display menu option
        }

        // Handle user input
        cout << "Enter command (1 = up, 2 = down, 3 = select): ";
        int command;
        cin >> command;

        switch (command) {
            case 1:  // Navigate up
                if (selection > 0) {
                    selection = selection - 1;
                } else {
                    selection = menusize - 1;  // Wrap to last option
                }
                break;

            case 2:  // Navigate down
                selection = (selection + 1) % menusize;  // Wrap around
                break;

            case 3:  // Select current option
                if (currentMenu == 0 && selection == 2) {
                    // Exit option in Main Menu
                    cout << "Exiting program. Goodbye!" << endl;
                    return 0;
                } else if (currentMenu == 0 && selection == 0) {
                    // Go to Settings Menu
                    currentMenu = 1;
                    selection = 0;
                } else if (currentMenu == 0 && selection == 1) {
                    // Go to Media Menu
                    currentMenu = 2;
                    selection = 0;
                } else if (currentMenu == 1 && selection == 2) {
                    // Back to Main Menu from Settings Menu
                    currentMenu = 0;
                    selection = 0;
                } else if (currentMenu == 2 && selection == 2) {
                    // Back to Main Menu from Media Menu
                    currentMenu = 0;
                    selection = 0;
                }
                break;

            default:
                cout << "Invalid command. Please try again." << endl;
                break;
        }
    }
}
