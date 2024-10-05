#include<bits/stdc++.h>
using namespace std;
#define ln endl

string doEncryption(string text,int s) {
    string result = "";

    for(int i =0 ;i<text.length();i++) {
        char ch = text[i];

        if(isupper(ch))
            result += char(int(ch+s-'A')%26+'A');
        else if(islower(ch)) 
            result += char(int(ch+s-'a')%26+'a');
        else 
            result += ch;
    }
    return result;
}
string doDecryption(string text,int s) {
    return doEncryption(text,26-s);
}
int main() {
    freopen("caesar1.txt","r",stdin);
    // freopen("caesar2.txt","w",stdout);
    string ptext;
    getline(cin,ptext,'\0');
    cout<<"Original PlainText : "<<ln;
    cout<<ptext<<ln;
    int shift = 3;
    // cout<<"Enter Shift Value = ";
    // cin>>shift;
    // cout<<shift<<ln;
    string ctext = doEncryption(ptext,shift);
    cout<<"After Encryption : "<<ln<<ctext<<ln;
    string dtext = doDecryption(ctext,shift);
    cout<<"After Decryption : "<<ln<<dtext<<ln;


}