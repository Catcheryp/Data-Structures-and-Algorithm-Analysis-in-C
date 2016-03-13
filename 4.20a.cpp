//这道题题目的意思是：先用用二叉搜索树的方法对Avl进行删除，然后对删除之后的Avl进行调整

//不得不承认AVL树的删除确实麻烦,下面先贴一个据说肯定正确的用C++实现的AVL删除的代码

//看懂了其实也没那么麻烦

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
