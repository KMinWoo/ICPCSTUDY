#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

int search(int width, int height, bool map[22][22], int emptySpace){

	int i, j;
	int posX, posY;
	int ret = 0;
	bool case1 = false, case2 = false, case3 = false, case4 = false;
	//case1「  
	//case2 ㄴ 
	//case3 ㄱ
	//case4 」

	for(i = 1; i <= height; i++){
		for(j = 1; j <= width; j++){
			if(map[i][j] == true){//왼쪽 상단부터 빈공간을 검색
				posX = j;
				posY = i;
				i = height + 1;
				j = width + 1;
			}
		}
	}

	if(map[posY][posX + 1] == true && map[posY + 1][posX] == true) case1 = true;
	if(map[posY+1][posX] == true && map[posY + 1][posX + 1] == true) case2 = true;
	if(map[posY][posX + 1] == true && map[posY + 1][posX + 1] == true) case3 = true;
	if(map[posY + 1][posX] == true && map[posY + 1][posX - 1] == true) case4 = true;
	// 해당위치에서 4가지의 경우 중 가능한 경우는 true로 값을 변경

	if(emptySpace == 3){// 만약 남은 칸이 3칸인 경우
		if(case1 || case2 || case3 || case4)// 4가지 경우 중 한가지만 가능해도 해당 경우는 블록을 채우는 경우의 수중 하나이므로 1을 반환
			return 1;
		else
			return 0;
	}


	if(case1){
		map[posY][posX] = false;
		map[posY + 1][posX] = false;
		map[posY][posX + 1] = false;
		ret += search(width, height, map, emptySpace - 3);
		map[posY][posX] = true;
		map[posY + 1][posX] = true;
		map[posY][posX + 1] = true;
	}
	if(case2){
		map[posY][posX] = false;
		map[posY + 1][posX] = false;
		map[posY + 1][posX + 1] = false;
		ret += search(width, height, map, emptySpace - 3);
		map[posY][posX] = true;
		map[posY + 1][posX] = true;
		map[posY + 1][posX + 1] = true;
	}
	if(case3){
		map[posY][posX] = false;
		map[posY][posX + 1] = false; 
		map[posY + 1][posX + 1] = false;
		ret += search(width, height, map, emptySpace - 3);
		map[posY][posX] = true;
		map[posY][posX + 1] = true;
		map[posY + 1][posX + 1] = true;		
	}
	if(case4){
		map[posY][posX] = false;
		map[posY + 1][posX] = false;
		map[posY + 1][posX - 1] = false;
		/*for(i = 0; i <= height; i++){
			for(j = 0; j <= width; j++){
				printf("%d",map[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		ret += search(width, height, map, emptySpace - 3);
		map[posY][posX] = true;
		map[posY + 1][posX] = true;
		map[posY + 1][posX - 1] = true;
	}

	return ret;
}


int main(){

	int count;
	bool map[22][22];
	char str[21];
	int width, height;
	int i, j;
	int emptySpace = 0;

	scanf("%d",&count);

	while(count--){
		scanf("%d %d",&height, &width);

		memset(map, 0, sizeof(map));//map을 초기화하는 함수
		for(i = 1; i <= height; i++){
			memset(str, 0, sizeof(char) * (width + 1));
			scanf("%s",str);
			for( j = 0; j < width; j++){
				if(str[j] == '.')
					map[i][j + 1] = true;
			}
		}
	
		
		for(i = 1; i <= height; i++){
			for(j = 1; j <= width; j++){
				if(map[i][j] == true)
					emptySpace++;// 빈 공간을 체크하여 3의 배수인지 확인하기 위해서 
			}
		}

		if(emptySpace < 3 || emptySpace % 3 != 0)
			printf("0\n");
		else
			printf("%d\n",search( width, height, map, emptySpace));

		emptySpace = 0;
	}
	
	return 0;
}
