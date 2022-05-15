#ifndef ACOES_H
    #define ACOES_H

    typedef struct Compra {
        int papel;
        int acoes;
        float precoCompra;
        struct Compra *proximaCompra;
    } Compra;

    typedef struct Venda {
        int papel;
        int acoes;
        float precoVenda;
        struct Venda *proximaVenda;
    } Venda;


    typedef struct Reg {
        int papel;
        int acoes;
        int operacao;
        float preco;
        int dia;
        int mes;
        int ano;
        int horas;
        int minutos;
        int segundos;
        struct Reg *proximaRegistro;
    } Registro;

    /* 
        Funções responsavel por carrega arquivo
    */
    void arquivoCompras();
    void arquivoVendas();
    void arquivoRegistros();

    /* 
        Funções de ordenação
    */
    void ordenarCompras(Compra* compra);
    void ordenarVenda(Venda* venda);
    void ordenarRegistro(Registro* reg);

    /* 
        Funções responsavel pela liberacação da memoria
    */
    void liberaCompraVendaRegistro();
    Compra* compraLibera(Compra* Compra);
    Venda* vendaLibera(Venda* venda);
    Registro* registroLibera(Registro* reg);

    /* 
        Funções responsavel pela insecao de novos elementos
    */
    Compra* compraInsere(Compra* compra,Compra aux);
    Venda* vendaInsere(Venda* venda,Venda aux);
    Registro* registroInsere(Registro* compra,Registro aux);
    Registro* registroInsereComData(Registro* reg,Registro aux);
    void inserirOfertaCompra();
    void inserirOfertaVenda();

    /* 
        Funções responsavel por atualiza arquivos
    */
    void atualizaRegistro();
    void atualizaVenda();
    void atualizaCompra();

    /* 
        Funções responsavel por mostra informacao para o usuario
    */
    void printfCompra(Compra* compra);
    void printfVenda(Venda* venda);
    void printfRegistro(Registro* reg);

    /* 
        Funções responsavel por busca elementos no cabecote principal
    */
    Compra* listaCompra(Compra* no,int papel);
    Venda* listaVenda(Venda* no,int papel);
    Registro* operacaoListaRegistro(Registro* no,int operacao);
    void listaOferta(int papel);
    void registroCompra();
    void registroVenda();

    /* 
        Funções de exclusao
    */  
    void apagaCompra();
    void apagaVenda();
    void retiraCompra(Compra* compra);
    void retiraVenda(Venda* venda);


    /* 
        Funções responsavel pela compra e venda
    */
    void negociaAcoes();



#endif // MACRO