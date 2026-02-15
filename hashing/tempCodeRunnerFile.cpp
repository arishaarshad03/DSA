void remove (int val){
    int index = hashfunc(val);

    Node* cur = table[index];
    Node* prev = nullptr;
    while (cur != nullptr){

        if (cur ->data == val){

            // deleting first node
            if (prev == nullptr){
                table[index] = cur ->next;
            }
            else {
                // deleting middle or last node
                prev ->next = cur ->next;
            }
            delete cur;
            cout <<"value deleted at index: "<<index;
            return;
        }
        prev = cur;
        cur = cur ->next;
    }
    cout <<"value " << val << " is not found\n";
}