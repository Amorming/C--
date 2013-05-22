ListNode *partition(ListNode *head, int x) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *rootSmall = new ListNode (0);
    ListNode *rootGreat = new ListNode (0);
    ListNode *runnerSmall = rootSmall;
    ListNode *runnerGreat = rootGreat;
    ListNode *runner = head;
    
    while (runner != NULL) {
         if (runner->val < x) {
             runnerSmall->next = runner;
             runnerSmall = runner;
             runner = runner->next;
             runnerSmall->next = NULL;
         }
         else {
             runnerGreat->next = runner;
             runnerGreat = runner;
             runner = runner->next;
             runnerGreat->next = NULL;
         }
    }
    
    runnerSmall->next = rootGreat->next;
    
    return rootSmall->next;
}
