//
//  hash.cpp
//  Lab_9
//
//  Created by Nik Kozhemyakin on 25.04.2023.
//

#include "hash.hpp"

void WordHashTable::setCollisionMethod(CollisionResolution method) {
        collisionMethod = method;
    }

void WordHashTable::readFile(const string& fileName) {
    ifstream input(fileName);
    if (!input.is_open()) {
        cout << "Error of " << fileName << "\n";
        return;
    }
    
    string line;
    while (getline(input, line)) {
        stringstream wordStream(line);
        string word;
        
        while (wordStream >> word) {
            deletePunctuation(word);
            if (!word.empty()) {
                int index = foldingMethod(word);
                int i = 0;
                bool collision = false; // Flag to track collision
                
                while (i < sizeOfTable) {
                    auto it = wordCount[index];
                    if (it.first.empty() || it.first == word) {
                        wordCount[index] = make_pair(word, it.second + 1);
                        break;
                    }
                    else {
                        collisionsCount++;
                        collision = true;  // Collision occurred
                
                        switch (collisionMethod) {
                            case CollisionResolution::LinearProbing:
                                index = (index + 1) % sizeOfTable;
                                break;
                                
                            case CollisionResolution::QuadraticProbing:
                                index = (index + i * i) % sizeOfTable;
                                break;
                                
                            case CollisionResolution::DoubleHashing:
                                index = (index + foldingMethod2(word)) % sizeOfTable;
                                break;
                        }
                    }
                    i++;
                }
            }
        }
    }
}

void WordHashTable::deletePunctuation(string& s) const {
    s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {return ispunct(c);}), s.end());
}

unsigned int WordHashTable::foldingMethod(const string& word) const {
    unsigned int hashValue = 0;
    const int k = 3;
    for (char c : word) {
        hashValue = (hashValue * k) + (c - 'a' + 1);
    }
    return hashValue % sizeOfTable;
}

unsigned int WordHashTable::foldingMethod2(const string& word) const {
    unsigned int hashValue = 0;
    const int k = 5;
    for (char c : word) {
        hashValue = (hashValue * k) + (c - 'a' + 1);
    }
    return (hashValue % (sizeOfTable - 2)) + 1;
}

void WordHashTable::printTopTen() const {
    vector<pair<string, int>> wordCountVector(wordCount.begin(), wordCount.end());
    sort(wordCountVector.begin(), wordCountVector.end(), comparisonOfPairs);
    int n = min(10, static_cast<int>(wordCountVector.size()));

    for (int i = 0; i < n; i++) {
        cout << wordCountVector[i].first << ": " << wordCountVector[i].second << '\n';
    }
}

void WordHashTable::printNumberOfCollisions() const {
    cout << "Number of collisions: " << collisionsCount << "\n";
}


