#include<cstdio>
#include<cmath>

int CLK_TCK = 100;

int main(){
	int C1, C2;
	scanf("%d%d", &C1, &C2);
	int time = round(double(C2-C1) / CLK_TCK);
	int hh, mm, ss;
	ss = time % 60;
	time /= 60;
	mm = time % 60;
	time /= 60;
	hh = time;
	char output[9];
	sprintf(output, "%02d:%02d:%02d", hh, mm, ss);
	printf("%s\n", output);
	
	return 0;
}
