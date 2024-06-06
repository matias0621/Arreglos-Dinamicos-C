#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} strAlumno;

const char nombreDeArchivoAlumno[20] = {"ArchivoAlumnos"};
void ejercicio1();
int cantidadDePares(int arr[], int validos);
void mostrarArregloEnteros (int A[], int validos);
int* pasarParesCreadoArreglos(int arrEst, int validosEst, int * valDim);
int pasarParesCreadoArreglosConPunteroDoble(int arrEst, int validosEst, int ** arrDim);
void cargarArchivoDeAlumnos();
strAlumno cargarAlumnos(strAlumno alumno);
void mostrarArchivoDeAlumno();
void mostrarAlumnos(strAlumno alumno);
int cantidadDeAlumnos();
void pasarDeUnArchivoAUnArregloDinamico(int cantidadAlumnos, strAlumno alumnos[]);
void mostrarArregloDeAlumnos(strAlumno alumnos[], int validos);

int main()
{
    //ejercicio1();
    /*
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int cantPares = cantidadDePares(arr, 10);


    int * arrDim = (int*) malloc(sizeof(int)*cantPares);

    mostrarArregloEnteros(arrDim, cantPares);

    int valDim = pasarDeUnArregloEstaticoADinamico(arr, 10, arrDim);

    mostrarArregloEnteros(arrDim, cantPares);

    int valDin3= 0;
    int* arrDinam3;

    arrDinam3 = pasarParesCreadoArreglos(arr, 10, &valDin3);
    printf("\nArreglo dinamico 3:\n");
    mostrarArregloEnteros(arrDinam3, cantPares);

    int *arrDimDoble;

    int valDimDoble = pasarParesCreadoArreglosConPunteroDoble(arr, 10, &arrDimDoble);

    printf("\nArreglo Dinamico con punteros dobles\n");

    mostrarArregloEnteros(arrDimDoble, valDimDoble);
    */

    int validosAlumnos = cantidadDeAlumnos();

    strAlumno * arrDimDeAlumnos = malloc(sizeof(strAlumno) * validosAlumnos);

    pasarDeUnArchivoAUnArregloDinamico(validosAlumnos, arrDimDeAlumnos);

    mostrarArregloDeAlumnos(arrDimDeAlumnos, validosAlumnos);


    return 0;
}

void ejercicio1()
{
    // Declaración de la variable y los punteros
    int valor;
    int *pint = &valor;
    int **ppint = &pint;

    // Mostrando las direcciones de memoria
    printf("Dirección de valor: %p\n", (void*)&valor);
    printf("Dirección de pint (puntero a valor): %p\n", (void*)&pint);
    printf("Dirección de ppint (puntero a puntero a valor): %p\n", (void*)&ppint);

    // Asignando valores usando el puntero pint
    *pint = 10;
    printf("Valor después de asignar 10 usando pint: %d\n", valor);

    // Asignando valores usando el puntero ppint
    **ppint = 20;
    printf("Valor después de asignar 20 usando ppint: %d\n", valor);

    // Mostrando las direcciones almacenadas en los punteros
    printf("Dirección almacenada en pint: %p\n", (void*)pint);
    printf("Dirección almacenada en ppint: %p\n", (void*)ppint);

}

int cantidadDePares(int arr[], int validos)
{
    int cantPares = 0;

    for(int i = 0; i < validos; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cantPares++;
        }
    }

    return cantPares;
}

void mostrarArregloEnteros (int A[], int validos)
{
    int i=0;
    printf("\nContenido del arreglo:  ");
    for (i=0; i<validos; i++)
    {
        printf(" | %d | ", A[i]);
    }
}

int pasarDeUnArregloEstaticoADinamico(int arrEst[], int valdidosEst, int arrDim[])
{
    int valDim = 0;

    for(int i = 0; i < valdidosEst; i++)
    {
        if (arrEst[i] % 2 == 0)
        {
            arrDim[valDim] = arrEst[i];
            valDim++;
        }
    }

    return valDim;
}

int* pasarParesCreadoArreglos(int arrEst, int validosEst, int * valDim)
{
    int cantPares = cantidadDePares(arrEst, validosEst);

    int * arrDim = (int*)malloc(sizeof(int)*cantPares);

    *valDim = pasarDeUnArregloEstaticoADinamico(arrEst, validosEst, arrDim);

    return arrDim;
}

int pasarParesCreadoArreglosConPunteroDoble(int arrEst, int validosEst, int ** arrDim)
{
    int cantPares = cantidadDePares(arrEst, validosEst);

    *arrDim = (int*) malloc(sizeof(int) * cantPares);

    int valDina = pasarDeUnArregloEstaticoADinamico(arrEst, validosEst, *arrDim);

    return valDina;
}

strAlumno cargarAlumnos(strAlumno alumno)
{

    printf("Ingrese el legajo del alumno\n");
    scanf("%d", &alumno.legajo);
    fflush(stdin);

    printf("Ingrese el nombre y apellido del alumno\n");
    gets(alumno.nombreYapellido);
    fflush(stdin);

    printf("Ingrese la edad del alumnos\n");
    scanf("%d", &alumno.edad);
    fflush(stdin);

    printf("Ingrese el anio del alumnos\n");
    scanf("%d", &alumno.anio);
    fflush(stdin);

    return alumno;
}

void cargarArchivoDeAlumnos()
{
    FILE* buff;
    int i = 0;
    strAlumno a;

    buff = fopen(nombreDeArchivoAlumno, "ab");

    if (buff)
    {
        while(i < 5)
        {
            a = cargarAlumnos(a);
            fwrite(&a, sizeof(strAlumno), 1, buff);
            i++;
        }
    }

    fclose(buff);
}

void mostrarAlumnos(strAlumno alumno)
{
    printf("/--------------------------------------------------------------/\n");
    printf("Nombre y Apellido: %s\n", alumno.nombreYapellido);
    printf("Anio del alumno en la carrera: %d\n", alumno.anio);
    printf("Edad: %d\n", alumno.edad);
    printf("Legajo: %d\n", alumno.legajo);
    printf("/--------------------------------------------------------------/\n");
}

void mostrarArchivoDeAlumno()
{
    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            mostrarAlumnos(aux);
        }
    }

    fclose(buff);
}

int cantidadDeAlumnos()
{
    FILE * buff = fopen(nombreDeArchivoAlumno, "rb");
    int alumnos = 0;

    strAlumno aux;

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            alumnos++;
        }
    }

    fclose(buff);
    return alumnos;
}

void pasarDeUnArchivoAUnArregloDinamico(int cantidadAlumnos, strAlumno alumnos[])
{

    FILE * buff = fopen(nombreDeArchivoAlumno, "rb");
    int i = 0;
    strAlumno aux;
    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0){
            alumnos[i] = aux;
            i++;
        }
    }
}

void mostrarArregloDeAlumnos(strAlumno alumnos[], int validos){
    for(int i = 0; i < validos; i++){
        mostrarAlumnos(alumnos[i]);
    }
}
