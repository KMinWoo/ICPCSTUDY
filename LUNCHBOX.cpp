#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>

using namespace std; 

typedef struct lunchBox{
	int Eat;
	int Hot;
}LunchBox;

bool sort_func(LunchBox d1, LunchBox d2){
	if((d1.Eat == d2.Eat))// 만약 먹는 시간이 같은 경우
		return (d1.Hot > d2.Hot);// 데우는 시간이 느린 것부터
	else
		return (d1.Eat > d2.Eat);//내림차순으로 정렬
}

int n;
LunchBox num[10001];

int main()
{
	
	int c;
	int i;
	int totalHot;
	int totalTime;
	int rul;

	scanf("%d",&c);
	
	while(c--){
		scanf("%d",&n);
		totalTime = 0;
		totalHot = 0;
		rul = 0;
		memset(num, 0, sizeof(num));
		for(i = 0; i < n; i++){
			scanf("%d",&num[i].Hot);
		}
		for(i = 0; i < n; i++){
			scanf("%d",&num[i].Eat);
		}
		sort(num, num + n, sort_func);// 내림차순으로 정렬 먹는시간을 기준으로
		/*for(i = 0; i < n; i++){
			printf("%d -> %d %d\n", (i + 1), num[i].Hot, num[i].Eat);
		}*/

		for(i = 0; i < n; i++){
			totalHot += num[i].Hot;
			totalTime = totalHot + num[i].Eat;// 현재 도시락을 가진 사람이 먹는시간을 고려한 시간
			if(rul < totalTime)
				rul = totalTime;// 현재까지의 시간 중에서 가장 긴시간을 저장
		}
		printf("%d\n",rul);
	}

	return 0;
}