#include <iostream>

struct No {
    int data;
    No* next;
};

No* criarNo(int data) {
    No* novoNo = new No;
    novoNo->data = data;
    novoNo->next = NULL;
    return novoNo;
}

void inserirNoInicio(No*& head, int data) {
    No* novoNo = criarNo(data);
    novoNo->next = head;
    head = novoNo;
}

using namespace std;
void mostrarLista(No* head) {
    No* atual = head;
    while (atual != NULL) {
        cout << atual->data << " -> ";
        atual = atual->next;
    }
    cout << "NULL" << endl;
}

No* reverterIntervalo(No* head, int inicio, int fim) {
    if (head == NULL || inicio >= fim) {
        return head;
    }

    No* auxiliar = criarNo(0);
    auxiliar->next = head;
    No* preInicio = auxiliar;

    for (int i = 0; i < inicio - 1; i++) {
        preInicio = preInicio->next;
    }

    No* inicioIntervalo = preInicio->next;
    No* proximo = NULL;

    for (int i = 0; i < fim - inicio + 1; i++) {
        No* temp = inicioIntervalo->next;
        inicioIntervalo->next = proximo;
        proximo = inicioIntervalo;
        inicioIntervalo = temp;
    }

    preInicio->next->next = inicioIntervalo;
    preInicio->next = proximo;

    No* novaHead = auxiliar->next;
    delete auxiliar;

    return novaHead;
}

using namespace std;
int main() {
    No* lista = NULL;

    inserirNoInicio(lista, 50);
    inserirNoInicio(lista, 40);
    inserirNoInicio(lista, 30);
    inserirNoInicio(lista, 20);
    inserirNoInicio(lista, 10);

    cout << "Lista original:" << endl;
    mostrarLista(lista);

    int inicio = 2;
    int fim = 4;

    lista = reverterIntervalo(lista, inicio, fim);

    cout << "Lista revertida:" << endl;
    mostrarLista(lista);

	system("pause");
    return 0;
}

