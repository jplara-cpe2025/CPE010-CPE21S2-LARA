#include <iostream>
#include <string>

class Fruit{
private:
    std::string name;
    double price;
    int quantity;

public:
    // Constructor 
    Fruit(std::string newName = "", double newPrice = 0, int newQuantity = 0){
        name = std::move(newName);
        price = newPrice;
        quantity = newQuantity;
    }

    // Destructor
    ~Fruit(){
        std::cout << "Fruit Destructor Called\n";
    }

    // Copy Constructor
    Fruit(const Fruit &copyFruit){
        std::cout << "Fruit Cropy Constructor Called\n";
        name = copyFruit.name;
        price = copyFruit.price;
        quantity = copyFruit.quantity;
    }

    double getTotalPrice(){
        return price * quantity;
    }

    void printDetails(){
        std::cout << "Fruit name: " << name << "\nFruit Price: P" << price << "\nFruit Quantity: " << quantity << "\nFruit Total Price: P" << getTotalPrice() << "\n\n";
    }
    
};

class Vegetable{
private:
    std::string name;
    double price;
    int quantity;

public:
    // Consttuctor
    Vegetable(std::string newName = "", double newPrice = 0, int newQuantity = 0){
        name = std::move(newName);
        price = newPrice;
        quantity = newQuantity;
    }

    // Destructor
    ~Vegetable(){
        std::cout << "Vegetable Destructor Called\n";
    }

    // Copy Constructor
    Vegetable(const Vegetable &copyVegetable){
        std::cout << "Vegetable Copy Constructor Called\n";
        name = copyVegetable.name;
        price = copyVegetable.price;
        quantity = copyVegetable.quantity;
    }

    double getTotalPrice(){
        return price * quantity;
    }

    void printDetails(){
        std::cout << "Vegetable name: " << name << "\nVegetable Price: P" << price << "\nVegetable Quantity: " << quantity << "\nVegetable Total Price: P" << getTotalPrice() << "\n\n";
    }    
};

double TotalSum(Fruit *fruitList[], size_t fruitSize, Vegetable *vegetableList[], size_t vegetableSize){
    double total = 0;
    // Add the total price of each fruit and vegetable total
    for (size_t i = 0; i < fruitSize; i++){
        if (fruitList[i] != nullptr){
            total += fruitList[i]->getTotalPrice();
        }
    }

    for (size_t i = 0; i < vegetableSize; i++){
        if (vegetableList[i] != nullptr){
            total += vegetableList[i]->getTotalPrice();
        }
    }

    return total;
}

int main(){
    // Set array size
    const size_t fruitSize = 2;
    const size_t vegetableSize = 2;

    // Initialize list
    Fruit *fruitList[fruitSize] = {};
    Vegetable *vegetableList[vegetableSize] = {};
    
    // Fruits & Vegetables
    fruitList[0] = new Fruit("Apple", 10, 7);
    fruitList[1] = new Fruit("Banana", 10, 8);
    vegetableList[0] = new Vegetable("Broccoli", 60, 12);
    vegetableList[1] = new Vegetable("Lettuce", 50, 10);

    // Display the lists for respective fruits and total price
    std::cout << "Jenna’s Grocery List\nFruits:\n";

    for (size_t i = 0; i < fruitSize; i++){
        fruitList[i]->printDetails();
    }

    std::cout << "Vegetables:\n";

    for (size_t i = 0; i < vegetableSize; i++) {
        vegetableList[i]->printDetails();
    }
    std::cout << "TRANSACTIONS\nTotal Price of all items: P" << TotalSum(fruitList, fruitSize, vegetableList, vegetableSize) << std::endl;

    // Delete the Lettuce
    delete vegetableList[1];
    vegetableList[1] = nullptr;
    std::cout << "Lettuce has been deleted from the list\n";

    return 0;
}