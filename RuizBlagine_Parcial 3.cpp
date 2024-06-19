//TEMA 1 (Abril de los Angeles Ruiz Blagine)
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TAMANIO 50

// Estrategia de Solución
/*
	Estructura Ascendente

	----Funciones
	1. Menu_Opciones()
	2. Cargar_Catalogo()
	3. IngresarCalcular_Compra()
	
	4.Total_Vendido()
	5.CatProd_MasVendido()
	6.MontoProm_LineaBlanca() 
	
	
	----Función MAIN
	1. Inicializar variables
	2. Preguntar
	3. Bucle While
		3.1. Se muestra menu de opciones.
			3.1.1. Cargar catálogo de productos
			3.1.2. Ingresar datos de compra
			3.1.3. Salir
		3.2. Se procesan datos en funciones (a, b, c, factura)
		3.3. Se muestran en pantalla los resultados procesados (factura)
	4. Se muestran en pantalla resultados finales (a, b, c)

*/

void Menu_Opciones(int *Op){
	int Opcion;
	
	do{
		printf("----------------------\n      MENU\n---------------------- \n");
		printf("\n(1) Cargar catalogo de productos \n(2) Ingresar y Calcular datos de compra \n(3) Salir \n");
		scanf("%d", &Opcion);
	}while((Opcion < 1)&&(Opcion >3));
	
	*Op = Opcion;
}


void Cargar_Catalogo(int Arr_CodProd[TAMANIO], char Arr_CatProd[TAMANIO], char Arr_DescProd[TAMANIO][TAMANIO], float Arr_PrecioUnit[TAMANIO], int *Op1_Contador){
	int CodProd;
	char CatProd;
	char DescProd[TAMANIO];
	float PrecioUnit;
	
	//Se ingresan y validan datos
	do{
		printf("\nIngrese el codigo del producto (numerico): ");
		scanf("%d", &CodProd);
	}while(CodProd < 0); //No llegue a hacer la validacion para que el codigo ingresado no se repita :(

	do{
		printf("\n-----------\n  CATEGORIA\n-----------");
		printf("\n(L) Linea Blanca\n(P) Pequenios electrodomesticos\n(E) Electrodomesticos \n");
		scanf(" %c", &CatProd);
		while(getchar()!='\n');
	}while((CatProd!='L')&&(CatProd!='P')&&(CatProd!='E'));

	printf("Ingrese una descripcion del producto: ");
	scanf(" %s", &DescProd);

	do{
		printf("Ingrese el valor unitario del producto: ");
		scanf("%f", &PrecioUnit);
	}while(PrecioUnit < 0);
	
	//Se almacenan datos en vectores
	Arr_CodProd[*Op1_Contador] = CodProd;
	Arr_CatProd[*Op1_Contador] = CatProd;
	Arr_DescProd[TAMANIO][*Op1_Contador] = DescProd[TAMANIO];
	Arr_PrecioUnit[*Op1_Contador] = PrecioUnit;
	
	(*Op1_Contador)++;
}

void IngresarCalcular_Compra(float Arr_CostoL[TAMANIO], float Arr_Costo[TAMANIO], int Arr_CodProd[TAMANIO], char Arr_CatProd[TAMANIO], char Arr_DescProd[TAMANIO][TAMANIO], float Arr_PrecioUnit[TAMANIO], int Arr_CantUnits[TAMANIO], int *Op2_Contador){
	int i, Valid = 0;
	int PosicionValid;
	
	int CodProd;
	int CantUnits;
	float CostoTot;
	
	
	//Se ingresan y validan datos
	
	
	do{ //Si el codigo ingresado no se encuentra en la base de datos, se le pedira nuevamente al usuario que ingrese el codigo del producto.
		do{
			printf("\nIngrese el codigo del producto (numerico): ");
			scanf("%d", &CodProd);
		}while(CodProd < 0);
	
		for(i = 0; i < TAMANIO; i++){
			if(Arr_CodProd[i] == CodProd){
				Valid = 1;
				PosicionValid = i;
			}
			else{
				Valid = 0;
			}
		}
	}while(Valid != 0);
	
	do{
		printf("\nIngrese la cantidad de unidades compradas: ");
		scanf("%d", &CantUnits);
	}while(CantUnits < 0);	
	
	//Se almacenan datos en los vectores
	Arr_CantUnits[*Op2_Contador] = CantUnits;
	
	//Se calcula el valor de la compra
	CostoTot = Arr_PrecioUnit[PosicionValid] * CantUnits;
	Arr_Costo[*Op2_Contador] = CostoTot;
	
	switch(Arr_CatProd[PosicionValid]){
		case 'L':{
			Arr_CostoL[*Op2_Contador] = CostoTot;
			break;
		}
	}
	
	//Se incrementa el contador
	(*Op2_Contador)++;
	
	system("cls");
	
	//Se muestra la factura en pantalla
	printf("\n-----------\n  FACTURA\n-----------");
	printf("\n Nro Factura %d\n Descripcion del producto: %s\n Categoria del producto: %c\n Monto a pagar: %.2f\n", *Op2_Contador, Arr_DescProd[TAMANIO][PosicionValid], Arr_CatProd[PosicionValid], Arr_Costo[*Op2_Contador - 1]);
}

void Total_Vendido(char Arr_CatProd[TAMANIO], float Arr_Costo[TAMANIO], int Arr_CantUnits[TAMANIO], int *CantUnits_LB, int *CantUnits_PE, int *CantUnits_E, float *MontoTot_LB, float *MontoTot_PE, float *MontoTot_E){
	int i;
	
	for(i = 0; i < TAMANIO; i++){
		switch(Arr_CatProd[i]){
			case 'L':{
				*CantUnits_LB = *CantUnits_LB + Arr_CantUnits[i];
				*MontoTot_LB = *MontoTot_LB + Arr_Costo[i];
				break;
			}
			case 'P':{
				*CantUnits_PE = *CantUnits_PE + Arr_CantUnits[i];
				*MontoTot_PE = *MontoTot_PE + Arr_Costo[i];
				break;
			}
			case 'E':{
				*CantUnits_E = *CantUnits_E + Arr_CantUnits[i];
				*MontoTot_E = *MontoTot_E + Arr_Costo[i];
				break;
			}
		}
	}
}
void CatProd_MasVendido(char Arr_CatProd[TAMANIO], int Arr_CantUnits[TAMANIO], char *MasVendido){
	int i, flag = 0;
	int PosicionMax, ValorMax;
	
	for(i = 0; i < TAMANIO; i++){
		if(flag == 0){
			PosicionMax = i;
			ValorMax = Arr_CantUnits[i];
			flag = 1;
		}else if(Arr_CantUnits[i] > ValorMax){
			PosicionMax = i;
			ValorMax = Arr_CantUnits[i];
		}
	}
	
	*MasVendido = Arr_CatProd[PosicionMax];
}
void MontoProm_LineaBlanca(float Arr_CostoL[TAMANIO], float *MontoProm_LB){
	int i, monto;
	
	for(i = 0; i < TAMANIO; i++){
		monto = monto + Arr_CostoL[i];
	}
	
	*MontoProm_LB = monto / TAMANIO;
}

int main(){
	
	//--Variables de entrada
	int Op;//Recibirá el valor de la opcion seleccionada por el usuario
	
	//--Variables de salida
	//PUNTO A
	int CantUnits_LB = 0;	 
	int CantUnits_PE = 0; 
	int CantUnits_E = 0;
	float MontoTot_LB = 0; 
	float MontoTot_PE = 0; 
	float MontoTot_E = 0;
	
	//PUNTO B
	char MasVendido = 0;
	
	//PUNTO C
	float Arr_CostoL[TAMANIO] = {0};
	float MontoProm_LB = 0;
	
	//--Variables auxiliares
	int Op1_Contador = 0;
	int Op2_Contador = 0;
	
	//Vectores Cargar Catálogo
	int Arr_CodProd[TAMANIO] = {0};
	char Arr_CatProd[TAMANIO] = {0};
	char Arr_DescProd[TAMANIO][TAMANIO] = {0};
	float Arr_PrecioUnit[TAMANIO] = {0};
	
	//Vectores Ingresar y Calcular datos de compra
	int Arr_CantUnits[TAMANIO] = {0};
	float Arr_Costo[TAMANIO] = {0};
	
	//RTA
	char RTA[2];
	
	//Preguntar
	do{
		printf("Desea iniciar el programa? SI/NO: ");
		scanf(" %s", &RTA);
		while(getchar()!='\n');
	}while((strcmp(RTA, "SI")!=0)&&(strcmp(RTA, "NO")!=0));
	
	if(strcmp(RTA, "NO")==0){
		printf("Apagando programa...");
		Sleep(2000);
	}
	
	system("cls");
	
	//Bucle While
	while(strcmp(RTA, "SI")==0){
		//Se muestra el menú en pantalla
		Menu_Opciones(&Op);
		
		//En base a la opción seleccionada se ejecuta una función distinta
		switch(Op){
			case 1:{
				if(Op1_Contador >= TAMANIO){
					printf("\nNo es posible cargar más datos.");
				}else{
					Cargar_Catalogo(Arr_CodProd, Arr_CatProd, Arr_DescProd, Arr_PrecioUnit, &Op1_Contador);
				}
				strcpy(RTA, "SI");
				break;
			}
			case 2:{
				if(Op2_Contador >= TAMANIO){
					printf("\nNo es posible cargar más datos.");
				}else{
					IngresarCalcular_Compra(Arr_CostoL, Arr_Costo, Arr_CodProd, Arr_CatProd, Arr_DescProd, Arr_PrecioUnit, Arr_CantUnits, &Op2_Contador);
				}
				strcpy(RTA, "SI");
				break;
			}
			case 3:{
				strcpy(RTA, "NO");
				printf("\nRealizando ultimos procesos...");
				Sleep(2000);
				break;
			}
		}
		
		Total_Vendido(Arr_CatProd, Arr_Costo, Arr_CantUnits, &CantUnits_LB, &CantUnits_PE, &CantUnits_E, &MontoTot_LB, &MontoTot_PE, &MontoTot_E);
		CatProd_MasVendido(Arr_CatProd, Arr_CantUnits, &MasVendido);
		MontoProm_LineaBlanca(Arr_CostoL, &MontoProm_LB);
		
		
	}
	
	system("cls");
	//Se muestran resultados finales
	
	//--PUNTO A
	
	//POR ALGUNA RAZON LOS RESULTADOS APARECEN MULTIPLICADOS POR 2
	printf("\nEl total vendido por cada categoria");
	printf("\nLinea Blanca\n  Cantidad de Unidades: %d\n  Monto Total: %.2f", CantUnits_LB, MontoTot_LB);
	printf("\nPequenios electrodomesticos\n  Cantidad de Unidades: %d\n  Monto Total: %.2f", CantUnits_PE, MontoTot_PE);
	printf("\nElectrodomesticos\n  Cantidad de Unidades: %d\n  Monto Total: %.2f", CantUnits_E, MontoTot_E);
	
	//--PUNTO B
	printf("\nLa categoria de producto que mas se ha vendido en cantidad de unidades es: %c", MasVendido);
	
	//--PUNTO C
	printf("\nEl monto promedio de los productos de linea blanca es: %.2f", MontoProm_LB);
	
	return 0;
}
