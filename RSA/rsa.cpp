#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gap " "
#define ln endl
// vector<ll>splitM(string m,int s) {
//     vector<ll>chunks;
//     int count = m.length();
//     for (int i = 0; i < count; i+=s){
//         string chunk = m.substr(i,s);
//         chunks.push_back(stoll(chunk));
//         cout<<chunks.back()<<ln;
//     }
//     return chunks;
    
// }

ll findD(ll e,ll phi) {
    ll temp = 1;
    ll cnt = 1;
    while(true) {
        temp = phi*cnt;
        temp++;
        if(temp%e==0)
            return temp/e;
        
        cnt++;
    }
    return -1;
}
/*int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long modInverse(long long a, long long m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

void generateKeys(int& n, int& e, int& d, int p, int q) {
    n = p * q;
    int phi = (p - 1) * (q - 1);
    e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) break;
        e++;
    }
    d = modInverse(e, phi);
}*/

//By the Method of Exponential Squaring (O(log Exp))
ll modExp(ll mes,ll exp,ll n) {
    // cout<<ln<<"Entering"<<ln;
    mes = mes % n;
    ll result = 1;
    while(exp>0) {
        if(exp&1)
            result = (result * mes) % n;
        
        mes = (mes*mes)%n;
        exp = exp >> 1;
    }
    // cout<<result<<ln;
    return result;
}

int main() {
    freopen("rsa1.txt","r",stdin);
    // freopen("rsa2.txt","w",stdout);
    // cout<<"hello"<<ln;
    string m;
    ll e,d,n;
    cin>>m>>e>>d>>n;
    // cout<<m<<gap<<e<<gap<<d<<gap<<n;
    vector<ll>chunkM;
    int chunkS=to_string(n).length()-1;

    //splitting the message
    // chunkM=splitM(m,chunkS);
    cout<<"Original Message is : "<<m<<ln;

    //splitting the message in anotherway & printing chunk by chunk
    cout<<"Splitting the Message : ";
    for(int i=0;i<m.length();i+=chunkS) {
        string chunk = m.substr(i,chunkS);
        chunkM.push_back(stoll(chunk));
        cout<<chunkM.back()<<gap;
    }
    cout<<ln<<"After Encrytion Chunk by Chunk : ";
    // cout<<ln<<"Total Blocks = "<<chunkM.size();
    vector<ll>chunkE;
    //chunk by chunk encryption : Ci = Mi^e % n;
    for(int i=0;i<chunkM.size();i++) {
        // cout<<ln<<i;
        ll temp = modExp(chunkM[i],e,n);
        chunkE.push_back(temp);
        cout<<chunkE.back()<<gap;
    }

    vector<ll> chunkD;
    cout<<ln<<"After Dencrytion Chunk by Chunk : ";
    //chunk by chunk decryption : Pi = Ci^d % n;
    for(int i=0;i<chunkE.size();i++) {
        // cout<<ln<<i;
        ll temp = modExp(chunkE[i],d,n);
        chunkD.push_back(temp);
        cout<<chunkD.back()<<gap;
    }
    //Altogether The Decrypted Message
    cout<<ln<<"Altogether The Decrypted Message : ";
    for(auto m:chunkD)
        cout<<m;


    // ll dd = findD(79,3220);
    // cout<<ln<<"d = "<<dd;

}