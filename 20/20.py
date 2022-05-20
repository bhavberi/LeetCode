class Solution:
    def isValid(self, s: str) -> bool:
        l=list()
        for i in s:
            if i == ')':
                if len(l)==0:
                    return False
                a = l.pop()
                if a!='(':
                    return False
            elif i == ']':
                if len(l)==0:
                    return False
                a = l.pop()
                if a!='[':
                    return False
            elif i == '}':
                if len(l)==0:
                    return False
                a = l.pop()
                if a!='{':
                    return False
            else:
                l.append(i)
        if len(l) == 0:
            return True
        return False
