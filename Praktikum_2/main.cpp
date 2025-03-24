#include "Creature.hpp"
#include "Dragon.hpp"


int main() {
    Dragon A("Draco");
    A.speak();
    A.wound();
    A.wound();
    A.print();

    Creature *B = &A;
    B->speak();
    B->wound();
    B->print();
    A.print();

    Creature C = A;
    C.speak();
    C.wound();
    C.print();
    A.print();


    return 0;
}