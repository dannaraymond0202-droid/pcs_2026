#include <iostream>
#include <algorithm>
#include <cmath>

double minimo(double array[],int N){
	double x = array[0];
	for (int i = 1; i<=N-1;i+=1) {
		x = std::min(x,array[i]);
	}
return x;
}

double massimo(double array[],int N){
	double x = array[0];
	for (int i = 1; i<=N-1;i+=1) {
		x = std::max(x,array[i]);
	}
return x;
}

double media(double array[],int N){
	double x = 0;
	for(int i = 0; i<=N-1 ; i+=1){
		x = array[i] + x;
	} 
	double y = x/N;
return y;
}

double devia_sta(double array[], double media, int N){
	double x = 0;
	for (int i = 0; i<=N-1; i+=1){
		x = x + (array[i]-media)*(array[i]-media);
	}	
	double devi = std::sqrt(x/N); 
return devi;
}

void Bubblesort(double array[],int N){
	int j = 1;
	while(j !=0){
		j = 0;
		for (int i = 0; i<N-1; i +=1){
			if(array[i]<array[i+1]){
				continue;
			}
			else{
				double min = array[i+1];	
				double max = array[i];
				array[i] = min;
				array[i+1] = max;
				j = 1+j;
			}
		}
	}
		
}	
void stampa(double array[],int N){
	for(int i=0;i<=N-1;i+=1){
		std::cout<<array[i]<<"  ";
	}

}

int main(){

	static const int N = 10;
	double arra[N] = {0.12,0.3,3.4,5.7,2,8,-9.4,8.3,6.94,-1.11};
	Bubblesort(arra,N); //per esercitarmi sull'uso delle funzioni mi sono semplicemente aiutato da gemini per //capire qualle tipo di funzione era meglio chiamare(int,void ecc..) sia in questa funzione che in stampa. Questo //perchè usando double in Bubblesort non riuscivo a mandare tutta l'array, mentre per stampa l'int ... return 0 mi //stampava 0 alla fine della mia array.   
	double min_arra = minimo(arra,N);
	double max_arra = massimo(arra,N);
	double media_arra = media(arra,N);
	double devista_arr = devia_sta(arra,media_arra, N);
	std::cout<<"L'Arrey che ho creato è ";
	stampa(arra,N);
	std::cout<<"\n";
	std::cout<<"Il minimo dell'array è "<<min_arra<<"\n";
	std::cout<<"Mentre il massimo è " << max_arra<<"\n";
	std::cout<<"Con una media di " <<media_arra<<"\n";
	std::cout<<"E con una deviazione standard pari ad " << devista_arr<<"\n";
return 0;
}












