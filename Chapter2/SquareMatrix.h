#pragma once

using namespace std;
const int MAX_ROWS = 50;

class SquareMatrix
{
private:
	int matrix[50][50];
public:
	void MakeEmpty(int);
	void StoreValue(int, int, int);
	SquareMatrix Add(SquareMatrix& , SquareMatrix& );
	SquareMatrix Substract(SquareMatrix& , SquareMatrix& );
	SquareMatrix Copy(SquareMatrix& );
};


/* ADT 명세서 + 시험계획
SquareMatrix ADT Specification
구조: N행과 N열을 가진 2차원 배열로 표현되는 정사각형 행렬이다. 최대 크기는 행 열, 각각 50개이다.

MakeEmpty
기능:Matrix의 n행 열 내부를 0으로 초기화
조건:N의 최대 크기는 50
결과:n 안의 행 열은 0으로 초기화
시험계획: SquareMatrix 객체 m을 만들고 m.MakeEmpty(3); 을 실행 후에, 출력해본다.

StoreValue
기능:value를 i번째행, j번째 열의 위치에 저장
조건:value는 int형 데이터
결과:원하는 위치(i,j)에 값 저장.
시험계획: Storevalue(1,1,2); 를 실행 한 후, (1,1) 위치에 2가 저장되었는 지 출력하여 확인한다.

Add
기능: 두 행렬을 함께 더한다.
조건: 행렬 계산
결과: 대응되는 위치의 원소끼리 더해져 새로운 행렬이 출력된다.
시험계획: C=A.Add(B);를 실행 후 C를 출력해본다.

Substract
기능: 한 행렬을 다른 행렬로부터 뺀다.
조건: 행렬 계산
결과: 대응되는 위치의 원소끼리 빼져 새로운 행렬이 출력된다.
시험계획: C=A.Substract(B);를 실행 후 C를 출력해본다.

Copy
기능: 한 행렬을 다른 행렬로 복사한다.
조건: 
결과: 대응되는 위치에 원소가 복사된다.
시험계획: B=B.Copy(A);를 실행 후 B를 출력해서 A가 복사되었는지 확인한다. 

*/