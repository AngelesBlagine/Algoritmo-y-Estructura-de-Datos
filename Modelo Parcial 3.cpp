#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TAMANIO 50


	//Estrategia de Solución
/*
	Enfoque Ascendente
	
	---Funciones
		Mostrar_Opcion()
		Op1_IngresarDatos()
		Op1_AlmacenarDatos()
		Op2_CalcularInformar()
	
	---Función MAIN
	1. Inicializar variables
	2. Preguntar 
	3. Bucle while
		3.1. Mostrar menú
	
	4. Informar resultados finales (b)
	


*/
void Mostrar_Menu(int *Op){
	int Opcion;
	
	printf("----------------------------------------------------------\n            MENU\n----------------------------------------------------------\n");
	do{
		printf("\n(1) Ingresar Datos de pedidos \n(2) Informar Cotizaciones \n(3) Salir \n");
		scanf("%d", &Opcion);
	}while((Opcion < 1)&&(Opcion > 3));
	
	*Op = Opcion;
}

void Op1_IngresarDatos(long int NumCell, char TipoNegocio, int Zona, long int NumsCells[TAMANIO], char Negocios[TAMANIO], int Zonas[TAMANIO], int *Contador_Cotizaciones, int *Deps_ZonaNoUrb){
		
	//Se ingresan y validan datos
	do{
		printf("\nIngrese su numero de telefono (con codigo de area y sin caracteres especiales): ");
		scanf("%ld", &NumCell);
	}while(NumCell < 0); //Validar para saber si el numero de telefono es de 10 digitos
	
	
	do{
		printf("\nTIPOS DE NEGOCIO \n(S) Negocio con salida a la calle \n(L) Local en centro comercial \n(D) Deposito o galpon \n(O) Oficina en edificio empresarial \nIngrese el tipo de negocio: ");
		scanf(" %c", &TipoNegocio);
		while(getchar()!='\n');
	}while((TipoNegocio!='S')&&(TipoNegocio!='L')&&(TipoNegocio!='D')&&(TipoNegocio!='O'));
	
	
	switch(TipoNegocio){
		case 'D':{
			do{
				printf("\nZONAS \n(1)Urbana \n(0)No Urbana");
				scanf("%d", &Zona);
			}while((Zona!=1)&&(Zona!=0));
			
			if(Zona==0){
				(*Deps_ZonaNoUrb)++;
			}
			
			break;
		}
		default:{
			Zona = 1;
			break;
		}	
	}
	
	
	//Se almacenan datos en arrays
	long int NumsCells[*Contador_Cotizaciones] = NumCell;
	char Negocios[*Contador_Cotizaciones] = TipoNegocio;
	int Zonas[*Contador_Cotizaciones] = Zona;
	
	(*Contador_Cotizaciones)++;
	
}

void Op1_AlmacenarDatos(){
	
}

void Op2_CalcularInformar(long int NumsCells[TAMANIO], char Negocios[TAMANIO], int Zonas[TAMANIO], float Costos[TAMANIO]){
	int i;
	
	//Se realizan los cálculos
	for(i = 0; i < TAMANIO; i++){
		switch(Negocios[i]){
			case 'S':{
				Costos[i] == 50000;
				break;
			}
			case 'L':{
				Costos[i] == 40000;
				break;
			}
			case 'D':{
				if(Zonas[i]==1){
					Costos[i] == 80000;
				}else{
					Costos[i] == 85000;
				}
				break;
			}
			case 'O':{
				Costos[i] == 30000;
				break;
			}
		}
	}
	//Se informan resultados
	
	for(i = 0; i < TAMANIO; i++){
		printf("\nEl sistema de alarma del cliente con el numero de celular %ld, cotiza con un valor de %.2f", NumsCells[i], Costos[i]);
	}
}

int main(){
	//---Variables de entrada
	long int NumCell;
	char TipoNegocio;
	int Zona;
	
	//--Variables Auxiliares
	int Op; //Recoge opcion del menu seleccionada
	int Contador_Cotizaciones = 0; //
	int Deps_ZonaNoUrb = 0; //Llevará la cuenta de la cantidad de cotizaciones de depósitos o galpones en zona no urbana
	
	//Vectores
	long int NumsCells[TAMANIO] = {0};
	char Negocios[TAMANIO] = {0};
	int Zonas[TAMANIO] = {0}; 
	float Costos[TAMANIO] = {0};
	
	//RTA
	char RTA[2];
	
	
	
	//Preguntar
	do{
		printf("Desea iniciar el programa? SI/NO: ");
		scanf(" %c", &RTA);
		while(getchar()!='\n'); //Limpiamos buffer
	}while((strcmp(RTA, "SI")!=0)&&(strcmp(RTA, "NO")!=0));
	
	system("cls");
	
	if(strcmp(RTA, "NO")==0){
		printf("Apagando programa...");
		Sleep(2000);
	}
	
	//Bucle While
	while(strcmp(RTA, "SI")==0){
		//Mostrar menu
		Mostrar_Menu(&Op);
		
		//En base a la opción seleccionada
		switch(Op){
			case 1:{
				//Verificamos que lo que estamos almacenando no haya superado el límite impuesto al array
				if (Contador_Cotizaciones >= TAMANIO) {
					printf("\nNo se pueden ingresar mas cotizaciones.");
				}else{
					//Se llama a la función para ingresar datos y almacenarlos en vectores
					Op1_IngresarDatos(NumCell, TipoNegocio, Zona, NumsCells, Negocios, Zonas, &Contador_Cotizaciones, &Deps_ZonaNoUrb);
				}
				
				strcpy(RTA, "SI");
				break;
			}
			case 2:{
				//Se llama a la función que calcula los costos y muestra las cotizaciones
				Op2_CalcularInformar(NumsCells, Negocios, Zonas, Costos);
				strcpy(RTA, "SI");
				break;
			}
			case 3:{
				//Se cambia el valor de RTA a "NO" para salir del bucle y terminar el programa
				strcpy(RTA, "NO");
				if(strcmp(RTA, "NO")==0){
					printf("Realizando ultimos calculos...");
					Sleep(2000);
				}
				break;
			}
		}
		
	}
	
	printf("\nLa cantidad de cotizaciones de depositos o galpones en zona no urbana fueron de: %d", Deps_ZonaNoUrb);
	
	return 0;
}
