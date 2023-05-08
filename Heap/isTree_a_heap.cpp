private:
int countNode(struct Node *root)
{
    if (root == NULL)
        return 0;

    int count = 1 + countNode(root->left) + countNode(root->right);
    return count;
}

bool isCBT(struct Node *root, int index, int count)
{
    if (root == NULL)
        return true;

    if (index >= count) //means a node is missing in left to right order
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2 * index + 1, count);
        bool right = isCBT(root->right, 2 * index + 2, count);
        return (left && right);
    }
}

bool maxHeap(struct Node *root)
{
    // leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // only left child exists
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = maxHeap(root->left);
        bool right = maxHeap(root->right);

        return (left && right && (root->left->data < root->data && root->right->data < root->data)); //left subtree & right subtree is max heap & left,right data is less than root data
    }
}

public:
bool isHeap(struct Node *tree)
{
    int count = countNode(tree);
    int index = 0;
    if (isCBT(tree, index, count) && maxHeap(tree))
    {
        return true;
    }
    else
    {
        return false;
    }
}