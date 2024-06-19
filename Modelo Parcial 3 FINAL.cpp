#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TAMANIO 50

// Función para mostrar el menú y obtener la opción del usuario
void Mostrar_Menu(int *Op){
	int Opcion;
	
	printf("----------------------------------------------------------\n            MENU\n----------------------------------------------------------\n");
	do{
		printf("\n(1) Ingresar Datos de pedidos \n(2) Informar Cotizaciones \n(3) Salir \n");
		scanf("%d", &Opcion);
	}while((Opcion < 1) || (Opcion > 3));
	
	*Op = Opcion;
}

// Función para ingresar datos y almacenarlos en los vectores
void Op1_IngresarDatos(long int NumsCells[TAMANIO], char Negocios[TAMANIO], int Zonas[TAMANIO], int *Contador_Cotizaciones, int *Deps_ZonaNoUrb){
	long int NumCell;
	char TipoNegocio;
	int Zona;

	// Se ingresan y validan datos
	do{
		printf("\nIngrese su numero de telefono (con codigo de area y sin caracteres especiales): ");
		scanf("%ld", &NumCell);
	}while(NumCell < 0); // Validar para saber si el numero de telefono es de 10 digitos
	
	do{
		printf("\nTIPOS DE NEGOCIO \n(S) Negocio con salida a la calle \n(L) Local en centro comercial \n(D) Deposito o galpon \n(O) Oficina en edificio empresarial \nIngrese el tipo de negocio: ");
		scanf(" %c", &TipoNegocio);
		while(getchar()!='\n');
	}while((TipoNegocio!='S')&&(TipoNegocio!='L')&&(TipoNegocio!='D')&&(TipoNegocio!='O'));
	
	switch(TipoNegocio){
		case 'D':{
			do{
				printf("\nZONAS \n(1) Urbana \n(0) No Urbana: ");
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
	
	// Se almacenan datos en arrays
	NumsCells[*Contador_Cotizaciones] = NumCell;
	Negocios[*Contador_Cotizaciones] = TipoNegocio;
	Zonas[*Contador_Cotizaciones] = Zona;
	
	(*Contador_Cotizaciones)++;
}

// Función para calcular los costos y mostrar las cotizaciones
void Op2_CalcularInformar(long int NumsCells[TAMANIO], char Negocios[TAMANIO], int Zonas[TAMANIO], float Costos[TAMANIO], int Contador_Cotizaciones){
	int i;
	
	// Se realizan los cálculos
	for(i = 0; i < Contador_Cotizaciones; i++){
		switch(Negocios[i]){
			case 'S':
				Costos[i] = 50000;
				break;
			case 'L':
				Costos[i] = 40000;
				break;
			case 'D':
				Costos[i] = (Zonas[i] == 1) ? 80000 : 85000;
				break;
			case 'O':
				Costos[i] = 30000;
				break;
		}
	}
	// Se informan resultados
	for(i = 0; i < Contador_Cotizaciones; i++){
		printf("\nEl sistema de alarma del cliente con el numero de celular %ld, cotiza con un valor de %.2f", NumsCells[i], Costos[i]);
	}
}

int main(){
	// Variables de entrada y auxiliares
	int Op; // Recoge opcion del menu seleccionada
	int Contador_Cotizaciones = 0; // Lleva la cuenta de cotizaciones ingresadas
	int Deps_ZonaNoUrb = 0; // Llevará la cuenta de la cantidad de cotizaciones de depósitos o galpones en zona no urbana
	
	// Vectores
	long int NumsCells[TAMANIO] = {0};
	char Negocios[TAMANIO] = {0};
	int Zonas[TAMANIO] = {0}; 
	float Costos[TAMANIO] = {0};
	
	// Respuesta del usuario
	char RTA[3];
	
	// Preguntar
	do{
		printf("Desea iniciar el programa? SI/NO: ");
		scanf("%s", RTA);
		while(getchar()!='\n'); // Limpiamos buffer
	}while((strcmp(RTA, "SI")!=0)&&(strcmp(RTA, "NO")!=0));
	
	system("cls");
	
	if(strcmp(RTA, "NO")==0){
		printf("Apagando programa...");
		Sleep(2000);
	}
	
	// Bucle While
	while(strcmp(RTA, "SI")==0){
		// Mostrar menú
		Mostrar_Menu(&Op);
		
		// En base a la opción seleccionada
		switch(Op){
			case 1:
				// Verificamos que lo que estamos almacenando no haya superado el límite impuesto al array
				if (Contador_Cotizaciones >= TAMANIO) {
					printf("\nNo se pueden ingresar más cotizaciones.");
				} else {
					// Se llama a la función para ingresar datos y almacenarlos en vectores
					Op1_IngresarDatos(NumsCells, Negocios, Zonas, &Contador_Cotizaciones, &Deps_ZonaNoUrb);
				}
				break;
			
			case 2:
				// Se llama a la función que calcula los costos y muestra las cotizaciones
				Op2_CalcularInformar(NumsCells, Negocios, Zonas, Costos, Contador_Cotizaciones);
				break;
			
			case 3:
				// Se cambia el valor de RTA a "NO" para salir del bucle y terminar el programa
				strcpy(RTA, "NO");
				printf("Realizando ultimos calculos...");
				Sleep(2000);
				break;
		}
	}
	
	printf("\nLa cantidad de cotizaciones de depósitos o galpones en zona no urbana fueron de: %d", Deps_ZonaNoUrb);
	
	return 0;
}
