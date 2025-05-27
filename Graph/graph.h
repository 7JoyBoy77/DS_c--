#pragma once
#include "../Queue/queue.h"
#include <limits>
using VStatus = enum { UNDISCOVERED,
                       DISCOVERED,
                       VISITED }; // ����״̬
                                  /**
                                   * @brief ���ڱ�����������������
                                   *
                                   */
using EType = enum { UNDETERMINED,
                     TREE,
                     CROSS,
                     FORWARD,
                     BACKWARD };

template <typename Tv, typename Te> // �������͡�������
class Graph
{ // ͼGraphģ����
private:
    void reset()
    { // ���ж��㡢�ߵĸ�����Ϣ��λ
        for (int v = 0; v < n; v++)
        { // ���ж����
            status(v) = UNDISCOVERED;
            dTime(v) = fTime(v) = -1; // ״̬��ʱ���ǩ
            parent(v) = -1;
            priority(v) = INT_MAX;      // ���ڱ������еģ����ڵ㣬���ȼ���
            for (int u = 0; u < n; u++) // ���бߵ�
                if (exists(v, u))
                    type(v, u) = UNDETERMINED; // ����
        }
    }
    /**
     * @brief ����ͨ��������
     *
     */
    void BFS(int, int &);                  // ����ͨ�򣩹�����������㷨
    void DFS(Rank, Rank &);                // ����ͨ��������������㷨
    void BCC(Rank, Rank &, Stack<Rank> &); // ����ͨ�򣩻���DFS��˫��ͨ�����ֽ��㷨
    bool TSort(Rank, Rank &, Stack<Tv> *); // ����ͨ�򣩻���DFS�����������㷨
    template <typename PU>
    void PFS(Rank, PU); // ����ͨ�����ȼ��������
protected:
    int n; // ����
    int e; // �ߣ�����Լ��������߾�ͳһת��Ϊ�������һ������ߣ��Ӷ�������ͼ��������ͼ������
    // ������
public:
    Graph() = default;
    virtual ~Graph() = default;
    virtual Rank insert(Tv const &) = 0; // ���붥�㣬���ر��
    virtual Tv remove(Rank) = 0;         // ɾ�����㼰������ߣ����ظö�����Ϣ
    virtual Tv &vertex(Rank) = 0;        // ��������ݣ��ö����ȷ���ڣ�
    virtual Rank inDegree(Rank) = 0;     // �������ȣ��ö����ȷ���ڣ�
    virtual Rank outDegree(Rank) = 0;    // ����ĳ��ȣ��ö����ȷ���ڣ�
    /**
     * @brief �����׸��ڽӽڵ�
     * @note �ڽӽڵ���ô����ģ���ô�ж��ģ����ȥ�ҵ�
     * @return Rank
     */
    virtual Rank firstNbr(Rank) = 0;
    /**
     * @brief ���Ҷ��� i ���ڽӱ��У�����С�� j �����һ���ڽӶ���
     *
     * @return Rank
     */
    virtual Rank nextNbr(Rank, Rank) = 0;
    /**
     *
     * @return VStatus& ���ô����޸�ֵ
     */
    virtual VStatus &status(Rank) = 0; // �����״̬
    virtual Rank &dTime(Rank) = 0;     // �����ʱ���ǩdTime
    virtual Rank &fTime(Rank) = 0;     // �����ʱ���ǩfTime
    virtual Rank &parent(Rank) = 0;    // �����ڱ������еĸ���
    virtual int &priority(Rank) = 0;   // �����ڱ������е����ȼ���

    virtual bool exists(Rank, Rank) = 0;                  // ��(v, u)�Ƿ����
    virtual void insert(Te const &, int, Rank, Rank) = 0; // ����������֮�����ָ��Ȩ�صı�
    virtual Te remove(Rank, Rank) = 0;                    // ɾ��һ�Զ���֮��ıߣ����ظñ���Ϣ
    virtual EType &type(Rank, Rank) = 0;                  // �ߵ�����
    virtual Te &edge(Rank, Rank) = 0;                     // �ߵ����ݣ��ñߵ�ȷ���ڣ�
    virtual int &weight(Rank, Rank) = 0;                  // ��(v, u)��Ȩ��

    /**
     * @brief ȫͼ������������㷨
     *
     */
    void bfs(Rank);

    void dfs(Rank);         // ������������㷨
    void bcc(Rank);         // ����DFS��˫��ͨ�����ֽ��㷨
    Stack<Tv> *tSort(Rank); // ����DFS�����������㷨
    void prim(Rank);        // ��С֧����Prim�㷨
    void dijkstra(Rank);    // ���·��Dijkstra�㷨
    template <typename PU>
    void pfs(Rank, PU); // ���ȼ��������
};

template <typename Tv>
struct Vertex
{
    Tv data;
    int inDegree, outDegree;
    VStatus status;
    // ʱ���ǩ
    int dTime, fTime;
    // �������еĽڵ㣬���ȼ�
    int parent, priority;
    Vertex(const Tv &d = (Tv)0);
    ~Vertex();
};
template <typename Te>
struct Edge
{
    Te data;
    int weight;
    EType type;
    Edge(const Te &d, int w);
    ~Edge();
};