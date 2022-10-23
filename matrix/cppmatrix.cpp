#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;
using std::cin;

main()
{
	int rowlen;	//행 길이(세로)
	int collen;	//열 길이(가로)
	int num;
	
	cout << "Enter matrix (row col) size : ";
	cin >> rowlen;
	cin >> collen;

	vector<vector<int>> matrix1;
	matrix1.reserve(rowlen);	//입력받은 행 크기만큼 메모리 할당
	
	vector <int> m1;
	m1.reserve(collen);		//입력받은 열 크기만큼 메모리 할당
	
	matrix1.push_back(m1);		//matrix1 벡터안에 m1벡터를 넣어 행렬 생성
	
	
	vector<vector<int>> matrix2;
	matrix2.reserve(rowlen);	//입력받은 행 크기만큼 메모리 할당
	
	vector <int> m2;
	m1.reserve(collen);		//입력받은 열 크기만큼 메모리 할당
	
	matrix2.push_back(m2);		//matrix2 벡터안에 m2벡터를 넣어 행렬 생성
	
	
	vector<vector<int>> resultmatrix;
	resultmatrix.reserve(rowlen);	//입력받은 행 크기만큼 메모리 할당
	
	vector <int> m3;
	m3.reserve(collen);		//입력받은 열 크기만큼 메모리 할당
	
	resultmatrix.push_back(m3);		//matrix1 벡터안에 m1벡터를 넣어 행렬 생성
	
	
	
	if(matrix1.empty() || matrix2.empty() || resultmatrix.empty()) { //메모리 할당 안되었다면 실패 메세지 출력과 실행 종료
		cout << "memory setting failed\n";
		exit(1);
	}
	
	
	for(int i = 0; i < rowlen; i++)
	{
		for(int j = 0; j < collen; j++)
		{
			num = 0;
			cout << "Enter first matrix[" << i << "][" << j << "] value = ";
			cin >> num;				//첫번째 행렬에 값 입력 받기	
			matrix1[i].push_back(num);		//matrix1[i]에 담겨있는 m1벡터에 num입력
		}
	}
	
	for(int i = 0; i < rowlen; i++)
	{
		for(int j = 0; j < collen; j++)
		{
			num = 0;
			cout << "Enter second matrix[" << i << "][" << j << "] value = ";
			cin >> num;				//두번째 행렬에 값 입력 받기	
			matrix2[i].push_back(num);		//matrix2[i]에 담겨있는 m2벡터에 num입력
		}
	}
	
	for(int i = 0; i < rowlen; i++)
	{
		for(int j = 0; j < collen; j++)
		{
			resultmatrix[i].push_back(matrix1[i][j] + matrix2[i][j]); //두행렬 덧셈 결과값 결과행렬에 저장
		}
	}
	
	for(int i = 0; i < rowlen; i++)
	{
		for(int j = 0; j < collen; j++)
		{
			cout << "resultmatrix[" << i << "][" << j << "] = " << resultmatrix[i][j] << " ";
		}
		cout << endl;
	}
}

