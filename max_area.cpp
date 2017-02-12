#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class point{
public:
double x,y;
};
int n;
double r,mx=0,sumx,sumy;
double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point v,nch,rez,zn1,zn2;
vector<point>ch;
int main(){
    cin>>n;
    nch.x=0; nch.y=0;
    for(int i=0;i<n;i++){
        cin>>v.x>>v.y;
        ch.push_back(v);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int q=j+1;q<n;q++){
                //r=dist(ch[i],ch[j])+dist(ch[i],ch[q])+dist(ch[j],ch[q]);
                zn1.x=ch[i].x-ch[j].x;
                zn1.y=ch[i].y-ch[j].y;
                zn2.x=ch[q].x-ch[j].x;
                zn2.y=ch[q].y-ch[j].y;
                mx=max(mx,0.5*abs(zn1.x*zn2.y-zn1.y*zn2.x));
            }
        }
    }
    printf("%.14lf",mx);
return 0;
}