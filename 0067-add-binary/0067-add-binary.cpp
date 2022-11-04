class Solution {
public:
    string addBinary(string a, string b) {
        // int num, num;
        // num=stoi(a);
        // num2=stoi(b);
        int n1 = a.size();
        int n2 = b.size();
        int diff=0,big,small;
        
        if(n1> n2){
            big=1;
            small=2;
            diff=n1-n2;
        }
        else
        {
            big=2;
            small=1;
            diff=n2-n1;
        }
        
        for(int i=0; i<diff; i++)
        {
            if(small==1)
                a.insert(0,"0");
            else
                b.insert(0,"0");
        }
        cout<<a; 
        char carry = '0';
        string ans;
        n1=a.size();
        n2 = b.size();
        for(int i=n1-1, j= n2-1; i>=0 || j>=0, j>=0; i--,j--)
        {
            if(a[i] == '1' && b[j] == '1' && carry == '0')
            {
                ans.push_back('0');
                carry = '1';
                if(i==0 && j==0 && carry=='1')
                    ans.push_back('1');
            }
            else if(a[i] == '1' && b[j] == '1' && carry == '1')
            {
                ans.push_back('1');
                carry = '1';
                if(i==0 && j==0 && carry=='1')
                    ans.push_back('1');
            }
            else if((a[i] == '1' && b[j] == '0' && carry == '0') || (a[i] == '0' && b[j] == '1' && carry == '0') || (a[i] == '0' && b[j] == '0' && carry == '1'))
            {
                ans.push_back('1');
                carry = '0';
                if(i==0 && j==0 && carry=='1')
                    ans.push_back('1');
            }
            else if((a[i] == '1' && b[j] == '0' && carry == '1') || (a[i] == '0' && b[j] == '1' && carry == '1'))
            {
                ans.push_back('0');
                carry = '1';
                if(i==0 && j==0 && carry=='1')
                    ans.push_back('1');
            }
            else if(a[i] == '0' && b[j] == '0' && carry == '0'){
                ans.push_back('0');
                carry = '0';
                if(i==0 && j==0 && carry=='1')
                    ans.push_back('1');
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};