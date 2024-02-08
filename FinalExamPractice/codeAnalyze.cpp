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

typedef struct Submission{
    string userId;
    string problemId;
    string timePoint;
    string status;
    int point;
} Submission;

int timePeriod(string s, string t1, string t2){
    int timeS = stoi(s.substr(6, 2)) + 60 * stoi(s.substr(3, 2)) + 3600 * stoi(s.substr(0, 2));
    int timeT1 = stoi(t1.substr(6, 2)) + 60 * stoi(t1.substr(3, 2)) + 3600 * stoi(t1.substr(0, 2));
    int timeT2 = stoi(t2.substr(6, 2)) + 60 * stoi(t2.substr(3, 2)) + 3600 * stoi(t2.substr(0, 2));
    return timeS >= timeT1 && timeS <= timeT2;
}

int numSubmit = 0, numErrSubmit = 0;
int main(){
    faster
    vector<Submission> submissions;
    string s;
    while (cin >> s && s != "#"){
        Submission submission;
        submission.userId = s;
        cin >> submission.problemId >> submission.timePoint >> submission.status >> submission.point;
        submissions.push_back(submission);
        numSubmit++;
        if(submission.status == "ERR") numErrSubmit++;
    }
    while (cin >> s && s != "#"){
        if(s == "?total_number_submissions") cout << numSubmit << endl;
        else if(s == "?number_error_submision") cout << numErrSubmit << endl;
        else if(s == "?number_error_submision_of_user"){
            string uId; cin >> uId;
            int numErrSubmitId = 0;
            for(Submission submission : submissions){
                if(submission.userId == uId && submission.status == "ERR")  numErrSubmitId++;
            }
            cout << numErrSubmitId << endl;
        } else if(s == "?total_point_of_user"){
            string uId; cin >> uId;
            unordered_map<string, int> p;
            int totalPt = 0;
            for(Submission submission : submissions){
                if(submission.userId == uId){
                    p[submission.problemId] = max(submission.point, p[submission.problemId]);
                }
            }
            for(auto i : p) totalPt += i.second;
            cout << totalPt << endl;
        } else if(s == "?number_submission_period"){
            int res = 0;
            string t1, t2; cin >> t1 >> t2;
            for(Submission submission : submissions){
                if(timePeriod(submission.timePoint, t1, t2)) res++;
            }
            cout << res << endl;
        }
    }
    return 0;
}