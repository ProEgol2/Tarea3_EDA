#include "trees/rb.hpp"
#include "trees/abb.hpp"
#include "trees/avl.hpp"
#include <string>
#include <fstream>
#include <iostream>

int* readKeysFromFile(std::string filename, int* n_keys){
    std::ifstream  fin(filename, std::ios::binary); 
    char* val = new char[4];
    int n = 0;
    fin.read(val, 4);
    while (!fin.eof()){
        n = n + 1;        
        fin.read(val, 4);
    }
    fin.close();
    fin.open(filename, std::ios::binary); 
    int* keys = new int[n];
    for(int i=0; i < n; i++){
        fin.read(val, 4);
        keys[i] = *reinterpret_cast<int*>(val);
    }
    fin.close();
    *n_keys = n;
    delete[] val;
    return keys;
}

int main(int nargs, char** vargs){
	int n_data;
	int* data;
//RB Tree
    n_data = 0;
    data = readKeysFromFile("../keys_sorted.bin", &n_data);
    trees::RB rbtree;
    for(int i=0; i<n_data;i++){
        std::cout<< "inserting " << data[i] << std::endl;
        rbtree.insert(data[i]);
    } 
    rbtree.traverse();

//ABB Tree
/*
	n_data = 0;
    std::cout << "Rufus1" << std::endl;
    data = readKeysFromFile("../keys_sorted.bin", &n_data);
    std::cout << "Rufus2" << std::endl;
    trees::ABB abbtree;
    for(int i=0; i<n_data;i++){
        std::cout<< "inserting " << data[i] << std::endl;
        abbtree.insert(data[i]);
    }
    abbtree.updateSize();
    abbtree.traverse();
//AVL Tree
	int n_data = 0;
    std::cout << "Rufus1" << std::endl;
    int* data = readKeysFromFile("../keys_sorted.bin", &n_data);
    std::cout << "Rufus2" << std::endl;
    trees::RB rbtree;
    for(int i=0; i<n_data;i++){
        std::cout<< "inserting " << data[i] << std::endl;
        rbtree.insert(data[i]);
    } 
    rbtree.traverse();
    return 0;
*/
}
