#include "graph.h"
#include "vector_template.h"
#include "../List_new/List.h"
template <typename Tv, typename Te>
class GraphList : public Graph<typename Tv, typename Te>
{
private:
    // 如何设计邻接表内部成员的数据结构取决于查询与增删改查的次数
    List<Vertex<typename Tv>> V;
    List<List<Edge<typename Te>>> VE;

public:
    GraphList()
    {
        this->n = 0;
        this->e = 0;
    }
    ~GraphList();
    Rank insert(const Tv &v) override
    {
        // 我们插入新节点，需要
        List<Edge<typename Te>> *l = new List<Edge<typename Te>>;
        VE.insertLast(l);
    }
};
