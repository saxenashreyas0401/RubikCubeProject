#include <bits/stdc++.h>
#include "RubikCube3DArray.cpp"
using namespace std;
unordered_map<RubikCube3DArray,GenericRubikCube::MOVE,Hash3d> mvs;
vector<string> m;
int k = 0;
RubikCube3DArray cube1;
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
vector<string> s;
int b = 0;
RubikCube3DArray cube2;
void print_moves(RubikCube3DArray cube)
{
    if(cube==cube2)return;
    auto mov = mvs[cube];
    cube.invert(mov);
    print_moves((cube));
    cout<<cube.getMove(mov)<<" ";
}

int main() {

    vector<GenericRubikCube::MOVE> mo = cube2.randomShuffleCube(2);
    for(auto i:mo)cout<<cube2.getMove(i)<<" ";
    cout<<"\n";
    cube2.print();
    unordered_map<RubikCube3DArray,int,Hash3d> mp;

    //dfs(cube2,1);
    queue<RubikCube3DArray> q;
    q.push(cube2);
    mp[cube2]=1;
    while(!q.empty())
    {
        RubikCube3DArray cube = q.front();
        q.pop();
        mp[cube]=1;
        if(cube.isSolved())
        {
            break;
        }
        for(int i=0;i<18;i++)
        {
            cube.move(GenericRubikCube::MOVE(i));
            if(!mp[cube])
            {
                q.push(cube);
                mvs[cube] = GenericRubikCube::MOVE(i);
            }
            cube.invert(GenericRubikCube::MOVE(i));
        }
    }
    print_moves(cube1);
    return 0;
}
