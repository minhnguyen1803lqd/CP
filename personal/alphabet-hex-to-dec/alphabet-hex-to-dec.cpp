#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e3 + 10;
const int oo = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

string num[] = {"0","1","2","3","4","5","6","7","8","9"};
string capLetter[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
string regLetter[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","s","y","z"};
string Hex[N];
string inps;

void Numbers() {
	int cnt = 0;
	for (int i = 30; i <= 39; i++) {
		Hex[i] = num[cnt++];
	}
	return;
}
void CapitalLetters() {
	int cnt = 0;
	for (int i = 65; i <= 90; i++) {
		Hex[i] = capLetter[cnt++];
	}
	return;
}
void RegularLetters() {
	int cnt = 0;
	for (int i = 97; i <= 122; i++) {
		Hex[i] = regLetter[cnt++];
	}
	return;
}

int hexadecimalToDecimal(char hexVal[]);

int main() {
    FileOpen;
    Hex[20] = " ";
    Numbers();
    CapitalLetters();
    RegularLetters();
    cout << "Numbers: ";
    for (int i = 30; i <= 39; i++) cout << Hex[i] << " ";
    cout << endl;
    cout << "Capital letters: ";
	for (int i = 65; i <= 90; i++) cout << Hex[i] << " ";
	cout << endl;
	cout << "Regular letters: ";
	for (int i = 97; i <= 122; i++) cout << Hex[i] << " ";
	cout << endl;
	cin >> inps;
	for (int i = 0; i < inps.length() / 2; i++) {
		//cout << "hex: " << inps[i] << inps[i + 1] << endl;
		char tmp[2];
		tmp[0] = inps[i];
		tmp[1] = inps[i + 1];
		int res = hexadecimalToDecimal(tmp);
		//cout << "dec: " << res << endl;
		if (res == 20) cout << " ";
		else cout << Hex[res];
	}
}
int hexadecimalToDecimal(char hexVal[]) 
{    
    int len = strlen(hexVal); 
      
    // Initializing base value to 1, i.e 16^0 
    int base = 1; 
      
    int dec_val = 0; 
      
    // Extracting characters as digits from last character 
    for (int i=len-1; i>=0; i--) 
    {    
        // if character lies in '0'-'9', converting  
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value. 
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
                  
            // incrementing base by power 
            base = base * 16; 
        } 
  
        // if character lies in 'A'-'F' , converting  
        // it to integral 10 - 15 by subtracting 55  
        // from ASCII value 
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        { 
            dec_val += (hexVal[i] - 55)*base; 
          
            // incrementing base by power 
            base = base*16; 
        } 
    } 
      
    return dec_val; 
} 