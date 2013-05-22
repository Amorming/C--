ListNode *deleteDuplicates(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!head)
        return head;
    
    ListNode root (0);
    root.next = head;
    
    int checker = head->val;
    ListNode *previous = head;
    ListNode *current;
    
    while (previous->next) {
        current = previous->next;
        if (current->val == checker) 
            previous->next = current->next;
        else {
            previous = previous->next;
            checker = previous->val;
        }
    }
    
    return root.next;
}
