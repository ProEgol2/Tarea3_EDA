/*
 * abb.cpp
 *
 *  Created on: Sep 2, 2022
 *      Author: jsaavedr
 */

#include "trees/rb.hpp"
#include <iostream>


namespace trees {

RB::RB():root(nullptr) {
	// TODO Auto-generated constructor stub
}

void RB::balance(RBNode* node){
	RotationType rType;
	RBNode* parent = node->getParent();
	
	if(node->getColor() == 'R' && parent->getColor() == 'R'){
		rType = getRotationType(node);
		
		if(rType == RotationType::case_1){
			//std::cout<<"Realiza caso 1"<<std::endl;
			do_case_1(node);
		}
		else if(rType == RotationType::case_2){
			//std::cout<<"Realiza caso 2"<<std::endl;
			do_case_2(node);
		}
		else if(rType == RotationType::case_3){
			//std::cout<<"Realiza caso 3"<<std::endl;
			do_case_3(node);
		}
		else if(rType == RotationType::case_4){
			//std::cout<<"Realiza caso 4"<<std::endl;
			do_case_4(node);
		}
		else{
			//std::cout<<"Realiza caso 5"<<std::endl;
			do_case_5(node);
		}
	}
}

RotationType RB::getRotationType(RBNode* node){
	/*this will run if node is unbalanced*/
	RotationType rType;
	
	RBNode* parent = node->getParent();
	RBNode* uncle = parent->isLeft()?parent->getParent()->getRight():parent->getParent()->getLeft();
	
	if(uncle != nullptr && uncle->getColor() == 'R'){
		//Caso solo recolor, case_1
		rType = RotationType::case_1;
	}
	else{
		if(parent->isLeft()){
			if(node->isLeft()){
				//Caso nodo y padre izquierdos
				rType = RotationType::case_2;
			}
			else{
				//Caso nodo derecho y padre izquierdo
				rType = RotationType::case_4;
			}
		}
		else{
			if(node->isRight()){
				//Caso nodo y padre derechos
				rType = RotationType::case_3;
			}
			else{
				//Caso nodo izquierdo y padre derecho
				rType = RotationType::case_5;
			}
		}
	}
	return rType;
}

void RB::do_case_1(RBNode* node){

	RBNode* parent = node->getParent();
	RBNode* uncle = parent->isLeft()?parent->getParent()->getRight():parent->getParent()->getLeft();
	
	parent->setColor(NodeColor::BLACK);
	if(parent->getParent()->getData() != root->getData()){
		parent->getParent()->setColor(NodeColor::RED);
	}
	uncle->setColor(NodeColor::BLACK);
}

void RB::do_case_2(RBNode* node){

	RBNode* parent = node->getParent();
	RBNode* gparent = parent->getParent();
	
	if(parent->getRight() != nullptr){
		gparent->setLeft(parent->getRight());
	}
	else{
		gparent->setLeft(nullptr);
	}
	if(gparent->getParent() == nullptr){
		root = parent;
		parent -> setParent(nullptr);
	}
	else{
		if(gparent->isRight()){
			gparent->getParent()->setRight(parent);
		}
		else{
			gparent->getParent()->setLeft(parent);
		}
	}
	parent->setRight(gparent);
	gparent->setColor(NodeColor::RED);
	parent->setColor(NodeColor::BLACK);
}

void RB::do_case_3(RBNode* node){
	
	RBNode* parent = node->getParent();
	RBNode* gparent = parent->getParent();
	
	if(parent->getLeft() != nullptr){
		gparent->setRight(parent->getLeft());
	}
	else{
		gparent->setRight(nullptr);
	}
	if(gparent->getParent() == nullptr){
		root = parent;
		parent -> setParent(nullptr);
	}
	else{
		if(gparent->isRight()){
			gparent->getParent()->setRight(parent);
		}
		else{
			gparent->getParent()->setLeft(parent);
		}
	}
	parent->setLeft(gparent);
	gparent->setColor(NodeColor::RED);
	parent->setColor(NodeColor::BLACK);
}

void RB::do_case_4(RBNode* node){
	
	RBNode* parent = node->getParent();
	RBNode* gparent = parent->getParent();
	
	if(node->getLeft() != nullptr){
		parent->setRight(node->getLeft());
	}
	else{
		parent->setRight(nullptr);
	}
	node->setLeft(parent);
	gparent->setLeft(node);
}

void RB::do_case_5(RBNode* node){
	
	RBNode* parent = node->getParent();
	RBNode* gparent = parent->getParent();
	
	if(node->getRight() != nullptr){
		parent->setLeft(node->getRight());
	}
	else{
		parent->setLeft(nullptr);
	}
	node->setRight(parent);
	gparent->setRight(node);
}

void RB::insert(int val, RBNode* node){

	if (val < node->getData()){
		if (node->getLeft() == nullptr){
			RBNode* newNode = new RBNode(val, node);
			node->setLeft(newNode);
			balance(newNode);
		}
		else{
			insert(val, node->getLeft());
		}
	}
	else{
		if (node->getRight() == nullptr){
			RBNode* newNode = new RBNode(val, node);
			node->setRight(newNode);
			balance(newNode);
		}
		else{
			insert(val, node->getRight());
		}
	}
	if(root != node){balance(node);}
}

void RB::insert(int val){
	if (root == nullptr){
		root = new RBNode(val);
		root->setColor(NodeColor::BLACK);
	}
	else{
		insert(val, root);
	}
}

RBNode* RB::find(int val, RBNode* node) {
    if (node == nullptr) {
        return nullptr;
    }
    
    if (node->getData() == val) {
        return node;
    }

    if (val < node->getData()) {
        return find(val, node->getLeft());
    } else {
        return find(val, node->getRight());
    }
}

RBNode* RB::find(int val) {
    return find(val, root);
}


void RB::traverse(RBNode* node, int label){
	if (node != nullptr){
		for (int i = 0; i < label; i++){
			std::cout << "*" << std::flush;
		}
		char T = node->isLeft()?'L':'R';
		std::cout << node->getData() << "  " << T <<std::endl;
		traverse(node->getLeft(), label + 1);
		traverse(node->getRight(), label + 1);
	}
}

void RB::traverse(){
	traverse(root, 1);
}

RB::~RB() {
	delete root;
}

} /* namespace trees */
