/***********
 *AvlTree.h*
 ***********/

#include <iostream>

template<typename Comparable>
class AvlTree {
public:
    AvlTree() {
        root = NULL;
    } // Constructor

    AvlTree(const AvlTree & rhs) {
        root = NULL;
        *this = rhs;
    } // Copy Constructor

    const AvlTree & operator=(const AvlTree & rhs) {
        if (this != &rhs) {
            makeEmpty();
            root = clone(rhs.root);
        }
        return *this;
    } // Overload "operator="

    ~AvlTree() {
        makeEmpty();
    } // Destructor

    const Comparable & findMin() const {
        return findMin(root);
    } // Find Minimum Element

    const Comparable & findMax() const {
        return findMax(root);
    } // Find Maximum Element

    bool contains(const Comparable & x) const {
        return contains(x, root);
    } // Test if an item is in the tree.

    bool isEmpty() const {
        return root == NULL;
    } // Test if the tree is empty.

    void makeEmpty() {
        makeEmpty(root);
    } // Make the tree empty.

    void insert(const Comparable & x) {
        insert(x, root);
    } // Insert an item into the tree.

    void remove(const Comparable & x) {
        remove(x, root);
    } // Remove an item from the tree.

    void printTree(std::ostream & out = std::cout) const {
        if (isEmpty())
            out << "Empty Tree" << std::endl;
        else
            printTree(root, out);
    } // Print the tree in sorted order.

    int treeHeight() const {
        return treeHeight(root);
    } // Compute the height of the tree.

private:
    struct AvlNode {
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const Comparable & theElement, AvlNode *lt, AvlNode *rt, int h = 0) : element(theElement), left(lt), right(rt), height(h) {}
    };

    AvlNode *root;

    void insert(const Comparable & x, AvlNode * & t);
    void remove(const Comparable & x, AvlNode * & t);
    AvlNode * findMin(AvlNode *t) const;
    AvlNode * findMax(AvlNode *t) const;
    bool contains(const Comparable & x, AvlNode *t) const;
    void makeEmpty(AvlNode * & t);
    void printTree(AvlNode *t, std::ostream & out) const;
    int treeHeight(AvlNode *t) const;
    AvlNode * clone(AvlNode *t) const;
    int height(AvlNode *t) const;
    void rotateWithLeftChild(AvlNode * & k2);
    void rotateWithRightChild(AvlNode * & k2);
    void doubleWithLeftChild(AvlNode * & k3);
    void doubleWithRightChild(AvlNode * & k3);
};




-----------------------------------------------------------------------------------------------------------

-----------------------------------------------------------------------------------------------------------

/*************
 *AvlTree.cpp*
 *************/

#include "AvlTree.h"

template<typename Comparable>
typename AvlTree<Comparable>::AvlNode * AvlTree<Comparable>::findMin(
        AvlNode *t) const {
    if (t == NULL)
        return NULL;
    if (t->left == NULL)
        return t;
    return findMin(t->left);
}

template<typename Comparable>
typename AvlTree<Comparable>::AvlNode * AvlTree<Comparable>::findMax(
        AvlNode *t) const {
    if (t == NULL)
        return NULL;
    if (t->right == NULL)
        return t;
    return findMax(t->left);
}

/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the subtree.
 */
template<typename Comparable>
bool AvlTree<Comparable>::contains(const Comparable & x, AvlNode *t) const {
    if (t == NULL)
        return false;
    else if (t->element > x)
        return contains(x, t->left);
    else if (x > t->element)
        return contains(x, t->right);
    else
        return true; // Match
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template<typename Comparable>
void AvlTree<Comparable>::insert(const Comparable & x, AvlNode * & t) {
    if (t == NULL)
        t = new AvlNode(x, NULL, NULL);
    else if (t->element > x) {
        insert(x, t->left);
        if (height(t->left) - height(t->right) == 2) {
            if (t->left->element > x)
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
    } else if (x > t->element) {
        insert(x, t->right);
        if (height(t->right) - height(t->left) == 2) {
            if (x > t->right->element)
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        }
    } else
        ; // Duplicate; do nothing
    t->height = std::max(height(t->left), height(t->right)) + 1;
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template<typename Comparable>
void AvlTree<Comparable>::remove(const Comparable & x, AvlNode * & t) {
    if (t == NULL)
        return;
    // Item not found; do nothing
    if (t->element > x) {
        remove(x, t->left);
        if (height(t->right) - height(t->left) == 2) {
            if (height(t->right->right) >= height(t->right->left))
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        }
    } else if (x > t->element) {
        remove(x, t->right);
        if (height(t->left) - height(t->right) == 2) {
            if (height(t->left->left) >= height(t->left->right))
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
    } else if (t->left != NULL && t->right != NULL) {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
        t->height = std::max(height(t->left), height(t->right)) + 1;
    } else {
        AvlNode *oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }

    if (t != NULL)
        t->height = std::max(height(t->left), height(t->right)) + 1;
}

/**
 * Internal method to make subtree empty.
 */
template<typename Comparable>
void AvlTree<Comparable>::makeEmpty(AvlNode * & t) {
    if (t != NULL) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = NULL;
}

/**
 * Internal method to clone subtree.
 */
template<typename Comparable>
typename AvlTree<Comparable>::AvlNode * AvlTree<Comparable>::clone(
        AvlNode *t) const {
    if (t == NULL)
        return NULL;
    return new AvlNode(t->element, clone(t->left), clone(t->right));
}

/**
 * Internal method to print a subtree rooted at t in sorted order.
 */
template<typename Comparable>
void AvlTree<Comparable>::printTree(AvlNode *t, std::ostream & out) const {
    if (t != NULL) {
        printTree(t->left, out);
        out << t->element << ' ';
        printTree(t->right, out);
    }
}

/**
 * Return the height of node t or -1 if NULL.
 */
template<typename Comparable>
int AvlTree<Comparable>::height(AvlNode *t) const {
    return t == NULL ? -1 : t->height;
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
template<typename Comparable>
void AvlTree<Comparable>::rotateWithLeftChild(AvlNode * & k2) {
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

/**
 * Rotate binary tree node with right child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
template<typename Comparable>
void AvlTree<Comparable>::rotateWithRightChild(AvlNode * & k2) {
    AvlNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max(height(k2->right), height(k2->left)) + 1;
    k1->height = std::max(height(k1->right), k2->height) + 1;
    k2 = k1;
}

/**
 * Double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
template<typename Comparable>
void AvlTree<Comparable>::doubleWithLeftChild(AvlNode * & k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

/**
 * Double rotate binary tree node: first right child
 * with its left child; then node k3 with new right child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
template<typename Comparable>
void AvlTree<Comparable>::doubleWithRightChild(AvlNode * & k3) {
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

/**
 * Internal method to compute the height of a subtree rooted at t.
 */
template<typename Comparable>
int AvlTree<Comparable>::treeHeight(AvlNode *t) const {
    if (t == NULL)
        return -1;
    else
        return 1 + std::max(treeHeight(t->left), treeHeight(t->right));
}


-------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------


/*********
*main.cpp*
**********/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AvlTree.cpp"

int main() {
    AvlTree<int> t1;
    srand(time(NULL));
    for (int i = 0; i < 127; i++) {
        t1.insert(rand());
    }

    std::cout << "t1's height=" << t1.treeHeight() << std::endl;
    std::cout << "t1 is { ";
    t1.printTree();
    std::cout << "}" << std::endl;

    AvlTree<int> t2(t1);
    int n = 0;
    while (n < 96) {
        int j = rand();
        if (t2.contains(j)) {
            t2.remove(j);
            n++;
        }
    }
    t1 = t2;

    std::cout << "t1's height=" << t1.treeHeight() << std::endl;
    std::cout << "t1 is { ";
    t1.printTree();
    std::cout << "}" << std::endl;

    return 1;
}



--------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------



/*t1's height=7
t1 is { 31 281 910 1187 1251 1265 1367 2362 2752 3080 3376 3770 4054 4146 4227 4396 4753 4756 5023 5520 5521 5569 
5660 5811 6187 6846 6983 7437 7445 7535 7649 7707 9141 10134 10250 10334 10440 10454 10758 10870 11110 11591 12744
 13191 13195 13219 13573 13653 14011 14270 14328 14356 14436 14500 14594 14775 15119 15188 15255 15259 15272 15489 
 15913 16133 16559 16860 17016 17115 17564 17749 18499 18843 19331 19369 19546 19579 19646 19731 19885 20213 20354 
 20384 21037 21065 21923 22538 22658 22762 22774 23209 23317 23449 23487 23643 23701 23858 25223 25232 25453 25478 
 25941 26480 26639 27365 27415 27461 27654 27851 28145 28398 28472 28590 29096 29156 29258 29290 29335 29466 29487 
 30569 31524 31979 32040 32185 32365 32480 32717 }
t1's height=5
t1 is { 2752 4054 5521 6187 6846 7437 9141 13573 13653 14270 14356 14500 14775 15489 17016 18499 19369 19546 20213
 21037 22762 23701 23858 27365 27851 28472 29290 29335 29466 31979 32717 }
 */
