#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

int search(int width, int height, bool map[22][22], int emptySpace){

	int i, j;
	int posX, posY;
	int ret = 0;
	bool case1 = false, case2 = false, case3 = false, case4 = false;
	//case1��  
	//case2 �� 
	//case3 ��
	//case4 ��

	for(i = 1; i <= height; i++){
		for(j = 1; j <= width; j++){
			if(map[i][j] == true){//���� ��ܺ��� ������� �˻�
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
	// �ش���ġ���� 4������ ��� �� ������ ���� true�� ���� ����

	if(emptySpace == 3){// ���� ���� ĭ�� 3ĭ�� ���
		if(case1 || case2 || case3 || case4)// 4���� ��� �� �Ѱ����� �����ص� �ش� ���� ����� ä��� ����� ���� �ϳ��̹Ƿ� 1�� ��ȯ
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

		memset(map, 0, sizeof(map));//map�� �ʱ�ȭ�ϴ� �Լ�
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
					emptySpace++;// �� ������ üũ�Ͽ� 3�� ������� Ȯ���ϱ� ���ؼ� 
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
