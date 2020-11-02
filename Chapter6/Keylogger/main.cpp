#include "customDLL.h"

int main() {
	// var init
	int passwdCnt; 
	string encryptedPasswd;
	string* decryptedPasswds;

	// input # of password, string of passwords
	cin >> passwdCnt;  
	decryptedPasswds = new string[passwdCnt];

	// decoding & save 
	for(int loop = 0; loop < passwdCnt; loop++){
		customDLL keylogger;
		cin >> encryptedPasswd;
		for (char c: encryptedPasswd) 
			keylogger.InsertItem(c);
		decryptedPasswds[loop] = keylogger.Decoding();
	}
	
	// print
	for (int i = 0; i < passwdCnt; i++) 
		cout << decryptedPasswds[i] << endl;

	return 0;
}