#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
#include"TRANS2D.hpp"
using namespace std;
using namespace Eigen;
int main(void)
{
	cout<<" Trabalho 1-Etapa "<<endl;
	cout<<"Disciplina: Computação Gráfica"<<endl;
	cout<<"integrantes: José Henrique e Mauro"<<endl;
	getchar();
	system("cls");
	int op_menu, seg, op_transf;
	string imagem;
	///imagem de entrada
	PGM* imgE = new PGM();
	///imagem de saida
	PGM* imgS = new PGM();
	///cria uma imagem pgm
	///leitura da imagem
	cout<<"Informe a imagem: "<<endl;
	cin>>imagem;
	fflush(stdin);
	///cout<<imagem;
	imgE->ler(imagem);
	imgS->criar(imgE->getLargura(), imgE->getAltura() );
	do{
		cout<<"\n Digite 1 para aplicar uma transformação, ou 0 para sair: ";
		cin>>op_menu;
		fflush(stdin);
		if(op_menu == 1){
			do{
			cout<<"\n Segmento (1, 2, 3 ou 4):";
			cin>>seg;
			fflush(stdin);
			cout<<"\n Transformações Geometricas Disponiveis: "<<endl;
			cout<<"1 - Rotação "<<endl;
			cout<<"2 - Translação"<< endl;
			cout<<"3 - Escala"<< endl;
			cout<<"4 - Reflexão  "<< endl;
			cout<<"5 - Cisalhamento"<< endl;
			cout<<"0 - Sair"<<endl;
			cin>>op_transf;
			fflush(stdin);
			switch(op_transf)
			{
				case 1: 
				cout<<"Rotação: "<<endl;
				Trans2D::rotacao(45.0f,imgE, imgS);
				imgS->gravar("saida.pgm");
				getchar();
				break;
				case 2: 
				cout<<"Translação: "<<endl;
				getchar();
				break;
				case 3: 
				cout<<"Escala: "<<endl;
				getchar();
				break;
				case 4: 
				cout<<"Reflexão: "<<endl;
				getchar();
				break;
				case 5: 
				cout<<"Cisalhamento: "<<endl;
				getchar();
				break;
			}
			}while(op_transf != 0);
		}else{
			cout<<"\n Programa Finalizado! ";
			getchar();
		}
	}while(op_menu != 0);
	///deleta as imagens de entrada e saida.
	///delete imgE;
	///0delete imgS;
	return EXIT_SUCCESS;
}
