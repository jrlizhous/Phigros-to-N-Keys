#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
#include<cstdlib>
using namespace std;
string s,edtim,las[10001];
int cnt,n,w[10001],cw,num,it;
int main()
{
	cout<<"¹ìµÀÊý£º";
	scanf("%d",&n);
	cw=1200/(n+1);
	w[0]=-600+cw/2;
	for(int i=1;i<=n;i++)
	{
		w[i]=w[i-1]+cw;
//		cout<<w[i]<<' ';
	}
	freopen("in.json","r",stdin);
	freopen("Result.json","w",stdout);
	while(getline(cin,s))
	{ 
		if(s.find("         \"notes\" : [")<s.size())
		{
			cout<<s<<endl;
		//	cout<<"IN";
		cnt=0;
			cnt++;
			while(getline(cin,s))
			{
		//		cout<<s.find("positionX");
				if(s.find("positionX")<s.size())
				{
					num=0; 
					for(int i=0;i<s.size();i++)
					{
						if(s[i]=='.') break;
						if(s[i]>='0'&&s[i]<='9')
						{
							num*=10;
							num+=s[i]-'0';
				//			cout<<num<<' '; 
						}
					}
					if(s.find("-")<s.size()) num*=-1;
					int mid=lower_bound(w+1,w+n+1,num)-w;
					if(rand()%2)
					{
						mid=upper_bound(w+1,w+n+1,num)-w;
					}
					if(num>w[n])
					{
				//		cout<<"IN";
						mid=n;
					}
					it=0;
				//	cout<<mid<<' '<<num<<' '<<w[n]<<endl;
					for(int i=0;i<=600;i+=cw)
					{
						int lw=w[mid]-i-cw/2,rw=w[mid]+i-cw/2;
				//		cout<<lw<<' '<<rw<<endl;
						if(lw>=-600&&mid-it>0&&las[mid-it]!=edtim)
						{
							cout<<"               \"positionX\" : "<<lw<<",\n";
							las[mid-it]=edtim;
							break;
						}
						if(rw<=600&&mid+it<=n&&las[mid+it]!=edtim)
						{
							cout<<"               \"positionX\" : "<<rw<<",\n";
							las[mid+it]=edtim;
							break;
						}
						it++;
					}
				//	cout<<"BREAK";
				}
				else if(s.find("above")<s.size())
				{
					cout<<"               \"above\" : 1,\n";
				}
				else if(s.find("\"endTime\" : ")<s.size())
				{
					cout<<s;
					edtim=s;
				}
				else
				{
					cout<<s<<endl;
				}
				if(s.find("[")<s.size())
				{
					cnt++;	
				}
				if(s.find("]")<s.size())
				{
					cnt--;	
				}
				if(cnt==0) break;
			}
		}
		else if(s.find("eventLayers")<s.size())
		{
			cout<<s<<endl;
			cnt=0;
			cnt++;
		//	cout<<"IN";
			while(getline(cin,s))
			{
			//	cout<<s<<' ';
				if(s.find("[")<s.size())
				{
					cnt++;
				}
				if(s.find("]")<s.size())
				{
					cnt--;
				}
				if(cnt==0)
				{
					cout<<"        {\n            \"alphaEvents\" : [\n            {\n            \"easingLeft\" : 0.0,\n            \"easingRight\" : 1.0,\n            \"easingType\" : 1,\n            \"end\" : 0,\n            \"endTime\" : [ 1, 0, 1 ],\n             \"linkgroup\" : 0,\n            \"start\" : 0,\n            \"startTime\" : [ 0, 0, 1 ]\n            }\n            ],\n            \"moveXEvents\" : [\n            {\n            \"easingLeft\" : 0.0,\n            \"easingRight\" : 1.0,\n            \"easingType\" : 1,\n            \"end\" : 0.0,\n            \"endTime\" : [ 1, 0, 1 ],\n            \"linkgroup\" : 0,\n            \"start\" : 0.0,\n            \"startTime\" : [ 0, 0, 1 ]\n            }\n            ],\n            \"moveYEvents\" : [\n            {\n            \"easingLeft\" : 0.0,\n            \"easingRight\" : 1.0,\n            \"easingType\" : 1,\n            \"end\" : -250.0,\n            \"endTime\" : [ 1, 0, 1 ],\n            \"linkgroup\" : 0,\n            \"start\" : -250.0,\n            \"startTime\" : [ 0, 0, 1 ]\n            }\n            ],\n            \"rotateEvents\" : [\n            {\n            \"easingLeft\" : 0.0,\n            \"easingRight\" : 1.0,\n            \"easingType\" : 1,\n            \"end\" : 0.0,\n            \"endTime\" : [ 1, 0, 1 ],\n            \"linkgroup\" : 0,\n            \"start\" : 0.0,\n            \"startTime\" : [ 0, 0, 1 ]\n            }\n            ],\n            \"speedEvents\" : [\n            {\n            \"end\" : 10.0,\n            \"endTime\" : [ 1, 0, 1 ],\n            \"linkgroup\" : 0,\n            \"start\" : 10.0,\n            \"startTime\" : [ 0, 0, 1 ]\n            }\n            ]\n            }\n            ";
					cout<<s<<endl;
			//		cout<<"IN";
					break;
				}
			}
		}
		else
		{
			cout<<s<<endl;
		}
	}
}
