/*
 * Vivienda.h
 *
 *  Created on: 26 may. 2022
 *      Author: diego
 */

#ifndef SRC_VIVIENDA_H_
#define SRC_VIVIENDA_H_

#define NOMBRE_LEN 25
#define ARRAY_LEN 200
#define REINTENTOS 3



typedef struct
{
	int idVivienda;
	char calle[NOMBRE_LEN];
	int cantidadPersonas;
	int cantidadHabitaciones;
	char tipoDeVivienda[NOMBRE_LEN];
	int legajoCensista;
	int isEmpty;

}Vivienda;

/**
 * \brief Inicializa el Array
 * \param pArray Array del viviendas al ser actualizado
 * \param limite Limite del array viviendas
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int vivi_inicializarArray(Vivienda* pArray, int limite);

/**
 * \brief Da de alta una vivienda en una posicion del array
 * \param pArray Array del viviendas al ser actualizado
 * \param limite Limite del array viviendas
  * \param indice Posicion a ser actualizada
 * \param id Identificacion a ser asignada a la vivienda
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int vivi_altaVivienda(Vivienda* pArray,int limite, int indice,int* id);

/**
 * \brief Imprime el array de viviendas
 * \param pElemento Puntero al producto que desea imprimir
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int vivi_imprimir(Vivienda* pElemento);
int vivi_imprimirArray(Vivienda* array, int limite);

/**
 * \brief Modifica los datos de una vivienda en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array viviendas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int vivi_modificarArray(Vivienda* array,int limite,int indice);

/**
 * \brief Actualiza una posicion del array
 * \param array Array de Viviendas a ser actualizado
 * \param limite Limite del array viviendas
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int vivi_bajaArray(Vivienda* array,int limite,int indice);

/**
 * \brief Busca un Id en el array y devuelve la posicion que encuentra
 * \param array Array de Vivienda a viviendas
 * \param limite Limite del array viviendas
 * \param valorBuscado Puntero a la posicion del array donde se encuentra el valor buscado
 * \return Retorna el indice de la posicion vacia y  -1 (ERROR) si no
 */
int vivi_buscarId(Vivienda* pArray, int limite,int valorBuscado);

/**
 * \brief Busca la primera posicion vacia
 * \param array Array de viviendas
 * \param limite Limite del array viviendas
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int vivi_getEmptyIndex(Vivienda* pArray, int limite);

/**
 * \brief Ordena el array de Viviendas por nombre de calle y por cantidad de personas
 * \param array Array de Viviendas
 * \param limite Limite del array viviendas
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int vivi_ordenarPorNombreOCantidadPersonas(Vivienda* array, int limite);

#endif /* SRC_VIVIENDA_H_ */
