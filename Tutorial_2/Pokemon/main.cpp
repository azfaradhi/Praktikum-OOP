#include "Pokemon.hpp"
#include "FirePokemon.hpp"
#include "WaterPokemon.hpp"
#include "GrassPokemon.hpp"


int main(){

    FirePokemon *f1 = new FirePokemon("Charmander");
    FirePokemon *f2 = new FirePokemon(*f1);
    WaterPokemon *w1 = new WaterPokemon("Squirtle",100,20,10);
    w1->heal(10);
    WaterPokemon w2("Magikarp",100,20,0);
    w2 = *w1;
    w1->attack(*f1);
    w1->attack(*f1);
    delete f1;

    return 0;
}