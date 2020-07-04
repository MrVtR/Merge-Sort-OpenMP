#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<chrono>

#define n 1000000
void merge(int a[],int l,int m,int r);
void mergeSort(int a[],int l,int r);

int main(){
    
    int a[n],i;
    srand(time(0));// Função Srand usada para que o código randomize o vetor de forma diferente a cada execução

    for(i = 0; i <n; i++)
    {
        a[i]=rand() % 2000000;//Randomizar vetor com valores inteiros até 2 milhões
    }
    auto inicio = std::chrono::high_resolution_clock::now(); //Clock de início

    mergeSort(a, 0, n-1);

    auto resultado = std::chrono::high_resolution_clock::now() - inicio;// Clock final
    long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
    
    //Print do Vetor ordenado para testes de conferência
    /*for(i = 0; i <n; i++)
          printf("%d ", a[i]); 
    printf("\n");*/
    printf("Tempo do Merge: 0.%lld ms\n",milliseconds);
    return(0);
}

void merge(int a[],int l,int m,int r)
{
    int b[m-l+1], c[r-m];
    for(int i=0; i<(m-l+1); i++){
        b[i]=a[l+i];
    }
    for(int i=0; i<(r-m); i++){
        c[i]=a[m+1+i];
    }
    int i=0, j=0, k=l;
    while(i<(m-l+1) && j<(r-m))
    {
        if(b[i]<c[j]){
            a[k++]=b[i++];
        }
        else{
            a[k++]=c[j++];
        }
    }
    while(i<(m-l+1)){
        a[k++]=b[i++];
    }
    while(j<(r-m)){
        a[k++]=c[j++];
    }
}

void mergeSort(int a[],int l,int r)
{
    if (l<r)
    {
        int m=(l + r)/2;
        mergeSort(a,l,m); 
        mergeSort(a,m+1,r); 
        merge(a,l,m,r);
    }
}
