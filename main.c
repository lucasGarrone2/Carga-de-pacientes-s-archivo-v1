#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
char NyA[40];
int edad;
char dni [9];
char direccion[40];
char telefono[11];
int estado;


}stPaciente;




int main()
{
    cargaDeArchivoPaciente();
    muestraPacientes();
    return 0;
}


void cargaDeArchivoPaciente()
{

    char seguir='s';
    stPaciente paciente;
    FILE *archi=fopen("ArchivoNuevosPacientes.bin", "wb");
    if(archi!=NULL)
    {
        while(seguir=='s')
        {
            printf("Ingrese Nombre y apellido del paciente: \n");
            fflush(stdin);
            gets(paciente.NyA);

            printf("Ingrese DNI: \n");
            fflush(stdin);
            gets(paciente.dni);
            ///////////////////////////////////////////// Validacion dni de 8 digitos BIEN
            int longitud= strlen(paciente.dni);
            while(longitud<8 || longitud>8)
            {
                printf("DNI mal ingresado, vuelva a intentarlo\n");
                fflush(stdin);
                gets(paciente.dni);
                longitud=strlen(paciente.dni);
            }

            /////////////////////////////////////////////
            printf("Ingrese edad: \n");
            fflush(stdin);
            scanf("%i",&paciente.edad);
            ///////////////////////////////////////////// Validacion edad entre 0 y 100 BIEN
            while(paciente.edad>110 || paciente.edad<1)
            {
                printf("Edad incorrecta, vuelva a intentarlo\n");
                fflush(stdin);
                scanf("%i",&paciente.edad);
            }

            /////////////////////////////////////////////

            printf("Ingrese direccion del paciente: \n");
            fflush(stdin);
            gets(paciente.direccion);
            ///////////////////////////////////////////// Validacion direccion NO ANDA
            /*
            int longDireccion=strlen(paciente.direccion);
            char numeroDireccion[5];
            int longNroDireccion=strlen(numeroDireccion);
            while(paciente.direccion> 30 && longNroDireccion<4)
            {
                printf("Direccion incorrecta, debe ingresar la calle y la altura(4 digitos max)\n");
                fflush(stdin);
                gets(paciente.direccion);
                longDireccion=strlen(paciente.direccion);
                longNroDireccion=strlen(numeroDireccion);
            }

                */

            /////////////////////////////////////////////
            printf("Ingrese estado del paciente: \n");
            printf("si es un nuevo paciente es 1\n");
            fflush(stdin);
            scanf("%i",&paciente.estado);
            ///////////////////////////////////////////// Validacion estado del paciente BIEN
            while(paciente.estado >1 || paciente.estado <0)
            {
                printf("Estado incorrecto, vuelva a intentarlo\n");
                fflush(stdin);
                scanf("%i",&paciente.estado);

            }

            /////////////////////////////////////////////
            printf("Ingrese numero de telefono del paciente: \n");
            fflush(stdin);
            gets(paciente.telefono);
            ///////////////////////////////////////////// Validacion Telefono 10 digitos BIEN
            int longTelefono= strlen(paciente.telefono);
            while(longTelefono<10 || longTelefono>10)
            {
                printf("Numero mal ingresado, vuelva a intentarlo\n");
                fflush(stdin);
                gets(paciente.telefono);
                longTelefono=strlen(paciente.telefono);
            }
            /////////////////////////////////////////////
            fwrite(&paciente, sizeof(stPaciente),1,archi);

            printf("Desea cargar otro paciente?\n");
            fflush(stdin);
            scanf("%c",&seguir);

        }

        fclose(archi);
    }
}

void muestraPacientes()
{
    stPaciente paciente;
    FILE *archi;
    archi= fopen("ArchivoNuevosPacientes.bin","rb");


    if(archi!=NULL)
    {
            while(fread(&paciente,sizeof(stPaciente),1,archi)>0)
            {
                printf("------------------------------------------------------------------------------------\n");
                printf("Nombre:%s, edad: %i, direccion: %s, dni: %i, telefono: %s \n", paciente.NyA, paciente.edad, paciente.direccion, paciente.dni, paciente.telefono);
                printf("------------------------------------------------------------------------------------\n");

            }
    }

        fclose(archi);
}







