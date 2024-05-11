#include <iostream>
#include<algorithm>
#include<string>
#include <deque>
using namespace std;
//20圈，每圈比上次多，有几种选择
deque<int > ans;
int total = 0;
void dfs(int nowval , int lastround){
//    cout<<nowval<<"now_val  "<<lastround<<"last   "<<endl;
    if(nowval > 20 ){
        return;
    }
    if(nowval == 20){//统计答案
        for(auto i : ans){
            cout<<i;
        }
        cout<<endl;
        ++total;
        return;
    }
    for(int i = lastround + 1 ; i <= 20 ; ++i){
        if(nowval + i <= 20 ){//若可以dfs则dfs
            ans.emplace_back(i);
            dfs(nowval + i , i);
            ans.pop_back();
        }
    }

}

int main() {
    for(int i = 1 ; i <= 20 ; ++i){
        ans.clear();
        ans.emplace_back(i);
//        cout<<i<<"times"<<endl;
        dfs(i , i);

    }
    cout<<"total num = "<<total<<endl;

    return 0;
}
