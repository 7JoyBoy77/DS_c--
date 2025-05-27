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
        // �˴������һ���ھӱ�������һ���ھ�
        for (int u = firstNbr(); -1 < u; u = nextNbr(u, v))
        {
            if (status(u) = UNDISCOVERED)
            {
                status(u) = DISCOVERED;
                Q.enqueue(u);
                type(v, u) = TREE;
                parent(u) = v; // ����������չ֧����
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
    // �����ж�����г�ʼ��
    reset();
    int clock = 0;
    int v = i;
    do                                 // ��һ������ж���
        if (UNDISCOVERED == status(v)) // һ�����b��δ���ְm����
            BFS(v, clock);             // ����ڹ���������۽һ��BFS
    while (i != (v = (++v % n)));
}
// bfs�ڻ���ʵ�֣����麯��������ʵ�֣����麯���ᶯ̬��