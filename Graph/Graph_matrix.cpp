#include "graph.h"
#include "../Vector_new/vector_template.h"

template <typename Tv, typename Te>
class GraphMatrix : public Graph<typename Tv, typename Te>
{
private:
    /**
     * @brief 用边E来描述顶点关系，顶点与关系(边)组成整个图
     *
     * @note 邻接矩阵描述法
     */
    Vector<Vertex<Tv>> V{};
    Vector<Vector<Edge<Te> *>> E;

public:
    GraphMatrix()
    {
        this->n = 0;
        this->e = 0
    };
    // 析构如何析构
    ~GraphMatrix();

    Tv &vertex(Rank i) override
    {
        return V[i].data;
    }
    Rank inDegree(Rank i) override { return V[i].inDegree; }
    Rank outDegree(Rank i) override { return V[i].outDegree; }
    VStatus &status(Rank i) override { return V[i].status; }
    Rank &dTime(Rank i) override { return V[i].dtime; }
    Rank &fTime(Rank i) override { return V[i].ftime; }
    Rank &parent(Rank i) override { return V[i].parent; }
    int &priority(Rank i) override { return V[i].priority; }

    bool exists(Rank i, Rank j) override
    {
        return (i < n) && (i >= 0) && (j < n) && (j >= 0) && (E[i][j] != nullptr);
    }

    // 顶点动态操作
    Tv remove(Rank i) override
    {
        for (int j = 0; j < n; j++)
        {
            if (exists(i, j))
            {
                delete E[i][j];
                V[j].inDegree--;
            }
        }
        E.erase(i);
        n--;
        Tv vBak = vertex(i);
        V.erase(i);
        for (int j = 0; j < n; j++)
        {
            if (Edge<Te> *e = E[j].remove(i))
            {
                delete e;
                V[j].outDegree--;
            }
        }
        return vBak;
    }
    /**
     * @brief 并没有直接插入节点Vertex，传递一个Tv类型数据，用它构造一个Vertex对象
     *
     * @param v
     * @return Rank
     */
    Rank insert(const Tv &v) override
    {
        // 为各顶点预留一条潜在边，这里是为什么
        for (int i = 0; i < n; i++)
        {
            E[i].insert(nullptr);
        }
        n++;
        E.insert(Vector<Edge<Te> *>(n, n, (Edge<Te> *)nullptr));
        return V.insert(Vertex<Tv>(v));
    }

    Rank firstNbr(Rank i) override
    {
        return nextNbr(i, n);
    }

    Rank nextNbr(Rank i, Rank j) override
    {
        while (-1 < (j--) && !exists(i, j))
        {
        }
        return j;
    }
    EType Te &edge(Rank i, Rank j) override
    {
        return E[i][j].data;
    }
    // 边的动态操作
    void insert(const Te &e, int w, Rank i, Rank j) override
    {
        if (exists(i, j))
        {
            return;
        }
        E[i][j] = new Edge<Te>(e, w);
        this->e++;
        V[i].outDegree++;
        V[j].inDegree++;
    }
    void remove(int i, int j) override
    {
        Te temp = edge(i, j);
        if (!exists(i, j))
        {
            return;
        }
        delete E[i][j];
        E[i][j] = nullptr;
        this->e--;
        V[i].outDegree--;
        V[j].inDegree--;
        return temp;
    }
};
