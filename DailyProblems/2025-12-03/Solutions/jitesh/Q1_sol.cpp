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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        stack<ListNode*> n;
        while(head){
            n.push(head);
            head=head -> next;
        }

        ListNode* newHead =n.top();
        n.pop();
        ListNode* current_value =newHead;
        while(!n.empty()){
            current_value -> next =n.top();
            n.pop();
            current_value =current_value -> next;
        }
        current_value ->next =NULL;
        return newHead;
    }
};
//method 2 or shortcut method --
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL ) return head;
        if (head -> next== NULL) return head;
        ListNode* newHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next =NULL;
        return newHead;

    }
};