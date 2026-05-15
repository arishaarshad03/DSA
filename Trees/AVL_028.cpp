#include <iostream>
using namespace std;

struct AVLNode{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

AVLNode* root = nullptr;

int height (AVLNode* node){
    if (node == nullptr){
        return -1;
    }
    return node->height;
}


AVLNode* rotate_right(AVLNode* cur){
    AVLNode* temp = cur;
    cur = cur ->left;
    AVLNode* temp2 = cur ->right;
    cur ->right = temp;
    temp ->left = temp2;

    temp ->height = 1 + max(height(temp ->left), height(temp->right));
    cur ->height = 1 + max(height(cur ->left), height(cur->right));

    return cur;

}

AVLNode* rotate_left(AVLNode* cur){
    AVLNode* temp = cur;
    cur = cur ->right;
    AVLNode* temp2 = cur ->left;
    cur ->left = temp;
    temp ->right = temp2;

    temp ->height = 1 + max(height(temp ->left), height (temp ->right));
    cur -> height = 1+ max(height(cur ->left), height (cur ->right));

    return cur;
}

AVLNode* rotate_right_left(AVLNode* cur){
    cur -> right = rotate_right(cur ->right);
    return rotate_left(cur);
}

AVLNode* rotate_left_right(AVLNode* cur){
    cur ->left = rotate_left(cur -> left);
    return rotate_right(cur);
}

int balanceFactor(AVLNode* node){
    return height(node->left) - height(node->right);
}

AVLNode* insert(AVLNode* cur, int val){
    // base case
    if (cur == nullptr){
        AVLNode* temp = new AVLNode;
        temp ->data = val;
        temp ->left = nullptr;
        temp ->right = nullptr;
        temp->height = 0;
        return temp;
    }
    
    if (val < cur ->data){
        cur ->left = insert(cur ->left, val);
    }
    else if (val > cur ->data){
        cur ->right = insert (cur ->right, val);
    }
    else{
        //duplicate, do nothing
        return cur;      
    }

    // update height 
    cur ->height = 1+ max(height(cur ->right), height (cur ->left));

    // calc balance factor
    int bf = balanceFactor(cur);

    // rotaations
    if (bf > 1 ){
        // left heavy
        int leftbf = balanceFactor(cur ->left);
        if (leftbf == -1){
            return rotate_left_right(cur);
        }
        else{
            return rotate_right(cur);
        }
    }
    if (bf < -1){
        // right heavy
        int rightbf = balanceFactor(cur ->right);
        if (rightbf ==1){
            return rotate_right_left(cur);
        }
        else{
            return rotate_left(cur);
        }
    }

    return cur;
}

AVLNode* remove (AVLNode* cur, int val){
    if (cur == nullptr){
        return nullptr;
    }
    if (cur -> data == val){
        // node has no child
        if (cur -> right == nullptr && cur ->left == nullptr)
        {
            delete cur;
            return nullptr;
        }
        // 1 child
        else if (cur ->left == nullptr){
            //right child exist
            AVLNode* temp = cur ->right;
            delete cur;
            return temp;
        }
        else if (cur ->right == nullptr){
            //left child exist
            AVLNode* temp = cur ->left;
            delete cur;
            return temp;
        }
        else{
            // have both child
            // find a sucessor that will take its place
            // -> go right once then mossst left and replace cur with sucessor then delete sucessor

            AVLNode* sucessor = cur ->right;
            while (sucessor ->left != nullptr){
                sucessor = sucessor ->left;
            }
            cur ->data = sucessor ->data;
            // delete sucessor
            cur ->right = remove (cur ->right, sucessor->data);
        }
    }
    else if (val > cur ->data){
        cur ->right = remove(cur ->right, val);
    }
    else{
        cur ->left = remove(cur ->left, val);
    }

    // update height
    cur ->height = 1 + max (height (cur -> right), height (cur -> left));

    // balance factor
    int bf = balanceFactor(cur);

    // rotations
    if (bf > 1 ){
        // left heavy
        int leftbf = balanceFactor(cur ->left);
        if (leftbf == -1){
            return rotate_left_right(cur);
        }
        else{
            return rotate_right(cur);
        }
    }
    if (bf < -1){
        // right heavy
        int rightbf = balanceFactor(cur ->right);
        if (rightbf ==1){
            return rotate_right_left(cur);
        }
        else{
            return rotate_left(cur);
        }
    }
    return cur;

}
void preorder(AVLNode* cur){
    if (cur != nullptr){
        cout<< cur ->data<< "  ";
        preorder(cur ->left);
        preorder(cur ->right);
    }
}
void inorder(AVLNode* cur){
    if (cur != nullptr){
        inorder(cur ->left);
        cout<< cur ->data<<"  ";
        inorder(cur ->right);

    }
}
void postorder(AVLNode* cur){
    if (cur != nullptr){
        postorder(cur ->left);
        postorder(cur ->right);
        cout << cur ->data <<"  ";
    }
}

AVLNode* search(AVLNode* cur , int val){
    if (cur == nullptr){
        return nullptr;
    }
    if (cur ->data == val){
        return cur;
    }

    if (val > cur ->data){
        return search (cur -> right, val);
    }
    else{
        return search (cur -> left, val);
    }
}



int main() {
    int choice, value;
    
    do {
        cout << "\n=====AVL TREE MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. delete a value\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Value inserted successfully!\n";
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value) != nullptr)
                cout << "Value FOUND in tree\n";
            else
                cout << "Value NOT FOUND in tree\n";
            break;

        case 3:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        
        case 6:
        cout << "Enter value to delete: ";
        cin >> value;
        if (search(root, value) == nullptr) {
            cout << "Error: Value NOT FOUND in the list. Nothing to delete.\n";
        } else {
            root = remove(root, value);
            cout << "Value deleted successfully.\n";
        }
        break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}