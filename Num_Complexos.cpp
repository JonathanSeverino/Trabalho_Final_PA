#include <iostream>

using namespace std;



struct tComplexos{
   int xreal = 0;
   int ximag = 0;
   int yreal = 0;
   int yimag = 0;

   tComplexos* proximo;  
              
};


tComplexos* criaNo(int item){
    tComplexos* no = new tNo;

    no -> info = item;
    no -> proximo = NULL;

    return no;
}


struct tLista{

    tComplexos* primeiro;
    tComplexos* ultimo;
    tComplexos* marcador;
    int tamanho;
};

void inicializaLista(tLista* pLista){
    pLista -> primeiro = NULL;
    pLista -> ultimo = NULL;
    pLista -> marcador = NULL;
    pLista -> tamanho = 0;
}

int obterTamanho(tLista* pLista){
    return pLista -> tamanho;
}

bool listaVazia(tLista* pLista){
    return (pLista -> tamanho ==0);
}


bool finalLista(tLista* pLista){
    return (pLista -> marcador == NULL);
}

void incluirNofim(tLista* pLista, int info){
    tComplexos* no;
    no = criaNo(info);

    if(listaVazia(pLista)){
        pLista -> primeiro = no;
    }
    else{
        pLista -> ultimo -> proximo = no;
    }

    pLista -> ultimo = no;
    pLista -> marcador = no;
    pLista -> tamanho ++;
}

void imprimirLista(tLista* pLista){
    pLista -> marcador = pLista -> primeiro;

    while(!finalLista(pLista)){
        int informacao = pLista -> marcador -> info;
        cout << "Ainformacao eh: " << informacao << endl;

        pLista -> marcador = pLista -> marcador -> proximo;
    }
}

void excluirPosicao(tLista* pLista, int pos){
    tComplexos* anterior;
    tComplexos* aux;
    tComplexos* apagado;

    if(!listaVazia(pLista)){
        pLista -> marcador = pLista -> primeiro;

        if(pos < obterTamanho(pLista)){

            if(pos == 0){
                pLista -> primeiro = pLista -> marcador -> proximo;

                
            }

            else{
                for(int i = 0; i < pos; i++){

                    anterior = pLista -> marcador;
                    pLista -> marcador = pLista -> marcador -> proximo;

                    aux = pLista -> marcador -> proximo;
                }

                anterior -> proximo = aux;
            }

            apagado = pLista -> marcador;
            free(apagado);
        }
    }
}


int main(){

    tLista* idades = new tLista;

    inicializaLista();

    cout << "O tamanho da lista eh: " << obterTamanho(idades) << endl;

    

     return 0;
