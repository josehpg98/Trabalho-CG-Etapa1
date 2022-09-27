#include "PGM.hpp"
#include <iostream>
using namespace std;
///struct para criar uma imagem com altura, largura e tipo.
PGM::PGM(){
    pixels = nullptr;
	larg = 0;
	alt = 0;
	tipo = "";
}
///descritor da imagem pgm.
PGM::~PGM() {
    if (pixels)
        delete pixels;
    pixels = nullptr;
}
///função para criar uma imagem pgm.
void PGM::criar(int largura, int altura)
{
    ///lagura x 2, para aumentar a imagem.
    this->larg = largura * 2;
    ///altura x 2, para aumentar a imagem.
    this->alt = altura * 2;
    ///tipo da imagem
    this->tipo = "P2";
    pixels = new unsigned char[this->larg * this->alt];
    for(int i=0; i< this->larg * this->alt; i++)
        pixels[i] = 0;

}
int PGM::getLargura()
{
    return larg;
}
int PGM::getAltura()
{
    return alt;
}
unsigned char* & PGM::getPixels()
{
    return pixels;
}
///funçõa que retorna a localização de um pixel.
unsigned char PGM::getPixel(int x, int y)
{
    if (pixels == nullptr)
    {
        cout << "Erro: faça a leitura da imagem antes de ler os pixels\n";
        return 0;
    }
    return pixels[y*larg + x];
}
///função que seta um pixel.
void PGM::setPixel(int x, int y, unsigned char cor)
{
    if (!pixels)
        return;
    if(pixels)
        pixels[y*larg + x] = cor;
}
///função para setar uma linha.
void PGM::setLinha(int y, unsigned char cor)
{
    if (pixels == nullptr)
    {
        cout << "Erro setLinha: faça a leitura da imagem antes de atribuir uma cor para a linha\n";
        return;
    }
    for(int x=0; x<larg; x++)
    {
         pixels[y*larg + x] = cor;
    }
}
///função para ler um arquivo imagem
bool PGM::ler(string caminho) {
    ifstream arq;
    string aux;
    arq.open(caminho);
    if (!arq.is_open()) {
        cout << "PGM: endereco do arquivo invalido\n";
        return false;
    }
    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler o tipo da imagem\n";
        return false;
    }
    tipo = aux;
    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler a largura da imagem\n";
        return false;
    }
    larg = atoi(aux.c_str());
    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler a altura da imagem\n";
        return false;
    }
    alt = atoi(aux.c_str());
    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler o valor máximo de cor\n";
        return false;
    }
    vmax = atoi(aux.c_str());
    if (pixels)
        delete pixels;
    pixels = new unsigned char[larg * alt];
    int i = 0;
    while (!arq.eof()) {
        if (!lerDado(arq, &aux)) {
            break;
        }
        pixels[i] = (unsigned char) atoi(aux.c_str());
        i++;
    }
    //cout << "i: " << i << endl;
    if (i != larg * alt) {
        cout << "PGM: erro ao ler os pixels\n";
        return false;
    }
    //cout << this->tipo << endl;
    //cout << this->larg << endl;
    //cout << this->alt << endl;
    //cout << this->vmax << endl;
    return true;
}
///grava o resultado uma imagem.
bool PGM::gravar(string caminho) {
    if (!pixels)
        return false;
    ofstream arq;
    arq.open(caminho);
    if (!arq.is_open()) {
        cout << "PGM: endereco do arquivo invalido\n";
        return false;
    }
    arq << tipo << endl;
    arq << larg << " " << alt << endl;
    arq << 255 << endl; // valor máximo de cor fixo em 255
    int tam = larg * alt;
    for (int i = 0; i < tam; i++)
    {
        arq << (int) pixels[i] << endl;
        arq.flush();
    }
    arq.close();
    return true;
}
bool PGM::lerDado(ifstream &arq, string *dado) {
    string aux;
    while (!arq.eof()) {
        arq >> aux;
        if (aux.size() > 0 && aux[0] == '#') {//isso é um comentário? descartar
            std::getline(arq, aux);//descartar
        }else if(aux.size() > 0){
            *dado = aux;
            return true;
        }
        aux = "";
    }
    return false;
}
