#include <vector>
#include <optional>

template<typename I> 
bool is_sorted(std::vector<I>& vec){
    if( vec.size() == 0 ||  vec.size() == 1){
        return true;
    }
    for (int i = 0; i< vec.size()-1; i++){
        if (vec[i] > vec[i+1]) {
            return false;
        }
    }
    return true;
}


