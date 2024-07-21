
class Solution{
public:
    Node* divide(int N, Node *head){
        Node * even=NULL,* odd=NULL,* rune=NULL,* runo=NULL;
        while(head){
            auto curr=new Node(head->data);
            if((head->data)%2==0) {
                if(even==NULL) even=rune=curr;
                else{
                    rune->next=curr;
                    rune=rune->next;
                }
            }
            else{
                if(odd==NULL) odd=runo=curr;
                else{
                    runo->next=curr;
                    runo=runo->next;
                }
            }
            head=head->next;
        }
        if(!even) return odd;
        rune->next=odd;
        return even;
    }
};