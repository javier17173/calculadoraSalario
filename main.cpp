#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <locale.h>
#include <string>
#include <stdio.h>
/* 
Javier Santana Rodr�guez
Tarea 1
Programaci�n 1
Universidad Tecnol�gica Costarricense
*/

/* 
Se solicita realice un programa para calcular N aumentos salariales de una empresa hasta que el usuario desee.  
El programa deber� leer los siguientes datos: n�mero cedula y nombre del empleado, tipo de empleado debe digitar un c�digo de 1 a 3 
(Correspondiendo a: 1-Operario 2-Tecnico  3-Profesional), cantidad horas laboradas, precio por hora.  
*/

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "spanish"); //Permite utilizar tildes en la consola de C++
	
	const float deduccionCCSS = 0.0917; //Porcentaje de deducci�n por ley de la ccss sobre el salario bruto
	
	//declaraci�n de variables
	int cedula, tipoEmpleado, cantidadOperarios= 0, cantidadTecnicos= 0, cantidadProfesionales= 0, opcionMenu;
	float precioPorHora, horasLaboradas, aumento, totalAumento, salarioOrdinario, impuestoSalario, salarioBruto, salarioNeto;
	float acumuladoSalarioOperarios= 0.0, promedioSalarioOperarios= 0.0, acumuladoSalarioTecnicos= 0.0, promedioSalarioTecnicos= 0.0, acumuladoSalarioProfesional = 0.0, promedioSalarioProfesional = 0.0;
	string nomTipoEmpleado;
	char nombre[100];

	printf("****************************** \n");
	printf("*                            * \n");
	printf("*         Bienvenido         * \n");
	printf("*                            * \n");
	printf("****************************** \n");
	printf("\n");
		
	do{
			//solicitud de datos al usuario		
			printf("Digite el n�mero de c�dula del empleado: ");
			scanf("%i", &cedula);
			
			printf("Digite el nombre del empleado: ");
			scanf(" %[^\n]", &nombre); 
		
			printf("Digite el tipo de empleado seg�n la siguiente lista: \n");
			printf("1. Operario \n");
			printf("2. T�cnico \n");
			printf("3. Profesional \n");
			scanf("%i", &tipoEmpleado);
			printf("\n");
	
			printf("Digite la cantidad de horas laboradas: ");
			scanf("%f", &horasLaboradas);
	
			printf("Digite el precio por hora: ");
			scanf("%f", &precioPorHora);
				
			//C�lculos de aumentos, deducciones de ley y salarios
			salarioOrdinario = horasLaboradas * precioPorHora;
	
			if(tipoEmpleado == 1){
				aumento = 0.15;
				totalAumento = salarioOrdinario*aumento;
				salarioBruto = salarioOrdinario + totalAumento;
				impuestoSalario = salarioBruto * deduccionCCSS;
				salarioNeto = salarioBruto - impuestoSalario;
				nomTipoEmpleado = "Operario";
				cantidadOperarios++;
				acumuladoSalarioOperarios += salarioNeto;
				
			}else{
				if(tipoEmpleado == 2){
					aumento = 0.10;
					totalAumento = salarioOrdinario*aumento;
					salarioBruto = salarioOrdinario + totalAumento;
					impuestoSalario = salarioBruto * deduccionCCSS;
					salarioNeto = salarioBruto - impuestoSalario;
					nomTipoEmpleado = "T�cnico";
					cantidadTecnicos++;
					acumuladoSalarioTecnicos += salarioNeto;
					
				}else{
					if(tipoEmpleado == 3){
						aumento = 0.05;
						totalAumento = salarioOrdinario*aumento;
						salarioBruto = salarioOrdinario + totalAumento;
						impuestoSalario = salarioBruto * deduccionCCSS;
						salarioNeto = salarioBruto - impuestoSalario;
						nomTipoEmpleado = "Profesional";
						
						cantidadProfesionales++;
						acumuladoSalarioProfesional += salarioNeto;
					}else{
						printf("opci�n no v�lida");
					}
				}
			}
			
			//c�lculos de promedios y acumulados por tipo de trabajador
			if(cantidadOperarios == 0){
				promedioSalarioOperarios = 0;
			}else{
				promedioSalarioOperarios = acumuladoSalarioOperarios / cantidadOperarios;
			}
			if(cantidadTecnicos == 0){
				promedioSalarioTecnicos = 0;
			}else{
				promedioSalarioTecnicos = acumuladoSalarioTecnicos / cantidadTecnicos;	
			}
			if(cantidadProfesionales == 0){
				promedioSalarioProfesional = 0;
			}else{
				promedioSalarioProfesional = acumuladoSalarioProfesional / cantidadProfesionales;
			}
			
			//Mostrar en pantalla la informaci�n solicitada
			printf("\n");
			printf("****************************************************\n");
			printf(" C�dula: %i\n", cedula);
			printf(" Nombre: %s\n", &nombre);
			printf(" Tipo de Empleado: %s\n", nomTipoEmpleado.c_str()); //se utiliza c_str() para leer los datos de las variables tipo string
			printf(" Precio por hora: %.0f\n", precioPorHora);
			printf(" Cantidad de horas laboradas: %.0f\n", horasLaboradas);
			printf(" Salario ordinario: %.2f\n", salarioOrdinario);
			printf(" Aumento otorgado: %.2f\n", totalAumento);
			printf(" Salario Bruto: %.2f\n", salarioBruto);
			printf(" Deducci�n CCSS: %.2f\n", impuestoSalario);
			printf(" Salario Neto: %.2f\n", salarioNeto);
			printf("****************************************************\n");
			
			printf("\n");
			printf("�Desea calcular otro empleado? \n");
			printf("1. Si \n");
			printf("2. Salir\n");
			scanf("%i", &opcionMenu);
			printf("\n");
					
	}while (opcionMenu != 2);
	
	
	printf("\n");
	printf("****************************************************\n");
	printf("Estad�sticas \n");
	printf("1. Cantidad de Operarios: %i\n", cantidadOperarios);
	printf("2. Acumulado Salario Neto para Operarios: %.2f\n", acumuladoSalarioOperarios);
	printf("3. Promedio Salario Neto para Operarios: %.2f\n", promedioSalarioOperarios);
	printf("\n");
	printf("4. Cantidad de T�cnicos: %i\n", cantidadTecnicos);
	printf("5. Acumulado Salario Neto para T�cnicos: %.2f\n", acumuladoSalarioTecnicos);
	printf("6. Promedio Salario Neto para T�cnicos: %.2f\n", promedioSalarioTecnicos);
	printf("\n");
	printf("7. Cantidad de Profesionales: %i\n", cantidadProfesionales);
	printf("8. Acumulado Salario Neto para Profesionales: %.2f\n", acumuladoSalarioProfesional);
	printf("9. Promedio Salario Neto para Profesionales: %.2f\n", promedioSalarioProfesional);
	printf("****************************************************\n");
		
	return 0;
}
