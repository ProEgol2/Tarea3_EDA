#include "trees/abb.hpp"
#include <iostream>

namespace trees {

ABB::ABB() : root(nullptr) {}

void ABB::insert(int val) {
    if (root == nullptr) {
        root = new ABBNode(val);
    } else {
        ABBNode* current = root;
        while (true) {
            if (val < current->getData()) {
                // Go left
                if (current->getLeft() == nullptr) {
					std::cout<<"inserting " << val <<std::endl;
                    current->setLeft(new ABBNode(val));
                    break;  // Node inserted, exit loop
                }
                current = current->getLeft();
            } else {
                // Go right
                if (current->getRight() == nullptr) {
					//std::cout<<"inserting " << val <<std::endl;
                    current->setRight(new ABBNode(val));
                    break;  // Node inserted, exit loop
                }
                current = current->getRight();
            }
        }
    }
}

ABBNode* ABB::find_rec(int val, ABBNode* node) {
    ABBNode* ans = nullptr;
    if (node == nullptr) return ans;

    else if (node->getData() == val) {
        ans = node;
    } else {
        if (val < node->getData()) {
            ans = find_rec(val, node->getLeft());
        } else {
            ans = find_rec(val, node->getRight());
        }
    }
    return ans;
}

ABBNode* ABB::find(int val) {
    ABBNode* ans = nullptr;
    ans = find_rec(val, root);
    return ans;
}

void ABB::traverse_rec(ABBNode* node, int level) {
    if (node != nullptr) {
        std::cout << std::string(level * 2, '-');
        std::cout << node->getData() << " | s = " << node->getSize() << std::endl;
        traverse_rec(node->getLeft(), level + 1);
        traverse_rec(node->getRight(), level + 1);
    }
}

void ABB::traverse() {
    traverse_rec(root, 1);
}

void ABB::showASC_rec(ABBNode* node) {
    if (node != nullptr) {
        showASC_rec(node->getLeft());
        std::cout << node->getData() << " " << std::flush;
        showASC_rec(node->getRight());
    }
}

void ABB::showASC() {
    showASC_rec(root);
    std::cout << std::endl;
}

void ABB::updateSize_rec(ABBNode* node) {
    if (node != nullptr) {
        updateSize_rec(node->getLeft());
        updateSize_rec(node->getRight());
        int lSize = 0;
        int rSize = 0;
        if (node->getLeft() != nullptr) {
            lSize = node->getLeft()->getSize();
        }
        if (node->getRight() != nullptr) {
            rSize = node->getRight()->getSize();
        }
        node->setSize(lSize + rSize + 1);
    }
}

void ABB::updateSize() {
    updateSize_rec(root);
}

ABBNode* ABB::k_element_rec(int k, ABBNode* node) {
    ABBNode* ans = nullptr;
    if (node != nullptr) {
        int lSize = 0;
        int posNode = 0;
        if (node->getLeft() != nullptr) {
            lSize = node->getLeft()->getSize();
        }
        posNode = lSize + 1;

        if (k == posNode) {
            ans = node;
        } else if (k > posNode) {
            ans = k_element_rec(k - posNode, node->getRight());
        } else {
            ans = k_element_rec(k, node->getLeft());
        }
    }
    return ans;
}

ABBNode* ABB::k_element(int k) {
    return k_element_rec(k, root);
}

ABB::~ABB() {
    delete root;
}

} /* namespace trees */
