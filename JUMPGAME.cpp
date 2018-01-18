#include <stdio.h>
#include <string.h>

int map[100][100];
int dp[100][100];
int n;

int search(int posX, int posY){
	
	int ret = 0;
	int x = posX, y = posY;
	
	if(posX == (n - 1) && posY == (n - 1)){
		return 1;//위치를 찾은 경우
	}

	if(dp[y][x] == -1){
		if(posX + map[y][x] < n){
			ret += search(posX + map[y][x], posY);//다음 위치로
			dp[y][x] = map[y][x];//현재의 위치를 탐색했다는 표시
		}
		if(posY + map[y][x] < n){
			ret += search( posX, posY  + map[y][x]);//다음 위치로
			dp[y][x] = map[y][x];
		}
	}
	

	return ret;

}

int main(){

	int i, j;
	int c;

	scanf("%d",&c);

	while(c--){
		scanf("%d",&n);
		for(i = 0; i < n; i++){
			memset(map[i], 0, sizeof(int) * n);
			memset(dp[i], -1, sizeof(int) * n);
			for(j = 0; j < n; j++){
				scanf("%d",&map[i][j]);
			}
		}

		if(search(0, 0) != 0)
			printf("YES\n");
		else
			printf("NO\n");
	
	}


	return 0;
}
