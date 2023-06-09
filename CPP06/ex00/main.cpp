/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:30 by mbozzi            #+#    #+#             */
/*   Updated: 2023/06/09 13:27:45 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* In C++, ci sono quattro operatori di cast principali che possono essere utilizzati per convertire i valori da un tipo all’altro: static_cast, dynamic_cast, const_cast e reinterpret_cast.

static_cast viene utilizzato per le conversioni tra tipi correlati, come la conversione tra tipi di base (ad esempio, da int a float) o la conversione tra puntatori a classi derivate e base. Questo operatore esegue una conversione a tempo di compilazione e non esegue alcun controllo a runtime.

dynamic_cast viene utilizzato per le conversioni sicure tra puntatori a classi derivate e base. A differenza di static_cast, questo operatore esegue un controllo a runtime per verificare che l’oggetto puntato sia effettivamente di tipo compatibile con il tipo di destinazione. Se il controllo ha esito negativo, dynamic_cast restituisce un puntatore nullo.

const_cast viene utilizzato per rimuovere o aggiungere qualificatori const o volatile da una variabile. Questo operatore può essere utile quando si ha bisogno di passare un puntatore const a una funzione che accetta solo puntatori non costanti, ma si è sicuri che la funzione non modificherà l’oggetto puntato.

reinterpret_cast viene utilizzato per le conversioni a basso livello tra tipi di puntatore o di riferimento. Questo operatore consente di reinterpretare i bit di un puntatore come se fossero di un altro tipo. Tuttavia, l’utilizzo di questo operatore può essere pericoloso e dovrebbe essere evitato quando possibile.

In generale, l’utilizzo dei cast dovrebbe essere limitato il più possibile, poiché può nascondere errori nel codice e rendere il programma più difficile da comprendere e mantenere. Quando è necessario utilizzare i cast, è importante scegliere l’operatore di cast più appropriato per la situazione specifica. */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
	}
	else
		std::cout << "Insert param" << std::endl;
}