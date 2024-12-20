/*
 * abb.hpp
 *
 *  Created on: Sep 2, 2022
 *      Author: jsaavedr
 */

#ifndef AVL_HPP_
#define AVL_HPP_

#include "trees/avlNode.hpp"

namespace AVLtrees {

enum RotationType{
	LeftRotation = 10,
	RightRotation = 20,
	LeftRightRotation = 30,
	RightLeftRotation = 40
};

class AVL {
private:
	AVLNode* root;
	/*private methods, rotations*/
	void balance(AVLNode* node);
	void leftRotation(AVLNode* node);
	void rightRotation(AVLNode* node);
	void leftRightRotation(AVLNode* node);
	void rightLeftRotation(AVLNode* node);
	RotationType getRotationType(AVLNode* node);
public:
	AVL();
	void insert_rec(int val, AVLNode* node);
	void insert(int val);
	AVLNode* find_rec(int val, AVLNode* node);
	AVLNode* find(int val);
	void traverse_rec(AVLNode* node, int level);
	void traverse();
	virtual ~AVL();
};

} /* namespace trees */

#endif /* AVL_HPP_ */
