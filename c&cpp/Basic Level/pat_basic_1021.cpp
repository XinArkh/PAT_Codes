#include<iostream>
#include<string>
using namespace std;

int main(){
	string N;
	cin>>N;
	int sum[10] = {0};
	for(int i=0; i<N.length(); i++){
		sum[N[i]-'0']++;
	}
	for(int i=0; i<10; i++){
		if(sum[i]>0){
			cout<<i<<":"<<sum[i]<<endl;
		}
	}
	return 0;
}
