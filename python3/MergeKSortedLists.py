# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heapList = []
        
        for index, listItem in enumerate(lists):
            if listItem:
                heapq.heappush(heapList, (listItem.val, index, listItem))
                
        dummyHead = ListNode()
        prev = dummyHead
        
        while (len(heapList)):
            item = heapq.heappop(heapList)
            if item[2].next:
                heapq.heappush(heapList, (item[2].next.val, item[1], item[2].next))
            prev.next = item[2]
            prev = prev.next
            prev.next = None
        
        return dummyHead.next
