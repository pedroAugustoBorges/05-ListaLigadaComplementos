#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL){
		cout << "Erro ao alocar memoria";
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;

	novo->prox = NULL;

	if (primeiro == NULL || novo-> valor < primeiro-> valor) {
		novo->prox = primeiro;
		primeiro = novo;
		return;
	}

	NO* atual = primeiro;
	NO* anterior = NULL;

	while (atual != NULL && atual->valor < novo->valor) {
		anterior = atual;

		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == novo->valor) {
		cout << "Valor já existe na memoria";
	}

	anterior -> prox = novo;
	novo->prox = atual;




}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia, impossivel excluir";
		return;
	}


	int valorAExcluir = 0;

	cout << "Insira o valor a excluir";

	cin >> valorAExcluir;

	NO* atual = primeiro;

	NO* anterior = NULL;


	while (atual->prox != NULL && atual ->valor <  valorAExcluir) {

		anterior = atual;
		atual = atual->prox;
	}

	if (atual == NULL && atual -> valor != valorAExcluir) {
		cout << "Elemento nao encontrado";
	}

	if (anterior == NULL) {
		primeiro = atual->prox;
	}
	else {
		anterior->prox = atual->prox;
		free(atual);
		cout << "Elemento excluido";
	}

}

void buscarElemento()
{
	NO* atual = primeiro;

	int	elementoABuscar = 0;

	cout << "Insira o elemento a ser buscado";

	cin >> elementoABuscar;

	while (atual != NULL ) {

		if (atual->valor == elementoABuscar) {
			cout << "Elemento encontrado";
			return;
		}

		if (atual->valor > elementoABuscar) {
			cout << "Elemento nao encontrado, passamos do valor";
			return;
		}

		atual = atual->prox;
	
	}
	
	cout << "Elemento nao encontrado" << endl;


}


