#include "graph.h"
#include "../Vector_new/vector_template.h"

template <typename Tv, typename Te>
class GraphMatrix : public Graph<typename Tv, typename Te>
{
private:
    Vector<Vertex<Tv>> V{};

    /**
     * @brief 用边E来描述顶点关系，顶点与关系(边)组成整个图
     *
     */
    Vector<Vector<Edge<Te> *>> E;

public:
    GraphMatrix()
    {
        this->n = 0;
        this->e = 0
    };
    // 析构如何析构
    ~GraphMatrix();
    Tv &vertex(Rank i) override { return V[i].data; }
    Rank inDegree(Rank i) override { return V[i].inDegree; }
    Rank outDegree(Rank i) override { return V[i].outDegree; }
    VStatus &status(Rank i) override { return V[i].status; }

    bool exists(Rank i, Rank j) override
    {
        return (i < n) && (i >= 0) && (j < n) && (j >= 0) && (E[i][j] != nullptr);
    }

    // 顶点动态操作
    Tv remove(Rank i) override
    {
    }
    Rank insert(const Tv &v) override
    {
    }
    // 边的动态操作
};