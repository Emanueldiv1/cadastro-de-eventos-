#include <iostream> 
#include <conio.h>
#include <math.h>
#include <string.h>
#include <locale.h>


using namespace std;


struct cidade {
	int codigoCidade;
	char nomeCidade[30];
	char uf[2];
};

struct apresentador{
	int codigoApresentador;
	char nomeApresentador[30];
};

struct evento {
	int codigoEvento;
	char descricaoEvento[30];
	int cod_cidade;
	int cod_apresentador;
	int qtdePart;
	int limitePart;
	float PrecoUnitario;
	int cod_event;
};

struct participante{
	int codigoParticipante;
	char nomeParticipante[30];
	int codigo_evento;
};

//FUNÇÕES DE VERIFICAÇÕES............. 

int verificarCidade(struct cidade CI[], int cod, int contadorCidade){
	int i = 0, f=contadorCidade;
	int m=(i+f)/2;
	int codEncontrado;
	
	for(; f >= i && cod != CI[m].codigoCidade; m = (i + f)/2){
		if (cod > CI[m].codigoCidade)
		i = m + 1;
	else 
		f = m - 1;
	}
	
	if( cod == CI[m].codigoCidade){
		cout<<"\nCidade encontrada";
		cout<<"\nNome da cidade: " <<CI[m].nomeCidade;
		cout<<"\nEstado: "<<CI[m].uf<<endl;
		cout<<"__________________________________________________________________________"<<endl;
		codEncontrado = CI[m].codigoCidade;
		return m;
	} else {
		return -1;
		}
	}

 int verificarApresentador(struct apresentador AP[], int cod, int contadorApresentador){
 	int i = 0, f=contadorApresentador;
	int m=(i+f)/2;
	int codAPencontrado = 0;
	
	for(; f >= i && cod != AP[m].codigoApresentador; m = (i + f)/2){
		if(cod > AP[m].codigoApresentador)
		i = m + 1;
	else
		f = m - 1;
	}
	if( cod == AP[m].codigoApresentador){
		
		cout<<"\nApresentador encontrado.";
		cout<<"\nNome do apresentador: "<<AP[m].nomeApresentador<<endl;
		cout<<"__________________________________________________________________________"<<endl;
		codAPencontrado = AP[m].codigoApresentador;
		return m;
	}else {
		return -1;
		}
 }
 
 int verificarParticipantes(struct participante PA[], int contadorParticipantes, int codigoParticipante){
    int i = 0, f = contadorParticipantes;
    int m = (i + f) / 2;
    for(; f > i && codigoParticipante != PA[m].codigoParticipante; m = (i + f) / 2){
        if(codigoParticipante > PA[m].codigoParticipante)
            i = m +1;
        else
            f = m - 1;
    }
    if (codigoParticipante == PA[m].codigoParticipante){
        cout <<PA[m].codigoParticipante;
        return m;
    } else
        return -1;
}


int consultarEvento(struct evento EV[], int consutEvento, int contEvento, struct cidade CI[], struct apresentador AP[] ){
	int i = 0, f=contEvento;
	int m=(i+f)/2;
	int codEVencontrado = 0;
	for (; f >= i && consutEvento != EV[m].codigoEvento; m = (i + f)/2){
		if(consutEvento > EV[m].codigoEvento)
		i = m + 1;
	else
		f = m - 1;
		
	}
	
	if( consutEvento == EV[m].codigoEvento){
		cout<<"\n--------------------- Evento encontrado ---------------------"<<endl;
		cout<<"\nDescrição do envento: "<<EV[m].descricaoEvento<<endl;
		cout<<"\nCidade do evento: "<<CI[m].nomeCidade<<endl;
		cout<<"\nApresentador do evento: "<<AP[m].nomeApresentador<<endl;
		cout<<"\nValor arrecadado para o evento foi de: "<<EV[m].qtdePart * EV[m].PrecoUnitario<< "$"<<endl;
		cout<<"__________________________________________________________________________"<<endl;
		codEVencontrado = EV[m].codigoEvento;
		return m;
	}
	else{
		return -1;
	}	
}

int verificarEvento(struct evento EV[], int codEvento, int contEvento, cidade CI[], apresentador AP[]){
	int i = 0, f=contEvento;
	int m=(i+f)/2;
	int codEVencontrado = 0;
	for (; f >= i && codEvento != EV[m].codigoEvento; m = (i + f)/2){
		if(codEvento > EV[m].codigoEvento)
		i = m + 1;
	else
		f = m - 1;
	}
	if( codEvento == EV[m].codigoEvento){
		cout<<"\n---------------Evento encontrado---------------"<<endl;
		cout<<"\nDescrição do evento: "<<EV[m].descricaoEvento<<endl;
		cout<<"\ncidade do evento: "<<CI[m].nomeCidade<<endl;
		cout<<"\napresentador do evento: "<<AP[m].nomeApresentador<<endl;
		cout<<"__________________________________________________________________________"<<endl;
		codEVencontrado = EV[m].codigoEvento;
		
		return m;
	}else {
		cout<<"\n !!! Evento não foi encontrado !!! \n";
		return -1;
	}
}

//FUNÇÕES DE LEITURA.......... 
void lerCidade(struct cidade CI[], int &contadorCidade){
	int saida = 1;
	int i= 0;
	
	for(; i<20 && saida !=0; i++ ){
		cout<<"\nDigite o codigo da cidade: ";
		cin>>CI[i].codigoCidade;
		cin.ignore();
		if(CI[i].codigoCidade > 0){
			cout<<"\nDigite o nome da cidade: ";
			gets(CI[i].nomeCidade);
			cout<<"\nDigite a UF: ";
			cin>>CI[i].uf;
			cout<<"__________________________________________________________________________"<<endl;
			cin.ignore();
		}
		else { 
		saida = 0;
		}
	}
	contadorCidade=i-1;
	cout<<"Foram cadastradas (" <<contadorCidade<< ") Cidades."<<endl;
}


void lerApresentador(struct apresentador AP[], int &contadorApresentador){
	int i=0;
	int saida = 1;
	
	for(; i<20 && saida !=0; i++ ){
		cout<<"\nDigite o codigo do apresentador: ";
		cin>>AP[i].codigoApresentador;
		cin.ignore();
		if(AP[i].codigoApresentador > 0){
			cout<<"\nDigite o nome do apresentador: ";
			gets(AP[i].nomeApresentador);
			cout<<"__________________________________________________________________________"<<endl;
		}
		else {
			cout<<"\nApresentadores cadastrados."<<endl;
			saida = 0;
		}
	}
	contadorApresentador=i-1;
	cout<<"Foram cadastrados ("<<contadorApresentador<<") Apresentadores.";
}

void lerEvento(struct evento EV[],int &contEvento, struct cidade CI[], struct apresentador AP[],
int contadorCidade, int contadorApresentador){
	int i=0;
	int x=0; //
	int y=0; //
	int saida = 1;
	int achouCidade; 
	int achouApresentador;
	
		for(; i<20 && saida !=0; i++ ){
		cout<<"Digite o codigo do evento: ";
		cin>>EV[i].codigoEvento;
		cin.ignore();
		
		if(EV[i].codigoEvento > 0){
			cout<<"\nDigite a descrição do evento: ";
			gets(EV[i].descricaoEvento);
			cout<<"__________________________________________________________________________"<<endl;
			
			x=1;
			while (x !=0){
			cout<<"Digite o codigo da cidade para o evento:  ";
			cin>>EV[i].cod_cidade;
			cin.ignore();
			
			achouCidade = verificarCidade(CI,EV[i].cod_cidade, contadorCidade);
				if(achouCidade != -1){
                x = 0;
				}
				else {
				cout<<"\n !!! Cidade não encontrada informe um codigo valido !!! \n"<<endl;
				}
			}
			
			y=1;
			while (y !=0){
			cout<<"Digite o codigo do apresentador do evento: ";
			cin>>EV[i].cod_apresentador;
			cin.ignore();
			
			achouApresentador = verificarApresentador(AP, EV[i].cod_apresentador,contadorApresentador);
				if(achouApresentador != -1){
				y = 0;
				}
				else{
				cout<<"\n !!! Apresentador não encontrada informe um codigo valido !!! \n"<<endl;
				}
			}
			
			cout<<"\nInforme qual sera o limite de participantes: ";
			cin>>EV[i].limitePart;
			cin.ignore();
				
			cout<<"\nDigite a quantidade de participantes: ";
			cin>>EV[i].qtdePart;
			cin.ignore();
			
			while(EV[i].qtdePart > EV[i].limitePart){
				cout<<"\n!!!! O LIMITE DE PARTICIPANTES FOI ULTRAPASSADO !!!!"<<endl;
				cout<<"\nInforme um valor menor que ("<<EV[i].limitePart<<") novo valor: ";
				cin>>EV[i].qtdePart;
				cin.ignore();
			}
					
			cout << "\nInforme qual o preco de entrada para este evento R$";
			cin>>EV[i].PrecoUnitario;
			cin.ignore();
			cout<<"__________________________________________________________________________"<<endl;
		
			contEvento = i+1;
		}
		else {
			cout<<"Eventos cadastrados..."<<endl;
			saida = 0;
		}
	}
	cout<<"Foram cadastrados (" << contEvento<< ") eventos."<<endl;
}

void lerParticipante(struct participante PA[],struct evento EV[], int contEvento, cidade CI[], apresentador AP[], int contadorParticipantes){
	int i = 0; 
	int saida = 1;
	int verEvento;
	int x = 0;
	int codigoverificaEv;
	
	for(;i<20 && saida != 0; i++){
		
		cout<<"\nDigite o codigo do participante: ";
		cin>>PA[i].codigoParticipante;
		cin.ignore();
		
		if(PA[i].codigoParticipante > 0 ){
			cout<<"\nInforme o nome do participante: ";
			gets(PA[i].nomeParticipante);
			
			x=1;
			while(x != 0){
				cout<<"\nInforme o evento do participante: ";
				cin>>codigoverificaEv;
				cin.ignore();
				verEvento = verificarEvento(EV,codigoverificaEv,contEvento, CI, AP);
				
				if(verEvento != -1 ){
					x=0;
				}
				else{
					cout<<"\n !!! informe um codigo valido !!! \n"<<endl;
					cout<<"__________________________________________________________________________\n"<<endl;
				}
			}
		}
		else{
			saida=0;
		}
		contadorParticipantes = i+1-1;
	}
	cout<<"Foram cadastrados (" << contadorParticipantes<< ") participantes"<<endl;
}



void incluirParticipantes(struct participante PA[], int contadorParticipantes, struct evento EV[], int contEventos, struct cidade CI[], int contadorCidade, struct apresentador AP[], int contadorApresentador){
    
	int eventoEncontrado = 0;
    int refCidade = 0;
    int refApresentador = 0;
    int codEvento;
    int codParticipante;
    char nomePart [30];

    cout << "Digite o codigo do Evento que deseja adicionar o participante: ";
    cin >> codEvento;

    if(codEvento != 0){
        eventoEncontrado = verificarEvento(EV,codEvento,contEventos, CI, AP);
        if(eventoEncontrado != -1){
            refCidade = EV[eventoEncontrado].cod_cidade;
            cout<<"\n-------------Cidade do evento-------------";
            verificarCidade(CI,EV[eventoEncontrado].cod_cidade, contadorCidade);
            refApresentador = EV[eventoEncontrado].cod_apresentador;
            cout<<"\n-------------Apresentador do evento-------------";
            verificarApresentador(AP, EV[eventoEncontrado].cod_apresentador,contadorApresentador);

            if(EV[eventoEncontrado].qtdePart < EV[eventoEncontrado].limitePart){
                int codParticipante = 0, participanteEncontrado = 0;
                cout <<"\nHa vagas disponiveis!"<<endl;
                cout <<"\nDigite o codigo do participante a ser inscrito: ";
                cin >>codParticipante;
                cin.ignore();
                cout<<"\nNome do participante: ";
                gets(nomePart);

                if(codParticipante != 0){
                    participanteEncontrado =  verificarParticipantes(PA, contadorParticipantes, codParticipante);
                    PA[participanteEncontrado].codigo_evento = codEvento;
                    EV[eventoEncontrado].qtdePart = EV[eventoEncontrado].qtdePart + 1;	
                    cout<<"\nParticipante inscrito no evento!! "<<endl;
                }
            } 
			else{
                cout <<"\nO evento escolhido não possui vagas para novas inscrições."<<endl;
            }
            cout << "\nQuantidade de participantes: " << EV[eventoEncontrado].qtdePart << endl;
            cout << "\nLimite de participantes: " << EV[eventoEncontrado].limitePart << endl;
        } 
    }
}

void consultarEventos(struct evento EV[], int contEvento, struct cidade CI[], struct apresentador AP[]){
	int consutEvento;
	int eventoEncontrado=0; 
	int x=0;
	
		cout<<"Informe o codigo do evento que deseja consultar: ";
		cin>>consutEvento;
		
		if(consutEvento != 0){
	        eventoEncontrado = consultarEvento(EV, consutEvento, contEvento, CI, AP);
		}
}


//FUNÇÔES DE INCLUSÃO

void inclusaoApresentador(struct apresentador S[], int contS, struct apresentador T[], int contT, struct apresentador A[], int &contA){
//						  S= lista atual 					  T= lista recebida 			       A= lista atualizada 																							 
	int i = 0, j = 0, k = 0;
	
	 for (;i < contS && j < contT;k++){
	 	if(S[i].codigoApresentador < T[j].codigoApresentador){
	 		A[k].codigoApresentador = S[i].codigoApresentador;
	 		strcpy (A[k].nomeApresentador,S[i].nomeApresentador);
	 		i++;
		 }	
		 else {
		 	A[k].codigoApresentador = T[j].codigoApresentador;
		 	strcpy(A[k].nomeApresentador,T[j].nomeApresentador);
		 	j++;
		 }	 	
		}
		while (i< contS){
			A[k].codigoApresentador = S[i].codigoApresentador;
			strcpy (A[k].nomeApresentador,S[i].nomeApresentador);
			i++;
			k++;
		}
		while (j<contT){
			A[k].codigoApresentador = T[j].codigoApresentador;
			strcpy (A[k].nomeApresentador,T[j].nomeApresentador);
			j++;
			k++;
		}
		contA = k;
	   	cout<<"\nInclusão concluida...";
	   	
}


void mostrarEventos(struct evento EV[], int contEvento, struct cidade CI[], int contadorCidade, struct apresentador AP[], int contadorApresentador){
	float total= 0;
	cout<<"Lista de todos os eventos atualizados: " <<endl;
		for(int i = 0; i < contEvento; i++){
			cout<<"\nCodigo do evento: "<<EV[i].codigoEvento;
			cout<<"\nDescrição do evento: "<<EV[i].descricaoEvento;
			cout<<"\nCodigo da cidade do evento: "<<EV[i].cod_cidade<<endl;
			verificarCidade(CI, EV[i].cod_cidade, contadorCidade);
			cout<<"\nCodigo do apresentador do evento: "<<EV[i].cod_apresentador<<endl;
			verificarApresentador(AP, EV[i].cod_apresentador, contadorApresentador);
			cout<<"\nQuantidade de participantes: "<<EV[i].qtdePart;
			cout<<"\nlimites de participantes: "<<EV[i].limitePart;
			cout<<"\nPreço do evento: R$"<<EV[i].PrecoUnitario;
			cout<<"\nValor arrecadado pelo evento: R$"<<EV[i].qtdePart * EV[i].PrecoUnitario;
			cout<<"__________________________________________________________________________\n"<<endl;
			cout<<"\n\n";
			total = total + (EV[i].qtdePart * EV[i].PrecoUnitario);	
		}
			cout<<"Valor total de todos os eventos: R$" << total;
			getch();
}

int main(){
	setlocale(LC_ALL,"");
	
	
	struct apresentador AP[20];
	int contadorApresentador;
	struct apresentador arqS[20], arqT[20], arqA[40];
	
	//--------------------------------------------------
	
	struct evento EV[20];
	int contEvento;
	struct evento arqES[20], arqET[20], arqEA[40];
	
	//--------------------------------------------------
	
	struct participante S[20], T[20], A[40];
	struct participante PA[20];
	int contadorParticipantes;
	int codigoverificaEv;
	int contS, contT, contA;
	
	//--------------------------------------------------

	struct cidade CI[20];
	int contadorCidade;
	
	//--------------------------------------------------
	
	int fim = -1;
	int sair;
	int opcao; 
	
	while( sair==0){
		system("cls");
		cout<<"\t\tOPÇÕES:\n\n";
		cout<<"\t\t\t1 - Ler cidade\n\n";
		cout<<"\t\t\t2 - Ler apresentador \n\n";
		cout<<"\t\t\t3 - Ler evento\n\n";
		cout<<"\t\t\t4 - Ler participante\n\n";
		cout<<"\t\t\t5 - Incluir participantes no evento\n\n";
		cout<<"\t\t\t6 - Incluir Novo Apresetador\n\n";
		cout<<"\t\t\t7 - Consultar evento\n\n";
		cout<<"\t\t\t8 - Verificar todos eventos cadastrados\n\n";
		cout<<"\t\t\t9 - Encerrar o programa\n\n";
		cout<<"\t\tESCOLHA: ";
		cin>>opcao;
		
		
		switch(opcao){
			
		case 1:{
			system("cls");
				lerCidade(CI, contadorCidade);
				getch();
				break;
			}
			case 2:{
				system("cls");
				lerApresentador(AP, contadorApresentador);
				getch();
				break;
			}
			case 3:{
				system("cls");
				lerEvento(EV,contEvento,CI,AP,contadorCidade,contadorApresentador);
				getch();
				break;
			}
			case 4:{
				system("cls");
				lerParticipante( PA,EV,contEvento,CI, AP, contadorParticipantes);
				getch();
				break;
		}		
			case 5:{	
				system("cls");
			    incluirParticipantes( PA, contadorParticipantes,EV, contEvento,  CI,  contadorCidade,AP, contadorApresentador);
				getch();
				break;
			}
			
			case 6:{
				system("cls");
				lerApresentador(arqT, contT );
				getch();
				inclusaoApresentador(arqS, contS, arqT, contT, arqA, contA);
				getch();
				break;	
			}
			
			case 7:{
				system("cls");
				consultarEventos(EV, contEvento, CI, AP);
				getch();
				break;
			}
			
			case 8:{
				system("cls");
				mostrarEventos(EV, contEvento, CI, contadorCidade, AP, contadorApresentador);
				break;
			}
			
			case 9:{
				system("cls");
				char Encerrar='N';
				cout<<"\n\nDeseja encerrar o programa? (S/N) : ";
				sair=toupper(getche());
				if(Encerrar=='S'){
					cout<<"\n\nSaindo do programa...";
					
				}
				getch();
				break;	
			}	
		}
	}
}
