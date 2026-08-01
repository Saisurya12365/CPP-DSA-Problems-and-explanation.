
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode* curr = head;
        stack<int> st;
        while(curr){
            if(cnt >= left && cnt <= right){
                st.push(curr -> val);
            }
            curr = curr -> next;
            cnt++;
        }
        cnt = 1;
        curr = head;
        while(curr){
            if(cnt >= left && cnt <= right){
                curr -> val = st.top(); 
                st.pop();
            }
            curr = curr -> next;
            cnt++;
        }

        return head;
    }
};