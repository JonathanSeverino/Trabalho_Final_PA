#include <iostream>

using namespace std;



struct tComplexos{
   int real = 0;
   int imag = 0;
   

   tComplexos* proximo;  
              
};


tComplexos* criaNo(int x, int y){
    tComplexos* no = new tComplexos;

    no -> real = x;
    no -> imag = y;
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

void incluirNofim(tLista* pLista, int x, int y){
    tComplexos* no;
    no = criaNo(x, y);

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
        int complex_real = pLista -> marcador -> real;
        int complex_imag = pLista -> marcador -> imag;
        cout << "O número complexo eh: " << complex_real << " + " << complex_imag << "b" << endl;

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

    tLista* complex = new tLista;

    inicializaLista(complex);

    cout << "O tamanho da lista eh: " << obterTamanho(complex) << endl;

    incluirNofim(complex, 2, 10);
    imprimirLista(complex);

    

     return 0;
}
