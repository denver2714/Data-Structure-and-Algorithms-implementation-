/*https://www.youtube.com/watch?v=uz6dimvl40Q*/ //For better explanation


void reverse() {
    Node *temp = nullptr;
    Node *current = head;
    
    // Swap next and prev for all nodes in the list
    while (current != nullptr) {
        // Swap the pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Move to the next node in the original list
        current = current->prev;
    }
    
    // After the loop, temp will be pointing to the last node (which should be the new head)
    if (temp != nullptr) {
        head = temp->prev;
    }
}
