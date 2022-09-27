#ifndef TRANS2D_H_INCLUDED
#define TRANS2D_H_INCLUDED
#include "PGM.hpp"
#include <Eigen/Dense>
#define _PI 3.14159265358979323846
class Trans2D
{
public:
    Trans2D()
    {
    }
    static void tranaform2D(Eigen::Matrix3f M, PGM *imgE, PGM *imgS)
    {
        for (int yE = 0; yE < imgE->getAltura(); yE++)
        {
            for (int xE = 0; xE < imgE->getLargura(); xE++)
            {
                Eigen::Vector3f pE(xE, yE, 1);
                Eigen::Vector3f pS = M * pE;
                pS(0) = round(pS(0));
                pS(1) = round(pS(1));
                if (imgS->coodValida(pS(0), pS(1)))
                {
                    imgS->setPixel(pS(0), pS(1), imgE->getPixel(pE(0), pE(1)));
                }
            }
        }
    }
    ///rotação
    static void rotacao(float angulo, PGM *imgE, PGM *imgS)
    {
        Eigen::Vector2f centro(imgE->getLargura() / 2.0f, imgE->getAltura() / 2.0f);
        Eigen::Matrix3f T = getMTranslacao(centro(0), centro(1));
        Eigen::Matrix3f Tinv = getMTranslacao(-centro(0), -centro(1));
        Eigen::Matrix3f R = getMRotacao(angulo);
        Eigen::Matrix3f M = T * R * Tinv;
        std::cout << M << std::endl;
        for (int yE = 0; yE < imgE->getAltura(); yE++)
        {
            for (int xE = 0; xE < imgE->getLargura(); xE++)
            {
                Eigen::Vector3f pE(xE, yE, 1);
                Eigen::Vector3f pS = M * pE;
                pS(0) = round(pS(0));
                pS(1) = round(pS(1));
                if (imgS->coodValida(pS(0), pS(1)))
                {
                    imgS->setPixel(pS(0), pS(1), imgE->getPixel(pE(0), pE(1)));
                }
            }
        }
    }
    static float degree2rad(float ang)
    {
        float r = ang * (float)(_PI / 180.0);
        return r;
    }
    ///translação
    static Eigen::Matrix3f getMTranslacao(float Tx, float Ty)
    {
        Eigen::Matrix3f M = Eigen::Matrix3f::Identity();
        M(0, 2) = Tx;
        M(1, 2) = Ty;
        return M;
    }
    static Eigen::Matrix3f getMRotacao(float angulo)
    {
        Eigen::Matrix3f M = Eigen::Matrix3f::Identity();
        float anguloRad = degree2rad(angulo);
        float cosT = cos(anguloRad);
        float sinT = sin(anguloRad);
        M(0, 0) = cosT;
        M(0, 1) = -sinT;
        M(1, 0) = sinT;
        M(1, 1) = cosT;
        return M;
    }
    ///escala
    static Eigen::Matrix3f getMEscala(float sx, float sy)
    {
        Eigen::Matrix3f M = Eigen::Matrix3f::Identity();
        M(0, 0) = sx;
        M(1, 1) = sy;
        return M;
    }
    ///cisalhamento
    static Eigen::Matrix3f getMCisalhamento(char sentido, float fator)
    {
        Eigen::Matrix3f M = Eigen::Matrix3f::Identity();
        if (sentido == 'H' || sentido == 'h')
        {
            M(0, 1) = fator;
        }
        else if (sentido == 'V' || sentido == 'v')
        {
            M(1, 0) = fator;
        }
        return M;
    }
    ///reflexão
    static Eigen::Matrix3f getMReflexao(char eixo)
    {
        Eigen::Matrix3f M = Eigen::Matrix3f::Identity();
        if (eixo == 'X' || eixo == 'x')
        {
            M(1, 1) = -1;
        }
        else if (eixo == 'Y' || eixo == 'y')
        {
            M(0, 0) = -1;
        }
        return M;
    }
};
#endif