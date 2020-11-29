#include <stdio.h>
#include <locale.h>
// preencher 

void preencherMatriz (int n, int matriz[n][n]) {
  int i, j;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("Elemento (%d, %d): ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
  
}

// imprimir a de adjacencia 
void imprimirMatriz(int n, int matriz[n][n]) {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("%d ", matriz[i][j]);
      printf("\t");
    }
    printf("\n");
  }
}

// algoritmo de warshall
void warshall(int n, int matriz[n][n]){
  int i, j, k;
  for (k = 0; k < n; k++){
    for (i = 0; i < n; i++){
      for (j = 0; j < n; j++){
        if(matriz[i][j] == 1 || (matriz[i][k] == 1 && matriz[k][j] == 1)){
          matriz[i][j] = 1;
        }
      }
    }
  }
  
}
// imprimir a de alcancabilidade

int main(){
  setlocale(LC_ALL, "Portuguese");
  int n;

  printf("Digite o número de elementos :");
  scanf("%d", &n);

  int matriz[n][n];

  printf("Preencha a matriz de adjacências \n");
  preencherMatriz(n, matriz);

  printf("Matriz de adjacências \n");
  imprimirMatriz(n, matriz);

  warshall(n, matriz);
  printf("Matriz de acessibilidade \n");
  imprimirMatriz(n, matriz);

  return 1;
}
