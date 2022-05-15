#include <time.h>
#include "..//model//acoes.h"
#include "..//util/utilidade.h"
void arquivoCompras(){

    cabecoteCompra = compraLibera(cabecoteCompra);
    Compra arquivo;   
    FILE * file  = fopen("docs/compras.txt","a+");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f", &arquivo.papel,&arquivo.acoes,&arquivo.precoCompra) != EOF ){
            cabecoteCompra = compraInsere(cabecoteCompra,arquivo);
        }
    }
    fclose(file);
}

Compra* compraLibera(Compra* compra){
    Compra* p = compra;
    while(p!=NULL){
        Compra* t = p->proximaCompra;
        free(p);
        p = t;
    } 
    return p;
}

Compra* compraInsere(Compra* compra,Compra aux){
    Compra* novo = (Compra*) malloc(sizeof(Compra));
    novo->acoes = aux.acoes;
    novo->papel = aux.papel;
    novo->precoCompra = aux.precoCompra;
    novo->proximaCompra = compra;
    return novo;
}

void ordenarCompras(Compra* compra){

	int aux_int;
	float aux_float;

    Compra *atual = compra;

    while(atual!=NULL){
        
        Compra *aux = atual ->proximaCompra;

        while(aux!=NULL){
            if(aux->precoCompra > atual->precoCompra){
                
                aux_float = aux->precoCompra;
                aux->precoCompra = atual->precoCompra;
                atual->precoCompra = aux_float;

                aux_int = aux->acoes;
                aux->acoes = atual->acoes;
                atual->acoes = aux_int;

                aux_int = aux->papel;
                aux->papel = atual->papel;
                atual->papel = aux_int;
            }else if( aux->precoCompra == atual->precoCompra && aux->acoes>atual->acoes){
                
                aux_float = aux->precoCompra;
                aux->precoCompra = atual->precoCompra;
                atual->precoCompra = aux_float;

                aux_int = aux->acoes;
                aux->acoes = atual->acoes;
                atual->acoes = aux_int;

                aux_int = aux->papel;
                aux->papel = atual->papel;
                atual->papel = aux_int;
            }
            aux = aux->proximaCompra;
        }

        atual= atual->proximaCompra;
    }
  
}

void arquivoRegistros(){

    cabecoteRegistro = registroLibera(cabecoteRegistro);
    Registro arquivo;   
    FILE * file  = fopen("docs/Registro.txt","a+");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f %d %d %d %d %d %d %d", &arquivo.papel,&arquivo.acoes,&arquivo.preco, &arquivo.operacao, &arquivo.ano, &arquivo.mes,&arquivo.dia, &arquivo.horas, &arquivo.minutos,&arquivo.segundos) != EOF ){      
            cabecoteRegistro = registroInsereComData(cabecoteRegistro,arquivo);
        }
    }
    fclose(file);
}

Registro* registroLibera(Registro* reg){
    Registro* p = reg;
    while(p!=NULL){
        Registro* t = p->proximaRegistro;
        free(p);
        p = t;
    } 
    return p;
}

Registro* registroInsereComData(Registro* reg,Registro aux){
    Registro* novo = (Registro*) malloc(sizeof(Registro));
    novo->acoes = aux.acoes;
    novo->papel = aux.papel;
    novo->preco = aux.preco;
    novo->operacao = aux.operacao;
    novo->ano = aux.ano;
    novo->mes = aux.mes;
    novo->dia = aux.dia;
    novo->horas = aux.horas;
    novo ->minutos = aux.minutos;
    novo->segundos = aux.segundos;
    novo->proximaRegistro = reg;

    return novo;
}

void arquivoVendas(){

    cabecoteVenda = vendaLibera(cabecoteVenda);
    Venda arquivo;
  
    FILE * file  = fopen("docs/vendas.txt","a+");

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
    }else{
        while (fscanf(file, "%d %d %f", &arquivo.papel,&arquivo.acoes,&arquivo.precoVenda) != EOF ){
           cabecoteVenda = vendaInsere(cabecoteVenda,arquivo);
        }
    }
    fclose(file);
}

Venda* vendaLibera(Venda* venda){
    Venda* p = venda;
    while(p!=NULL){
        Venda* t = p->proximaVenda;
        free(p);
        p = t;
    } 
    return p;
}

Venda* vendaInsere(Venda* venda, Venda aux){
    Venda* novo = (Venda*) malloc(sizeof(Venda));
    novo->acoes = aux.acoes;
    novo->papel = aux.papel;
    novo->precoVenda = aux.precoVenda;
    novo->proximaVenda = venda;
    return novo;
}

void ordenarVenda(Venda* venda){
	Venda *atual = venda;
	int aux_i;
	float aux_f;
	  
    while(atual != NULL) {
        Venda* indice = atual->proximaVenda;
        while(indice != NULL) {

            if(atual->precoVenda > indice->precoVenda){
              
                aux_f = atual->precoVenda;
                atual->precoVenda = indice->precoVenda;
                indice->precoVenda = aux_f;

                aux_i = atual->acoes;
                atual->acoes = indice->acoes;
                indice->acoes = aux_i;

                aux_i = atual->papel;
                atual->papel =  indice->papel;
                indice->papel = aux_i;   

            }else if(atual->precoVenda == indice->precoVenda && atual->acoes < indice->acoes){
                
                aux_f = atual->precoVenda;
                atual->precoVenda = indice->precoVenda;
                indice->precoVenda = aux_f;

                aux_i = atual->acoes;
                atual->acoes = indice->acoes;
                indice->acoes = aux_i;

                aux_i = atual->papel;
                atual->papel =  indice->papel;
                indice->papel = aux_i;
            }

            indice = indice->proximaVenda;
        }
        atual = atual->proximaVenda;
    }
}


Compra* listaCompra(Compra* no,int papel){
    Compra* geral = cabecoteCompra;
    Compra aux;

    while(geral!=NULL){

        if(geral->papel == papel){
            aux.acoes = geral->acoes;
            aux.papel = geral->papel;
            aux.precoCompra = geral->precoCompra;
            no = compraInsere(no,aux);
        }

        geral = geral->proximaCompra;
    }

    return no;
}

Venda* listaVenda(Venda* no, int papel){
    Venda* geral = cabecoteVenda;
    Venda aux;

    while(geral!=NULL){

        if(geral->papel == papel){
            aux.acoes = geral->acoes;
            aux.papel = geral->papel;
            aux.precoVenda = geral->precoVenda;
            no = vendaInsere(no,aux);
        }

        geral = geral->proximaVenda;
    }

    return no;
}

void liberaCompraVendaRegistro(){
    cabecoteCompra = compraLibera(cabecoteCompra);
    cabecoteVenda = vendaLibera(cabecoteVenda);
    cabecoteRegistro = registroLibera(cabecoteRegistro);
}

void retiraCompra(Compra* compra){
  
    Compra* p = cabecoteCompra;
    Compra* ant = NULL;

    while(p!=NULL && p->acoes != compra->acoes && p->papel != compra->papel && p->precoCompra != compra->precoCompra){
        ant = p;
        p = p->proximaCompra;
    }

    if(p==NULL){
        apagaCompra();
    }

    if(ant==NULL){
        cabecoteCompra = cabecoteCompra->proximaCompra;
    }else{
        ant->proximaCompra = p->proximaCompra;
    }
    
    free(p);

    FILE * file  = fopen("docs/compras.txt","w");
    Compra * aux = cabecoteCompra;

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
        apagaCompra();
    }else{
        while(aux!=NULL){
            fprintf(file,"%d %d %.2f\n",aux->papel,aux->acoes,aux->precoCompra);
            aux = aux->proximaCompra;
        }
    }
    fclose(file);    

}

void retiraVenda(Venda* venda){
    
    Venda* p = cabecoteVenda;
    Venda* ant = NULL;

    while(p!=NULL && p->acoes != venda->acoes && p->papel != venda->papel && p->precoVenda != venda->precoVenda){
        ant = p;
        p = p->proximaVenda;
    }

    if(p==NULL){
        apagaVenda();
    }

    if(ant==NULL){
        cabecoteVenda = cabecoteVenda->proximaVenda;
    }else{
        ant->proximaVenda = p->proximaVenda;
    }
    
    free(p);

    FILE * file  = fopen("docs/vendas.txt","w");
    Venda * aux = cabecoteVenda;

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
        apagaCompra();
    }else{
        while(aux!=NULL){
            fprintf(file,"%d %d %.2f\n",aux->papel,aux->acoes,aux->precoVenda);
            aux = aux->proximaVenda;
        }
    }
    fclose(file); 
}

void atualizaVenda(){
    FILE * file  = fopen("docs/vendas.txt","w");
    Venda * aux = cabecoteVenda;

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
        apagaCompra();
    }else{
        while(aux!=NULL){
            fprintf(file,"%d %d %.2f\n",aux->papel,aux->acoes,aux->precoVenda);
            aux = aux->proximaVenda;
        }
    }
    fclose(file); 
}

void atualizaCompra(){
    FILE * file  = fopen("docs/compras.txt","w");
    Compra * aux = cabecoteCompra;

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
        apagaCompra();
    }else{
        while(aux!=NULL){
            fprintf(file,"%d %d %.2f\n",aux->papel,aux->acoes,aux->precoCompra);
            aux = aux->proximaCompra;
        }
    }
    fclose(file);     
}


Registro* registroInsere(Registro* reg,Registro aux){
   
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);   
    data_hora_atual = localtime(&segundos);

    aux.ano = data_hora_atual->tm_year+1900;
    aux.dia = data_hora_atual->tm_mday;
    aux.mes =  data_hora_atual->tm_mon+1;
    aux.horas = data_hora_atual->tm_hour;
    aux.minutos = data_hora_atual->tm_min;
    aux.segundos = data_hora_atual->tm_sec;

    Registro* novo = (Registro*) malloc(sizeof(Registro));
    novo->acoes = aux.acoes;
    novo->papel = aux.papel;
    novo->preco = aux.preco;
    novo->operacao = aux.operacao;
    novo->ano = aux.ano;
    novo->mes = aux.mes;
    novo->dia = aux.dia;
    novo->horas = aux.horas;
    novo->minutos = aux.minutos;
    novo->segundos = aux.segundos;
    novo->proximaRegistro = reg;

    return novo;
}

void atualizaRegistro(){
    
    FILE * file  = fopen("docs/registro.txt","w");
    Registro * arquivo = cabecoteRegistro;

    if(file == NULL){
    	printf("Não foi possível abrir o arquivo.\n");
        apagaCompra();
    }else{
        while(arquivo!=NULL){
            fprintf(file,"%d %d %f %d %d %d %d %d %d %d\n", arquivo->papel,arquivo->acoes,arquivo->preco, arquivo->operacao, arquivo->ano, arquivo->mes, arquivo->dia, arquivo->horas, arquivo->minutos,arquivo->segundos);
            arquivo = arquivo->proximaRegistro;
        }
    }
    fclose(file);    

}

Registro* operacaoListaRegistro(Registro* no,int operacao){
    Registro* geral = cabecoteRegistro;
    Registro aux;

    while(geral!=NULL){

        if(geral->operacao == operacao){
            aux.acoes = geral->acoes;
            aux.papel = geral->papel;
            aux.preco = geral->preco;
            aux.operacao = geral->operacao;
            aux.ano = geral->ano;
            aux.mes = geral->mes;
            aux.dia = geral->dia;
            aux.horas = geral->horas;
            aux.minutos = geral->minutos;
            aux.segundos = geral->segundos;
            no = registroInsereComData(no,aux);
        }

        geral = geral->proximaRegistro;
    }

    return no;
}

void ordenarRegistro(Registro* reg){
    Registro* atual = reg; 
    Registro* aux = NULL;
    int auxInt, auxFloat;

    while(atual !=NULL){
        aux = atual->proximaRegistro;

        while(aux != NULL){

            if((aux->ano > atual->ano) || (aux->ano == atual->ano && aux->mes > atual->mes)
            || (aux->ano == atual->ano && aux->mes == atual->mes && aux->dia > atual->dia) 
            || (aux->ano == atual->ano && aux->mes == atual->mes && aux->dia == atual->dia && aux->horas > atual->horas) 
            || (aux->ano == atual->ano && aux->mes == atual->mes && aux->dia == atual->dia && aux->horas == atual->horas && aux->minutos > atual->minutos) 
            || (aux->ano == atual->ano && aux->mes == atual->mes && aux->dia == atual->dia && aux->horas == atual->horas && aux->minutos > atual->minutos && aux->segundos > atual->segundos) ){

                auxInt = aux->acoes;
                aux->acoes = atual ->acoes;
                atual->acoes = auxInt;

                auxInt = aux->operacao;
                aux->operacao = atual->operacao;
                atual->operacao = auxInt;

                auxInt = aux->papel;
                aux->papel = atual->papel;
                atual->papel = auxInt;

                auxFloat = aux->preco;
                aux ->preco = atual->preco;
                atual->preco = auxFloat;

                auxInt = aux->ano;
                aux->ano = atual->ano;
                atual ->ano =auxInt;

                auxInt =aux->mes;
                aux->mes = atual->mes;
                atual->mes = auxInt; 

                auxInt =aux->dia;
                aux->dia = atual->dia;
                atual->dia = auxInt;

                auxInt =aux->horas;
                aux->horas = atual->horas;
                atual->horas = auxInt;

                auxInt =aux->minutos;
                aux->minutos = atual->minutos;
                atual->minutos = auxInt;

                auxInt =aux->segundos;
                aux->segundos = atual->segundos;
                atual->segundos = auxInt;
            }

            aux = aux->proximaRegistro;
        }

        atual = atual ->proximaRegistro;
    }
}
