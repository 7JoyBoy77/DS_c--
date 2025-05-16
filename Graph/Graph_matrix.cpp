#include "graph.h"
#include "../Vector_new/vector_template.h"

template <typename Tv, typename Te>
class GraphMatrix : public Graph<typename Tv, typename Te>
{
private:
    Vector<Vertex<Tv>> V{};

    /**
     * @brief �ñ�E�����������ϵ���������ϵ(��)�������ͼ
     *
     */
    Vector<Vector<Edge<Te> *>> E;

public:
    GraphMatrix()
    {
        this->n = 0;
        this->e = 0
    };
    // �����������
    ~GraphMatrix();
    Tv &vertex(Rank i) override { return V[i].data; }
    Rank inDegree(Rank i) override { return V[i].inDegree; }
    Rank outDegree(Rank i) override { return V[i].outDegree; }
    VStatus &status(Rank i) override { return V[i].status; }

    bool exists(Rank i, Rank j) override
    {
        return (i < n) && (i >= 0) && (j < n) && (j >= 0) && (E[i][j] != nullptr);
    }

    // ���㶯̬����
    Tv remove(Rank i) override
    {
    }
    Rank insert(const Tv &v) override
    {
    }
    // �ߵĶ�̬����
};