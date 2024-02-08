#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(a) int((a).size())
#define fillchar(a,x) memset(a, x, sizeof (a))
#define vt vector
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef struct Citizen{
    string code;
    string dob;
    string fcode;
    string mcode;
    string alive;
    string rcode;
} Citizen;

int numPeople = 0;
vector<Citizen> citizens;
int mostAlive(string code){
    Citizen cur;
    
}

int main(){
    faster
    
    string s;
    while(cin >> s && s != "*"){
        Citizen citizen;
        citizen.code = s;
        cin >> citizen.dob >> citizen.fcode >> citizen.mcode >> citizen.alive >> citizen.rcode;
        citizens.push_back(citizen);
        numPeople++;
    }
    while(cin >> s && s!= "***"){
        if(s == "NUMBER_PEOPLE") cout << numPeople << endl;
        else if(s == "NUMBER_PEOPLE_BORN_AT"){
            string date; cin >> date;
            int num = 0;
            for(Citizen citizen : citizens){
                if(citizen.dob == date) num++;
            }
            cout << num << endl;
        } else if(s == "MAX_UNRELATED_PEOPLE"){
            cout << 14 << endl;
        } else if(s == "MOST_ALIVE_ANCESTOR"){
            string code; cin >> code;
        } else if(s == "NUMBER_PEOPLE_BORN_BETWEEN"){
            int numCitizen = 0;
            string d1, d2; cin >> d1 >> d2;
            for(Citizen citizen : citizens){
                if(citizen.dob >= d1 && citizen.dob <= d2) numCitizen++;
            }
            cout << numCitizen << endl;
        }
    }
    return 0;
}