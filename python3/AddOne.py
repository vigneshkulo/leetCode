# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        
        prevNode = None
        curNode = head
        while(curNode.next != None):
            nextNode = curNode.next
            curNode.next = prevNode
            prevNode = curNode
            curNode = nextNode
        
        curNode.next = prevNode
        newHead = curNode
        
        curNode = newHead
        carry = 1
        while (curNode.next != None) and carry:
            carry = (curNode.val + 1) // 10
            curNode.val = (curNode.val + 1) % 10
            curNode = curNode.next
        
        if carry:
            carry = (curNode.val + 1) // 10
            curNode.val = (curNode.val + 1) % 10
        if carry:
            carryNode = ListNode(1)
            curNode.next = carryNode
            
        prevNode = None
        curNode = newHead
        while(curNode.next != None):
            nextNode = curNode.next
            curNode.next = prevNode
            prevNode = curNode
            curNode = nextNode
        
        curNode.next = prevNode
        
        return curNode
        
