/*
 ============================================================================
 Name        : Ejercicio5.c
 Author      : Diego Uthurburu
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Vivienda.h"
#include "Censista.h"




int main(void)
{

	setbuf(stdout, NULL);


	Vivienda viviendas[ARRAY_LEN];
	Censista censistas[CENSISTA_LEN];
	int auxiliarIndice;
	int menuOpcion;
	int flagDelPrimero=0;

	vivi_inicializarArray(viviendas, ARRAY_LEN);

// HARCODEAMOS LOS DATOS DE LOS CENSISTAS
	censistas[0].legajoCensista=100;
	censistas[1].legajoCensista=101;
	censistas[2].legajoCensista=102;

	strncpy(censistas[0].nombre,"Ana",NOMBRE_LEN);
	strncpy(censistas[1].nombre,"Juan",NOMBRE_LEN);
	strncpy(censistas[2].nombre,"Sol",NOMBRE_LEN);

	censistas[0].edad=34;
	censistas[1].edad=24;
	censistas[2].edad=47;

	strncpy(censistas[0].telefono," 1203-2345",NOMBRE_LEN);
	strncpy(censistas[1].telefono,"4301-54678",NOMBRE_LEN);
	strncpy(censistas[2].telefono,"5902-37487",NOMBRE_LEN);





do
{
	if(utn_getNumero(&menuOpcion, "\n\n     *********MENU PRINCIPAL********\n\n"
									"1-ALTA DE VIVIENDA\n"
									"2-MODIFICAR VIVIENDA\n"
									"3-BAJA VIVIENDA\n"
									"4-LISTAR VIVIENDAS\n"
									"5-LISTAR CENSISTAS\n"
									"6-SALIR\n", "ERROR,tiene que elegir una opcion(1-6-)\n", 1, 6, 3)==0)
	{
		switch (menuOpcion)
		{
			case 1:
				printf("**********ALTA DE VIVIENDA*******\n\n");

					auxiliarIndice=vivi_getEmptyIndex(viviendas, ARRAY_LEN);
					vivi_altaVivienda(viviendas, ARRAY_LEN,auxiliarIndice,&viviendas->idVivienda);
					flagDelPrimero=1;

				break;
			case 2:
				if(flagDelPrimero==1)
				{
					utn_getNumero(&viviendas->idVivienda, "\nIngrese el numero de Id: \n", "ERROR, Ingrese nuevamente:\n", 1, ARRAY_LEN,REINTENTOS);

						printf("**********MODIFICAR VIVIENDA*******\n\n");

						vivi_modificarArray(viviendas, ARRAY_LEN, auxiliarIndice);

						printf("La modificacion se realizo con exito \n\n");

				}
				else
				{
					printf("Primero debe dar de alta una vivienda.\n\n");
				}
				break;
			case 3:
				if(flagDelPrimero==1)
				{
					printf("**********BAJA VIVIENDA*******\n\n");

					vivi_bajaArray(viviendas, ARRAY_LEN, auxiliarIndice);
					printf("La baja se realizo con exito \n\n");
				}
				else
				{
					printf("Primero debe dar de alta una vivienda.\n\n");
				}
				break;
			case 4:
				if(flagDelPrimero==1)
				{
					printf("**********LISTAR VIVIENDAS*******\n\n");

					vivi_ordenarPorNombreOCantidadPersonas(viviendas, ARRAY_LEN);
					vivi_imprimirArray(viviendas, ARRAY_LEN);
				}else
				{
					printf("Primero debe dar de alta una vivienda.\n\n");
				}

				vivi_ordenarPorNombreOCantidadPersonas(viviendas, ARRAY_LEN);
				vivi_imprimirArray(viviendas, ARRAY_LEN);

				break;
			case 5:
				printf("**********LISTAR CENSISTAS*******\n\n");

					cen_imprimirArray(censistas, CENSISTA_LEN);
				break;

			default:
				printf("********MUCHAS GRACIAS POR UTILIZAR MI SOFTWARE******** \n\n");
				break;
		}
	}

}while(menuOpcion!=6);
















	return EXIT_SUCCESS;
}

