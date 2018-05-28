#include <iostream>
#include "pilha.h"
#include "lista.h"
#include <algorithm>

/**
 *@file main.cpp
 *@brief Programa para verificar se palavras são palíndromos com a ajuda do TAD Pilha
 *@author Ailton Gabriel Figueira Dantas Ramos da Silva
 *@author Felipe Douglas Cavalcante Marinho de Vasconcelos
 *@since 20/05/2018
 *@date 28/05/2018
*/

using namespace std;

using std::string;
using std::cout;
using std::endl;

/**
 * @details Explicação: Primeiro, o usuário entra com sua string.
 * Em seguida, é calculado o tamanho dessa string e caractere por caractere são empilhhados em uma pilha de 'char'.
 * Com a ajuda de um contador, o primeiro até o último caractere da string é comparado com o topo até o final da pilha.
 * Se este contador no final da iteração for igual ao tamanho da string, então a string é um palíndromo.
*/
int main(int argc, char const *argv[])
{
/*
	Pilha<int> pilha;
	cout << "Tamanho: " << pilha.size() << endl;
	pilha.push(10);
	pilha.push(15);
	pilha.push(20);
	cout << pilha.top() << endl;
	pilha.pop();
	cout << "Tamanho: " << pilha.size() << endl;
	cout << pilha.top() << endl;
	pilha.pop();
	cout << pilha.top() << endl;
	pilha.pop();

	cout << "Testando a lista..." << endl;

	ListaLigada<int> lista1;
	cout << "Tamanho: " << lista1.size() << endl;
	lista1.InsereNoFinal(2);
	lista1.InsereNoFinal(3);
	lista1.InsereNoFinal(4);
	lista1.InsereNaPosicao(0,1);
	lista1.InsereNoFinal(6);
	lista1.InsereNaPosicao(4,5);
	lista1.InsereNoFinal(7);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNaPosicao(3);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoInicio();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoFinal();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
*/
	cout << "Entre com a string: " << endl;
	string valor;
	getline(cin, valor);
	
	
	transform(valor.begin(), valor.end(), valor.begin(),::tolower);

	int contador = 0;


	int aux = valor.length();

	Pilha<char> stack;

	for(int i = 0; i < aux; i++)  
	{
		stack.push(valor[i]);
	}

	for(int i = 0; i < aux; i++)   
	{
		if(valor[i] == stack.top())
		{
			contador++;        
			stack.pop();
		}
		

	}

	if(contador == aux)    
	{
		cout << "É palíndromo!" << endl;
	}


	else
	{
		cout << "Não é palíndromo!" << endl;
	}

}