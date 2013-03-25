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
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * rez,*p,*q;
        int aux,t=0;
       
       rez = new ListNode (0);
       p = rez;
        while(l1!=NULL && l2!=NULL){
            aux = l1->val + l2->val  + t;
            if(aux >= 10 ) {
                t = 1;
                aux = aux - 10;
            }
            else{
                t = 0;
            }
            q = new ListNode(aux);           
            p->next = q;
            p = q;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
             aux = l1->val + t;
           if(aux >= 10 ) {
                t = 1;
                aux = aux - 10;
            }
            else{
                t = 0;
            }
            q = new ListNode(aux);  
            p->next = q;
            p = q;
            l1 = l1->next;
        }
        
        while(l2!=NULL){
            aux = l2->val + t;
             if(aux >= 10 ) {
                t = 1;
                aux = aux - 10;
            }
            else{
                t = 0;
            }
            q = new ListNode(aux);  
            p -> next = q;
            p = q;
            l2 = l2->next;
        }
        if ( t !=0 ){ 
            q = new ListNode(t);
            p->next = q;
        }
        return rez->next;
    }
};