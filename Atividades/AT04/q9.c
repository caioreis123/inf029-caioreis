#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct{
    char nome[30];
    char dataNascimento[30];
    char cpf[30];
    char sexo;
}dados;

int INVALIDO = -1;
int VALIDO = 0;

void validarNome(char nome[30]){
    if (strlen(nome)>21){
        printf("nome invalido");
    }
}
void validarDataNascimento(char data[30]){
    int status = VALIDO;
    int tudo=0, parte, diaInt, mesInt, anoInt;
    char diaStr[100], mesStr[100], anoStr[100]; 
    
    //capturar valores
    for(tudo=0, parte=0; data[tudo]!='/'; tudo++, parte++){       
       diaStr[parte] = data[tudo];       
    }
    diaStr[parte] = '\0';
    tudo++;

    for(parte=0; data[tudo]!='/'; tudo++, parte++){       
       mesStr[parte] = data[tudo];       
    }
     tudo++;
     mesStr[parte]='\0';
    for(parte=0; tudo<strlen(data); tudo++, parte++){       
       anoStr[parte] = data[tudo];       
    }
    anoStr[parte]='\0';     

    //validar tamanho:
    if(strlen(diaStr)!=2 && strlen(diaStr)!=1){
       status=INVALIDO;
    }

    if(strlen(mesStr)!=2 && strlen(mesStr)!=1){
       status=INVALIDO;
    }

    if(strlen(anoStr)!=4 && strlen(anoStr)!=2){
       status=INVALIDO;
    }

    //validar inteiros:
    diaInt = atoi(diaStr);
    mesInt = atoi(mesStr);
    anoInt = atoi(anoStr);

    if(anoInt<100&&anoInt<20) anoInt+=2000;
    if(anoInt<100&&anoInt>=20) anoInt+=1900;
    

   if (((diaInt >= 1 && diaInt <= 31) && (mesInt == 1 || mesInt == 3 || mesInt == 5 || mesInt == 7 || mesInt == 8 || mesInt == 10 || mesInt == 12)) ||
		(diaInt == 29 && mesInt == 2 && (anoInt % 400 == 0 || (anoInt % 4 == 0 && anoInt % 100 != 0))) ||
		((diaInt >= 1 && diaInt <= 30) && (mesInt == 4 || mesInt == 6 || mesInt == 9 || mesInt == 11)) ||
		((diaInt >= 1 && diaInt <= 28) && (mesInt == 2))) status=VALIDO;
      else status=INVALIDO;   

    if (status==INVALIDO){
        printf("data invalida");
    }
}
void validarCpf(char cpf[30]){
    int status = VALIDO;
    	if(strlen(cpf) - 1 != 11) {
		status = INVALIDO;
	} else {
		double cpfInt = atof(cpf);

		double primeiroDigitoF = 0;
		int primeiroDigito = 0;
		int segundoDigito = 0;
		int terceiroDigito = 0;
		int quartoDigito = 0;
		int quintoDigito = 0;
		int sextoDigito = 0;
		int setimoDigito = 0;
		int oitavoDigito = 0;
		int nonoDigito = 0;

		// Validando primeiro digito vericador

		int multiDigito1 = 0;
		int multiDigito2 = 0;
		int multiDigito3 = 0;
		int multiDigito4 = 0;
		int multiDigito5 = 0;
		int multiDigito6 = 0;
		int multiDigito7 = 0;
		int multiDigito8 = 0;
		int multiDigito9 = 0;

		int somaDigitos = 0;
		int restoDigitos = 0;
		int subDigitos = 0;

		int primeiroDigitoVerificador = 0;

		primeiroDigitoF = cpfInt / 10000000000;
		primeiroDigito = primeiroDigitoF;
		segundoDigito = cpfInt / 1000000000;
		segundoDigito = segundoDigito % 10;
		terceiroDigito = cpfInt / 100000000;
		terceiroDigito = terceiroDigito % 10;
		quartoDigito = cpfInt / 10000000;
		quartoDigito = quartoDigito % 10;
		quintoDigito = cpfInt / 1000000;
		quintoDigito = quintoDigito % 10;
		sextoDigito = cpfInt / 100000;
		sextoDigito = sextoDigito % 10;
		setimoDigito = cpfInt / 10000;
		setimoDigito = setimoDigito % 10;
		oitavoDigito = cpfInt / 1000;
		oitavoDigito = oitavoDigito % 10;
		nonoDigito = cpfInt / 100;
		nonoDigito = nonoDigito % 10;

		//	Pegando últimos digitos informados

		long long int decimoDigito  =0;
		long long int decimo1Digito = 0;

		decimoDigito = cpfInt / 10;
		decimoDigito = decimoDigito % 10;
		decimo1Digito = cpfInt;
		decimo1Digito = decimo1Digito % 10;

		multiDigito1 = primeiroDigito * 10;
		multiDigito2 = segundoDigito  * 9;
		multiDigito3 = terceiroDigito * 8;
		multiDigito4 = quartoDigito   * 7;
		multiDigito5 = quintoDigito   * 6;
		multiDigito6 = sextoDigito    * 5;
		multiDigito7 = setimoDigito   * 4;
		multiDigito8 = oitavoDigito   * 3;
		multiDigito9 = nonoDigito     * 2;

		somaDigitos = (multiDigito1 + multiDigito2 + multiDigito3 + multiDigito4
					    + multiDigito5 + multiDigito6 + multiDigito7 + multiDigito8 + multiDigito9);

		restoDigitos = somaDigitos % 11;

		subDigitos = 11 - restoDigitos;

		if(subDigitos >= 10) {
			primeiroDigitoVerificador = 0;
		} else {
			primeiroDigitoVerificador = subDigitos;
		}

		// Validando segundo digito verifcador

		int multi2Digito1 = 0;
		int multi2Digito2 = 0;
		int multi2Digito3 = 0;
		int multi2Digito4 = 0;
		int multi2Digito5 = 0;
		int multi2Digito6 = 0;
		int multi2Digito7 = 0;
		int multi2Digito8 = 0;
		int multi2Digito9 = 0;
		int multi2Digito10 = 0;

		int soma2Digitos = 0;
		int resto2Digitos = 0;
		int sub2Digitos = 0;

		int segundoDigitoVerificador = 0;

		multi2Digito1 = primeiroDigito * 11;
		multi2Digito2 = segundoDigito  * 10;
		multi2Digito3 = terceiroDigito * 9;
		multi2Digito4 = quartoDigito   * 8;
		multi2Digito5 = quintoDigito   * 7;
		multi2Digito6 = sextoDigito    * 6;
		multi2Digito7 = setimoDigito   * 5;
		multi2Digito8 = oitavoDigito   * 4;
		multi2Digito9 = nonoDigito     * 3;
		multi2Digito10 = primeiroDigitoVerificador * 2;

		soma2Digitos = (multi2Digito1 + multi2Digito2 + multi2Digito3 + multi2Digito4 + multi2Digito5
					    + multi2Digito6 + multi2Digito7 + multi2Digito8 + multi2Digito9 + multi2Digito10);

		resto2Digitos = soma2Digitos % 11;

		sub2Digitos = 11 - resto2Digitos;
		
		if(sub2Digitos >= 10) {
			segundoDigitoVerificador = 0;
		} else {
			segundoDigitoVerificador = sub2Digitos;
		}

		if(!(decimoDigito == primeiroDigitoVerificador && decimo1Digito == segundoDigitoVerificador)) {
            status = INVALIDO;
		}
	}
    if (status==INVALIDO){
        printf("cpf invalido");
    }
}
void validarSexo(char sexo){
    sexo = toupper(sexo);

    if (sexo != 'M' || sexo != 'F' || sexo != 'O'){
        printf("sexo invalido");
    }
}

void validarDados(dados dados){
    validarNome(dados.nome);
    validarDataNascimento(dados.dataNascimento);
    validarCpf(dados.cpf);
    validarSexo(dados.sexo);
}

dados cadastrarCliente(){
    dados dados;

    printf("digite o nome \n");
    fgets(dados.nome, 30, stdin);

    printf("digite a data de nascimento \n");
    fgets(dados.dataNascimento, 30, stdin);

    printf("digite o cpf \n");
    fgets(dados.cpf, 30, stdin);
    
    printf("digite o sexo \n");
    scanf("%c", &dados.sexo);
    getchar();

    return dados;
}

void main(){
    dados dados;
    dados = cadastrarCliente();
    validarDados(dados);
    printf("%s", dados.nome);
    printf("%s", dados.dataNascimento);
    printf("%s", dados.cpf);
    printf("%c", dados.sexo);
}