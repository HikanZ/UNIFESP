/*
P R O B L E M A  1 - Testando um novo codigo
Usar um par de numeros X e Y.
A partir desses numeros preciso saber quantos bits 1
existem entre o intervalo definido acima.

Entrada: 0 < X <= Y <= 10^16
Saida: Uma linha com o resultado
Tempo limite: 0,5s
*/

/*
Obs.: Resolvi de varias formas,
mas nenhuma funcionou dentro do tempo limite estabelecido.
Assim eu procurei na internet e fiz uma adaptacao de um codigo encontrado.
*/

#include <stdio.h>
#include <math.h>

unsigned long long int f(unsigned long long int n){
 /* Caso base f(0) = 0 */
 if(n == 0 || n == -1) return 0;

           /* Trata caso n for ímpar */
 if(n % 2)  return 2 * f(n / 2) + (n + 1) / 2  ;
 /* Se n for impar é qdo o programa de fato calcula o valor.
    Sendo um valor n impar considerando o 0 é qdo pode-se dividir em 2 grupos com mesmo tamanho
    Ex. n = 3
    000:0         001:1
    010:2         011:3
    Mostrando que temos 2 grupos com a mesma quantidade de membros
    Os bits mais significativos temos
    00
    01
    em ambos os grupos, isso se calcula usando o trecho 2*f(n/2)
    o restante é calculado por (n+1)/2
 */

           /* Trata caso n for par */
 else       return f(n - 1) + __builtin_popcountll(n); //__builtin_popcountll recebe unsignet long long
 /* A função __builtin_popcount recebe um valor inteiro e retorna a qtde de bits 1. */
 /* Se n for par, retorna o valor de bits 1 de n e chama a funcao passando n-1,
    um valor impar para que seja calculado
 */
}

void main(){
    unsigned long long int x, y;
   // scanf("%llu %llu", &x, &y);
    x = 123456789; y = 9876543210;
    //x = 2; y = 12;
    //x = 100; y = 1000;
    printf("\n%llu", f(y)-f(x-1));
}


