#include "graph.h"
#include "vector_template.h"
#include "../List_new/List.h"
template <typename Tv, typename Te>
class GraphList : public Graph<typename Tv, typename Te>
{
private:
    // �������ڽӱ��ڲ���Ա�����ݽṹȡ���ڲ�ѯ����ɾ�Ĳ�Ĵ���
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
        // ���ǲ����½ڵ㣬��Ҫ
        List<Edge<typename Te>> *l = new List<Edge<typename Te>>;
        VE.insertLast(l);
    }
};
