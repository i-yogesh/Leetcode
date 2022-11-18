class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a = ax2 - ax1;
        int b = ay2 -ay1;
        int s1 = a*b;

        int c = bx2 - bx1;
        int d = by2 - by1;
        int s2 = c*d;
  
        int e = min(ay2, by2);
        int h =min(ax2, bx2);
            
        int f = max(ax1, bx1);
        int g = max(ay1, by1);
        
        int d1 = e-g; 
        int d2 = h-f;
        
        int area = 0;
        if(d1 > 0 && d2 > 0)
            area=d1*d2;
        return (s1+s2)-area;
    }
};