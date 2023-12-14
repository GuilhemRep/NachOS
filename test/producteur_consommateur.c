#include <libnachos.h>

Semaphore sema = Semaphore("sema", 10);

int tab[10];
int i = 0;


void producteur() {
    int x = 0;
    while (true) {
        sema.V();
        i = 1 + i % 10;
        x += 1;
        tab[i] = x;
        sema.P();
    }
}


void consommateur() {
    while (true) {
        sema.V();
        print(tab[i]);
        sema.P();
    }
}




int main() {
    Thread Producteur("Producteur");
    Thread Consommateur("Consommateur");

    Producteur.Fork(producteur, 0);
    Consommateur.Fork(consommateur, 0);
    return 0;
}