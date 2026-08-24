/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int len(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        int l1=len(headA);
        int l2=len(headB);
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;
        int d=abs(l1-l2);
        if(l1 > l2){
            //move temp1
            int cnt=d;
            while(cnt > 0){
                temp1=temp1->next;
                cnt--;
            }
        }
        else if(l2 > l1){
            //move temp2
            int cnt=d;
            while(cnt > 0){
                temp2=temp2->next;
                cnt--;
            }
        }
        while(temp1 && temp2){
            if(temp1 == temp2) return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};