#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs.root;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}


template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> rhs)
{
    swap(rhs);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType>& rhs)
{
    std::swap(root, rhs.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

// FOLLOWING TEMPLATE GIVEN IN CLASS 

    // 1. insert(key, item):
    // 2. search(key)
    // 3. if search fails
    // 4. if key < last visited
    // 5. insert left child
    // 6. if key > last visited
    // 7. insert right child

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // "Base Case" - if the tree is empty
    if(root == nullptr)
    {
        // Add item to root of tree
        root = new Node<KeyType, ItemType>;
        root->key = key;
        root->data = item;
        return true;
    }

    // Declaring wanted pointers
    Node<KeyType,ItemType> *one, *two;

    // search (key)
    search(key, one, two);

    // Making sure there are no duplicates
    if(key == one->key)
    {
        return false;
    }

    // Declaring wanted pointers
    Node<KeyType,ItemType> *temp = new Node<KeyType, ItemType>;
    temp->data = item;
    temp->key = key;

    // Insert Left Child
    if (key < one->key)
    {
        one->left = temp;
    }
    // Insert Right Child
    else
    {
        one->right = temp;
    }

    // Returning the value of true meaning it has been inserted
    return true;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

// FOLLOWING TEMPLATE GIVEN IN CLASS 

    // 1. delete(key):
    // 2a. if (search for key fails)
    // 2b. delete fails
    // 3. else
    // 4a. if (found node is leaf)
    // 4b. delete it
    // 5a. if (found node has left or right child only)
    // 5b. delete node, replace with child
    // 6a. else
    // 6b. find inorder successor, copy to found node
    // 6c. delete inorder successor

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
    {
        return false; // empty tree
    }

    // case one thing in the tree - DONE
    if (root->left == nullptr && root->right == nullptr)
    {
        // Deleting the root of the tree, since that is the only thing that is present
        if (key == root->key)
        {      
            root = nullptr;
            delete root; 
            return true;
        }
    }

    // Declaring wanted pointers
    Node<KeyType,ItemType> *one, *two;

    // search (key)
    search(key, one, two);

    // If search for key fails, then delete fails
    if (key != one->key)
    {
        one = nullptr;
        delete one;
        return false;
    }

    // case, found deleted item at leaf - DONE
    if (one->right == nullptr && one->left == nullptr)
    {
        // Checks if the left side or right side needs to be deleted ( two == parent )
        if (two->right == one)
        {
            two->right = nullptr;
        }
        else
        {
            two->left = nullptr;
        }

        // Delete node
        one = nullptr;
        delete one;
        return true;
    }

    // case, item to delete has only a right child - DONE
    if (one->right != nullptr && one->left == nullptr)
    {
        // Replace the node to be deleted with the child 
        Node<KeyType,ItemType> *temp = one->right;
        *one = *temp;

        // Delete node
        temp = nullptr;
        delete temp;
        return true;
    }

    // case, item to delete has only a left child - DONE
    if (one->right == nullptr && one->left != nullptr)
    {
        // Replace the node to be deleted with the child 
        Node<KeyType,ItemType> *temp = one->left;
        *one = *temp;

        // Delete node
        temp = nullptr;
        delete temp;
        return true;
    }
    // case, item to delete has two children - DONE
    else if (one->right != nullptr && one->left != nullptr)
    {
        // Find inorder successor
        Node<KeyType,ItemType> *three, *four;
        inorder(one, three, four);

        // Copy to found node
        *one = *three;

        // Delete inorder successor
        three = nullptr;
        delete three;
        return true;
    }

    // Returning false if the key does not fit into any of these statements 
    return false; 
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    // TODO: find inorder successor of "curr" and assign to "in"

    if (curr == nullptr)
    {
        return;
    }

    // Recursively traversing through the left subtree
    inorder(curr->left, in, parent);

    // If the parent is not empty and curr > last node
    if (parent != nullptr && curr->key >= parent->key)
    {
        // Successor has been found and the function can end
        in = curr;
        return;
    }

    // Setting parent node to the curr node
    parent = curr;

    // Recursively traversing through the left subtree
    inorder(curr->right, in, parent);

}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

// *************************
// BONUS TREESORT FUNCTION *
// *************************

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int size)
{
    // Create a Binary Search Tree by inserting list items into the tree
    Node<KeyType, ItemType> *root = nullptr; 

    ItemType item;
  
    insert2(root, arr[0], item);

    // Construct the BST 
    for (int i = 0; i < size; i++)
    {
        insert2(root, arr[i], item);
    }

    // Perform in-order traversal of the tree to access the items in sorted order
    int i = 0; 
    storeSorted(root, arr, i); 
}

// New Inorder-Traversal function to help implement the TreeSort BONUS function
// ****************************
// GOT HELP FOR GEEKSFORGEEKS *
// ****************************

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::storeSorted(Node<KeyType, ItemType>* node, KeyType arr[], int& i)
{
    if (node != nullptr) 
    { 
        // Sorts the value in sorted order
        storeSorted(node->left, arr, i); 
        arr[i++] = node->key; 
        storeSorted(node->right, arr, i); 
    } 
}

// New Insert function to help implement the TreeSort BONUS function
// ****************************
// GOT HELP FOR GEEKSFORGEEKS *
// ****************************

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::insert2(Node<KeyType, ItemType>*& node, const KeyType& key, const ItemType& item)
{
    if (node == nullptr)
    {
        node = new Node<KeyType, ItemType>;
        node->key = key;
        node->data = item; 
        node->left = node->right = nullptr;
    }

    // Recursively insert into the appropriate subtree
    if (key < node->key)
    {
        insert2(node->left, key, item);
    }
    else if (key > node->key)
    {
        insert2(node->right, key, item);
    }
}