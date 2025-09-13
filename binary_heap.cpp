
#include<vector>
#include<algorithm>

template<typename T>
class binary_heap {
    protected:
    std::vector<T> data;

    public:
    binary_heap(void){
    } 

    binary_heap(const std::vector<T>& vector) : data(vector) {
        std::make_heap(data.begin(), data.end());
    }

    T extractMin(void){
        if(!data.empty()){
            std::pop_heap(data.begin(), data.end());
            T minElement = data.back();
            data.pop_back();
            return minElement;
        }
    }

    void insert(const T& element){
        data.push_back(element);
        std::push_heap(data.begin(), data.end());
    }

};