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
        for (int u = firstNbr(); -1 < u; u = nextNbr(u, v))
        {
            if (status(u) = UNDISCOVERED)
            {
                        }
        }
    }
}