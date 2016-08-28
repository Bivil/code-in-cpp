#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,i,item;
    // N = 6 Items = 5 4 4 2 2 8 op = 6 4 2 1
    cin >> N;
    vector<int> stickL;
    for(i=0;i<N;i++){
        cin>>item;
        stickL.push_back(item);
    }
    sort(stickL.begin(),stickL.end());
    int a =stickL[0];
    cout<<stickL.size()<<endl;
    for(i=0;i<N;i++){
     	if(stickL[i]==a)
     	{
     		stickL.erase(stickL.begin());i--;N--;
     	}
     	else{
     		a=stickL[i];i--;
     		cout<<stickL.size()<<endl;
     	}

    }

    return 0;
}
