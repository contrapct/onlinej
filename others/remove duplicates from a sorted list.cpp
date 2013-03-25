/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
 ListNode *deleteDuplicates(ListNode *head) {
       ListNode *p = head;
       if(p==NULL) return head;
       while(p!=NULL){
           if(p->next==NULL) break;
           ListNode *q=p;
           while(q->next!=NULL && q->val == q->next->val){
               q=q->next;
           }
    	   if(p!=q)
			   p->next = q->next;
           p = p ->next;
       }
       return head;
    }
};