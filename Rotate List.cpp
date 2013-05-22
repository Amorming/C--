ListNode *rotateRight(ListNode *head, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!head)
        return head;
    
    /* compute the length of list */
    int len = 0;
    ListNode *runner = head;
    while (runner) {
        len++;
        runner = runner->next;
    } 
    
    /* edge case, else node after the rotation point is NULL */
    if (k % len == 0)
        return head;
    
    /* search for the rotation point */
    int move = len - (k % len);
    runner = head;
    while (move-- > 1) 
        runner = runner->next;
        
    /* tmp is the node before the point, runner is the node after */
    ListNode *tmp = runner;
    runner = runner->next;
    tmp->next = NULL;
        
    /* rotate the list */
    ListNode root (0);
    root.next = runner;
    while(runner->next)
        runner = runner->next;
    runner->next = head;
    return root.next;
}
