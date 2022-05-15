#ifndef UTILIDADE_H
    #define UTILIDADE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "..//model/acoes.h"
    #define VENDA 2
    #define COMPRA 1

    #define TODASAASOFERTA 0
    #define TSLA34 1
    #define FBOK34 2
    #define AAPL34 3
    #define PETR4  4 

    #if defined(_WIN32) || defined(_WIN64)
        #include <windows.h>
        #define CLEAR "cls"
    #else
        #define CLEAR "clear"
        #include <unistd.h>
    #endif

 
    Compra *cabecoteCompra ;
    Venda *cabecoteVenda ;
    Registro *cabecoteRegistro;

#endif // MACRO