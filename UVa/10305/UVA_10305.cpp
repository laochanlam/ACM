#include <vector>
#include <iostream>
using namespace std;

struct Job{
    bool Isdone;
    vector <int> PreJobList;
};

Job JobList[101];

void backtracing(int JobNum)
{
    while (!JobList[JobNum].PreJobList.empty()) {
        backtracing(JobList[JobNum].PreJobList.back());
        JobList[JobNum].PreJobList.pop_back();
    };
    if (!JobList[JobNum].Isdone) {
            JobList[JobNum].Isdone = true;
            cout<<JobNum<<endl;
    }
}

int main(){
    int m,n;
    int preJob,curJob;
    int i;

    while (1) {
        cin>>n>>m;
        for (i=1; i<=n; i++)
            JobList[i].Isdone = false;
        if ( m == 0 && n == 0) return 0;
        for (i=0; i<m; i++) {
            cin>>preJob>>curJob;
            JobList[curJob].PreJobList.push_back(preJob);
        }

        for (i=1; i<=n; i++)
        backtracing(i);
    }
}
