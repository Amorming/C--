ListNode *reverseBetween(ListNode *head, int m, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (head->next == NULL || n == m)
        return head;
        
    ListNode *root = new ListNode (0);
    root->next = head;
    
    ListNode *headin, *headout, *tailin, *tailout;
    ListNode *pre, *cur, *nex;

    int count = 0;
    pre =root;
    /* search for the previous point of reverse start point 
     * record the headout */
    while ( count < m - 1 ) {
        pre = pre->next;
        count++;
    }
    headout = pre;
    tailin = pre->next;
    
    /* head forward to the actual start point of reversing */
    pre = pre->next;
    cur = pre->next;
    nex = cur->next;
    count++;
    
    /* start reversing the list */
    /* cur != NULL */
    while ( count < n ) {    
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
        count++;
    }
    
    headin = pre;
    tailout = cur;
    
    /* get them linked !!! */
    headout->next = headin;
    tailin->next = tailout;
    
    return root->next;
}
