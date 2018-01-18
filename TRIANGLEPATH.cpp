#include <stdio.h>
#include <algorithm>
#include <string.h>

int chack[100][100];

int search(int map[100][100], int n, int x, int y){

	if(x == (n - 1)){
		chack[x][y] = 1;	
		return map[x][y];
	}
	if(chack[x][y] == 1)
		return map[x][y];

	map[x][y] += search(map, n, x + 1, y) > search(map, n, x + 1, y + 1) ? map[x + 1][y] : map[x + 1][y + 1]; 
	chack[x][y] = 1;

	return map[x][y];
}



int main(){
	
	int map[100][100];
	int c;
	int n;
	int i, j;

	scanf("%d",&c);

	while(c--){
		scanf("%d",&n);

		memset(map, 0, sizeof(map));
		memset(chack, -1, sizeof(chack));

		for(i = 0; i < n; i++){
			for(j = 0; j <= i; j++){
				scanf("%d",&map[i][j]);
			}
		}
		printf("%d\n",search(map, n , 0, 0));
	}

	return 0;
}
