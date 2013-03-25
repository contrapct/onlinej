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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        set<pair<int,int> > hash;
        ListNode * ret=NULL,*ul;
        //pun in hash 
        int n = lists.size();
        if (n==0) 
            return NULL;
        if(n==1)
            return lists[0];
        for(int i=0;i<n;++i){
            if(lists[i]!=NULL){
               hash.insert(make_pair(lists[i]->val,i));
                lists[i]=lists[i]->next;
            
            }
        }
        int valoare;
        int nrlista;
        while(hash.empty()==false){
            valoare = (*hash.begin()).first;
            nrlista = (*hash.begin()).second;
            hash.erase(hash.begin());
            if(ret == NULL) {
                ret = new ListNode(valoare);
                ul = ret;}
            else { 
                ListNode * p = new ListNode(valoare);
                ul->next= p;
                ul = p;                
            }
            if(lists[nrlista]!=NULL){
                hash.insert(make_pair(lists[nrlista]->val,nrlista));
                lists[nrlista]=lists[nrlista]->next;
            }
        }
       // ret = new ListNode(1);
        return ret;
    }
};