/*
 * Vivienda.c
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



int vivi_inicializarArray(Vivienda* pArray, int limite)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL && limite >0)
	{
		for (i = 0; i < limite; i++)
		{
			pArray[i].isEmpty = 1;
			retorno=0;
		}
	}
	return retorno;
}

int vivi_altaVivienda(Vivienda* pArray,int limite, int indice, int* id)
{
	int retorno=-1;
	Vivienda viviendaAux;
	int opcionVivienda;

	if(pArray !=NULL && limite >0 && indice >=0 && indice < limite && id!=NULL )
	{
		if(utn_getNombre(viviendaAux.calle, "Ingrese el nombre de la calle:\n", "ERROR, Vuelva a intentarlo: \n", NOMBRE_LEN, REINTENTOS)==0 &&

			utn_getNumero(&viviendaAux.cantidadPersonas, "\nIngrese la cantidad personas que viven en la vivienda: \n", "ERROR, vuelva a intentarlo: \n", 1, 50, REINTENTOS)==0 &&

			utn_getNumero(&viviendaAux.cantidadHabitaciones, "\nIngrese la cantidad de habitaciones que tiene la vivienda: \n", "ERROR, vuelva a intentarlo: \n", 1, 30, REINTENTOS)==0 &&

			utn_getNumero(&opcionVivienda, "\nIngrese la una opcion para el tipo de vivienda : \n"
										"1-CASA\n"
										"2-DEPARTAMENTO\n"
										"3-CASILLA\n"
										"4-RANCHO\n", "ERROR, vuelva a intentarlo: \n", 1, 4, REINTENTOS)==0)

					{
						switch (opcionVivienda)
						{
							case 1:
								strncpy(viviendaAux.tipoDeVivienda,"CASA",NOMBRE_LEN);

								break;
							case 2:
								strncpy(viviendaAux.tipoDeVivienda,"DEPARTAMENTO",NOMBRE_LEN);
								break;
							case 3:
								strncpy(viviendaAux.tipoDeVivienda,"CASILLA",NOMBRE_LEN);

								break;

							default:
								strncpy(viviendaAux.tipoDeVivienda,"RANCHO",NOMBRE_LEN);
								break;
						}
					}


					if(utn_getNumero(&viviendaAux.legajoCensista, "Ingrese su numero de legajo: \n", "ERROR, vuelva a intentarlo: \n",100,102, REINTENTOS)==0)
					{
						if(viviendaAux.legajoCensista == 100 || viviendaAux.legajoCensista == 101 || viviendaAux.legajoCensista == 102 )
						{


						viviendaAux.idVivienda=*id;
						viviendaAux.isEmpty=0;
						pArray[indice]=viviendaAux;
						(*id)++;
						retorno=0;
						}
					}
	}
	return retorno;
}


int vivi_imprimir(Vivienda* pElemento)
{
	int retorno=-1;
	if(pElemento!= NULL && pElemento ->isEmpty==0)
	{
		printf("\nidVivienda: %d\n"
				"Calle: %s\n"
				"Cantidad de personas: %d\n "
				"Cantidad de habitaciones: %d\n"
				"Tipo de vivienda: %s\n"
				"Legajo del censista: %d\n",pElemento->idVivienda,pElemento->calle,pElemento->cantidadPersonas,pElemento->cantidadHabitaciones,pElemento->tipoDeVivienda,pElemento->legajoCensista);
		retorno=0;

	}


	return retorno;
}

int vivi_imprimirArray(Vivienda* array, int limite)
{
	int retorno=-1;
	int i;


	if(array!=NULL && limite >0)
	{
		retorno=0;
		for (i = 0; i < limite; i++)
		{
			vivi_imprimir(&array[i]);
		}

	}
	return retorno;
}


int vivi_modificarArray(Vivienda* array,int limite,int indice)
{
	Vivienda viviendaAux;
	int retorno=-1;
	int menuOp;
	int opVivienda;


		if(array !=NULL && limite >0 && indice >=0 && indice < limite && array[indice].isEmpty==0 )
		{

				if(utn_getNumero(&menuOp, "				\n\n     \n\n"
													"1-MODIFICAR CALLE\n"
													"2-MODIFICAR CANTIDAD DE PERSONAS\n"
													"3-MODIFICAR CANTIDAD DE HABITACIONES\n"
													"4-MODIFICAR TIPO DE VIVIENDA\n", "ERROR,tiene que elegir una opcion(1-5-)\n", 1, 5, 3)==0)
					{
						switch (menuOp)
						{
							case 1:
								printf("**********MODIFICAR LA CALLE*******\n\n");

								if(utn_getNombre(viviendaAux.calle, "Ingrese el nombre de la calle:\n", "ERROR, Vuelva a intentarlo: \n", NOMBRE_LEN, REINTENTOS)==0)
								{

									printf("Se realizo la modificacion con exito \n\n");
								}


								break;
							case 2:
								printf("**********MODIFICAR CANTIDAD DE PERSONAS*******\n\n");

								if(utn_getNumero(&viviendaAux.cantidadPersonas, "Ingrese la cantidadde personas que viven en la vivienda: \n", "ERROR, vuelva a intentarlo: \n", 1, 50, REINTENTOS)==0)
								{
									printf("Se realizo la modificacion con exito \n\n");
								}

								break;
							case 3:
								printf("**********MODIFICAR CANTIDAD DE HABITACIONES*******\n\n");

								if(utn_getNumero(&viviendaAux.cantidadHabitaciones, "Ingrese la cantidad de habitaciones que tiene la vivienda: \n", "ERROR, vuelva a intentarlo: \n", 1, 30, REINTENTOS)==0)
								{
									printf("Se realizo la modificacion con exito \n\n");
								}
								break;
							case 4:
								printf("**********MODIFICAR TIPO DE VIVIENDA*******\n\n");
								if(utn_getNumero(&opVivienda, "Ingrese la una opcion para el tipo de vivienda : \n"
										"1-CASA\n"
										"2-DEPARTAMENTO\n"
										"3-CASILLA\n"
										"4-RANCHO\n", "ERROR, vuelva a intentarlo: \n", 1, 4, REINTENTOS)==0)
								{
									switch (opVivienda)
									{
										case 1:
											strncpy(viviendaAux.tipoDeVivienda,"CASA",NOMBRE_LEN);

											break;
										case 2:
											strncpy(viviendaAux.tipoDeVivienda,"DEPARTAMENTO",NOMBRE_LEN);
											break;
										case 3:
											strncpy(viviendaAux.tipoDeVivienda,"CASILLA",NOMBRE_LEN);

											break;

										default:
											strncpy(viviendaAux.tipoDeVivienda,"RANCHO",NOMBRE_LEN);
											break;
									}
									printf("Se realizo la modificacion con exito \n\n");
								}

								break;

							default:
								printf("\n\n   *********************************   \n\n");
								break;
						}
					}
								viviendaAux.idVivienda= array[indice].idVivienda;
								viviendaAux.isEmpty=0;
								array[indice]=viviendaAux;
								retorno=0;

		}
		return retorno;
}

int vivi_bajaArray(Vivienda* array,int limite,int indice)
{
	int retorno=-1;

	if(array !=NULL && limite >0 && indice >=0 && indice < limite && array[indice].isEmpty==0 )
	{
		array[indice].isEmpty=1;
		retorno=0;
	}


	return retorno;
}

int vivi_buscarId(Vivienda* pArray, int limite,int valorBuscado)
{
	int retorno=-1;
		int i;
		if(pArray!=NULL && limite >0 && valorBuscado >=0)
		{
			for (i = 0; i < limite; i++)
			{
				if(pArray[i].idVivienda== valorBuscado)
				{
					retorno=i;
					break;
				}
			}
		}
		return retorno;
}

int vivi_getEmptyIndex(Vivienda* pArray, int limite)
{
	int retorno=-1;
			int i;
			if(pArray!=NULL && limite >0)
			{
				for (i = 0; i < limite; i++)
				{
					if(pArray[i].isEmpty==1 )
					{
						retorno=i;
						break;
					}
				}
			}
			return retorno;

}

int vivi_ordenarPorNombreOCantidadPersonas(Vivienda* array, int limite)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Vivienda buffer;
	if(array!=NULL && limite >0)
	{
		do
		{
			flagSwap=0;
			for ( i = 0;  i < limite; i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].calle,array[i+1].calle,NOMBRE_LEN) < 0 ||
				  (strncmp(array[i].calle,array[i+1].calle,NOMBRE_LEN) == 0 &&
				  array[i].cantidadPersonas < array[i+1].cantidadPersonas))
				{
					buffer= array[i];
					array[i]=array[i+1];
					array[i+1]=buffer;
					flagSwap=1;
				}
			}

			limite--;

		}while(flagSwap);
	}

	return retorno;
}
