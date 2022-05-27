/*
 * Censista.h
 *
 *  Created on: 26 may. 2022
 *      Author: diego
 */

#ifndef SRC_CENSISTA_H_
#define SRC_CENSISTA_H_
#define CENSISTA_LEN 3

typedef struct
{
	int legajoCensista;
	char nombre[NOMBRE_LEN];
	int edad;
	char telefono[NOMBRE_LEN];


}Censista;

/**
 * \brief Imprime el array de viviendas
 * \param pElemento Puntero al producto que desea imprimir
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int cen_imprimir(Censista* pElemento);
int cen_imprimirArray(Censista* array, int limite);



#endif /* SRC_CENSISTA_H_ */
