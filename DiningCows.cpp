/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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
