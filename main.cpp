#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
#include"TRANS2D.hpp"
using namespace std;
using namespace Eigen;
int main(void)
{
	///imagem de entrada
	PGM* imgE = new PGM();
	///imagem de saida
	PGM* imgS = new PGM();
	///cria uma imagem pgm
	imgS->criar(imgE->getLargura(), imgE->getAltura() );
	///leitura da imagem
	imgE->ler("numeros.pgm");
	///int menu;
	////do
	///{
		///system("cls");
		///cout<<"\n 0  - Sair "<<endl;
		///cout<<" 1  - Translação "<<endl;
		///cout<<" 2  - Rotação "<<endl;
		///cout<<" 3  - Escala "<<endl;
		///cout<<" 4  - Cisalhamento horizontal "<<endl;
		///cout<<" 5  - Cisalhamento vertical "<<endl;
		///cout<<" 6  - Reflexão em torno do eixo x "<<endl;
		///cout<<" 7  - Reflexão em torno do eixo y "<<endl;
		///cout<<" \n Escolha uma Opcao: "<<endl;
		///cin>>menu;
		///fflush(stdin);
		///switch (menu)
		///{
		///case 0:
			///cout << "PROGRAMA FINALIZADO!";
			///getchar();
			///break;
		///case 1:
			///system("cls");
			Trans2D::getMTranslacao(0,150);
			imgS->gravar("saida.pgm");
			///getchar();
			///break;
		///case 2:
			///system("cls");
			Trans2D::rotacao(45.0f,imgE, imgS);
			imgS->gravar("saida.pgm");
			///getchar();
			///break;
		///case 3:
			///system("cls");
			Trans2D::getMEscala(0.5, 0.5);
			imgS->gravar("saida.pgm");
			///getchar();
			///break;
		///case 4:
			///system("cls");
			///getchar();
			///break;
		///case 5:
			///system("cls");
			///getchar();
			///break;
		///case 6:
			///getchar();
			///break;
		///case 7:
			///system("cls");
			///getchar();
			///break;
		///default:
			///cout<<"Opção invalida!";
			///getchar();
			///break;
		///}
		///fflush(stdin);
	///
	//} while (menu != 0);
	///deleta as imagens de entrada e saida.
	delete imgE;
	delete imgS;
	return EXIT_SUCCESS;
}
