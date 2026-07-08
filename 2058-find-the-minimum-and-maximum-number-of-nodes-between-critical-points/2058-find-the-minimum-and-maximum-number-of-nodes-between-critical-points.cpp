/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr; //idx of critical nodes
        int idx=2;
        ListNode*temp=head->next;
        ListNode*prev=head;
        if(head==NULL) return {-1,-1};
        if(head->next==NULL) return {-1,-1};
        if(head->next->next==NULL) return {-1,-1};
        while(temp->next!=NULL){
            int b=temp->val;
            int a=prev->val;
            int c=temp->next->val;
            if((b>a && b>c) || (b<a && b<c)){
                arr.push_back(idx);
            }
            temp=temp->next;
            prev=prev->next;
            idx++;
        }
        int n=arr.size();
        if(n < 2) return {-1,-1};
        int mini=INT_MAX;
        int maxi=INT_MIN;
        sort(arr.begin(), arr.end());
        for(int i=0; i<=n-2; i++){
            mini=min(mini,arr[i+1]-arr[i]);
        }
        maxi=arr[n-1]-arr[0];
        return {mini,maxi};
    }
};