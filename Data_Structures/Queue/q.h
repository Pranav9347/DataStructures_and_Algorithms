using namespace std;
#include<vector>

template <typename T>
class Queue
{
    private:
    vector<T> v;

    public:
    void enqueue(T item)
    {
        v.push_back(item);
    }
    T dequeue()
    {
        if(empty())
        {
            cout<<"Queue is empty!\n";
            return 0;
        }
        T temp = *(v.begin());
        v.erase(v.begin());
        return temp;
    }
    bool empty()
    {
        if(v.begin() == v.end())
            return true;
        else return false;
    }
};