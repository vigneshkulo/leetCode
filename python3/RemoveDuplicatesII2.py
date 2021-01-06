# Time: O(n), Space: O(1)

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:

        dummyHead = ListNode()
        dummyHead.next = head
        
        prev = dummyHead
        curNode = head
        
        while (curNode and curNode.next):
            if curNode.val == curNode.next.val:
                while (curNode.next and curNode.val == curNode.next.val):
                    curNode = curNode.next
                prev.next = curNode.next
            else:
                prev = curNode
            curNode = curNode.next
        
        return dummyHead.next
