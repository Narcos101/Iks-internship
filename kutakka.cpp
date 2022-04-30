#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}

vector<double> kuttakaSolve(double a, double c,double b){
    double A = abs(a);
    double B = abs(b);
    double C = abs(c);
    double _gcd = gcd(A, gcd(B, C));
    A = A / _gcd; 
    B = B / _gcd; 
    C = C / _gcd;
    vector<double>quot;
    int rem = 0;
    int d = A;
    int s = B;
    while (rem != 1){
        rem = d % s;
        quot.push_back(floor(d/s));
        int temp = d;
        d = s;
        s = temp % s;
    }
    double x = 0;
    double y = C;
    for(int i = quot.size()-1; i >= 0;i--){
        double temp = x;
        x = y;
        y = quot[i] * y + temp;
    }
    if(quot.size() % 2 != 0){
        x = B - x; 
        y = A - y;
    }
    if(c < 0){
        x = B - x; 
        y = A - y;
    }
    if (a < 0){
        x = -1 * x; 
    }
    if(b < 0){
        y = -1 * y;
    }
    double q = min(floor(x / B),floor(y / A));
    x = x - q * b; 
    y = y - q * a;
    return {x,y};
}

int main(){
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    cout << "The input format is: " << "ax + c = by" << endl;
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int g = gcd(abs(a),abs(b));
        if(abs(c) % gcd(abs(a),abs(b)) != 0){
            cout << "Solution is not possible" << endl;
        }
        else{
            vector<double>soln = kuttakaSolve(a,c,b);
            double x = soln[0];
            double y = soln[1];
            for(int i = 0; i < 5; i++){
                int n1 = (x + i * (b/g));
                int n2 = (y - i * (a/g));
                cout << "x: " << n1 << " " << "y: " << n2 << endl;
            }
        }
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
}