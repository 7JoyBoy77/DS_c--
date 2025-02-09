#include <iostream>
#include <vector>
using namespace std;
int Maxrecurise(vector<int> vec, int n)
{
    if (n >= 2)
    {
        return max(Maxrecurise(vec, n - 1), vec[n - 1]);
    }
    else
    {
        return vec[n - 1];
    }
}
// awdjwadji

int main()
{
    vector<int> vec;
    unsigned n;
    cin >> n;
    while ((n--) > 0)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    int max = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (max < vec[i])
        {
            max = vec[i];
        }
    }
    return 0;
}
