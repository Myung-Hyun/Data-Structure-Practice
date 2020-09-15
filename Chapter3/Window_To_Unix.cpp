#include <fstream>
#include <iostream>
// myIn.txt 파일에서 첫 문자 읽어서 myOut.txt에 기록


using namespace std;

int main(int argc, char* argv[])//Command line argument, argv는 포인터 변수들로 이루어진 배열, main 함수의 input format 정해져 있다.
{

	// 명령 prompt 창에서, Window_To_Unix.exe myln,txt myOut.txt 입력하면 argc가 3, 앞에서부터 argv[0]~argv[2]까지 들어간다. 
	ifstream input_file(argv[1]);
	ofstream output_file(argv[2]);

	char ch;
	while (input_file.eof()!=true)  //파일의 끝이 아닐때까지 루프를 반복함
	{
		// 공백문자 여부 상관 없이 한 문자(1byte) 만큼 읽음
		input_file.get(ch);
		if (input_file.bad()) break;  // 입력 파일 스트림에 에러비트가 존재한다면 루프를 빠져나감
		
		if (ch=='\r') // Window->Unix, \r\n을 \n으로 바꾸기 위해
			output_file << NULL ;
		else
			output_file << ch;
	}
	input_file.close();
	output_file.close();
	return 0;
}
