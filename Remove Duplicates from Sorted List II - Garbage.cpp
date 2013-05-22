ListNode *deleteDuplicates(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!head || !head->next)
        return head;
        
    ListNode root (0);
    /* use to insert the return list at end */
    ListNode *runnerRet = &root;
    /* use to traverse the original list */
    ListNode *runnerOrg = head;
    
    while (runnerOrg && runnerOrg->next) {
        /* different adjacent nodes */
        if (runnerOrg->val != runnerOrg->next->val) {
            /* add it to the return list */
            runnerRet->next = runnerOrg;
            /* both move next */
            runnerOrg = runnerOrg->next;
            runnerRet = runnerRet->next;
            runnerRet->next = NULL;
        }
        /* duplicate nodes */
        else {
            /* make the runnerOrg the next unique node */
            while (runnerOrg->next && runnerOrg->val == runnerOrg->next->val) {
                runnerOrg = runnerOrg->next;
            }
            runnerOrg = runnerOrg->next;
        }
        
    }
    /* insert the last node */
    runnerRet->next = runnerOrg;
    return root.next;
}
