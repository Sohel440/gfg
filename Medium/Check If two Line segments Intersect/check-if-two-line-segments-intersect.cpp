//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
double fnct(int x1, int y1, int x2, int y2, int x, int y) {
    return (double)((x2 - x1) * (y - y1) - (y2 - y1) * (x - x1));
}

bool onSegment(int x1, int y1, int x2, int y2, int x, int y) {
    return (x >= min(x1, x2) && x <= max(x1, x2) && y >= min(y1, y2) && y <= max(y1, y2));
}

string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
    // Checking the orientations
       double m1 = (double)(q1[1] - p1[1]) / (double)(q1[0] - p1[0]);
        double m2 = (double)(q2[1] - p2[1]) / (double)(q2[0] - p2[0]);
        if(m1 == m2){
            return "false";
        }
        bool chk211 = p2[1]-p1[1] - m1*(p2[0]-p1[0]) >0?true:false;
        bool chk212 = q2[1]-p1[1] - m1*(q2[0]-p1[0]) >0?true:false;
        bool chk121 = p1[1]-p2[1] - m2*(p1[0]-p2[0]) >0?true:false;
        bool chk122 = q1[1]-p2[1] - m2*(q1[0]-p2[0]) >0?true:false;
        if((chk211==true && chk212 == true) || (chk211==false && chk212 == false) || 
        (chk121 == true && chk122 == true) || (chk121 == false && chk122 == false)){
            return "false";
        }
        return "true";
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends