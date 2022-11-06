class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wh=0,mini=INT_MAX;
        for(int i=0; i<k; i++)
        {
            if(blocks[i] == 'W')
                wh++;
        }
        mini=wh;
        for(int i=1,j=k; j<blocks.size(); i++,j++)
        {
            if(blocks[i-1]=='W' && blocks[j]=='B')
                wh--;
            if(blocks[i-1]=='B' && blocks[j] == 'W')
                wh++;
            mini=min(mini,wh);
        }
        return mini;
    }
};