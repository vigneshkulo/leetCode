# Time: O(n), Space: O(n)

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if (head == None):
            return None
        
        dup = set()
        
        curNode = head
        while (curNode.next):
            if curNode.val == curNode.next.val:
                dup.add(curNode.val)
            
            curNode = curNode.next        

        if len(dup) == 0:
            return head

        dummyHead = ListNode()
        dummyHead.next = head
        
        prev = dummyHead
        curNode = head
        
        while (curNode):
            if curNode.val in dup:
                prev.next = curNode.next
            else:
                prev = curNode
            
            curNode = curNode.next
        
        return dummyHead.next
