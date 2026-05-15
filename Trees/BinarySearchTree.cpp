#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};
Node* root = nullptr;

Node* insert(Node* cur, int val){

    // base case
    if (cur == nullptr){
        Node* temp = new Node;
        temp->data = val;
        temp ->left = nullptr;
        temp -> right = nullptr;
        
        return temp;
    }
    if (val > cur ->data){
        cur -> right = insert(cur ->right, val);
    }
    else{
        cur ->left = insert (cur ->left , val);
    }
    return cur;
}

void preorder(Node* cur){
    if (cur != nullptr){
        cout<< cur ->data<< "  ";
        preorder(cur ->left);
        preorder(cur ->right);
    }
}
void inorder(Node* cur){
    if (cur != nullptr){
        inorder(cur ->left);
        cout<< cur ->data<<"  ";
        inorder(cur ->right);

    }
}
void postorder(Node* cur){
    if (cur != nullptr){
        postorder(cur ->left);
        postorder(cur ->right);
        cout << cur ->data <<"  ";
    }
}

Node* search(Node* cur , int val){
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


Node* remove (Node* cur, int val){
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
            Node* temp = cur ->right;
            delete cur;
            return temp;
        }
        else if (cur ->right == nullptr){
            //right child exist
            Node* temp = cur ->left;
            delete cur;
            return temp;
        }
        else{
            // have both child
            // find a sucessor that will take its place
            // -> go right once then mossst left and replace cur with sucessor then delete sucessor

            Node* sucessor = cur ->right;
            while (sucessor ->left != nullptr){
                sucessor = sucessor ->left;
            }
            cur ->data = sucessor ->data;
            // delete sucessor
            cur ->right = remove (cur ->right, sucessor->data);
        }
        return cur;
    }
    if (val > cur ->data){
        cur ->right = remove(cur ->right, val);
    }
    else{
        cur ->left = remove(cur ->left, val);
    }
    return cur;

}

int main() {
    int choice, value;
    
    do {
        cout << "\n===== BINARY SEARCH TREE MENU =====\n";
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
                cout << "Value FOUND in BST\n";
            else
                cout << "Value NOT FOUND in BST\n";
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