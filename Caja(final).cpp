#include <stdio.h>
#include <string.h>
#include <windows.h>

// Función para inicializar el vector de movimientos de fondos
void Inicializar_Vector(float MovFondos[31]) {
    for (int i = 0; i < 31; i++) {
        MovFondos[i] = 0;
    }
}

// Función para mostrar el menú de opciones
void Menu_Opciones(int *Opcion) {
    do {
        printf("--------------------\n       FINANZAS \n--------------------\n");
        printf("1. Ingresar datos de Movimientos de Fondos\n");
        printf("2. Evaluacion de Cobranzas en RRHH\n");
        printf("3. Salir\n");
        printf("Ingrese la opcion que desee: ");
        scanf("%d", Opcion);
    } while (*Opcion < 1 || *Opcion > 3);
}

// Función para ingresar los movimientos de fondos
void Movimiento_Fondos(float MovFondos[31]) {
    int dia;
    char CodMov;
    float MontoMov;

    do {
        printf("Ingrese el dia del mes (1-31): ");
        scanf("%d", &dia);
    } while (dia < 1 || dia > 31);

    do {
        printf("El movimiento sera un Ingreso (I) o un Egreso (E): ");
        scanf(" %c", &CodMov);
    } while (CodMov != 'I' && CodMov != 'E');

    do {
        printf("Ingrese el monto: ");
        scanf("%f", &MontoMov);
    } while (MontoMov <= 0);

    // Acumulamos coda monto ingresado en el vector de movimientos
    if (CodMov == 'I') {
        MovFondos[dia - 1] += MontoMov;
    } else if (CodMov == 'E') {
        MovFondos[dia - 1] -= MontoMov;
    }
}

// Función para evaluar las cobranzas en RRHH
void Eval_Cobranzas(float *SaldoInicial, float *SaldoFinal, float SaldoParcial[31], float MovFondos[31]) {
    int i;

    do {
        printf("Ingrese el saldo inicial de la caja: ");
        scanf("%f", SaldoInicial);
    } while (*SaldoInicial < 0);

    *SaldoFinal = *SaldoInicial;
    SaldoParcial[0] = *SaldoInicial + MovFondos[0];

    for (i = 1; i < 31; i++) {
        SaldoParcial[i] = SaldoParcial[i - 1] + MovFondos[i];
    }

    for (i = 0; i < 31; i++) {
        printf("\nSaldo al final del dia %d: %.2f\n", i + 1, SaldoParcial[i]);
    }

    printf("\nSaldo final de caja del mes: %.2f\n", SaldoParcial[30]);
}


// Función MAIN
int main() {
    // Variables de entrada
    int Opcion;

    // Saldos
    float SaldoInicial;
    float SaldoFinal;
    float SaldoParcial[31];
    float MovFondos[31];

    // Respuesta
    char RTA[3];

    // Inicializar
    Inicializar_Vector(SaldoParcial);
    Inicializar_Vector(MovFondos);

    // Pregunta inicial
    do {
        printf("Desea evaluar el flujo de fondos del mes? SI/NO: ");
        scanf("%s", RTA);
    } while (strcmp(RTA, "SI") != 0 && strcmp(RTA, "NO") != 0);

    if (strcmp(RTA, "NO") == 0) {
        printf("Cerrando sesion...");
        Sleep(2000);
        return 0;
    }
	
	system("cls");

    // Bucle principal
    while (strcmp(RTA, "SI") == 0 && Opcion != 3) {
        // Mostrar menú y obtener la opción del usuario
        Menu_Opciones(&Opcion);
        
        system("cls");

        switch (Opcion) {
            case 1:
                Movimiento_Fondos(MovFondos);
                break;
            case 2:
                Eval_Cobranzas(&SaldoInicial, &SaldoFinal, SaldoParcial, MovFondos);
                break;
            case 3:
                printf("Cerrando sesion...\n");
                break;
        }
        

        if (Opcion != 3) {
            do {
                printf("\nDesea evaluar el flujo de fondos del mes? SI/NO: ");
                scanf("%s", RTA);
            } while (strcmp(RTA, "SI") != 0 && strcmp(RTA, "NO") != 0);

            if (strcmp(RTA, "NO") == 0) {
                printf("Cerrando sesion...\n");
                Sleep(2000);
            }
        }
        system("cls");
    }

    return 0;
}
