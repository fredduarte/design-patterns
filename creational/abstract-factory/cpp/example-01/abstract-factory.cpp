#include <iostream>

using namespace std;

class Shape {
public:
    Shape() {
        TotalShapes += 1;
        ShapeId = TotalShapes;
    }

    virtual void draw() = 0;

protected:
    static int TotalShapes;
    int ShapeId;
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Draw Shape " << ShapeId << ": Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Draw Shape " << ShapeId << ": Square" << endl;
    }
};

class Ellipse : public Shape {
public:
    void draw() {
        cout << "Draw Shape " << ShapeId << ": Ellipse" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() {
        cout << "Draw Shape " << ShapeId << ": Rectangle" << endl;
    }
};

class Factory {
public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory {
public:
    Shape* createCurvedInstance() {
        return new Circle();
    }

    Shape* createStraightInstance() {
        return new Square();
    }
};

class RobustShapeFactory : public Factory {
public:
    Shape* createCurvedInstance() {
        return new Ellipse();
    }

    Shape* createStraightInstance() {
        return new Rectangle();
    }
};

int Shape::TotalShapes = 0;

int main(int argc, char **argv) {
#ifdef ROBUST
    Factory* factory = new RobustShapeFactory();
#else // SIMPLE
    Factory* factory = new SimpleShapeFactory();
#endif
    Shape* shapes[3];

    shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Circle();
    shapes[1] = factory->createStraightInstance(); // shapes[1] = new Square();
    shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Circle();

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
    }

    return 0;
}
