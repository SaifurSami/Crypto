#include<bits/stdc++.h>
using namespace std;
#define ln endl
int main() {
    // cout << "ok";
    cin.clear();
    freopen("otp1.txt", "r", stdin);
    string ptext;
    getline(cin,ptext,'\0');
    cout << "Original Message is : "<<ln <<ptext<<ln;

    vector<char> keys,alpha;
    unordered_map<char, int> encoder;
    unordered_map<int, char> decoder;
    int cnt = 0;
    for (char c = 'A'; c <= 'Z';c++) {
        keys.push_back(c);
        // alpha.push_back(c);
        encoder[c] = cnt;
        decoder[cnt] = c;
        // if(c=='O')
        cnt++;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        keys.push_back(c);
        // alpha.push_back(c);
        encoder[c] = cnt;
        decoder[cnt] = c;
        cnt++;
    }
    // cout << cnt<<ln<<encoder['z']<<ln;
    cnt = 0;
    //Randomly Shuffle & Generating the Keys
    random_shuffle(keys.begin(), keys.end());
    // for(char c:keys) {
    //     decoder[c] = cnt;
    //     cnt++;
    // }
    // cout << ln<<cnt<<ln;
    string ctext="";
    for (int i = 0; i < ptext.length();i++) {
        if (isalpha(ptext[i])) {
            int pi, ki, ci;
            pi = encoder[ptext[i]];
            ki = encoder[keys[i]];
            int temp = (pi+ki)%52;
            ctext += decoder[temp];
        }
        else
            ctext += ptext[i];
    }
    cout << ln << "After Encryption : ";
    cout << ln << ctext<<ln;
    string dtext = "";
    for (int i = 0; i < ctext.length(); i++) {
        if (isalpha(ctext[i]))
        {
            int di, ci, ki;
            ci = encoder[ctext[i]];
            ki = encoder[keys[i]];
            int temp = (ci-ki+52)%52;
            dtext += decoder[temp];
        }
        else
            dtext += ctext[i];
    }
    cout << ln << "After Decryption : ";
    cout << ln << dtext << ln;
}