#include "..//model/acoes.h"
#include "..//util/utilidade.h"
#include "..//model/menu.h"

void listaOferta(int papel){
    system(CLEAR);
    int opcao;
    Compra* compra = NULL;
    Venda* venda = NULL;
    Registro* reg = NULL;

    if(papel){
        compra = listaCompra(compra,papel);
        venda = listaVenda(venda,papel); 
        
    }else{
        compra = cabecoteCompra;
        venda = cabecoteVenda;        
    }

    logo();

    if(compra == NULL || venda == NULL){
       
        if(compra == NULL )
            printf("Nao foi registrado nenhum oferta de compra para essa acao\n");
        
        if(venda == NULL)
            printf("Nao foi registrado nenhum oferta de Venda para essa acao\n");

        if(compra == NULL && venda==NULL){
            printf("Digite entre para continua...");
            getchar();
            system(CLEAR);
            menuListaOferta();
        }
    }

    if(compra !=NULL)ordenarCompras(compra);
    if(venda != NULL) ordenarVenda(venda);

    if(papel){
        reg = operacaoListaRegistro(reg,VENDA);
        reg = operacaoListaRegistro(reg,COMPRA);
        ordenarRegistro(reg);

        while(reg != NULL){

            if(reg->papel == papel){
                printf("------------------\n");
                printf("| cotacao : %.2f   |\n", reg->preco);
                printf("------------------\n");
                break;
            }

            reg = reg->proximaRegistro;
        }

        if(reg == NULL){
            printf("\nnao existir cotacao para essa acao\n");
        }
    }
    

    printf("-------------------------------------------BOOK DE OFERTA------------------------------------------\n\n");          

    while(compra != NULL || venda !=NULL){
        
        if(compra!=NULL){
            printfCompra(compra);
            compra = compra->proximaCompra;
        }else{
            printf("\t\t\t\t\t");
        }
        printf("\t\t");

        if(venda!=NULL){
            printfVenda(venda); 
            venda = venda->proximaVenda;
        } 

        printf("\n");  
    }
    printf("--------------------------------------------------------------------------------------------------\n");
    compra = compraLibera(compra);
    venda = vendaLibera(venda);

    printf("\nDigite qualquer tecla para continua...");
    getchar();
    system(CLEAR);
    menuListaOferta();
}

void printfCompra(Compra* compra){
    
    if(TSLA34 == compra->papel)
        printf("| TSLA34 | COMPRA | QT: %d | PRECO: %.2f |", compra->acoes , compra->precoCompra);
    else if(FBOK34 == compra->papel)
        printf("| FBOK34 | COMPRA | QT: %d | PRECO: %.2f |", compra->acoes , compra->precoCompra);
    else if(AAPL34 == compra->papel)
        printf("| AAPL34 | COMPRA | QT: %d | PRECO: %.2f |", compra->acoes , compra->precoCompra);
    else if(PETR4 == compra->papel)
        printf("| PETR4 | COMPRA | QT: %d | PRECO: %.2f |", compra->acoes , compra->precoCompra);

}

void printfVenda(Venda* venda){
    
    if(TSLA34 == venda->papel)
        printf("| TSLA34 | VENDA | QT: %d | PRECO: %.2f |", venda->acoes , venda->precoVenda);
    else if(FBOK34 == venda->papel)
        printf("| FBOK34 | VENDA | QT: %d | PRECO: %.2f |", venda->acoes , venda->precoVenda);
    else if(AAPL34 == venda->papel)
        printf("| AAPL34 | VENDA | QT: %d | PRECO: %.2f |", venda->acoes , venda->precoVenda);
    else if(PETR4 == venda->papel)
        printf("| PETR4 | VENDA | QT: %d | PRECO: %.2f |", venda->acoes , venda->precoVenda);
}

void inserirOfertaCompra(){
    
    int opcao;
    Compra compra;

    do{
        do{
            system(CLEAR);
            logo();
            printf("De qual cotacao deseja comprar:\n");
            printf("1 - TSLA34 (TESLA)\n");
            printf("2 - FBOK34 (FACEBOOK)\n");
            printf("3 - AAPL34 (APPLE)\n");
            printf("4 - PETR4 (PETROBRAS)\n");
            printf("5 - Volta\n");
            printf("Escolha uma opcao: ");
            scanf("%d", & opcao);
            getchar();

            if(opcao<1 || opcao>5){
                printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                getchar();
            }
        }while(opcao<1 || opcao>5);

        switch (opcao){
            case TSLA34: compra.papel = TSLA34; break;
            case FBOK34: compra.papel = FBOK34; break;
            case AAPL34: compra.papel = AAPL34;break;
            case PETR4: compra.papel = PETR4 ; break;
            case 5: menuInserirOferta(); break;
        }

        do{
            printf("\nDigite o valor de compra: R$");
            scanf("%f", & compra.precoCompra);
            getchar();

            if(compra.precoCompra<0){
                printf("Atencao: valor informado invalido\n");
                printf("Digite um valor positivo\n");
            }

        }while(compra.precoCompra<0);

        do{

            printf("\nQuantidade de acoes:");
            scanf("%d", & compra.acoes);
            getchar();

            if(compra.precoCompra<0){
                printf("Atencao: valor informado invalido\n");
                printf("Digite um valor positivo\n");
            }

        }while(compra.acoes<=0);

        do{
            printf("\n\n");
            printfCompra(&compra);
            printf("\nConfimar:\n1 - SIM\n2 - NAO\n");
            printf("Escolha uma opcao:");
            scanf("%d",& opcao);
            getchar(); 

            if(opcao<1 || opcao>2){
                printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                getchar();
            }

        }while(opcao<1 || opcao>2);

    }while(opcao ==2);    

    FILE * file  = fopen("docs/compras.txt","a+");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        fprintf(file,"%d %d %.2f\n",compra.papel,compra.acoes,compra.precoCompra);
    }

    fclose(file);

    printf("Oferta de Compra registrada com sucesso");
    printf("\nDigiteentra para continua...");
    getchar();  
    system(CLEAR);  
    menuInserirOferta();
}

void inserirOfertaVenda(){
    
    int opcao;
    Venda venda;

    do{
        do{
            system(CLEAR);
            logo();
            printf("De qual cotacao deseja vender:\n");
            printf("1 - TSLA34 (TESLA)\n");
            printf("2 - FBOK34 (FACEBOOK)\n");
            printf("3 - AAPL34 (APPLE)\n");
            printf("4 - PETR4 (PETROBRAS)\n");
            printf("5 - Volta\n");
            printf("Escolha uma opcao: ");
            scanf("%d", & opcao);
            getchar();

            if(opcao<1 || opcao>5){
                printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                getchar();
            }
        }while(opcao<1 || opcao>5);

        switch (opcao){
            case TSLA34: venda.papel = TSLA34; break;
            case FBOK34: venda.papel = FBOK34; break;
            case AAPL34: venda.papel = AAPL34;break;
            case PETR4: venda.papel = PETR4 ; break;
            case 5: menuInserirOferta(); break;
        }

        do{
            printf("\nDigite o valor da venda: R$");
            scanf("%f", & venda.precoVenda);
            getchar();

            if(venda.precoVenda<0){
                printf("Atencao: valor informado invalido\n");
                printf("Digite um valor positivo\n");
            }

        }while(venda.precoVenda<0);

        do{

            printf("\nQuantidade de acoes:");
            scanf("%d", & venda.acoes);
            getchar();

            if(venda.acoes<0){
                printf("Atencao: valor informado invalido\n");
                printf("Digite um valor positivo\n");
            }

        }while(venda.acoes<=0);

        do{
            printf("\n\n");
            printfVenda(&venda);
            printf("\nConfimar:\n1 - SIM\n2 - NAO\n");
            printf("Escolha uma opcao:");
            scanf("%d",& opcao);
            getchar(); 

            if(opcao<1 || opcao>2){
                printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                getchar();
            }

        }while(opcao<1 || opcao>2);

    }while(opcao ==2);    

    FILE * file  = fopen("docs/vendas.txt","a+");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        fprintf(file,"%d %d %.2f\n",venda.papel,venda.acoes,venda.precoVenda);
    }

    fclose(file);

    printf("Oferta de venda registrada com sucesso");
    printf("\nDigite entre para continua...");
    getchar();  
    system(CLEAR);  
    menuInserirOferta();
}

void apagaCompra(){
    
    int opcao,papel, id = 0,idAux = 1;
    Compra* compra = NULL;
    Compra* auxCompra =NULL;

    do{
        system(CLEAR);
        logo();
        printf("De qual cotacao deseja apaga:\n");
        printf("1 - TSLA34 (TESLA)\n");
        printf("2 - FBOK34 (FACEBOOK)\n");
        printf("3 - AAPL34 (APPLE)\n");
        printf("4 - PETR4 (PETROBRAS)\n");
        printf("5 - Todas as oferta de compra\n");
        printf("6 - Volta\n");
        printf("Escolha uma opcao: ");
        scanf("%d", & opcao);
        getchar();

        if(opcao<1 || opcao>6){
            printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
            getchar();
        }
    }while(opcao<1 || opcao>6);

    switch (opcao){
        case TSLA34: papel = TSLA34; break;
        case FBOK34: papel = FBOK34; break;
        case AAPL34: papel = AAPL34;break;
        case PETR4: papel = PETR4 ; break;
        case 6: menuInserirOferta(); break;
    }

    if(opcao == 5){
        compra = cabecoteCompra;

        if(compra == NULL){
            printf("Nao foi registrado nenhum oferta de compra para essa acao\n");
            printf("\naperte entre para continua...");
            getchar();
        }
        
        while(compra!=NULL){
            retiraCompra(compra);
            compra = compra->proximaCompra;
        }

        printf("Todas as ofertas de compra eliminadas com Sucesso...\naperte entre para continua...");
        getchar();

    }else{

        compra = listaCompra(compra,papel);

        if(compra==NULL){
            printf("Nao foi registrado nenhum oferta de compra para essa acao\n");
            printf("aperte entre para continua...");
            getchar();
            apagaCompra();
        }else{
            ordenarCompras(compra);
        }


        Compra* aux = compra;
        printf("-------------------------------------------BOOK DE OFERTA------------------------------------------\n\n");          

        while(aux != NULL ){
            id++;
            printf("ID - %d ", id);
            printfCompra(aux);
            printf("\n");
            aux = aux->proximaCompra;
        }
        printf("--------------------------------------------------------------------------------------------------\n");

        do{
            printf("\nDigite um id: ");
            scanf("%d", & opcao);
            getchar();        

            if(opcao<1 || opcao>id){
                printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                getchar();
            }

        }while(opcao<1 || opcao>id);
        id = opcao;
        aux = compra;

        while(aux != NULL && idAux != id){
            aux = aux->proximaCompra;
            idAux++;
        }

        do{
            printf("\n\n");
            printfCompra(aux);
            printf("\nConfimar:\n1 - SIM\n2 - NAO\n");
            printf("Escolha uma opcao:");
            scanf("%d",& opcao);
            getchar(); 

            if(opcao<1 || opcao>2){
                printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                getchar();
            }

        }while(opcao<1 || opcao>2);

        retiraCompra(aux);

        printf("Oferta de compra eliminada com Sucesso...\naperte entre para continua...");
        getchar();
    }

    apagaCompra();
}

void apagaVenda(){
    
    int opcao,papel, id = 0,idAux = 1;
    Venda* venda = NULL;
    Venda* auxVenda =NULL;

    do{
        system(CLEAR);
        logo();
        printf("De qual cotacao deseja apaga:\n");
        printf("1 - TSLA34 (TESLA)\n");
        printf("2 - FBOK34 (FACEBOOK)\n");
        printf("3 - AAPL34 (APPLE)\n");
        printf("4 - PETR4 (PETROBRAS)\n");
        printf("5 - Todas as vendas\n");
        printf("6 - Volta\n");
        printf("Escolha uma opcao: ");
        scanf("%d", & opcao);
        getchar();

        if(opcao<1 || opcao>6){
            printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
            getchar();
        }
    }while(opcao<1 || opcao>6);

    switch (opcao){
        case TSLA34: papel = TSLA34; break;
        case FBOK34: papel = FBOK34; break;
        case AAPL34: papel = AAPL34;break;
        case PETR4: papel = PETR4 ; break;
        case 6: menuInserirOferta(); break;
    }

    if(opcao == 5){
        venda = cabecoteVenda;

        if(venda == NULL){
            printf("Nao foi registrado nenhum oferta de venda para essa acao\n");
            printf("\naperte entre para continua...");
            getchar();
        }
        
        while(venda!=NULL){
            retiraVenda(venda);
            venda = venda->proximaVenda;
        }

        printf("Todas as ofertas de vendas eliminadas com Sucesso...\naperte entre para continua...");
        getchar();

    }else{
        venda = listaVenda(venda,papel);

        if(venda==NULL){
            printf("Nao foi registrado nenhum oferta de venda para essa acao\n");
            printf("\naperte entre para continua...");
            getchar();
            apagaVenda();
        }else{
            ordenarVenda(venda);
        }


        Venda* aux = venda;
        printf("-------------------------------------------BOOK DE OFERTA------------------------------------------\n\n");          

        while(aux != NULL ){
            id++;
            printf("ID - %d ", id);
            printfVenda(aux);
            printf("\n");
            aux = aux->proximaVenda;
        }
        printf("--------------------------------------------------------------------------------------------------\n");

        do{
            printf("\nDigite um id: ");
            scanf("%d", & opcao);
            getchar();        

            if(opcao<1 || opcao>id){
                printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                getchar();
            }

        }while(opcao<1 || opcao>id);
        id = opcao;
        aux = venda;

        while(aux != NULL && idAux != id){
            aux = aux->proximaVenda;
            idAux++;
        }

        do{
            printf("\n\n");
            printfVenda(aux);
            printf("\nConfimar:\n1 - SIM\n2 - NAO\n");
            printf("Escolha uma opcao:");
            scanf("%d",& opcao);
            getchar(); 

            if(opcao<1 || opcao>2){
                printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                getchar();
            }

        }while(opcao<1 || opcao>2);

        retiraVenda(aux);

        printf("Oferta de venda eliminada com Sucesso...\naperte entre para continua...");
        getchar();
    }

    apagaVenda();

}

void negociaAcoes(){

    int opcao,papel,operacao,id = 0,idAux = 1;

    arquivoCompras();
    arquivoVendas();
    arquivoRegistros();

    Compra* compra = NULL;
    Venda* venda = NULL;
    
    if(cabecoteCompra ==NULL)
        printf("nao existe nenhum oferta de compra registrada\n");
    if(cabecoteVenda ==NULL)
        printf("nao existe nenhuk oferta de venda registrada\n");
    if(cabecoteVenda == NULL || cabecoteCompra ==NULL){
        printf("Digite entre para continua...");
        getchar();
        menuPrincipal();
    }

    do{
        system(CLEAR);
        logo();
        printf("Escolha uma cotacao:\n");
        printf("1 - TSLA34 (TESLA)\n");
        printf("2 - FBOK34 (FACEBOOK)\n");
        printf("3 - AAPL34 (APPLE)\n");
        printf("4 - PETR4 (PETROBRAS)\n");
        printf("5 - Volta\n");
        printf("Escolha uma opcao: ");
        scanf("%d", & papel);
        getchar();

        if(papel<1 || papel>5){
            printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
            getchar();
        }

    }while(papel<1 || papel>5);

    switch (papel){
        case TSLA34: papel = TSLA34; break;
        case FBOK34: papel = FBOK34; break;
        case AAPL34: papel = AAPL34;break;
        case PETR4: papel = PETR4 ; break;
        case 5: menuInserirOferta(); break;
    }

    compra = listaCompra(compra,papel);
    venda = listaVenda(venda,papel);

    if(compra ==NULL)
        printf("nao existe nenhum oferta de compra registrada para essa acao\n");
    if(venda ==NULL)
        printf("nao existe nenhuk oferta de venda registrada para essa acao\n");
    if(venda == NULL || compra ==NULL){
        printf("Digite entre para continua...");
        getchar();
        negociaAcoes();
    }

    ordenarCompras(compra);
    ordenarVenda(venda);

    do{
        printf("Escolha uma operacao:\n");
        printf("1 - Compra\n");
        printf("2 - Venda\n");
        printf("Digite uma opcao:");
        scanf("%d", & operacao);

        if(operacao<1 || operacao>2){
            printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
            getchar();   
        }
            
    }while(operacao<1 || operacao>2);


    if(operacao ==COMPRA){
        Compra* aux = NULL;

        do{
            system(CLEAR);
            Registro* reg = NULL;
            reg = operacaoListaRegistro(reg,VENDA);
            reg = operacaoListaRegistro(reg,COMPRA);
            ordenarRegistro(reg);

            while(reg != NULL){

                if(reg->papel == papel){
                    printf("------------------\n");
                    printf("| cotacao : %.2f   |\n", reg->preco);
                    printf("------------------\n");
                    break;
                }

                reg = reg->proximaRegistro;
            }

            if(reg == NULL){
                printf("\nnao existir cotacao para essa acao\n");
            }
            
    

            aux = compra;
            printf("--------------------BOOK DE OFERTA DE COMPRA-------------------------------\n\n");          

            while(aux != NULL ){
                id++;
                printf("ID - %d ", id);
                printfCompra(aux);
                printf("\n");
                aux = aux->proximaCompra;
                
            }
            printf("---------------------------------------------------------------------------\n");

            do{
                printf("\nDigite um id da oferta de compra cadastrada: ");
                scanf("%d", & opcao);
                getchar();        

                if(opcao<1 || opcao>id){
                    printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                    getchar();
                }

            }while(opcao<1 || opcao>id);
            id = opcao;
            aux = compra;

            while(aux != NULL && idAux !=id){
                aux = aux->proximaCompra;
                idAux++;
            }
           
            do{
                printf("\n\n");
                printfCompra(aux);
                printf("\nConfimar:\n1 - SIM\n2 - NAO\n");
                printf("Escolha uma opcao:");
                scanf("%d",& opcao);
                getchar(); 

                if(opcao<1 || opcao>2){
                    printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                    getchar();
                }

            }while(opcao<1 || opcao>2);
        }while(opcao==2);


        Venda* auxVenda = venda;
        Venda * match = NULL;
        Venda *auxMatch = NULL;
        Registro reg;

        while(auxVenda != NULL){
            if(aux->papel ==auxVenda->papel &&  auxVenda->acoes >= aux->acoes &&  aux->precoCompra >= auxVenda->precoVenda){
                Venda v;
                v.acoes = auxVenda->acoes;
                v.papel = auxVenda ->papel;
                v.precoVenda = auxVenda->precoVenda;
                match = vendaInsere(match,v);
            }
            auxVenda = auxVenda->proximaVenda;
        }

        if(match == NULL){
            printf("Nao encontramos nenhum match com essa oferta de compra...\naperte entre para continua...");
            getchar();
            negociaAcoes();
        }
        ordenarVenda(match);
        

        do{
            system(CLEAR);
            Registro* reg = NULL;
            reg = operacaoListaRegistro(reg,VENDA);
            reg = operacaoListaRegistro(reg,COMPRA);
            ordenarRegistro(reg);

            while(reg != NULL){

                if(reg->papel == papel){
                    printf("------------------\n");
                    printf("| cotacao : %.2f   |\n", reg->preco);
                    printf("------------------\n");
                    break;
                }

                reg = reg->proximaRegistro;
            }

            if(reg == NULL){
                printf("\nnao existir cotacao para essa acao\n");
            }
            
            printf("--------------------BOOK DE OFERTA DE VENDA-------------------------------\n\n");          
            id = 0,idAux = 1;

            auxMatch = match;
            while(auxMatch != NULL ){
                id++;
                printf("ID - %d ", id);
                printfVenda(auxMatch);
                printf("\n");
                auxMatch = auxMatch->proximaVenda;
            }
            printf("---------------------------------------------------------------------------\n");

            do{
                printf("\nDigite um id: ");
                scanf("%d", & opcao);
                getchar();        

                if(opcao<1 || opcao>id){
                    printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                    getchar();
                }

            }while(opcao<1 || opcao>id);
            auxMatch = match;

            while(auxMatch != NULL && idAux != opcao){
                auxMatch = auxMatch->proximaVenda;
                idAux++;
            }

            do{
                printf("\n\n");
                printfVenda(auxMatch);
                printf("\nConfimar:\n1 - SIM\n2 - NAO\n");
                printf("Escolha uma opcao:");
                scanf("%d",& opcao);
                getchar(); 

                if(opcao<1 || opcao>2){
                    printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                    getchar();
                }

            }while(opcao<1 || opcao>2);
        
        }while(opcao == 2);

        if(aux->precoCompra == auxMatch ->precoVenda){
            reg.preco = aux->precoCompra;
        }else{
            reg.preco = (aux->precoCompra + auxMatch->precoVenda) /2;
        }

        printf("O valor ser pago e : %.2f\n", reg.preco);

        reg.acoes = aux-> acoes;
        reg.papel = aux->papel;
        reg.operacao = COMPRA;
        cabecoteRegistro = registroInsere(cabecoteRegistro,reg);
        atualizaRegistro();

        if(auxMatch->acoes == aux ->acoes){
            retiraVenda(auxMatch);
        }else{
            Venda copia;
            copia.acoes = auxMatch->acoes - aux->acoes;
            copia.papel = auxMatch->papel;
            copia.precoVenda = auxMatch ->precoVenda;
            retiraVenda(auxMatch);
            cabecoteVenda = vendaInsere(cabecoteVenda,copia);
            atualizaVenda();
        }

        retiraCompra(aux);
    
        printf("Operacao realizada com sucesso...\naperte entre para continua...");


    }else{

    
        Venda* aux = NULL;

        do{
            system(CLEAR);
            Registro* reg = NULL;
            reg = operacaoListaRegistro(reg,VENDA);
            reg = operacaoListaRegistro(reg,COMPRA);
            ordenarRegistro(reg);

            while(reg != NULL){

                if(reg->papel == papel){
                    printf("------------------\n");
                    printf("| cotacao : %.2f   |\n", reg->preco);
                    printf("------------------\n");
                    break;
                }

                reg = reg->proximaRegistro;
            }

            if(reg == NULL){
                printf("\nnao existir cotacao para essa acao\n");
            }

            aux = venda;
            printf("--------------------BOOK DE OFERTA DE VENDA-------------------------------\n\n");          

            while(aux != NULL ){
                id++;
                printf("ID - %d ", id);
                printfVenda(aux);
                printf("\n");
                aux = aux->proximaVenda;
                
            }
            printf("---------------------------------------------------------------------------\n");

            do{
                printf("\nDigite um id da oferta de compra cadastrada: ");
                scanf("%d", & opcao);
                getchar();        

                if(opcao<1 || opcao>id){
                    printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                    getchar();
                }

            }while(opcao<1 || opcao>id);
            id = opcao;
            aux = venda;

            while(aux != NULL && idAux !=id){
                aux = aux->proximaVenda;
                idAux++;
            }
           
            do{
                printf("\n\n");
                printfVenda(aux);
                printf("\nConfimar:\n1 - SIM\n2 - NAO\n");
                printf("Escolha uma opcao:");
                scanf("%d",& opcao);
                getchar(); 

                if(opcao<1 || opcao>2){
                    printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                    getchar();
                }

            }while(opcao<1 || opcao>2);
        }while(opcao==2);


        Compra* auxCompra = compra;
        Compra * match = NULL;
        Compra *auxMatch = NULL;
        Registro reg;

        while(auxCompra != NULL){

            if(aux->papel ==auxCompra->papel && auxCompra->acoes >= aux-> acoes && auxCompra->precoCompra >= aux->precoVenda){
                Compra v;
                v.acoes = auxCompra->acoes;
                v.papel = auxCompra ->papel;
                v.precoCompra = auxCompra->precoCompra;
                match = compraInsere(match,v);
            }

            auxCompra = auxCompra->proximaCompra;
        }

        if(match == NULL){
            printf("Nao encontramos nenhum match com essa oferta de venda...\naperte entre para continua...");
            getchar();
            negociaAcoes();
        }
        ordenarCompras(match);
        

        do{
            system(CLEAR);
            Registro* reg = NULL;
            reg = operacaoListaRegistro(reg,VENDA);
            reg = operacaoListaRegistro(reg,COMPRA);
            ordenarRegistro(reg);

            while(reg != NULL){

                if(reg->papel == papel){
                    printf("------------------\n");
                    printf("| cotacao : %.2f   |\n", reg->preco);
                    printf("------------------\n");
                    break;
                }

                reg = reg->proximaRegistro;
            }

            if(reg == NULL){
                printf("\nnao existir cotacao para essa acao\n");
            }
            
            printf("--------------------BOOK DE OFERTA DE COMPRA-------------------------------\n\n");          
            id = 0,idAux = 1;

            auxMatch = match;
            while(auxMatch != NULL ){
                id++;
                printf("ID - %d ", id);
                printfCompra(auxMatch);
                printf("\n");
                auxMatch = auxMatch->proximaCompra;
            }
            printf("---------------------------------------------------------------------------\n");

            do{
                printf("\nDigite um id: ");
                scanf("%d", & opcao);
                getchar();        

                if(opcao<1 || opcao>id){
                    printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                    getchar();
                }

            }while(opcao<1 || opcao>id);
            id = opcao;
            auxMatch = match;

            while(auxMatch != NULL && idAux != id){
                auxMatch = auxMatch->proximaCompra;
                idAux++;
            }

            do{
                printf("\n\n");
                printfCompra(auxMatch);
                printf("\nConfimar:\n1 - SIM\n2 - NAO\n");
                printf("Escolha uma opcao:");
                scanf("%d",& opcao);
                getchar(); 

                if(opcao<1 || opcao>2){
                    printf("Por Favor, digite uma opcao valida...\naperte entre para continua...");
                    getchar();
                }

            }while(opcao<1 || opcao>2);
        
        }while(opcao == 2);

        if(aux->precoVenda == auxMatch ->precoCompra){
            reg.preco = aux->precoVenda;
        }else{
            reg.preco = (aux->precoVenda + auxMatch->precoCompra) /2;
        }

        printf("O valor ser pago e : %.2f\n", reg.preco);

        reg.acoes = aux-> acoes;
        reg.papel = aux->papel;
        reg.operacao = VENDA;
        cabecoteRegistro = registroInsere(cabecoteRegistro,reg);
        atualizaRegistro();

        if(auxMatch->acoes == aux ->acoes){
            retiraCompra(auxMatch);
        }else{
            Compra copia;
            copia.acoes = auxMatch->acoes - aux->acoes;
            copia.papel = auxMatch->papel;
            copia.precoCompra = auxMatch ->precoCompra;
            
            retiraCompra(auxMatch);
            cabecoteCompra = compraInsere(cabecoteCompra,copia);
            atualizaCompra();
        }

        retiraVenda(aux);
    
        printf("Operacao realizada com sucesso...\naperte entre para continua...");
    }

    getchar();
    menuPrincipal();
}

void registroCompra(){
    system(CLEAR);
    Registro * reg = NULL;
    reg = operacaoListaRegistro(reg,COMPRA);

    if(reg ==NULL){
        printf("Nenhum registro de compra encontrado\n");
        printf("Aperte entre para continua...");
        getchar();
        menuRegistro();
    }
    ordenarRegistro(reg);

    printf("-------------------------------------------HISTORICO DE COMPRA------------------------------------------\n\n");          

    while(reg != NULL){
      printfRegistro(reg);
      reg = reg->proximaRegistro;
    }

    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("\n\nAperte entra para volta...");
    getchar();
    menuRegistro();
}

void registroVenda(){
    system(CLEAR);
    Registro * reg = NULL;
    reg = operacaoListaRegistro(reg,VENDA);

    if(reg ==NULL){
        printf("Nenhum registro de compra encontrado\n");
        printf("Aperte entre para continua...");
        getchar();
        menuRegistro();
    }
    ordenarRegistro(reg);

    printf("-------------------------------------------HISTORICO DE VENDA------------------------------------------\n\n");          

    while(reg != NULL){
      printfRegistro(reg);
      reg = reg->proximaRegistro;
    }

    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("\n\nAperte entra para volta...");
    getchar();
    menuRegistro();
}

void printfRegistro(Registro* reg){
    
    if(reg ->operacao == COMPRA){

        if(TSLA34 == reg->papel)
            printf("| TSLA34 | COMPRA | QT: %d | PRECO: %.2f | Ano : %d| Mes : %d | Dia : %d | Horas: %d | Minutos: %d | Segundo: %d|\n", reg->acoes , reg->preco, reg->ano, reg->mes, reg->dia, reg->horas,reg->minutos,reg->segundos);
        else if(FBOK34 == reg->papel)
            printf("| FBOK34 | COMPRA | QT: %d | PRECO: %.2f | Ano : %d| Mes : %d | Dia : %d | Horas: %d | Minutos: %d | Segundo: %d|\n", reg->acoes , reg->preco, reg->ano, reg->mes, reg->dia, reg->horas,reg->minutos,reg->segundos);
        else if(AAPL34 == reg->papel)
            printf("| AAPL34 | COMPRA | QT: %d | PRECO: %.2f | Ano : %d| Mes : %d | Dia : %d | Horas: %d | Minutos: %d | Segundo: %d|\n", reg->acoes , reg->preco, reg->ano, reg->mes, reg->dia, reg->horas,reg->minutos,reg->segundos);
        else if(PETR4 == reg->papel)
            printf("| PETR4  | COMPRA | QT: %d | PRECO: %.2f | Ano : %d| Mes : %d | Dia : %d | Horas: %d | Minutos: %d | Segundo: %d|\n", reg->acoes , reg->preco, reg->ano, reg->mes, reg->dia, reg->horas,reg->minutos,reg->segundos);

    }else{

        if(TSLA34 == reg->papel)
            printf("| TSLA34 | VENDA | QT: %d | PRECO: %.2f | Ano : %d| Mes : %d | Dia : %d | Horas: %d | Minutos: %d | Segundo: %d|\n", reg->acoes , reg->preco, reg->ano, reg->mes, reg->dia, reg->horas,reg->minutos,reg->segundos);
        else if(FBOK34 == reg->papel)
            printf("| FBOK34 | VENDA | QT: %d | PRECO: %.2f | Ano : %d| Mes : %d | Dia : %d | Horas: %d | Minutos: %d | Segundo: %d|\n", reg->acoes , reg->preco, reg->ano, reg->mes, reg->dia, reg->horas,reg->minutos,reg->segundos);
        else if(AAPL34 == reg->papel)
            printf("| AAPL34 | VENDA | QT: %d | PRECO: %.2f | Ano : %d| Mes : %d | Dia : %d | Horas: %d | Minutos: %d | Segundo: %d|\n", reg->acoes , reg->preco, reg->ano, reg->mes, reg->dia, reg->horas,reg->minutos,reg->segundos);
        else if(PETR4 == reg->papel)
            printf("| PETR4  | VENDA | QT: %d | PRECO: %.2f | Ano : %d| Mes : %d | Dia : %d | Horas: %d | Minutos: %d | Segundo: %d|\n", reg->acoes , reg->preco, reg->ano, reg->mes, reg->dia, reg->horas,reg->minutos,reg->segundos);

    }
}