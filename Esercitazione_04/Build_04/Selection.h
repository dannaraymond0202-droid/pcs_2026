#include <vector>

template<typename T>
void Selection(std::vector<T>& A){
    if (A.size() == 0 || A.size() == 1){
        return;
    }
    for(int i = 0; i<A.size()-1; i+=1){
        int min = i;
        for(int j = i +1; j<A.size(); j+=1){
            if(A[j]<A[min]){
                min = j;
            }
        }
        T a = A[i];
        T b = A[min];
        A[min] = a;
        A[i] = b;
    }
}