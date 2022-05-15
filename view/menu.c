
#include "..//model/menu.h"
#include "..//util/utilidade.h"
void inicializadoMenu(){
    system(CLEAR);
    logoInicial();
    printf("--------------------\n");
    printf("  inicializando ...\n");
    printf("--------------------\n");

    Compra *cabecoteCompra =NULL ;
    Venda *cabecoteVenda = NULL;

    for (int i = 1; i <= 50; i++){
      printf ("  %d%%\r", i*2);
      fflush (stdout);

        for (int j = 0; j < i; j++){
            if (!j)
            printf("  ");

            printf ("%c", 2);
            #if defined(_WIN32) || defined(_WIN64)
                Sleep(0.5); 
            #else
                usleep(0.5*1000);  
            #endif
        }
    }

    menuPrincipal();
}

void sair(){
    system(CLEAR);
    liberaCompraVendaRegistro();
    logoInicial();
    printf("--------------------\n");
    printf("   Obrigado por utiliza \n Casa De Valores Mobiliario\n");
    printf("--------------------\n");
    exit(0);

}

void logoInicial(){

    printf("* °°  °  ° * *° °\n");
    printf("* °°  °  ° * *° °\n");
    printf("° °° .°*BEM-VINDO* ° °\n");
    printf(" ° °¨A CASA DE VALORES .°\n");
    printf("*° °. *MOBILIARIO*° *.°\n");
    printf("˛ *__________ * ° *°\n ");
    printf("*/____ ____/~\\ * ° °\n ");
    printf("*| []  [] || || ° °\n");

}

void menuPrincipal(){

    int opcao;

    do{
        system(CLEAR);
        logo();
        printf("1 - Lista ofertas\n");
        printf("2 - Inserir ofertas\n");
        printf("3 - Apaga ofertas\n");
        printf("4 - Negociar ofertas\n");
        printf("5 - Registro de Compra e Venda\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", & opcao);
        getchar();

        if(opcao<1 || opcao>6){
            printf("Por Favor, digite uma opcao valida...\naperte qualquer tecla para continua...");
            getchar();
        }
        
    }while(opcao<1 || opcao>6);

    switch (opcao){
        case 1: menuListaOferta(); break;
        case 2: menuInserirOferta(); break;
        case 3: menuApagaOferta(); break;
        case 4: negociaAcoes(); break;
        case 5: menuRegistro();break;
        case 6:sair();break;     
    }
}

void logo(){
    printf("---------------------------------\n");
    printf("    Casa de Valores Mobiliarios         \n");
    printf("---------------------------------\n\n");
}

void menuListaOferta(){
    int opcao;

    arquivoCompras();
    arquivoVendas();
    arquivoRegistros();


    do{
        system(CLEAR);
        logo();
        printf("1 - TSLA34 (TESLA)\n");
        printf("2 - FBOK34 (FACEBOOK)\n");
        printf("3 - AAPL34 (APPLE)\n");
        printf("4 - PETR4 (PETROBRAS)\n");
        printf("5 - Lista todas as ofertas\n");
        printf("6 - Volta\n");
        printf("Escolha uma opcao: ");
        scanf("%d", & opcao);
        getchar();

        if(opcao<1 || opcao>6){
            printf("Por Favor, digite uma opcao valida...\naperte qualquer tecla para continua...");
            getchar();
        }
        
    }while(opcao<1 || opcao>6);

    switch (opcao){
        case TSLA34: listaOferta(opcao); break;
        case FBOK34: listaOferta(opcao); break;
        case AAPL34: listaOferta(opcao);break;
        case PETR4: listaOferta(opcao); break;
        case 5: listaOferta(TODASAASOFERTA); break;
        case 6: menuPrincipal(); break;
    }
    
}

void menuInserirOferta(){
    int opcao;
    liberaCompraVendaRegistro();
    
    do{
        system(CLEAR);
        logo();
        printf("\nEscolha uma opcao de oferta para inserir:");
        printf("\n1 - Compra");
        printf("\n2 - Venda");
        printf("\n3 - Volta");
        printf("\nEscolha uma opcao:");
        scanf("%d", & opcao);
        getchar();
    }while(opcao<1 || opcao>3);

    switch (opcao){

        case COMPRA:inserirOfertaCompra(); break;
        case VENDA: inserirOfertaVenda();break;
        case 3: menuPrincipal(); break;
    } 
}

void menuApagaOferta(){
    int opcao;

    arquivoCompras();
    arquivoVendas();    

    do{
        system(CLEAR);
        logo();
        printf("\nEscolha uma opcao de oferta para apaga:");
        printf("\n1 - Compra");
        printf("\n2 - Venda");
        printf("\n3 - Volta");
        printf("\nEscolha uma opcao:");
        scanf("%d", & opcao);
        getchar();
        
    }while(opcao<1 || opcao>3);

    switch (opcao){

        case COMPRA:apagaCompra(); break;
        case VENDA:apagaVenda();break;
        case 3: menuPrincipal(); break;
    }

}

void menuRegistro(){
    int opcao;   
    arquivoRegistros();

    do{
        system(CLEAR);
        logo();
        printf("\nEscolha uma opcao de oferta:");
        printf("\n1 - Compra");
        printf("\n2 - Venda");
        printf("\n3 - Volta");
        printf("\nEscolha uma opcao:");
        scanf("%d", & opcao);
        getchar();
        
    }while(opcao<1 || opcao>3);

    switch (opcao){

        case COMPRA:registroCompra(); break;
        case VENDA:registroVenda();break;
        case 3: menuPrincipal(); break;
    }    
}