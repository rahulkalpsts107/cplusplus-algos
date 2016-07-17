//Flatland is a country with n cities, m of which have space stations. Its cities (c) are numbered from 0 to n−1, where ith city is referred to as ci.
//Between each ci and ci+1 (where 0≤i<n), there exists a bidirectional road 1 km long.
//For example, if n=5 and cities c0 and c4 have space stations, Flatland would look like this:

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int retShortest(vector<int> & stations ,int start ,int end ,int k)
{
    if(end-start <=0)
    {
            //cout<<"end "<<end<<" st "<<start<<" "<<stations[start]<<endl;
            if(end <0)
                end=0;
            if(start<0)
                start=0;
            if(stations.size() >1)
                if(k>stations[start])
                    if(start+1 <stations.size()-1 )
                        return min(abs(k-stations[start]),abs(k-stations[start+1]));
                    else
                        return abs(k-stations[start]);
                else
                    if(start-1 >=0)
                        return min(abs(k-stations[start]),abs(k-stations[start-1]));
                    else
                        return abs(k-stations[start]);
            else
                return abs(k-stations[start]);

    }
    else
    {
        int mid = (start+end)/2;
        if(k<stations[mid])
            return retShortest(stations,start,mid,k);
        else
            return retShortest(stations,mid+1,end,k);
    }
}

int computeShortestDist(int dist [], int n , vector<int> &stations,int m )
{
    int max = 0;
    for (int i=0 ;i< n ;i++)
    {
        if(dist[i] == -1)
        {
            int curr = retShortest(stations ,0 , m-1 , i);
            dist[i] =curr;
            //cout<<curr<<" for "<<i<<endl;
            if(curr>max)
                max = curr;
        }
    }
    return max;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m); 
    int dist[n];
    for(int i=0 ;i<n ;i++)
        dist[i] =-1;
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
       dist[c[c_i]] = 0;
    }
    sort(c.begin(),c.end());
    int max = computeShortestDist(dist ,n ,c, m);
    cout<<max<<endl;
    return 0;
}
