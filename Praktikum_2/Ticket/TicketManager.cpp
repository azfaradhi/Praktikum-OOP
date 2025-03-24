#include "TicketManager.hpp"

using namespace std;
TicketManager::TicketManager(string eventName){
    for (int i=0; i<VENUE_CAPACITY; i++){
        this->tickets[i] == nullptr;
    }
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentVIPTickets = 0;
    this->currentRegularTickets = 0;
}

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity){
    if (vipCapacity + regularCapacity > 15){
        cout << "The total capacity you construct is "<< vipCapacity + regularCapacity <<", meanwhile the venue capacity is 15" << endl;
    }
    this->eventName = eventName;
    this->vipCapacity = vipCapacity;
    this->regularCapacity = regularCapacity;
    this->ticketCount = 0;
    this->currentRegularTickets = 0;
    this->currentVIPTickets = 0;
    for (int i=0; i<VENUE_CAPACITY; i++){
        this->tickets[i] == nullptr;
    }
}

TicketManager::~TicketManager(){
}

string TicketManager::getEventName() const{
    return this->eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP){
    if (this->ticketCount == VENUE_CAPACITY){
        cout <<"Error: All tickets are sold out!" << endl;
        return;
    }
    if (isVIP && this->currentVIPTickets == this->vipCapacity){
        cout << "Error: No VIP tickets left!" << endl;
        return;
    }
    if (!isVIP && this->currentRegularTickets == this->regularCapacity){
        cout << "Error: No Regular tickets left!" <<endl;
        return;
    }
    string temp = "";
    if (isVIP){
        currentVIPTickets++;
        temp += "V" + to_string(currentVIPTickets);
        this->tickets[this->ticketCount] = new VIPTicket(temp,ownerName);

    }
    if (!isVIP){
        currentRegularTickets++;
        temp += "R" + to_string(currentRegularTickets);
        this->tickets[this->ticketCount] = new RegularTicket(temp,ownerName);

    }
    this->ticketCount++;
    if (isVIP){
        cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: "<< temp << endl;
    }
    if (!isVIP){
        cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: "<< temp << endl;
    }

}

void TicketManager::checkTicket(const string &ticketID) const{
    for (int i=0; i< this->ticketCount; i++){
        if (this->tickets[i]->getTicketID() == ticketID){
            this->tickets[i]->printTicket();
            return;
        }
    }
    cout << "Ticket ID is invalid!" << endl;

}

void TicketManager::listAudience() const{
    if (this->ticketCount == 0){
        cout << "No audience yet!" << endl;
        return;
    }
    for (int i=0;i < this->ticketCount; i++){
        cout << i+1 << ". ";
        this->tickets[i]->printTicket();
    }
}

int TicketManager::calculateRevenue() const{
    return this->currentRegularTickets*275 + this->currentVIPTickets*500;
}