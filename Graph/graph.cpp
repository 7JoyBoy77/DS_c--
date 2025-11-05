#pragma once
#include "graph.h"
template <typename Tv>
Vertex<Tv>::Vertex(const Tv &d = (Tv)0)
    : data(d), inDegree(0), outDegree(0), status(UNDETERMINED),
      dTime(-1), fTime(-1), parent(-1), priority(INT_MAX)
{
}

template <typename Te>
Edge<Te>::Edge(const Te &d, int w)
    : data(d), weight(w), type(UNDETERMINED)
{
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int &clock)
{
    Queue<int> Q;
    status(v) = DISCOVERED;
    Q.enqueue(v);
    while (!Q.empty())
    {
        int v = Q.dequeue();
        dTime(v) = ++clock;
        // 此处从最后一个邻居遍历到第一个邻居
        for (int u = firstNbr(); -1 < u; u = nextNbr(u, v))
        {
            if (status(u) = UNDISCOVERED)
            {
                status(u) = DISCOVERED;
                Q.enqueue(u);
                type(v, u) = TREE;
                parent(u) = v; // 引入树边拓展支撑树
            }
            else
            {
                type(v, u) = CROSS;
            }
            status(v) = VISITED;
        }
    }
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(Rank i)
{
    // 对所有顶点进行初始化
    reset();
    int clock = 0;
    int v = i;
    do                                 // 逐一检查所有顶点
        if (UNDISCOVERED == status(v)) // 一旦遇刡尚未収现癿顶点
            BFS(v, clock);             // 即从诠顶点出収启劢一次BFS
    while (i != (v = (++v % n)));
}
// bfs在基类实现，纯虚函数在子类实现，纯虚函数会动态绑定