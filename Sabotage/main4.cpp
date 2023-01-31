#include<cstdio>
#include<algorithm>
using namespace std;
int sum[100001]; 
int n;
bool check(double x)
{
    double minv = sum[1]-x*1; 
    for(int i=2;i<n;i++)
    {
        if (sum[n]-x*n-(sum[i]-x*i)+minv<=0) 
            return 1;
        minv=min(minv,sum[i]-x*i);   
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        int a;
        scanf("%d",&a);
        sum[i] = sum[i-1]+a;
    }
    double l = 0, r = 10000;
    while(r-l>1e-5)   
    {
        double mid = (l+r)/2;
        if (check(mid)) 
            r = mid;    
        else 
            l = mid;
    }
    printf("%.3lf",r);
    return 0;
}