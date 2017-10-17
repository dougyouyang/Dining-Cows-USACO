//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int cost[30005], rcost[30005];

int main()
{
    int n, cow[30005], min=1000000;
    int i;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> cow[i];
    }
    
    for(i=0;i<n;i++){
        if(cow[i]==2){
            cost[i+1]=cost[i]+1;
        }
        else{
            cost[i+1]=cost[i];
        }
    }
    for(i=n-1;i>=0;i--){
        if(cow[i]==1){
            rcost[i+1]=rcost[i+2]+1;
        }
        else{
            rcost[i+1]=rcost[i+2];
        }
    }
    for(i=0;i<=n;i++){
        if(cost[i]+rcost[i+1]<min)
            min=cost[i]+rcost[i+1];
    }
    
    cout << min << endl;
    
    return 0;
}
