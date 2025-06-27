#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int E, N, min_count = 0;
    cin >> E >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
    sort(A.begin(), A.end(), [](int a, int b){return a>b;}); //reverse=true
    int i=0;
    while(E > 0 && i<A.size())
    {
        if(E < A[i])
        {
            min_count++;
            E -= A[i];
            break;
        }
        else
        {
            E -= 2*A[i];
            min_count += 2;
            i++;
        }       
    }
    if(E>0) cout << -1;
    else cout << min_count;
    return 0;
}