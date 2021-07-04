#include <iostream>
#include <fstream>
#include <string>


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




void escreve_arquivo(tLista* pLista){
    int tamanho = obterTamanho(pLista);
    
    ofstream base_dados;    
    base_dados.open("BasedeDados.txt", std::ios_base::app);

    pLista -> marcador = pLista -> primeiro;   

    while(!finalLista(pLista)){
        
        int complex_real = pLista -> marcador -> real;
        int complex_imag = pLista -> marcador -> imag;

        base_dados << complex_real << " + " << complex_imag << "b" << endl; 
     

        pLista -> marcador = pLista -> marcador -> proximo;    
        
    } 
    base_dados.close();     
}

void le_arquivo(){

    ifstream input("BasedeDados.txt");
    string textoLido;    
    for(string line; getline(input, line);){
        textoLido += line;
    }
    
    cout << textoLido << endl;
    
}




int main(){

    tLista* complex = new tLista;

    string base;

    inicializaLista(complex);
    

    incluirNofim(complex, 2, 10);
    incluirNofim(complex, 100, 1);
    incluirNofim(complex, 20, 27);

    escreve_arquivo(complex);
    le_arquivo();

     
    //imprimirLista(complex);
    

     return 0;
}
