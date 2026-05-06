#include <iostream>
#include <vector>

using namespace std;

void kaj() {
    int n;
    cin >> n; // Read the number of columns
    char arr[3][n]; // Fixed-size 2D array for the grid

    // Input the 3x18 character grid
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j]; // Read each character
        }
    }

    
    
    int  j =0;
    int i=0;
    string a, b , c;
    string ans;
    while(j < n){
        if(arr[0][j] == '#'){
            j++;
            i=j;
            cout << i << " "<< j << endl;
            ans.push_back('#');
        }
        a.push_back( arr[0][j]);
        b.push_back(arr[1][j]);
        c.push_back( arr[2][j]);

        if(j-i+1==3){
            cout << a << endl;
            cout << b << endl;
            cout << c << endl;
            //cout << i << " "<< j << endl;

            if((a[0] == '*' && a[1]=='*' && a[2] =='*') 
            && (b[0] == '*' && b[1]=='*' && b[2] =='*')
            && (c[0] == '*' && c[1]=='*' && c[2] =='*')){
                ans.push_back('E');
            }else if((a[0] == '*' && a[1]=='.' && a[2] =='*') 
                  && (b[0] == '*' && b[1]=='.' && b[2] =='*')
                  && (c[0] == '*' && c[1]=='*' && c[2] =='*')){
                    ans.push_back('U');
            }else if((a[0] == '.' && a[1]=='*' && a[2] =='.') 
                  && (b[0] == '*' && b[1]=='*' && b[2] =='*')
                  && (c[0] == '*' && c[1]=='.' && c[2] =='*')){
                    ans.push_back('A');
            }else if((a[0] == '*' && a[1]=='*' && a[2] =='*') 
                  && (b[0] == '.' && b[1]=='*' && b[2] =='.')
                  && (c[0] == '*' && c[1]=='*' && c[2] =='*')){
                    ans.push_back('I');
            }else if((a[0] == '*' && a[1]=='*' && a[2] =='*') 
                  && (b[0] == '*' && b[1]=='.' && b[2] =='*')
                  && (c[0] == '*' && c[1]=='*' && c[2] =='*')){
                    ans.push_back('O');
            }
            i=j+1;
            a.clear();
            b.clear();
            c.clear();

        }
        j++;
    }
    cout << endl;
    cout << ans << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " "; 
        }
        cout << endl; 
        
    }
}

int main() {
    kaj();
    return 0;
}
