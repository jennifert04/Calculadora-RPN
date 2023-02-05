#include <stdio.h>
#include <math.h>

float pila[8];

void printStack(void)
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d", 8 - i);
        printf(". ");
        printf("%f", pila[i]);
        printf("\n");
    }
    printf("\n");
}

void moveStackUp(void)
{
    for (int i = 1; i < 8; i++)
    {
        pila[i - 1] = pila[i];
    }
}

void moveStackDown(void)
{
    for (int i = 7; i > 0; i--)
    {
        pila[i] = pila[i - 1];
    }
}

void clean(void)
{
    for (int i = 0; i < 8; i++)
    {
        pila[i] = 0;
    }
}

int main(void)
{
    int i, op;
    float res = 0, num = 0;

    clean();

    do
    {
        printf("\033[2J\033[1;1H");
        printf("--------CALCULADORA RPN----------\n");
        printStack();
        printf("\n");
        printf("1. Ingresar número\n2. Seleccionar operador\n3. Limpiar último\n4. Limpiar todo\n5. Salir\n");
        printf("Ingrese el número de opción: ");
        scanf("%d", &op);
        if (op == 1)
        {
            if (pila[0] == 0)
            {
                printf("\033[2J\033[1;1H");
                printf("--------CALCULADORA RPN----------\n");
                printStack();
                printf("Ingrese el número: ");
                num = 0;
                scanf("%f", &num);
                moveStackUp();
                pila[7] = num;
            }
            else
            {
                printf("La pila está llena\n");
            }
        }
        else if (op == 2)
        {
            printf("\033[2J\033[1;1H");
            char operador;
            printf("\n");
            printf("+ (Suma)\n");
            printf("- (Resta)\n");
            printf("* (Multiplicación)\n");
            printf("/ (División)\n");
            printf("r (Raiz cuadrada)\n");
            printf("s (Seno)\n");
            printf("c (Coseno)\n");
            printf("t (Tangente)\n");
            printf("p (Potencia)\n");
            printf("Ingrese el operador\n");
            scanf("%s", &operador);
            switch (operador)
            {
            case '+':
                res = pila[6] + pila[7];
                moveStackDown();
                pila[7] = res;
                printf("\n\n");
                break;
            case '-':
                res = pila[6] - pila[7];
                moveStackDown();
                pila[7] = res;
                printf("\n\n");
                break;
            case '*':
                res = pila[6] * pila[7];
                moveStackDown();
                pila[7] = res;
                printf("\n\n");
                break;
            case '/':
                if (pila[7] == 0)
                {
                    printf("\n");
                    printf("Math Error\n");
                    break;
                }
                else
                {
                    res = pila[6] / pila[7];
                    moveStackDown();
                    pila[7] = res;
                    printf("\n\n");
                }
                break;
            case 'p':
                res = pow(pila[6], pila[7]);
                moveStackDown();
                pila[7] = res;
                printf("\n\n");
                break;
            case 'r':
                if (pila[7] < 0)
                {
                    printf("\n");
                    printf("Math Error\n");
                    break;
                }
                else
                { 
                    res = sqrt(pila[7]);
                    pila[7] = res;
                    printf("\n\n");
                }
                break;
            case 's':
                res = sin(pila[7]);
                pila[7] = res;
                printf("\n\n");
                break;

            case 'c':
                res = cos(pila[7]);
                pila[7] = res;
                printf("\n\n");
                break;
            case 't':
                if ((int)pila[7] == 90 || (int)pila[7] == 270)
                {
                    printf("\n");
                    printf("Math Error\n");
                    break;
                }
                else
                {
                    
                    res = tan(pila[7]);
                    pila[7] = res;
                    printf("\n\n");
                    break;
                }
            default: printf("La opción ingresada no es válida.");
            }
        }
        else if (op == 3)
        {
            printf("\033[2J\033[1;1H");
            pila[7]=0;
            moveStackDown();
        }
        else if (op == 4){
            printf("\033[2J\033[1;1H");
            clean();
        }
        else if (op == 5){
            printf("\033[2J\033[1;1H");
            break;
        }

    } while (op != 5);
}
