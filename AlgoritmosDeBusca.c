#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000
#define M 1000


/**********Busca Sequencial***********/
int seqSearch(int v[], int n, int key){ //Entra com (Vetor, Tamanho, Valor a ser Buscado)
    int i = 0;
    while(v[i] < key && i <= n) i++; //Verifica se o vetor na posi��o i (v[i]) � igual a chave(key)
    return i;
}

/**********Busca Bin�ria***********/
int binSearch(int v[], int n, int key){ //Entra com (Vetor, Tamanho, Valor a ser Buscado)
    int i, a=0, b=n, c=0; //Coloca inical com valor 0 e final com valor n
    while(a<=b){ //Verifica se a posi��o inicial � maior que a final
        c++;
        i=(a+b)/2; // Posiciona o buscador na metade do vetor
        if(v[i]==key) break; // Verifica se a posi��o i do vetor � igual a chave
        else if(v[i]<key) a=i+1; //se a chave for maior, o inicio vira a posi��o logo ap�s o meio
        else b=i-1; // Se n�o, o final vira vira a posi��o anterior ao meio
    }
    return (c);
}

/**********Busca por Interpola��o***********/
int intSearch(int v[], int n, int key){
    int i=n/2, a=0, b=n, c=0;
    double e= v[0]/(1000*v[b]);

    while(a<=b){
        c++;
        i = a + ceil((double)((key - v[a])*( (b-a)/(double) (v[b]-v[a])+e)));

        if(i<a) i =a;
        if(i>b) i =b;

        if (v[i] == key) break;
        else if (v[i] < key) a = i+1;
        else b= i-1;
    }
return(c);
}


int compare(const void*a, const void *b){
    return (*(int*)a - *(int*)b);
}



int main(){
    int i,v[N], k;
    double ic,bc,sc;

    for (i=0; i<N; i++){
        v[i] = rand()%N;
    }

    qsort(v,N, sizeof(int), compare);

    ic = 0;
    bc = 0;
    sc = 0;

    for  (i=0; i<M; i++){
        k = rand() %N;
        bc = bc + binSearch(v,N-1,k);
        ic = ic + intSearch(v,N-1,k);
        sc = sc + seqSearch(v,N-1,k);
    }
    printf("\n BinSearch --> avg of %f steps",bc/M);
    printf("\n IntSearch --> avg of %f steps",ic/M);
    printf("\n SeqSearch --> avg of %f steps",sc/M);
    printf("\n");
}
