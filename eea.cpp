#include<bits/stdc++.h>
using namespace std;

int extendedGCD(int a, int b, int&x, int&y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1;
    int ans = extendedGCD(b%a,a,x1,y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ans;
}

bool findSolution(int a, int b,int c,int &x, int &y,int &g){
    g = extendedGCD(a,b,x,y);
    if(c % g){
        return false;
    }
    x = x * (c / g);
    y = y * (c / g);
    if(a < 0){
        x = -1 * x;
    }
    if(b < 0){
        y = -1 * y;
    }
    return true;
}


int main(){
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        int x,y,g;
        cout << "The input format is: " << "ax + by = c" << endl;
        cin >> a >> b >> c;
        bool ans = findSolution(a,b,c,x,y,g);
        if(ans){
            cout << "GCD: " << g << endl;
            cout << "x: " << x << endl;
            cout << "y: " << y << endl;
            cout << "Five Distinct Solutions: " << endl;
            for(int i = 0; i < 5; i++){
                int n1 = (x + i * (b/g));
                int n2 = (y - i * (a/g));
                cout << "x: " << n1 << " " << "y: " << n2 << endl;
            }
        }
        else{
            cout << "No Possible Solution" << endl;
        }
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
}