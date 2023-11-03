#include <iostream>
#include <cmath>

typedef struct _coordinates {
    double x;
    double y;
} Coord;

void generateCoordSquare(Coord basicPoint, double lengthSide, double angle) {
    angle = angle * M_PI / 180.0;

    Coord vertices[4];

    if ((int)angle % 45 == 0) {
        for (int i = 0; i < 4; ++i) {
            double x = round(basicPoint.x + lengthSide * std::cos(angle));
            double y = round(basicPoint.y + lengthSide * std::sin(angle));
            vertices[i] = {x, y};
            angle += M_PI / 2.0;
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            double x = basicPoint.x + lengthSide * std::cos(angle);
            double y = basicPoint.y + lengthSide * std::sin(angle);
            vertices[i] = {x, y};
            angle += M_PI / 2.0;
        }
    }

    

    for (int i = 0; i < 4; ++i) {
        std::cout << "Coord sq" << i + 1 << "= {" << vertices[i].x << ", " << vertices[i].y << "}" << std::endl;
    }
}

void generateCoordTriangle(Coord basicPoint, double lengthSide, double angle) {
    angle = angle * M_PI / 180.0;

    Coord vertices[3];

    if ((int)angle % 30 == 0) {
        for (int i = 0; i < 3; ++i) {
            double x = round(basicPoint.x + lengthSide * cos(angle));
            double y = round(basicPoint.y + lengthSide * sin(angle));
            vertices[i] = {x, y};
            angle += (2.0 * M_PI / 3.0); 
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            double x = basicPoint.x + lengthSide * cos(angle);
            double y = basicPoint.y + lengthSide * sin(angle);
            vertices[i] = {x, y};
            angle += (2.0 * M_PI / 3.0);
        }
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << "Coord tr" << i + 1 << "= {" << vertices[i].x << ", " << vertices[i].y << "}" << std::endl;
    }
}

void generateCoordOctagon(Coord basicPoint, double lengthSide, double angle) {
    angle = angle * M_PI / 180.0;

    Coord vertices[8];

    if (int(angle) % (int)22.5 == 0) {
        for (int i = 0; i < 8; ++i) {
            double x = round(basicPoint.x + lengthSide * cos(angle));
            double y = round(basicPoint.y + lengthSide * sin(angle));
            vertices[i] = {x, y};
            angle += (M_PI / 4.0);
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            double x = basicPoint.x + lengthSide * cos(angle);
            double y = basicPoint.y + lengthSide * sin(angle);
            vertices[i] = {x, y};
            angle += (M_PI / 4.0);
        }
    }

    for (int i = 0; i < 8; ++i) {
        std::cout << "Coord oc" << i + 1 << "= {" << vertices[i].x << ", " << vertices[i].y << "};" << std::endl;
    }
}

int main() {
    std::cout << "Enter a number of Figure: \n" <<
        "1. Square\n" << "2. Triangle\n" << "3. Octagon" << "4. exit"<< std::endl;
    
    int choose;
    while (1) {
        std::cin >> choose;
        
        Coord basP;
        double x, y;
        double lenS;
        double angle;
        
        switch (choose) {
        case 1:
            std::cout << "Enter coord (X Y): ";
            std::cin >> x >> y;
            basP.x = x;
            basP.y = y;
            std::cout << "\nEnter length side: ";
            std::cin >> lenS;
            std::cout << "\nEnter tilt angle (base 45): ";
            std::cin >> angle;

            generateCoordSquare(basP, lenS, angle);
            break;
        case 2:
            std::cout << "Enter coord (X Y): ";
            std::cin >> x >> y;
            basP.x = x;
            basP.y = y;
            std::cout << "\nEnter length side: ";
            std::cin >> lenS;
            std::cout << "\nEnter tilt angle (base 30): ";
            std::cin >> angle;

            generateCoordTriangle(basP, lenS, angle);
            break;
        case 3:
            std::cout << "Enter coord (X Y): ";
            std::cin >> x >> y;
            basP.x = x;
            basP.y = y;
            std::cout << "\nEnter length side: ";
            std::cin >> lenS;
            std::cout << "\nEnter tilt angle (base 22.5): ";
            std::cin >> angle;

            generateCoordOctagon(basP, lenS, angle);
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid number" << std::endl;
            break;
        }
    }
    

    return 0;
}