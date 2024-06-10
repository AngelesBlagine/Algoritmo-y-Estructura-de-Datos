#include <stdio.h>

//ENFOQUE ASCENDENTE

void Burbujeo_Ascendente(int arr[10]){
	
	int i, j, aux;
	
	//Con el primer for me encargo de que se recorra el vector por completo.
	for(i = 0; i < 10; i++){
		
		//A traves del segundo for comparo los elementos entre posiciones.
		for(j = 0; j < 10 - i - 1; j++){ //Al restarle "i" y 1, evito volver a pasar por los anteriores valores, ya que se supone que ya se acomodaron.
			
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
		for(j = 0; j < 10 - i; j++){//Al restarle "i" y 1, evito volver a pasar por los anteriores valores, ya que se supone que ya se acomodaron.
			
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

int main(){
	
	int arr[10];
	int i, nro, RTA;
	char sigue;
	
	do{
		printf("Desea ordenar una lista de numeros? S/N: ");
		scanf("%c", &sigue);
	}while(sigue!='S'&&sigue!='N');
	
	//system("cls");
	
	while(sigue == 'S'){
		
		for(i = 0; i < 10; i++){
			printf("Ingrese un numero: ");
			scanf("%d", &nro);
			arr[i] = nro;
		}
		
		//system("cls");
		
		do{
			printf("\nComo quiere ordenar los numeros? \n(1) Ascendente \n(2) Descendente \n");
			scanf("%d", &RTA);
		}while((RTA!=1)&&(RTA!=2));
		
		switch(RTA){
			case 1: 
				Burbujeo_Ascendente(arr);
				break;
			case 2: 
				Burbujeo_Descendente(arr);
				break;
		}
		
		
		do{
			printf("\nDesea ordenar una lista de numeros? S/N: ");
			scanf("%c", &sigue);
		}while(sigue!='S'&&sigue!='N');
		
	}
	
	return 0;
}
