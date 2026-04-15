#include <vector>

template<typename I>
void Insertion(std::vector<I>& A){
    int N = A.size();
    if (N == 0 || N == 1){
    return;
    }
    for(int j = 1; j<N; j += 1){
        I key = A[j];
        int i = j-1;  
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
}