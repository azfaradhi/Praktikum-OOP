#include "Agent.hpp"
#include "SuperAgent.hpp"


void changeID(Agent *a, int n){
    a->setID(n);
}
int main(){
    SuperAgent agentX;
    changeID(&agentX, 1337);
    agentX.setID(9999);


    agentX.print();
    return 0;
}