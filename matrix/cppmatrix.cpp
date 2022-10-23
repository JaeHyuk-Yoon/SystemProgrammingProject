#include <stdio.h>
#include <stdlib.h>

main()
{
	int rowlen;	//행 길이(세로)
	int collen;	//열 길이(가로)
	
	printf("Enter matrix (row col) size : ");	
	scanf("%d %d", &rowlen, &collen);	//행 열 사이즈 입력받기
	
	//첫번째 행열
	int** matrix1 = malloc(sizeof(int*) * rowlen);	//(int의 size)*행 크기만큼 메모리 동적 할당
	
	for (int i = 0; i < rowlen; i++)
	{
		matrix1[i] = malloc(sizeof(int) * collen);	//각 행마다 (int의 size)*열 크기만큼  메모리 동적 할당
	}
	
	//두번째 행열
	int** matrix2 = malloc(sizeof(int*) * rowlen);	//(int의 size)*행 크기만큼 메모리 동적 할당
	
	for (int i = 0; i < rowlen; i++)
	{
		matrix2[i] = malloc(sizeof(int) * collen);	//각 행마다 (int의 size)*열 크기만큼  메모리 동적 할당
	}
	
	
	//두 행열의 덧셈결과값 저장할 행열
	int** resultmatrix = malloc(sizeof(int*) * rowlen);	//(int의 size)*행 크기만큼 메모리 동적 할당
	
	for (int i = 0; i < rowlen; i++)
	{
		resultmatrix[i] = malloc(sizeof(int) * collen);   //각 행마다 (int의 size)*열 크기만큼  메모리 동적 할당
	}
	
	
	if(matrix1 == NULL || matrix2 == NULL || resultmatrix == NULL) { //메모리 할당 안되었다면 실패 메세지 출력과 실행 종료
		printf("memory setting failed\n");
		exit(1);
	}
	
	for(int i = 0; i < rowlen; i++)
	{
		for(int j = 0; j < collen; j++)
		{
			printf("Enter first matrix[%d][%d] value = ", i, j);	
			scanf("%d", &matrix1[i][j]);			//첫번째 행렬에 값 입력 받기
		}
	}
	
	for(int i = 0; i < rowlen; i++)
	{
		for(int j = 0; j < collen; j++)
		{
			printf("Enter second matrix[%d][%d] value = ", i, j);
			scanf("%d", &matrix2[i][j]);			//두번째 행렬에 값 입력 받기
		}
	}
	
	for(int i = 0; i < rowlen; i++)
	{
		for(int j = 0; j < collen; j++)
		{
			resultmatrix[i][j] = matrix1[i][j] + matrix2[i][j]; //두행렬 덧셈 결과값 결과행렬에 저장
		}
	}
	
	for(int i = 0; i < rowlen; i++)
	{
		for(int j = 0; j < collen; j++)
		{
			printf("resultmatrix[%d][%d] = %d ", i, j, resultmatrix[i][j]);
		}
		printf("\n");
	}
	
	for(int i = 0; i < rowlen; i++)
	{
		free(matrix1[i]);		//열(가로공간) 메모리 반환
		free(matrix2[i]);
		free(resultmatrix[i]);
	}
	
	free(matrix1);			//행(세로공간) 메모리 반환
	free(matrix2);
	free(resultmatrix);

}

