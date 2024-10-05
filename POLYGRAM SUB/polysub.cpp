#include<bits/stdc++.h>
using namespace std;
#define ln endl
vector<string>combination;
int bsize = 3;
string doEncryption(string text,int shift,int mod) {
    string result = "";
    for(int i=0;i<text.length();i+=bsize) {
        string temp =text.substr(i,bsize);
        if(temp.length()==bsize && find(combination.begin(),combination.end(),temp)!=combination.end()) {
            int pos = find(combination.begin(),combination.end(),temp)-combination.begin();
            pos = (pos+shift) % mod;
            result += combination[pos];
        }
        else 
            result += temp;
    }
    return result;
}
string doDecryption(string text,int shift,int mod) {
    return doEncryption(text,(mod-shift),mod);
}
int main() {
    //Creating All Possible Combinations
    string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int bsize = 3;
    for(auto ch1:alphabets) {
        for(auto ch2:alphabets) {
            for(auto ch3:alphabets) {
                string temp = "";
                temp += ch1;
                temp += ch2;
                temp += ch3;
                combination.push_back(temp);
            }
        }
    }

    //Printing all possible combinations
    ofstream dicout("dictinoray.txt");
    for(int i=0;i<combination.size();i++) 
        dicout<<combination[i]<<endl;

    //Taking the Plaintext
    ifstream fin("polysub1.txt");
    string ptext;
    getline(fin,ptext,'\0');
    cout<<"Orginal Text : "<<ln;
    cout<<ptext<<ln;
    

    //taking a random number for base index
    int mod = pow(52,bsize);
    srand(time(0));
    int shift = rand()% mod;
    cout<<"Shift = "<<shift<<ln;

    cout<<"After Polygram Encryption : "<<ln;
    string ctext = doEncryption(ptext,shift,mod);
    cout<<ctext<<ln;
    cout<<"After Polygram Decryption : "<<ln;
    string dtext = doDecryption(ctext,shift,mod);
    cout<<dtext<<ln;








}