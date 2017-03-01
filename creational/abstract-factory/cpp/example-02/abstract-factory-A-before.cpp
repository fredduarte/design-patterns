#include <iostream>

using namespace std;

#define LINUX

/*
 *  Abstract base product.
 */
class Widget {
public:
    virtual void draw() = 0;
};

/*
 *  Concrete product family 1.
 */
class LinuxButton : public Widget {
public:
    void draw() {
        cout << "Widget: LinuxButton" << endl;
    }
};

class LinuxMenu : public Widget {
public:
    void draw() {
        cout << "Widget: LinuxMenu" << endl;
    }
};

/*
 *  Concrete product family 2.
 */
class WindowsButton : public Widget {
public:
    void draw() {
        cout << "Widget: WindowsButton" << endl;
    }
};

class WindowsMenu : public Widget {
public:
    void draw() {
        cout << "Widget: WindowsMenu" << endl;
    }
};

/*
 *  Client code which uses concrete products directly.
 *  It's code filled up with nasty switch statements
 *  which check the product type before its use.
 */
void display_window_one() {
#ifdef LINUX
    Widget* widgets[] = {
        new LinuxButton(),
        new LinuxMenu()
    };
#else // WINDOWS
    Widget* widgets[] = {
        new WindowsButton(),
        new WindowsMenu()
    };
#endif

    cout << "Drawing Window 1" << endl;

    widgets[0]->draw();
    widgets[1]->draw();
}

void display_window_two() {
#ifdef LINUX
    Widget* widgets[] = {
        new LinuxMenu(),
        new LinuxButton()
    };
#else // WINDOWS
    Widget* widgets[] = {
        new WindowsMenu(),
        new WindowsButton()
    };
#endif

    cout << "Drawing Window 2" << endl;

    widgets[0]->draw();
    widgets[1]->draw();
}

int main(int argc, char **argv) {
#ifdef LINUX
    Widget* widget = new LinuxButton();
#else // WINDOWS
    Widget* widget = new WindowsButton();
#endif

   widget->draw();

   display_window_one();
   display_window_two();

   return 0;
}
