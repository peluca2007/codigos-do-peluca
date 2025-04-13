#include <stdio.h>
#include <string.h>
#include <locale.h>

#define tam 50


 struct pessoa{
    int idade;
    float altura;
    char nome [tam];
};

typedef struct pessoa pessoa;

int main(){
        setlocale(LC_ALL,"Portuguese");
        
        pessoa p = {17,1.70,"Pedro"};
        
        
        printf("\nsua idade :%d\n", p.idade);
        printf("\nseu nome :%s\n", p.nome);
        printf("\nsua altura:%.2f\n", p.altura);
        
        p.idade=18;
        p.altura=2.04;
        strcpy(p.nome,"lucas");
        
        printf("\nalterando via codigo\n");
        printf("\nsua idade :%d\n", p.idade);
        printf("\nseu nome :%s\n", p.nome);
        printf("\naltura:%.2f\n", p.altura);
        
        printf("\nescreva sua idade:\n");
        scanf("%d", &p.idade);
        printf("\nescreva seu nome :\n");
        scanf("%s", p.nome);
        printf("\nescreva sua altura:\n");
        scanf("%f", &p.altura);
        
        printf("\nsua idade:%d\n", p.idade);
        printf("\nseu nome:%s\n", p.nome);
        printf("\nsua altura:%.2f\n", p.altura);
        
    
}
