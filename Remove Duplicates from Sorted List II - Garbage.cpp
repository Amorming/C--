ListNode *deleteDuplicates(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!head || !head->next)
        return head;
        
    ListNode root (0);
    ListNode *runnerRet = &root;
    ListNode *runnerOrg = head;
    
    while (runnerOrg && runnerOrg->next) {
        if (runnerOrg->val != runnerOrg->next->val) {
            runnerRet->next = runnerOrg;
            runnerOrg = runnerOrg->next;
            runnerRet = runnerRet->next;
            runnerRet->next = NULL;
        }
        else {
            while (runnerOrg->next && runnerOrg->val == runnerOrg->next->val) {
                runnerOrg = runnerOrg->next;
            }
            runnerOrg = runnerOrg->next;
        }
        
    }
    runnerRet->next = runnerOrg;
    return root.next;
}
