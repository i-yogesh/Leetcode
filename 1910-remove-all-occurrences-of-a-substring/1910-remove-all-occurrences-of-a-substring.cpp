class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(1)
        {
            size_t found = s.find(part);
            if (found != string::npos)
            {
                s.erase(found, part.length());
            }
            else
                break;
        }
        return s;
    }
};