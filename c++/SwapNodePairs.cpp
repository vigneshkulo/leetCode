class Solution {
	public:
		ListNode* reverse(ListNode* curNode) {
			if (curNode == NULL) {
				return curNode;
			}

			ListNode* first = curNode;
			ListNode* second = first->next;

			if (second) {
				first->next = reverse(second->next);
				second->next = first;
				return second;
			} else {
				return first;
			}
		}

		ListNode* swapPairs(ListNode* head) {
			if (head == NULL || head->next == NULL) {
				return head;
			}

			return reverse(head);
		}
};
