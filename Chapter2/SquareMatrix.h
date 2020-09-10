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


/* ADT ���� + �����ȹ
SquareMatrix ADT Specification
����: N��� N���� ���� 2���� �迭�� ǥ���Ǵ� ���簢�� ����̴�. �ִ� ũ��� �� ��, ���� 50���̴�.

MakeEmpty
���:Matrix�� n�� �� ���θ� 0���� �ʱ�ȭ
����:N�� �ִ� ũ��� 50
���:n ���� �� ���� 0���� �ʱ�ȭ
�����ȹ: SquareMatrix ��ü m�� ����� m.MakeEmpty(3); �� ���� �Ŀ�, ����غ���.

StoreValue
���:value�� i��°��, j��° ���� ��ġ�� ����
����:value�� int�� ������
���:���ϴ� ��ġ(i,j)�� �� ����.
�����ȹ: Storevalue(1,1,2); �� ���� �� ��, (1,1) ��ġ�� 2�� ����Ǿ��� �� ����Ͽ� Ȯ���Ѵ�.

Add
���: �� ����� �Բ� ���Ѵ�.
����: ��� ���
���: �����Ǵ� ��ġ�� ���ҳ��� ������ ���ο� ����� ��µȴ�.
�����ȹ: C=A.Add(B);�� ���� �� C�� ����غ���.

Substract
���: �� ����� �ٸ� ��ķκ��� ����.
����: ��� ���
���: �����Ǵ� ��ġ�� ���ҳ��� ���� ���ο� ����� ��µȴ�.
�����ȹ: C=A.Substract(B);�� ���� �� C�� ����غ���.

Copy
���: �� ����� �ٸ� ��ķ� �����Ѵ�.
����: 
���: �����Ǵ� ��ġ�� ���Ұ� ����ȴ�.
�����ȹ: B=B.Copy(A);�� ���� �� B�� ����ؼ� A�� ����Ǿ����� Ȯ���Ѵ�. 

*/