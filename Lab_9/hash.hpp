//
//  hash.hpp
//  Lab_9
//
//  Created by Nik Kozhemyakin on 25.04.2023.
//

#ifndef hash_hpp
#define hash_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::unordered_map;
using std::remove_if;
using std::ispunct;
using std::pair;
using std::sort;
using std::vector;
using std::min;
using std::make_pair;

enum class CollisionResolution {
    LinearProbing,
    QuadraticProbing,
    DoubleHashing
};


class WordHashTable {
    
private:
    // Функция сравнения пар по второму элементу (для сортировки)
    CollisionResolution collisionMethod;
    static bool comparisonOfPairs(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    }
    
    int sizeOfTable = 3000;
    vector<pair<string, int>> wordCount = vector<pair<string, int>>(sizeOfTable, make_pair("", 0));
    int collisionsCount = 0;
    
public:
    WordHashTable() = default;
    void setCollisionMethod(CollisionResolution method);
    // Функция чтения слов из файла и добавления их в хеш-таблицу
    void readFile(const string& fileName);
    
    // Функция удаления знаков препинания из строки
    void deletePunctuation(string& s) const;
    
    // Хеш-функция методом свертки
    unsigned int foldingMethod(const string& word) const;
    unsigned int foldingMethod2(const string& word) const;
    
    // Функция вывода топ-10 слов
    void printTopTen() const;
    
    //Подсчет количества коллизий
    void printNumberOfCollisions() const;
};


#endif /* hash_hpp */
