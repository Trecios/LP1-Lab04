#ifndef FILA_H
#define FILA_H

#include <iostream>
#include "circular.h"

template <typename T> class fila;
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, fila<T> const & );

/**@brief Implementação da TAD FilaCircular que utiliza Herança para herdar os artifícios da ListaCirular.
*/

template <typename T>
class fila : public circular<T>
{
	public:
		fila();
		~fila();
		friend std::ostream& operator<< <T>( std::ostream&, fila<T> const & );
};

/**@brief Construtor padrão não-parametrizado.
*/
template <typename T>
fila<T>::fila() {}

/**@brief Destrutor padrão.
*/

template <typename T>
fila<T>::~fila() {}

/**@brief Sobrecarga do operador de inserção.
*/

template <typename T>
std::ostream& operator<< ( std::ostream& o, fila<T> const &l) {
	auto atual = l.cauda->getNext();
	for(int i = 0; i < l.tamanho; i++) {
		o << atual->getValor() << " ";
		atual = atual->getNext();
	}
	return o;
}

#endif