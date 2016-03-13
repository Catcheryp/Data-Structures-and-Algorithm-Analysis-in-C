AvlTree Remove(Element X, AvlTree T)
{
    if(T == NULL)
        return NULL;
    if(X < T->Element)
    {
        T->Left = Remove(X, T->Left);
        if(Height(T->Right) - Height(T->Left) == 2)
            if(Height(T->Right->Right) >= Height(T->Right->Left))//这里有个等号是因为有种特殊情况不是R旋转的情形，但是用R旋转可行
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
    }
    else if(X > T->Element)
    {
        T->Right = Remove(X, T->Right);
        if(Height(T->Left) - Height(T->Right) == 2)
            if(Height(T->Left->Left) >= Height(T->Left->Right))
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
    }
    else if(T->Left != NULL && T->Right != NULL)//*这里我们找到了待删除的节点，我们从其右子树中寻找一个最小的值来代替该节点，再删除该值的叶子节点即可
    {
        T->Element = FindMin(T->Right)->Element;
        
        T->Right = Remove(T->Element, T->Right);

        T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    }
    else//当删除的节点只有一个或者没有叶子节点时
    {
        //这里是基于void函数的，所以我觉得不能这样改
       /* AvlTree temp = T;
        T = (T->Left != NULL)?T->Left:T->Right;
        free(temp);*/
        if(T->Left != NULL)
            return T->Left;
        else if(T->Right != NULL)
            return T->Right;
        else
            return NULL;
    }

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

//*处的特殊情况
/*
        6
       / \
           8
          / \
         7  10
*/

//我感觉应该现在修改后的代码应该是对的
