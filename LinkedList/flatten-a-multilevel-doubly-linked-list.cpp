/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node * ans=NULL,* run=NULL;
        auto help=[&](Node* curr,auto&& help){
            if(!curr) return ;
            auto dup=new Node();
            dup->prev=run;
            dup->val=curr->val;
            dup->next=dup->child=NULL;
            if(ans==NULL) ans=run=dup;
            else {
                run->next=dup;
                run=run->next;
            }
            if(curr->child) help(curr->child,help);
            if(curr->next) help(curr->next,help);
        };
        help(head,help);
        return ans;
    }
};