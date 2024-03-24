class Solution:
    def judgeCircle(self, moves: str) -> bool:
        v_pos = 0
        h_pos = 0
        for m in moves:
            if m == 'U':
                v_pos += 1
            elif m == 'R':
                h_pos += 1
            elif m == 'L':
                h_pos -= 1
            else:
                v_pos -= 1

        if v_pos == 0 and h_pos==0: 
            return True
        else: 
            return False