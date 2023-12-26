//
// Created by Shreyas on 24-12-2023.
//

#ifndef RUBIKCUBEPROJECT_IDASTARSOLVER_H
#define RUBIKCUBEPROJECT_IDASTARSOLVER_H
#include<bits/stdc++.h>
#include "GenericRubikCube.h"
#include "CornerPatternDatabase.h"
template<typename T, typename H>
class IDASTARSOLVER{
private:
    CornerPatternDatabase cornerDB;
    unordered_map<T, int, H> vis;
    unordered_map<T, GenericRubikCube::MOVE, H> previous_move;
    vector<GenericRubikCube::MOVE> moves;
    struct Node{
        int depth;
        int estimate;
        T cube;
        Node(T _cube, int _depth, int _estimate) : cube(_cube), depth(_depth), estimate(_estimate) {};
    };
    struct compare{
       bool operator()(pair<Node,int> const &p1, pair<Node,int> const &p2){
           auto node1 = p1.first; auto node2 = p2.first;
           if(node1.depth+node1.estimate==node2.depth+node2.estimate)
           {
               return node1.estimate>node2.estimate;
           }
           else return node1.depth+node1.estimate>node2.depth+node2.estimate;
       }
    };
    void reset()
    {
        moves.clear();
        previous_move.clear();
        vis.clear();
    }
    pair<T,int> IDAstar(int bound)
    {
        priority_queue<pair<Node,int>, vector<pair<Node,int>>, compare> pq;
        auto start = Node(rubiksCube,0,cornerDB.getNumMoves(rubiksCube));
        pq.push({start,0});
        int next_bound = 100;
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            Node cur_node = p.first;
            previous_move[cur_node.cube] = GenericRubikCube::MOVE(p.second);
            if(cur_node.cube.isSolved())return {cur_node.cube,bound};
            if(vis[cur_node.cube])continue;
            vis[cur_node.cube]=1;
            cur_node.depth++;
            for(int i=0;i<18;i++)
            {
                auto cur_move = GenericRubikCube::MOVE(i);
                cur_node.cube.move(cur_move);
                if(!vis[cur_node.cube])
                {
                    cur_node.estimate = cornerDB.getNumMoves(cur_node.cube);
                    if(cur_node.depth+cur_node.estimate>bound)
                    {
                        next_bound = min(next_bound,cur_node.depth+cur_node.estimate);
                    }
                    else
                    {
                        pq.push({cur_node,i});
                    }
                    cur_node.cube.invert(cur_move);
                }
            }
        }
        return {rubiksCube,next_bound};
    }

public:
    T rubiksCube;
    IDASTARSOLVER(T rc, string fileName)
    {
        rubiksCube = rc;
        cornerDB.fromFile(fileName);
    }
    vector<GenericRubikCube::MOVE> solve(){
        int bound = 1;
        auto p = IDAstar(bound);
        while(p.second!=bound)
        {
            reset();
            bound = p.second;
            p = IDAstar(bound);
        }
        T cur_cube = p.first;
        while(!(cur_cube==rubiksCube))
        {
            moves.push_back(previous_move[cur_cube]);
            cur_cube.invert(previous_move[cur_cube]);
        }
        reverse(moves.begin(),moves.end());
        return moves;
    }

};

#endif //RUBIKCUBEPROJECT_IDASTARSOLVER_H
