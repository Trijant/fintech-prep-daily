#include<bits/stdc++.h>
using namespace std;

// topic: prefix sum + binary search

class ExamTracker
{
private:
    vector<long long> scores;
    vector<int> t;

public:
    ExamTracker()
    {
        scores.reserve(100001);
        scores.push_back(0);
        t.reserve(100001);
        t.push_back(0);
    }

    void record(int time, int score)
    {
        scores.push_back(scores.back() + score);
        t.push_back(time);
    }

    long long totalScore(int startTime, int endTime)
    {
        int s = lower_bound(t.begin(), t.end(), startTime) - t.begin() - 1;
        int e = upper_bound(t.begin(), t.end(), endTime) - t.begin() - 1;
        return scores[e] - scores[s];
    }
};


int main(){
    cout<<"Instructions: "<<endl;
    cout<<"record <time> <score>"<<endl;
    cout<<"find <startTime> <endTime>"<<endl;
    cout<<"exit"<<endl;
    ExamTracker t;
    while(true){
        string s;
        cin>>s;
        if(s=="exit")
            break;
        else if(s=="record"){
            int time, score;
            cin>>time>>score;
            t.record(time, score);
        }
        else if(s=="find"){
            int st, et;
            cin >> st >> et;
            cout << "Total score: " << t.totalScore(st, et) << endl;
        }
        else{
            cout << "Invalid instruction!" << endl;
        }
    }
}