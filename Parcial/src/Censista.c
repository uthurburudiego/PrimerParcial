/*
 * Censista.c
 *
 *  Created on: 26 may. 2022
 *      Author: diego
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Vivienda.h"
#include "Censista.h"


int cen_imprimirArray(Censista* array, int limite)
{
	int retorno=-1;
	int i;


	if(array!=NULL && limite >0)
	{
		retorno=0;
		for (i = 0; i < limite; i++)
		{
			cen_imprimir(&array[i]);
		}

	}
	return retorno;
}

int cen_imprimir(Censista* pElemento)
{
	int retorno=-1;
	if(pElemento!= NULL && pElemento)
	{
		printf("\nNumero de legajo: %d\n"
				"Nombre: %s\n"
				"Edad: %d\n"
				"Telefono: %s\n",pElemento->legajoCensista,pElemento->nombre,pElemento->edad,pElemento->telefono);

		retorno=0;

	}




	return retorno;
}
