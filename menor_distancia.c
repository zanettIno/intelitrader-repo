#include <stdio.h>
#include <stdlib.h>

int numArray1, numArray2;

int menorDistancia(int array1[], int tam1, int array2[], int tam2){
    int menor = abs(array1[0] - array2[0]);
    
    for(int i = 0; i < tam1; i++){
    
        for (int j = 0; j < tam2; j++){
            int distancia = abs(array1[i] - array2[j]);
            
            if (distancia < menor){
                numArray1 = array1[i];
                numArray2 = array2[j];
                menor = distancia;
            } 
        }
    }
    
    return menor;
}

void main(){
    int tam1, tam2;
    
    printf("Tamanho da primeira array:");
    scanf("%d", &tam1);
    int array1[tam1];
    
    printf("Valores da primeira array:\n");
    for (int val = 0; val < tam1; val++) {
        
        scanf("%d", &array1[val]);
    }
    
    printf("Tamanho da segunda array:");
    scanf("%d", &tam2);
    int array2[tam2];
    
    printf("Valores da segunda array:\n");
    for (int val = 0; val < tam2; val++) {
        
        scanf("%d", &array2[val]);
    }
    
    int resultado = menorDistancia(array1, tam1, array2, tam2);
    printf("\nA menor distância entre dois numeros das arrays é de: %d, entre os números %d e %d", resultado, numArray1, numArray2);

}
