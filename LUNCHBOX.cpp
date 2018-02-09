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
	if((d1.Eat == d2.Eat))// ���� �Դ� �ð��� ���� ���
		return (d1.Hot > d2.Hot);// ����� �ð��� ���� �ͺ���
	else
		return (d1.Eat > d2.Eat);//������������ ����
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
		sort(num, num + n, sort_func);// ������������ ���� �Դ½ð��� ��������
		/*for(i = 0; i < n; i++){
			printf("%d -> %d %d\n", (i + 1), num[i].Hot, num[i].Eat);
		}*/

		for(i = 0; i < n; i++){
			totalHot += num[i].Hot;
			totalTime = totalHot + num[i].Eat;// ���� ���ö��� ���� ����� �Դ½ð��� ����� �ð�
			if(rul < totalTime)
				rul = totalTime;// ��������� �ð� �߿��� ���� ��ð��� ����
		}
		printf("%d\n",rul);
	}

	return 0;
}