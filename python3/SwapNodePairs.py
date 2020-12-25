class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        
        def reverse(curNode):
            if curNode == None:
                return None
            
            first = curNode
            second = curNode.next
            
            if second:
                first.next = reverse(second.next)
                second.next = first
                return second
            else:
                return first

        return reverse(head)
