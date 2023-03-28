//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<int> values, weight;
        for(int i=0; i<n; i++){
            values.push_back(arr[i].value);
            weight.push_back(arr[i].weight);
        }
        vector<double> per;
        for(int i=0; i<n; i++){
            per.push_back((double)values[i]/weight[i]);
        }
        vector<pair<double, pair<int,int>>> store;
        for(int i=0; i<n; i++){
          store.push_back({per[i], {values[i], weight[i]}});
        }
        sort(store.begin(), store.end(), [&](auto a, auto b){
            return a.first > b.first;            
        });
        double sum = 0;
        for(auto i: store)
        {
            if(i.second.second <= W){
                sum+= i.second.first;
                W-= i.second.second;
            }else if(W>0){
                sum+= (i.first*W);
                break;
            }
        }
        return sum;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends