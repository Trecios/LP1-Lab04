#include <iostream>
#include "fila.h"

/**
 *@file main.cpp
 *@brief Programa cujo objetivo é a implementação de uma TAD 'fila cirular' utilizando artifícios como Herança de outros TAD como ListaLigada e ListaCircular.
 *@author Ailton Gabriel Figueira Dantas Ramos da Silva
 *@author Felipe Douglas Cavalcante Marinho de Vasconcelos
 *@since 20/05/2018
 *@date 28/05/2018
*/

int main()
{
	fila<int> fila;
	fila.InsereNoInicio(1);
	fila.InsereNoInicio(1);
	fila.InsereNoInicio(2);
	fila.InsereNoInicio(3);
	std::cout << fila << std::endl;
	fila.InsereNoFinal(3);
	fila.InsereNoFinal(2);
	fila.InsereNoFinal(1);
	fila.InsereNoFinal(1);
	std::cout << fila << std::endl;
	fila.RemoveNoInicio();
	std::cout << fila << std::endl;
	fila.RemoveNoInicio();
	std::cout << fila << std::endl;
	fila.RemoveNoFinal();
	std::cout << fila << std::endl;
	fila.RemoveNoFinal();
	std::cout << fila << std::endl;
	fila.RemoveNoFinal();
	fila.RemoveNoFinal();
	fila.RemoveNoFinal();
	std::cout << fila.isEmpty() << std::endl;
	fila.RemoveNoFinal();
	std::cout << fila.isEmpty() << std::endl;
	
	return 0;
}