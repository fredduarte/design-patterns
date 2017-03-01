#include <iostream>

using namespace std;

#define WINDOWS

/*
 *  Abstract base product. It should define an interface
 *  which will be common to all products. Clients will
 *  work with products through this interface, so it
 *  should be sufficient to use all products.
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
 *  Abstract factory defines methods
 *  to create all related products.
 */
class Factory {
public:
    virtual Widget* create_button() = 0;
    virtual Widget* create_menu() = 0;
};

/*
 *  Each concrete factory corresponds to one product
 *  family. It creates all possible products of
 *  one kind.
 */
class LinuxFactory : public Factory {
public:
    Widget* create_button() {
        return new LinuxButton();
    }

    Widget* create_menu() {
        return new LinuxMenu();
    }
};

/*
 *  Concrete factory creates concrete products, but,
 *  returns them as abstract.
 */
class WindowsFactory : public Factory {
public:
    Widget* create_button() {
        return new WindowsButton();
    }

    Widget* create_menu() {
        return new WindowsMenu();
    }
};

/*
 *  Client receives a factory object from its creator.
 *
 *  All clients work with factories through abstract
 *  interface. They don't know concrete classes of
 *  factories. Because of this, you can interchange
 *  concrete factories without breaking clients.
 *
 *  Clients don't know the concrete classes of created
 *  products either, since abstract factory methods
 *  returns abstract products.
 */
void display_window_one(Factory *factory) {
    Widget* widgets[] = {
        factory->create_button(),
        factory->create_menu()
    };

    cout << "Drawing Window 1" << endl;

    widgets[0]->draw();
    widgets[1]->draw();
}

void display_window_two(Factory *factory) {
    Widget* widgets[] = {
        factory->create_menu(),
        factory->create_button()
    };

    cout << "Drawing Window 2" << endl;

    widgets[0]->draw();
    widgets[1]->draw();
}

/*
 *  Now the nasty switch statement is needed only once to
 *  pick and create a proper factory. Usually that's
 *  happening somewhere in program initialization code.
 */
int main(int argc, char **argv) {
    Factory* factory = NULL;
#ifdef LINUX
    factory = new LinuxFactory();
#else // WINDOWS
    factory = new WindowsFactory();
#endif

    Widget* widget = factory->create_button();

    widget->draw();

    display_window_one(factory);
    display_window_two(factory);

    return 0;
}
