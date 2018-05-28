#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <memory>
#include "lista.h"

/**@brief Implementação da classe ListaCirular a qual utiliza do artíficio de herança para herdar atibutos e métodos da classe 'ListaLigada'.
*/
template <typename T>
class circular : public ListaLigada<T>
{
	public:
		circular();
		~circular();
		bool InsereNoInicio(T _value);
		bool InsereNoFinal(T _value);
		bool RemoveNoInicio();
		bool RemoveNoFinal();
		bool isEmpty();
};

/**@brief Construtor padrão não-parametrizado.
*/
template <typename T>
circular<T>::circular() {}

/**@brief Destrutor padrão.
*/
template <typename T>
circular<T>::~circular() {}

/**@brief Implementação do método InsereNoInicio levando em conta que é uma ListaCircular.
*/
template <typename T>
bool circular<T>::InsereNoInicio(T _value)
{
	auto toInsert = make_shared<Node<T>>(_value);
	if (!toInsert) return false;
	if(isEmpty())
	{
		toInsert->setNext(toInsert);
		this->cauda = toInsert;
		this->tamanho++;
		return true;
	}

	toInsert->setNext(this->cauda->getNext());
	this->cauda->setNext(toInsert);
	this->tamanho++;
	return true;
}

/**@brief Implementação do método InsereNoFinal levando em conta que é uma ListaCircular.
*/

template <typename T>
bool circular<T>::InsereNoFinal(T _value)
{
	auto toInsert = make_shared<Node<T>>(_value);
	if (!toInsert) return false;
	if(isEmpty())
	{
		InsereNoInicio(_value);
	}

	toInsert->setNext(this->cauda->getNext());
	this->cauda->setNext(toInsert);
	this->cauda = toInsert;
	this->tamanho++;
	return true;
}

/**@brief Implementação do método RemoveNoInicio levando em conta que é uma ListaCircular.
*/

template <typename T>
bool circular<T>::RemoveNoInicio()
{
	auto toRemove = this->cauda->getNext();
	if(!toRemove) return false;
	if(isEmpty())
	{
		return true;
	}

	this->cauda->setNext(toRemove->getNext());
	toRemove->setNext(nullptr);
	this->tamanho--;
	return true;
}

/**@brief Implementação do método RemoveNoFinal levando em conta que é uma ListaCircular.
*/

template <typename T>
bool circular<T>::RemoveNoFinal()
{
	auto pen = this->cauda->getNext();
	if(!pen) return false;
	if(isEmpty())
	{
		return true;
	}

	while(pen->getNext() != this->cauda)
	{
		pen = pen->getNext();
	}

	pen->setNext(this->cauda->getNext());
	this->cauda->setNext(nullptr);
	this->cauda = pen;
	this->tamanho--;
	return true;
}

/**@brief Método IsEmpty que retorna 'true' se a lista estiver vazia ou 'false' se não estiver.
*/
template <typename T>
bool circular<T>::isEmpty()
{
	if(this->tamanho == 0)
	{
		return true;
	}

	return false;
}

#endif