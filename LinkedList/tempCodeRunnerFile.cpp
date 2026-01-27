void display(){
    LLNode* cur = list;
    if (cur == NULL){
        cout<< "list is empty\n";
        return;
    }
    while (cur != NULL){
        cout << cur ->data<< "-->";
        cur = cur -> next;

    }
    cout << "Null\n";
}