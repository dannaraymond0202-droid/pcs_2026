#include <vector>
template<typename I>
void Bubble(std::vector<I>& array){
    int N = array.size();
    if (N == 0 || N == 1){
        return;
    }
    for (int i = 0; i<N-1; i+=1){
        for (int j = N-1; j>i;j-=1){
            if (array[j] < array[j-1]){
                I a = array[j];
                I b = array[j-1];
                array[j] = b;
                array[j-1] = a;
            }
        }
    }
}
