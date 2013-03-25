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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode * ret=NULL,*ul=NULL,*p=NULL;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                p = l1;
                l1=l1->next;
            }
            else {p=l2;l2=l2->next;}
            if(ret == NULL) {
                ret = new ListNode(p->val);
                delete p;
                ul = ret;
            }
            else{
                ListNode *q = new ListNode(p->val);
                ul->next = q;
                ul = q;
                delete p;
            }            
        }
        while(l1!=NULL){
            p=l1;
            l1=l1->next;
             if(ret == NULL) {
                ret = new ListNode(p->val);
                delete p;
                ul = ret;
            }
            else{
                ListNode *q = new ListNode(p->val);
                ul->next = q;
                ul = q;
                delete p;
            }   
        }
           while(l2!=NULL){
            p=l2;
            l2=l2->next;
             if(ret == NULL) {
                ret = new ListNode(p->val);
                delete p;
                ul = ret;
            }
            else{
                ListNode *q = new ListNode(p->val);
                ul->next = q;
                ul = q;
                delete p;
            }   
        }
        return ret;
    }
};