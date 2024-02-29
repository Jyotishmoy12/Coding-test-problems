
Alfie was a prisoner in mythland. Though Alfie was a witty and intelligent guy. He was confident of escaping prison. After few days of observation, he figured out that the prison consists of (
�
×
�
N×N) cells. i.e., the shape of prison was (
�
×
�
N×N) matrix. Few of the cells of the prison contained motion detectors. So Alfie planned that while escaping the prison he will avoid those cells containing motion detectors. Yet before executing his plan, Alfie wants to know the total number of unique possible paths which he can take to escape the prison. Initially Alfie is in cell (
1
,
1
1,1) while the exit of the cell (
�
,
�
N,N).

Note: Alfie can move in all four direction. If his current location is (
�
,
�
X,Y), he can move to either (
�
+
1
,
�
X+1,Y), (
�
,
�
+
1
X,Y+1), (
�
−
1
,
�
X−1,Y), (
�
,
�
−
1
X,Y−1). If the first cell (
1
,
1
1,1) and the last cell (
�
,
�
N,N) contain motion detectors, then Alfie can't break out of the prison.


#include <bits/stdc++.h>

using namespace std;

char arr [20 + 1][20 + 1];
int dirc [][2] = { {1 , 0} , {-1 , 0}, {0 , 1}, {0 , -1} };
int ans , n;
bool vis [20 + 1][20 + 1];

void rec (int x , int y){

    if(x == n - 1 && y == n - 1){           // base case

        ans++;
        return;
    }

    vis[x][y] = true;                       // set this state as visited

    for(int i = 0; i < 4; i++){

        int dx = x + dirc[i][0];            // try new transitions
        int dy = y + dirc[i][1];

        if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;        // check outside of the board
        if(vis[dx][dy] || arr[dx][dy] == '1') continue;             // check for motion detectors or state was visited before

        rec(dx , dy);                                               // go to next state
        vis[dx][dy] = false;                                        // set state as false (Back Track).
    }
}

int main()
{
    int t;

    cin >> t;

    while(t--){

        ans = 0;
        memset(vis , false, sizeof vis);        // set all states as unvisited

        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                cin >> arr[i][j];
            }
        }

        rec(0 , 0);
        cout << ans << "\n";
    }

    return 0;
}
