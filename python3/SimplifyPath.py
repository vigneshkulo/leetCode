class Solution:
    def simplifyPath(self, path: str) -> str:
        items = path.split("/")
        
        stack = []
        for item in items:
            if item == "" or item == ".":
                continue
            elif item == "..":
                if len(stack):
                    stack.pop()
            else:
                stack.append(item)
        
        output = ""
        for item in stack:
            output += "/"
            output += item
        
        return output if output != "" else "/"
