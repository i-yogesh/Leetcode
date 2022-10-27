class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0; i<image.size(); i++)
        {
                for(int k=0, l= image[i].size()-1; k<l; k++, l--){
                    swap(image[i][k], image[i][l]);
                }
        }
        
        for(int i=0; i<image.size(); i++)
        {
            for(int j=0; j<image[i].size(); j++)
            {
                if(image[i][j] == 0)
                    image[i][j] = 1;
                else
                    image[i][j] = 0;
            }
        }
        return image;
    }
};