#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

// Singleton Pattern
class HMISystem {
private:
    static HMISystem* instance;
    string currentMode;

    HMISystem() : currentMode("Day") {}

public:
    static HMISystem* getInstance() {
        if (!instance)
            instance = new HMISystem();
        return instance;
    }

    void setMode(const string& mode) {
        currentMode = mode;
    }

    string getMode() const {
        return currentMode;
    }
};
HMISystem* HMISystem::instance = nullptr;

// Observer Pattern
class ModeObserver {
public:
    virtual void update(const string& mode) = 0;
    virtual ~ModeObserver() = default;
};

class Button : public ModeObserver {
public:
    void update(const string& mode) override {
        cout << "Button updated for " << mode << " mode.\n";
    }
};

class Slider : public ModeObserver {
public:
    void update(const string& mode) override {
        cout << "Slider updated for " << mode << " mode.\n";
    }
};

// Factory Pattern
class Control {
public:
    virtual void render() const = 0;
    virtual ~Control() = default;
};

class ButtonControl : public Control {
public:
    void render() const override {
        cout << "Rendering Button Control\n";
    }
};

class SliderControl : public Control {
public:
    void render() const override {
        cout << "Rendering Slider Control\n";
    }
};

class ControlFactory {
public:
    static unique_ptr<Control> createControl(const string& type) {
        if (type == "Button") {
            return make_unique<ButtonControl>();
        } else if (type == "Slider") {
            return make_unique<SliderControl>();
        }
        return nullptr;
    }
};

// Strategy Pattern
class RenderStrategy {
public:
    virtual void render() const = 0;
    virtual ~RenderStrategy() = default;
};

class Render2D : public RenderStrategy {
public:
    void render() const override {
        cout << "Rendering in 2D mode.\n";
    }
};

class Render3D : public RenderStrategy {
public:
    void render() const override {
        cout << "Rendering in 3D mode.\n";
    }
};

class Renderer {
    unique_ptr<RenderStrategy> strategy;

public:
    void setStrategy(unique_ptr<RenderStrategy> newStrategy) {
        strategy = move(newStrategy);
    }

    void render() const {
        if (strategy)
            strategy->render();
        else
            cout << "No rendering strategy set.\n";
    }
};

int main() {
    HMISystem* system = HMISystem::getInstance();
    Button button;
    Slider slider;

    Renderer renderer;
    vector<unique_ptr<Control>> controls;

    int choice;
    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Set and Get HMI Mode (Singleton)\n";
        cout << "2. Notify Observers of Mode Change (Observer)\n";
        cout << "3. Create Controls Dynamically (Factory)\n";
        cout << "4. Apply Rendering Strategies (Strategy)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string mode;
            cout << "Enter the mode (Day/Night): ";
            cin >> mode;
            system->setMode(mode);
            cout << "Mode set to: " << system->getMode() << endl;
            break;
        }
        case 2: {
            cout << "Notifying observers...\n";
            button.update(system->getMode());
            slider.update(system->getMode());
            break;
        }
        case 3: {
            string controlType;
            cout << "Enter control type (Button/Slider): ";
            cin >> controlType;
            auto control = ControlFactory::createControl(controlType);
            if (control) {
                controls.push_back(move(control));
                cout << controlType << " created and added to the system.\n";
            } else {
                cout << "Invalid control type!\n";
            }
            break;
        }
        case 4: {
            int renderChoice;
            cout << "Choose rendering strategy:\n";
            cout << "1. Render in 2D\n";
            cout << "2. Render in 3D\n";
            cout << "Enter your choice: ";
            cin >> renderChoice;

            if (renderChoice == 1) {
                renderer.setStrategy(make_unique<Render2D>());
            } else if (renderChoice == 2) {
                renderer.setStrategy(make_unique<Render3D>());
            } else {
                cout << "Invalid choice!\n";
                continue;
            }
            renderer.render();
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
