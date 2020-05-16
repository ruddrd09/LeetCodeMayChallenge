/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { //Solution 1
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return NULL;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* temp3 = head->next;
        while(temp1 && temp1->next) {
            temp1->next = temp1->next->next;
            if(temp1 && temp1->next) {
                temp1 = temp1->next;   
            }
            if(temp2 && temp2->next) {
                temp2->next = temp2->next->next;
                temp2 = temp2->next;   
            }
        }
        temp1->next = temp3;   
        return head;
    }
};

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* odd = NULL, *oddHead;
        ListNode* even = NULL, *evenHead;
        ListNode* temp = head;
        int i = 1;
        while(temp) {
            if(i%2 == 0) {
                if(!even) {
                    even = temp;
                    evenHead = even;
                } else {
                    even->next = temp;
                    even = even->next;
                }
            } else {
                if(!odd) {
                    odd = temp;
                    oddHead = odd;
                } else {
                    odd->next = temp;
                    odd = odd->next;
                }
            }
            temp = temp->next;
            i++;
        }
        even->next = NULL;
        odd->next = evenHead;
        return oddHead;
    }
};