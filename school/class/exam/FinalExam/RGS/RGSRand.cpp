#include<bits/stdc++.h>

using namespace std;

string st;
stack<int> s;
bool kt[1000009];

int main()
{
	freopen("RGS.inp","r",stdin);
	freopen("RGS.ans","w",stdout);
	cin>>st;
	if (st.length()==1) {
		cout<<1;
		return 0;
	}
	unsigned int vt1=0,vt2=1;
	while(vt2<st.length()){
		if (st[vt1]==st[vt2]){
			kt[vt1]=1;
			kt[vt2]=1;
			if (!s.empty()){
				if (kt[s.top()]==0 && !s.empty()) {
					vt1=s.top();
					vt2++;
					s.pop();
				}
				else {
					vt1=vt2+1;
					vt2+=2;
				}
			}
			else {
				vt1=vt2+1;
				vt2+=2;
			}
		}
		else {
			s.push(vt1);
			vt1=vt2;
			vt2++;
		}
		if (vt2==st.length()) break;
	}
	int d=0;
	for (unsigned int  i=0;i<st.length();i++){
		if (!kt[i]) d++;
	}
	cout<<d<<endl;
	return 0;
}