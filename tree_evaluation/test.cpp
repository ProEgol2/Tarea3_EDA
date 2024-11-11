#include "trees/rb.hpp"
#include "trees/abb.hpp"
#include "trees/avl.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

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

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

int main(int nargs, char** vargs){
	int n_data;
    int n_data2 = 0;
    int n_data3 = 0;
    int n_data4 = 0;
    int n_queries= 0;
    /*
    int* data = readKeysFromFile("../keys_1024.bin", &n_data);
    int* data2 = readKeysFromFile("../keys_32768.bin", &n_data2);
    int* data3 = readKeysFromFile("../keys_1048576.bin", &n_data3);
    int* data4 = readKeysFromFile("../keys_33554432.bin", &n_data4);
    */
    int* data = readKeysFromFile("../keys_sorted_1024.bin", &n_data);
    int* data2 = readKeysFromFile("../keys_sorted_32768.bin", &n_data2);
    int* data3 = readKeysFromFile("../keys_sorted_1048576.bin", &n_data3);
    int* data4 = readKeysFromFile("../keys_sorted_33554432.bin", &n_data4);
    
    
   int* questions = readKeysFromFile("../queries_1000.bin", &n_queries);
    
    trees::RB rbtree;
    trees::RB rbtree2;
    trees::RB rbtree3;
    trees::RB rbtree4;
    
    
    

    /*
    trees::ABB rbtree;
    trees::ABB rbtree2;
    trees::ABB rbtree3;
    trees::ABB rbtree4;
    */
    
    

    /*
    AVLtrees::AVL rbtree;
    AVLtrees::AVL rbtree2;
    AVLtrees::AVL rbtree3;
    AVLtrees::AVL rbtree4;
    */
    


    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n_data;i++){
        //std::cout<< "inserting " << data[i] << std::endl;
        rbtree.insert(data[i]);
    } 
    auto end = std::chrono::high_resolution_clock::now();
    std::cout<<" Elapsed1 : " << getElapsedTime(start, end) << std::endl;

    auto startq = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n_queries;i++){
        //std::cout<< "finding  " << data[i] << std::endl;
        rbtree.find(questions[i]);
    } 
    auto endq = std::chrono::high_resolution_clock::now();
    std::cout<<" Elapsed queries1 : " << getElapsedTime(startq, endq) << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n_data2;i++){
        //std::cout<< "inserting " << data[i] << std::endl;
        rbtree2.insert(data2[i]);
    } 
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout<<" Elapsed2 : " << getElapsedTime(start2, end2) << std::endl;
    auto startq2 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n_queries;i++){
        //std::cout<< "finding  " << questions[i] << std::endl;
        rbtree2.find(questions[i]);
    } 
    auto endq2 = std::chrono::high_resolution_clock::now();
    std::cout<<" Elapsed queries2 : " << getElapsedTime(startq2, endq2) << std::endl;
    
    auto start3 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n_data3;i++){
        //std::cout<< "inserting " << data3[i] << std::endl;
        rbtree3.insert(data3[i]);
    } 
    auto end3 = std::chrono::high_resolution_clock::now();
    std::cout<<" Elapsed3 : " << getElapsedTime(start3, end3) << std::endl;
    auto startq3 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n_queries;i++){
        //std::cout<< "finding  " << questions[i] << std::endl;
        rbtree3.find(questions[i]);
    } 
    auto endq3 = std::chrono::high_resolution_clock::now();
    std::cout<<" Elapsed queries3 : " << getElapsedTime(startq3, endq3) << std::endl;


    auto start4 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n_data4;i++){
        //std::cout<< "inserting " << data[i] << std::endl;
        rbtree4.insert(data4[i]);
    } 
    auto end4 = std::chrono::high_resolution_clock::now();
    std::cout<<" Elapsed4 : " << getElapsedTime(start4, end4) << std::endl;
    auto startq4 = std::chrono::high_resolution_clock::now();
    for(int i=0; i<n_queries;i++){
        //std::cout<< "finding  " << questions[i] << std::endl;
        rbtree4.find(questions[i]);
    } 
    auto endq4 = std::chrono::high_resolution_clock::now();
    std::cout<<" Elapsed queries4 : " << getElapsedTime(startq4, endq4) << std::endl;
    //rbtree.traverse();
    


}
