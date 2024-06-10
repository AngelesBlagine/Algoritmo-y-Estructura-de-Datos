#include <stdio.h>
#include <windows.h>

//ENFOQUE ASCENDENTE

void Burbujeo_Ascendente(int arr[10]){
	
	int i, j, aux;
	
	//Con el primer for me encargo de que se recorra el vector por completo.
	for(i = 0; i < 10; i++){
		
		//A traves del segundo for comparo los elementos entre posiciones.
		for(j = 0; j < 10 - i - 1; j++){ //Al restarle "i" y 1, evito volver a pasar por los anteriores valores, ya que se supone que ya se acomodaron.
		//Al restarle 1 también evitamos que j+1 supere el tamaño del array.
			
			//Comparo el valor de 2 posiciones adyacentes, si el que está a la izquierda "arr[j]" es mayor que el valor a su derecha "arr[j + 1]", entonces intercambio sus posiciones.  
			if(arr[j] > arr[j + 1]){
				aux = arr[j + 1]; //Resguardo valor de "arr[j + 1]" para luego asignarlo a "arr[j]"
				arr[j + 1] = arr[j];
				arr[j] = aux;
			}
		}
	}
	
	//Iniciamos otro ciclo for para mostrar los resultados
	printf("\n Los numeros ordenados de forma ascendente");
	
	for(i = 0; i < 10; i++){
		printf("\n %d", arr[i]);	
	}
	
}
void Burbujeo_Descendente(int arr[10]){
	
	int i, j, aux;
	
	//Con el primer for me encargo de que se recorra el vector por completo.
	for(i = 0; i < 10; i++){
		
		//A traves del segundo for comparo los elementos entre posiciones.
		for(j = 0; j < 10 - i - 1; j++){//Al restarle "i" y 1, evito volver a pasar por los anteriores valores, ya que se supone que ya se acomodaron.
			
			//Comparo el valor de 2 posiciones adyacentes, si el que está a la derecha "arr[j + 1]" es mayor que el valor a su izquierda "arr[j]", entonces intercambio sus posiciones.  
			if(arr[j + 1] > arr[j]){
				aux = arr[j + 1]; //Resguardo valor de "arr[j + 1]" para luego asignarlo a "arr[j]"
				arr[j + 1] = arr[j];
				arr[j] = aux;
			}
		}
	}
	
	//Iniciamos otro ciclo for para mostrar los resultados
	printf("\n Los numeros ordenados de forma descendente");
	
	for(i = 0; i < 10; i++){
		printf("\n %d", arr[i]);	
	}
	
}

void Seleccion_Ascente(int arr[10]){
	int i, j, valorMin, posicionMin, aux;
	
	//10, 9, 8, 7, 6, 5, 4, 3, 2, 1
	
	for(i = 0; i < 10; i++){
		
		valorMin = arr[i];
		
		for(j = i + 1; j < 10; j++){	
			if(arr[j] < valorMin){
				valorMin = arr[j];
				posicionMin = j;
			}
		}
		
		aux = arr[posicionMin];
		arr[posicionMin] = arr[i];
		arr[i] = aux;
	}
	
	//Iniciamos otro ciclo for para mostrar los resultados
	printf("\n Los numeros ordenados de forma ascendente");
	
	for(i = 0; i < 10; i++){
		printf("\n %d", arr[i]);	
	}	
	
}

void Seleccion_Descendente(int arr[10]){
		int i, j, valorMax, posicionMax, aux;
	
	//1, 2, 3, 4, 5, 6, 7, 8 9, 10
	
	for(i = 0; i < 10; i++){
		
		valorMax = arr[i];
		
		for(j = i + 1; j < 10; j++){	
			if(arr[j] > valorMax){
				valorMax = arr[j];
				posicionMax = j;
			}
		}
		
		aux = arr[posicionMax];
		arr[posicionMax] = arr[i];
		arr[i] = aux;
	}
	
	//Iniciamos otro ciclo for para mostrar los resultados
	printf("\n Los numeros ordenados de forma ascendente");
	
	for(i = 0; i < 10; i++){
		printf("\n %d", arr[i]);	
	}	
	
}

void Insercion_Ascendente(int arr[10]){
	int vector[10]={0};
	int i, j, valorMin, posicionMin;
	int flag = 0;
	
	//10, 9, 8, 7, 6, 5, 4, 3, 2, 1
	
	for(i = 0; i < 10; i++){
		
		valorMin = arr[i];
		if(flag==0){
			for(j = 0; j < 10; j++){	
				if(arr[j] < valorMin){
					valorMin = arr[j];
					posicionMin = j;
				}
			}
		}else{
			for(){
				
			}	
		}
		
		vector[i] = arr[posicionMin];
		flag = 1;
	}
	//Iniciamos otro ciclo for para mostrar los resultados
	printf("\n Los numeros ordenados de forma ascendente");
	
	for(i = 0; i < 10; i++){
		printf("\n %d", vector[i]);	
	}		
	
}
void Insercion_Descendente(int arr[10]){
	
}

int main(){
	
	int arr[10];
	int i, nro, RTA;
	char sigue;
	
	do{
		printf("Desea ordenar una lista de numeros? S/N: ");
		scanf("%c", &sigue);
	}while(sigue!='S'&&sigue!='N');
	
	system("cls");
	
	while(sigue == 'S'){
		
		for(i = 0; i < 10; i++){
			printf("Ingrese un numero: ");
			scanf("%d", &nro);
			arr[i] = nro;
		}
		
		//system("cls");
		
		do{
			printf("\nComo quiere ordenar los numeros? \n(1) Burbujeo Ascendente \n(2) Burbujeo Descendente \n(3) Seleccion Ascendente \n(4) Seleccion Descendente \n(5) Insercion Ascendente \n(6) Insercion Descendente \n");
			scanf("%d", &RTA);
		}while((RTA < 1)&&(RTA > 6));
		
		switch(RTA){
			case 1: 
				Burbujeo_Ascendente(arr);
				break;
			case 2: 
				Burbujeo_Descendente(arr);
				break;
			case 3:
				Seleccion_Ascente(arr);
				break;
			case 4: 
				Seleccion_Descendente(arr);
				break;
			case 5:
				Insercion_Ascendente(arr);
				break;
			case 6:
				Insercion_Descendente(arr);
				break;
		}
		
		
		do{
			printf("\nDesea ordenar una lista de numeros? S/N: ");
			scanf("%c", &sigue);
		}while(sigue!='S'&&sigue!='N');
		
	}
	
	return 0;
}
