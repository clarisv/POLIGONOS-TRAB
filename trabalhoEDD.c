#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* funçao para ler os pontos do arquivo e calcular a área do polígono */

 typedef struct{
    float X;
    float Y;
 }Ponto;
 
/* calculando a área de um triângulo formado por três pontos A, B e C */

float AreaTriangulo(Ponto A, Ponto B, Ponto C){
    return fabs((A.X * (B.Y-C.Y)+B.X*(C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2.0);
}

/* lendo os pontos do arquivo e calculando a área do polígono */

float AreaPoligono(const char *nomeArquivo){
    FILE *file;
    file = fopen(nomeArquivo, "r");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            perror("fopen");
        return -1; 
    }

    /* lendo o número de veículos do arquivo */

    int numVertices;
     fscanf(file, "%d", &numVertices);

     Ponto *vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));

    for (int i = 0; i < numVertices; i++) {
        fscanf(file, "%f %f", &vertices[i].X, &vertices[i].Y);
        printf("%f %f\n", vertices[i].X, vertices[i].Y);
    }

     fclose(file);

    /* calculando a área do polígono */

    float areaTotal = 0;
        for (int i = 1; i < numVertices - 1; i++){
        areaTotal += AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }
    free(vertices);

    return areaTotal;
}

   /* programa principal */

    int main() {

     float area = AreaPoligono("trianguloABC");
        if (area >= 0) {
            printf("A área do polígono é %.2f\n", area);
    }

    return 0;
}
