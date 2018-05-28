#include <iostream>
#include "pilha.h"
#include "lista.h"
#include <algorithm>

/**
 *@file main.cpp
 *@brief Programa para cálculo de expressões pós-fixas com ajuda do TAD Pilhas.
 *@author Ailton Gabriel Figueira Dantas Ramos da Silva
 *@author Felipe Douglas Cavalcante Marinho de Vasconcelos
 *@since 20/05/2018
 *@date 28/05/2018
*/

using std::string;
using std::cout;
using std::endl;

/**
 *@details Explicação: Primeiro o usuário entra com sua respectiva expressão pós-fixa.
 *Em seguida, é atribuído a uma variável inteira o tamanho da string entrrada. Depois, utilizando os artifícios da TAD Pilha, operando por operando é empilhado e desimpilhado
 *fazendo as respectivas operações até que o topo da Pilha tenha o resultado final da expressão. No qual, o mesmo é atribuído a uma string e impresso na tela.
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
	cout << "Entre com a expressão: " << endl;
	cout << "Obs.:Sempre utilize espaço entre números e operandos." << endl;
	string teste;
	getline(cin, teste);

	string conc = "";



	int aux = teste.length();

	



	Pilha<int> stack;
	
	for(int i = 0; i < aux; i++)
	{

			if(teste[i] == '+' || teste[i] == '-' || teste[i] == '/' || teste[i] == '*')
			{
				int b = stack.top();
				stack.pop();
				int a = stack.top();
				stack.pop();

				if(teste[i] == '+')
				{
					stack.push(a+b);
				}

				else if(teste[i] == '-')
				{
					stack.push(a-b);
				}

				else if(teste[i] == '/')
				{
					stack.push(a/b);
				}

				else
				{
					stack.push(a*b);
				}

			}


			else if(teste[i] != ' ')
			{ 	 
		    	conc += teste[i];
	     	}

	     	else if(teste[i] == ' ' && conc != "")
	    	{
	    		int valor = stoi(conc);
		    	stack.push(valor);
		    	conc = "";
	    	}


	     	
	
	}



	


	int result = stack.top();
	cout << "Resultado: " << result << endl;

	return 0;
	

}