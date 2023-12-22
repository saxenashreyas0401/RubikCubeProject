#include <bits/stdc++.h>
#include "RubikCube3DArray.cpp"
using namespace std;
unordered_map<RubikCube3DArray,int,Hash3d> mp;
vector<string> m;
int k = 0;
void dfs(RubikCube3DArray cube, int depth)
{
    if(k==1)return;
    if(cube.isSolved()&&k!=1)
    {
        for(auto u:m)cout<<u<<" ";
        cout<<"\n";
        k = 1;
        return;
    }
    for(int i = 0; i<18; i++)
    {
        cube.move(GenericRubikCube::MOVE(i));
        {
            m.push_back(cube.getMove(GenericRubikCube::MOVE(i)));
            if(depth<=6)dfs(cube,depth+1);
            m.pop_back();
            cube.invert(GenericRubikCube::MOVE(i));
        }
    }
}


int main() {
    RubikCube3DArray cube1;
    RubikCube3DArray cube2;
    vector<GenericRubikCube::MOVE> mo = cube2.randomShuffleCube(5);
    for(auto i:mo)cout<<cube2.getMove(i)<<" ";
    cout<<"\n";
    cube2.print();
    dfs(cube2,1);
    return 0;
}
