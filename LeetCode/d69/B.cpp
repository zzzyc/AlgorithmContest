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
    int pairSum(ListNode* head) {
        vector<ListNode*> vec;
        while(head != nullptr) vec.push_back(head), head = head->next;
        int res = vec[0]->val + vec.back()->val;
        int n = vec.size();
        for(int i = 0; i <= n / 2 - 1; ++i) {
            res = max(res, vec[i]->val + vec[n - 1 - i]->val);
        }
        return res;
    }
};


// space complexity: O(1) 
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        while(true) {
        	fast = fast->next;
			if(fast == nullptr) break;
			fast = fast->next;
			if(fast == nullptr) break; 
			slow = slow->next;
		}
		
		ListNode* first = head;
		ListNode* second = reverseList(slow, slow->next, fast);
        
        int res = first->val + second->val;
        while(second != nullptr) {
        	res = max(res, first->val + second->val);
        	first = first->next;
        	second = second->next;
		}
        
        return res;
    }
private:
	ListNode* reverseList(ListNode* prev, ListNode* head, ListNode* tail) {
		ListNode* cur = head, *pre = tail;
		while(cur != tail) {
			ListNode* nxt = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nxt;
		} return pre;
	}
};
