
//  main.cpp
//  Lab_9
//
//  Created by Nik Kozhemyakin on 25.04.2023.


#include "hash.hpp"

int main() {
    WordHashTable wordHT1;

//    wordHT1.readFile("/Users/nikkozhemyakin/Documents/C++/Laboratory/2course/Lab_9/Lab_9/input1.txt");
//    cout << "Text number 1\n";
//    wordHT1.printTopTen();
//    wordHT1.printNumberOfCollisions();
//
    WordHashTable wordHT2;
//    wordHT2.readFile("/Users/nikkozhemyakin/Documents/C++/Laboratory/2course/Lab_9/Lab_9/input2.txt");
//    cout << '\n' << "Text number 2\n";
//    wordHT2.printTopTen();
//    wordHT2.printNumberOfCollisions();
//
    WordHashTable wordHT3;
//    wordHT3.readFile("/Users/nikkozhemyakin/Documents/C++/Laboratory/2course/Lab_9/Lab_9/input3.txt");
//    cout << '\n' << "Text number 3\n";
//    wordHT3.printTopTen();
//    wordHT3.printNumberOfCollisions();

    std::cout << "Enter collision resolution method (0 - Linear Probing, 1 - Quadratic Probing, 2 - Double Hashing): ";
    int method = 0;
    std::cin >> method;

    switch (method) {
        case 0:
            wordHT1.setCollisionMethod(CollisionResolution::LinearProbing);
            wordHT2.setCollisionMethod(CollisionResolution::LinearProbing);
            wordHT3.setCollisionMethod(CollisionResolution::LinearProbing);
            break;
        case 1:
            wordHT1.setCollisionMethod(CollisionResolution::QuadraticProbing);
            wordHT2.setCollisionMethod(CollisionResolution::QuadraticProbing);
            wordHT3.setCollisionMethod(CollisionResolution::QuadraticProbing);
            break;
        case 2:
            wordHT1.setCollisionMethod(CollisionResolution::DoubleHashing);
            wordHT2.setCollisionMethod(CollisionResolution::DoubleHashing);
            wordHT3.setCollisionMethod(CollisionResolution::DoubleHashing);
            break;
        default:
            std::cout << "Invalid method. Using Linear Probing by default.\n";
            wordHT1.setCollisionMethod(CollisionResolution::DoubleHashing);
            break;
    }

    wordHT1.readFile("/Users/nikkozhemyakin/Documents/C++/Laboratory/2course/Lab_9/Lab_9/input1.txt");
    std::cout << "Text number 1\n";
    wordHT1.printTopTen();
    wordHT1.printNumberOfCollisions();

    wordHT2.readFile("/Users/nikkozhemyakin/Documents/C++/Laboratory/2course/Lab_9/Lab_9/input2.txt");
    cout << '\n' << "Text number 2\n";
    wordHT2.printTopTen();
    wordHT2.printNumberOfCollisions();


    wordHT3.readFile("/Users/nikkozhemyakin/Documents/C++/Laboratory/2course/Lab_9/Lab_9/input3.txt");
    cout << '\n' << "Text number 3\n";
    wordHT3.printTopTen();
    wordHT3.printNumberOfCollisions();

    return 0;
}


