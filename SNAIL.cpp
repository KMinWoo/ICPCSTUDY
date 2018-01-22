#include <stdio.h>
#include <string.h>

double rain[1001];
double sunny[1001];

void sol(int distance, int day){

	double ret = 0.0;
	double percent[1001];
	int i, j;

	if(distance <= day){
		ret = 1.0;
		printf("%.10lf\n",ret);
		return ;
	}
	if(distance > (2 * day) ){
		printf("%.10lf\n",ret);
		return ;
	}

	percent[0] = day;
	
	for(i = 1, j = day - 1; i < day; i++){
		percent[i] = (percent[i - 1] * (j--)) / (i + 1); // day C i 를 구하는 작업 확률을 계산하여 저장
	}

	for(i = distance - day; i <= day; i++){
		ret += rain[i] * sunny[day - i] * percent[i - 1];
	}
	printf("%.10lf\n",ret);
}


int main()
{
	int c, n, m;
	int i;
	scanf("%d",&c);

	rain[0] = 1.0;
	sunny[0] = 1.0;
	rain[1] = 0.75;
	sunny[1] = 0.25;
	for(i = 2; i < 1001; i++){
		rain[i] = rain[i - 1] * 0.75;
		sunny[i] = sunny[i - 1] * 0.25;
	}
	while(c--){
		scanf("%d %d",&n , &m);
		sol(n ,m);
	}

	return 0;
}