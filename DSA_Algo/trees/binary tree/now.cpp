#include<bits/stdc++.h>
using namespace std;
int main(){
	string a="apcdapapospaap";
	string b="";
	b.append(a,0,2);
	int al=a.length(), bl=b.length(),c=0;
	//a.replace(b,"$")
	for(int i=0;i<al-bl+1;i++){
		if(a.substr(i,bl) == b){
			a.replace(i,2,"$$");
		}
		//a[2]="$";
		//cout<<a[i];
	}
	for(int i=0;i<al;i++){
		if(a[i]=='$'){
			a[i+1]=' ';
		}	
	}
	//cout<<a;
	for(int i=0;i<al;i++){
		if(a[i]==' '){
			a.replace(i,1,"");
		}
		
	}
	
	for(int i=0;i<al;i++){
		if(a[i]=='$' && a[i+1]=='$'){
			a.replace(i,1,"");
		}
	}
	for(int i=0;i<al;i++){
		if(a[i]=='$'){
			c++;
		}
	}
	cout<<c;
	return 0;
}
