/* REGULA FALSI METHOD IN C++  

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: January 31st, 2022 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "RegulaFalsi.hpp"

using namespace std;

double avaliacao_funcao(const double &x){

    return sqrt(x + 1) - sin(x) - 1; 

}

void print(const double &a, const double &b, const double &Fa, const double &Fb, 
           const double &x, const double &Fx, const double &deltax, const unsigned &k){

    
    cout << setprecision(5) << fixed << k << "   " << a 
        << "   " << Fa << "  ";

    if((Fa < 10 && Fa > 0) || (Fa > -1 * 10 && Fa < 0)) cout << " ";
        
    cout << b << "  ";
        
    if((Fb < 10 && Fb > 0) || (Fb > -1 * 10 && Fb < 0)) cout << " ";

    cout << Fb << "    "; 
    cout << scientific << deltax << "    ";
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << fixed << x << "    ";

    if(Fx > 0) cout << " ";
             
    cout << scientific << Fx << endl;
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << fixed;

}

void regula_falsi(double &a, double &b, double &Toler, unsigned &IterMax){

    cout << "\n\tCalculo de raiz pelo metodo da regula falsi\n" << endl;

    cout << "k     a_k       Fa_k      b_k       Fb_k      deltax_k     x_k        Fx_k" << endl;

    int Info;

    unsigned k = 0;

    double Fa = avaliacao_funcao(a);
    double Fb = avaliacao_funcao(b);

    double deltax = Fb * (b - a) / (Fb - Fa);

    double x = b - deltax;
    double Fx = avaliacao_funcao(x);

    while(1){

        print(a, b, Fa, Fb, x, Fx, deltax, k);

        if((fabs(deltax) <= Toler && fabs(Fx) <= Toler)
            || k >= IterMax){

            goto SaiDoLoop;

        }

        if(Fa * Fb > 0){

            Info = -1;
            goto Final;

        }

        if(Fb * Fx < 0){

            a = b;
            Fa = Fb;

        }

        b = x;
        Fb = Fx;

        deltax = Fb * (b - a) / (Fb - Fa);
        x = b - deltax;
        Fx = avaliacao_funcao(x);

        k++;

    }

    SaiDoLoop:

    if(fabs(deltax) <= Toler && fabs(Fx) <= Toler){

        Info = 0;

    }

    else{

        Info = 1;

    }

    Final:

    cout << endl;
    
    if(Info == 0){
        
        cout << "Raiz = " << x << endl;

    }

    cout << "Iter = " << k << endl;
    cout << "Info = " << Info << endl << endl;

}