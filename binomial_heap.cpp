#include <vector>

struct Nodo {
    int data, grado;
    Nodo* padre, * hijo, * hermano;

    Nodo(int valor){
        data = valor;
        grado = 0;
        padre = hijo = hermano = nullptr;
    }
};

class BinomialHeap {
    private:
    std::vector<Nodo*> raices = {nullptr};
    int max = 0;

    Nodo* unir(Nodo* a, Nodo* b) {
    if (a->data > b->data) std::swap(a, b);
    b->padre = a;
    b->hermano = a->hijo;
    a->hijo = b;
    a->grado++;
    return a;
}

    public:
    BinomialHeap(void){
    }

    void insert_Nodo(Nodo* nuevo_nodo){
        int temp = 0;
        Nodo* raiz = nuevo_nodo; // raiz del sub binomial heap actual
        while(true){
            if (raices.size() <= temp){
                raices.resize(temp + 1, nullptr);
            }

            if (raices[temp] == nullptr) {
                raices[temp] = raiz;
                break;
            } else {
                raiz = unir(raices[temp], raiz);
                raices[temp] = nullptr;
                temp++;
            }
        }
    }
};
