#include <iostream>

using namespace std;

struct Elem {
    Elem* link1, 
        * link2;
    int info;
};

int main() {
    Elem* p;

    p = new Elem; //1
    p->info = 1; // 2

    p->link1 = new Elem; // 3
    p->link1->info = 2; // 4

    p->link1->link1 = new Elem; // 5
    p->link1->link1->info = 3; // 6
    p->link1->link1 = p->link1; // 7

    p->link2 = new Elem; // 8
    p->link2->info = 4; // 9
    p->link2->link2 = NULL; //10

    p->link2->link1 = p->link1; // 11

    p->link1->link2 = p->link2; // 12

    p->link1->link1->link2 = p->link2;  // 13

    delete p->link2->link2; // Видалення елементу з 'info' 3
    delete p->link2; // Видалення елементу з 'info' 4
    delete p->link1; // Видалення елементу з 'info' 2
    delete p; // Видалення кореневого елементу з 'info' 1

    return 0;
}