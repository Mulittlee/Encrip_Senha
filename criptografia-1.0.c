#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

 // VARIAVEIS GLOBAIS
FILE *senhas, *crip_senhas,*descrip_senhas;
char senha[16];

int main()
{
    setlocale(LC_ALL, "Portugueses");
     puts("Programa de criptografia");
    int opcao = 0;
    do{

      puts("\n");
        puts("---------------------------------");
        printf("Digite as opcao conforme abaixo:\n");
        puts("  1 - Registrar senha");
        puts("  2 - Ver senha registrada");
        puts("  3 - Criptografar senha");
        puts("  4 - Descriptografar senha");
        puts("---------------------------------");
        scanf("%d", &opcao);
       switch (opcao){
        case 1:
         system("cls");
            registrarSenha();
        break;
        case 2:
         system("cls");
            verSenhas();
        break;
        case 3:
         system("cls");
            criptografar();
        break;
        case 4:
         system("cls");
            descriptografar();
        break;
        default:
         system("cls");
            printf("Opcao invalida!");
        break;

    }
    }while (opcao != 0);

    puts("\n");
    return 0;
}
void registrarSenha(){

        senhas = fopen("senhas.txt", "w+");

        int validado = 0;
        char confirma;
        do
        {
            puts("---------------------------------");
            printf("Digite uma senha a ser criptografada: ");
            scanf("%s",&senha);


            int i;
            for (i = 0; senha[i] != '\0'; i++) {
                    if (senha[i] < 'a' || senha[i] > 'z') {
                        break;
                    }
                }
            if (senha[i] != '\0'){

                validado = 0;

                printf("Tem caracteres inválidos\n");
            }else{
                 validado = 1;
            }
        } while (validado == 0);

            printf("por favor confirme (S/N)\n");
            scanf("%s",&confirma);
            printf("---------------------------------\n");

            if(confirma == 's' || confirma == 'S'){
                fprintf(senhas,"%s",senha);
                fclose(senhas);
                system("cls");
            }else{
                puts("Operação cancelada");
            }

}
void verSenhas(){


    puts("\n");
    puts("---------------------------------");
    printf("|SENHA : %s |\n",senha);
    puts("---------------------------------");

}
void criptografar(){

        senhas = fopen("senhas.txt", "r");
        crip_senhas = fopen("crip_senha.txt", "w");

        if(crip_senhas != NULL)
        {
            char c;
            int contador = 0;
            int i = 0;

            printf("--------------------------\n");
            printf("CRIPTOGRAFADA \n");
            printf("--------------------------\n");
            printf("SENHA -> ");
           while(( c = fgetc(senhas)) != EOF)
            {
                contador++;

                i = c;
                i = i * contador;
                printf("%i",i);
                fprintf(crip_senhas,"%i ", i);
            }

            fclose(senhas);
            fclose(crip_senhas);

            printf(" |\n");
            printf("--------------------------");


        }
        else
        {
            puts("Erro...");
        }

}
void descriptografar(){

        senhas = fopen("crip_senha.txt", "r");
        descrip_senhas = fopen("descrip_senha.txt", "w");

        if(descrip_senhas != NULL)       {

            int contador = 0;
            char c[100];
            int i = 0;

            printf("--------------------------\n");
            printf("DESCRIPTOGRAFADA \n");
            printf("--------------------------\n");
            printf("SENHA -> ");


            while(fscanf(senhas, "%s", c) != EOF)
            {
                contador++;

                i = atoi(c);
                i /= contador;

                printf("%c", i);

                fprintf(descrip_senhas,"%c", i);
            }

            fclose(senhas);
            fclose(descrip_senhas);
            printf(" |\n");
            printf("--------------------------\n");


        }

    }

