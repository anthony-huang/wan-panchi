#include <bits/stdc++.h>

using namespace std;

int t,i,j,n;
string a[307];
string s;

string kiri(string s, int len) {
	int i;
	string tmp = "";
	for (i=len-1 ; i-1>=0 ; i-=2) {
		tmp += a[s[i]-'a'][s[i-1]-'a'];
	}
	if (i >= 0) tmp += s[i];
	reverse(tmp.begin(),tmp.end());
	return tmp;
}

string kanan(string s, int len) {
	int i;
	string tmp = "";
	for (i=0 ; i+1<len ; i+=2) {
		tmp += a[s[i]-'a'][s[i+1]-'a'];
	}
	if (i < len) tmp += s[i];
	return tmp;
}

int coba(int x, string s, int len) {
	if (len == 1) {
		if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') return 1;
		return -1;
	}
	
	int ans;
	string ki = kiri(s,len);
	string ka = kanan(s,len);
	
	if (x % 2 == 0) {
		ans = max(coba(x+1,ki,(len+1)/2),coba(x+1,ka,(len+1)/2));
	} else {
		ans = min(coba(x+1,ki,(len+1)/2),coba(x+1,ka,(len+1)/2));
	}
	
	return ans;
}

int main() {
	scanf("%d",&t);
	while (t--) {
		for (i=0 ; i<26 ; i++) {
			cin >> a[i];
		}
		cin >> s;
		n = s.length();
		//cout << kiri(s,n) << " " << kanan(s,n) << endl;
		if (coba(0,s,n) == 1) printf("Salah\n"); else printf("Marzo\n");
	}
}