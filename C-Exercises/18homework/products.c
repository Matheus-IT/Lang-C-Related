#include <stdio.h>

void clearBuffer() {
    while ((getchar()) != '\n');
}

typedef struct {
    char nome[40];
    float preco;
    float desconto; 
    float precoComDesconto;
} Produto;

void apresentarProduto(Produto p) {
    puts(" -------------------------- ");
    printf("%s - %.2f\n", p.nome, p.preco);
    printf("Preco com desconto %.2f\n", p.precoComDesconto);
}

void mostrarMaiorPreco(Produto prods[],  unsigned length) {
    Produto prodMaiorPreco = {.preco=prods[0].preco};

    for (int i = 1; i < length; i++) {
         if (prods[i].preco > prodMaiorPreco.preco)
            prodMaiorPreco = prods[i]; 
    } 
    puts("Produto que teve o maior preco foi:");
    printf("%s - %.2f\n", prodMaiorPreco.nome, prodMaiorPreco.preco);
}

int main() {
    unsigned numOfProd;

    printf("Quantos produtos deseja armazenar? ");
    scanf(" %d", &numOfProd);

    if (numOfProd <= 0)
        return 0;

    Produto produtos[numOfProd];

    for (int i = 0; i < numOfProd; i++) {
        printf("Nome do produto: ");
        scanf(" %s", produtos[i].nome);

        printf("Preco do produto: ");
        scanf(" %f", &produtos[i].preco);
        clearBuffer();
        
        printf("Desconto(em %%): ");
        scanf(" %f", &produtos[i].desconto);
        produtos[i].desconto = (produtos[i].desconto / 100) * produtos[i].preco;
        clearBuffer();
        printf("\n");

        // calcular desconto
        produtos[i].precoComDesconto = produtos[i].preco - produtos[i].desconto;
    }

    for (int i = 0; i < numOfProd; i++) {
        apresentarProduto(produtos[i]);
    }

    mostrarMaiorPreco(produtos, numOfProd);
    return 0;
}
