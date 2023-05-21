class Solution {
public:
    int pairSum(ListNode* head) {
        {
            /*
            upper side code linklist value in the stack
            */
            //second slide code process the stack
        }
        stack<int>st;
        ListNode*curr = head;
        while(curr!=NULL){
            st.push(curr->val);
            curr= curr->next;
        }
        int N = st.size();
        curr = head; 
        int count = 1; // becuse i have seen
        int result = 0;
        while(count <= N/2){
            result = max(result, curr->val + st.top());
            curr = curr->next;
            st.pop();
            count++;
        }
        return result;
    }
};