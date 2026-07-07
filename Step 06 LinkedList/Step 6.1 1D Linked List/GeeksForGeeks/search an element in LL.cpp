bool searchKey(Node* head, int key) {
        bool p = false;
        while(head!=NULL && !p){
            if(key == head->data){
                p = true;
            }
            head = head->next;
        }
        return p;
    }
