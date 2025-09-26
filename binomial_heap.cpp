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

    
    void insert(int valor){
        Nodo* nuevo_nodo = new Nodo(valor);
        insert(nuevo_nodo);
    }
    void insert(Nodo* nuevo_nodo){
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

    int extractMin() {
        // Buscar el nodo raíz con el valor mínimo
        int minIndex = -1;
        int minValue = INT_MAX;
        for (int i = 0; i < raices.size(); ++i) {
            if (raices[i] && raices[i]->data < minValue) {
                minValue = raices[i]->data;
                minIndex = i;
            }
        }
        if (minIndex == -1) throw std::out_of_range("Heap vacío");

        Nodo* minNode = raices[minIndex];
        raices[minIndex] = nullptr;

        // Reinsertar los hijos del nodo mínimo como nuevos árboles
        Nodo* child = minNode->hijo;
        std::vector<Nodo*> children;
        while (child) {
            Nodo* siguiente = child->hermano;
            child->padre = nullptr;
            child->hermano = nullptr;
            children.insert(children.begin(), child); // Insertar al inicio para mantener el orden
            child = siguiente;
        }
        for (Nodo* c : children) {
            insert(c);
        }

        int result = minNode->data;
        delete minNode;
        return result;
    }
};
