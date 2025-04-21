#include "PetShelter.hpp"

template<typename T>
PetShelter<T>::PetShelter(std::string shelterName){
    this->shelterName = shelterName;
    this->dogCapacity = 8;
    this->catCapacity = 12;
    this->currentCats = 0;
    this->currentDogs = 0;
    this->petCount = 0;
    for (int i=0; i < MAX_SHELTER_CAPACITY; i++){
        this->pets[i] = nullptr;
    }
}

template<typename T>
PetShelter<T>::PetShelter(std::string shelterName, int dogCapacity, int catCapacity){
    this->shelterName = shelterName;
    this->dogCapacity = dogCapacity;
    this->catCapacity = catCapacity;
    this->currentCats = 0;
    this->currentDogs = 0;
    this->petCount = 0;
    for (int i=0; i < MAX_SHELTER_CAPACITY; i++){
        this->pets[i] = nullptr;
    }
    if (dogCapacity + catCapacity > MAX_SHELTER_CAPACITY){
        std::cout << "The total capacity you construct is "<< dogCapacity + catCapacity <<", meanwhile the shelter capacity is 20" << std::endl;
    }
}
template<typename T>
PetShelter<T>::~PetShelter(){
    for (int i=0; i < MAX_SHELTER_CAPACITY; i++){
        delete this->pets[i];
        pets[i] = nullptr;  
    }
}
template<typename T>
std::string PetShelter<T>::getShelterName() const{
    return this->shelterName;
}
template<typename T>
void PetShelter<T>::addPet(const std::string &petName, int age, bool isDog, const std::string &extraInfo){
    if (petCount == MAX_SHELTER_CAPACITY){
        std::cout << "Error: Shelter is at full capacity!" << std::endl;
        return;
    }
    if (!isDog && currentCats >= catCapacity){
        std::cout << "Error: No space for more cats!" << std::endl;
        return;
    }
    if (isDog && currentDogs >= dogCapacity){
        std::cout << "Error: No space for more dogs!" << std::endl;
        return;
    }
    int empty = -1;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] == nullptr){
            empty = i;
            break;
        }
    }
    Pet *newPet = nullptr;
    std::string temp;

    if (isDog){
        newPet = new Dog(petName, age, extraInfo);
        currentDogs++;
        temp = "D" + std::to_string(currentDogs);
    }
    else{
        newPet = new Cat(petName, age, extraInfo);
        currentCats++;
        temp = "C" + std::to_string(currentCats);
    }

    newPet->setId(temp);
    pets[empty] = newPet;
    petCount++;
    std::cout << "Success: " << petName << " has been added as a ";
    if (isDog){
        std::cout << "Dog";
    }
    else{
        std::cout << "Cat";
    }
    std::cout << "! Pet ID: " << temp << std::endl;
}

template<typename T>
T* PetShelter<T>::findPet(const std::string &petID) const{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] != nullptr && pets[i]->getId() == petID){
            pets[i]->displayInfo();
            return dynamic_cast<T *>(pets[i]);
        }
    }
    std::cout << "Pet ID is invalid!" << std::endl;
    return nullptr;
}
template<typename T>
void PetShelter<T>::listAllPets() const{
    if (petCount == 0){
        std::cout << "No pets in the shelter yet!" << std::endl;
        return;
    }
    int temp = 1;
    for (int i=0; i < MAX_SHELTER_CAPACITY; i++){
        if (this->pets[i] != nullptr){
            std::cout << temp << ". ";
            this->pets[i]->displayInfo();
            temp++;
        }
    }
}
template<typename T>
int PetShelter<T>::calculateCost() const{
    int totalCost = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] != nullptr){
            if (dynamic_cast<Dog *>(pets[i])){
                totalCost += 75;
            }
            else if (dynamic_cast<Cat *>(pets[i])){
                totalCost += 60;
            }
        }
    }
    return totalCost;
}
template <typename T>
void PetShelter<T>::removePet(const std::string &petID){
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] != nullptr && pets[i]->getId() == petID){
            std::string petName = pets[i]->getName();
            if (dynamic_cast<Dog *>(pets[i])){
                currentDogs--;
            }
            else if (dynamic_cast<Cat *>(pets[i])){
                currentCats--;
            }
            delete pets[i];
            pets[i] = nullptr;
            petCount--;
            std::cout << petName << " has been removed from the shelter." << std::endl;
            return;
        }
    }
    std::cout << "Pet ID is invalid!" << std::endl;
}
template class PetShelter<Pet>;