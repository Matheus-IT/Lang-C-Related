#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    typedef struct {
        int hora, minutos, segundos;
    } horario;
    typedef struct {
        int mes, dia, ano;
    } data;
    typedef struct {
        data dat;
        horario hr;
        char desc[];
    } compromisso;

    compromisso cp;
    printf(" - Criando novo compromisso - \n");
    printf(" - Inserir data: \n");
    printf(" =>Dia: ");
    scanf(" %d", &cp.dat.dia);
    printf(" =>Mes: ");
    scanf(" %d", &cp.dat.mes);
    printf(" =>Ano: ");
    scanf(" %d", &cp.dat.ano);
    printf(" - Inserir horario: \n");
    printf(" =>Hora: ");
    scanf(" %d", &cp.hr.hora);
    printf(" =>Minutos: ");
    scanf(" %d", &cp.hr.minutos);
    cp.hr.segundos = 0;
    setbuf(stdin, NULL);
    printf(" - Inserir uma descricao: \n");
    printf(" => ");
    fgets(cp.desc, 40, stdin);
    printf("------------------------------------------\n");
    printf("Data: %d/%d/%d \n", cp.dat);
    printf("Horario: %d:%d:%d \n", cp.hr);
    printf("Descricao: %s \n", cp.desc);
    printf("------------------------------------------\n");
    return 0;
}
