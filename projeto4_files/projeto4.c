//David Segalle, 2280507
//Viviane Ruotolo, 2324822


#include "projeto4.h"


void mudaGanho (double* dados, int n_amostras, double ganho){

    int i;
    //multiplica todos os valores pelo ganho
    for (i = 0; i < n_amostras; i++){

        dados[i] *= ganho;

    }
}




int contaSaturacoes (double* dados, int n_amostras){

    int i, saturacoes = 0;

    //busca valores maiores que 1 ou menores que -1
    for (i = 0; i < n_amostras; i++){
        if (dados[i] < -1 || dados[i] > 1)
            saturacoes++;
    }

    return saturacoes;
}




int hardClipping (double* dados, int n_amostras, double limite){

    int i, amostras_alteradas;

    amostras_alteradas = 0;

    for (i = 0; i < n_amostras; i++){
        //se o valor for maior que o limite ele é alterado para limite
        if (dados[i] > limite){
            dados[i] = limite;
            amostras_alteradas++;
        }
        //se o valor for menor que o limite ele é alterado para -limite
        if (dados[i] < - limite){
            dados[i] = - limite;
            amostras_alteradas++;
        }
    }

    return amostras_alteradas;
}




void limitaSinal (double* dados, int n_amostras, int n_passos){


    int i, j, passos_contados;
    double diferenca, ganho;

    for (i = 0; i < n_amostras; i++){
        //ao encontrar um valor fora do limite, o limiter é acionado
        if (dados[i] < -1 || dados[i] > 1){

            //calcular ganho
            ganho = 1/dados[i];
            if (dados[i] < -1)
                ganho *= -1;

            //calcula o ganho nas amostras perto n_passos de dados[i]
            diferenca = (1 - ganho) / (n_passos + 1);
            dados[i] *= ganho;

                //calcula os passos para multiplicar a diferença
            for (passos_contados = 1; passos_contados <= n_passos; passos_contados++){
                if (i + passos_contados < n_amostras){
                    dados[i + passos_contados] *= ganho + (double) passos_contados * diferenca;
                }
                if (i - passos_contados >= 0) {
                    dados[i - passos_contados] *= ganho + (double) passos_contados * diferenca;
                }
            }
        }
    }
}




void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq){


    float meio_ciclo, parte_decimal;
    int int_meio_ciclo, i, j, repete, amostras_contadas, troca_sinal;

    //calcula quantas vezes cada ciclo terá
    meio_ciclo = taxa / (2 * freq);
    int_meio_ciclo = (int) meio_ciclo;

    //quando repete for >= 1 a posição da onda será repetida 1x para compensar a parte que sobra da onda
    //caso meio_ciclo != int_meio_ciclo
    repete = 0;

    troca_sinal = 1;

    parte_decimal = 0;
    for(amostras_contadas = 0; amostras_contadas < n_amostras; i++){

        //imprime o valor x vezes
        for(j = 0; j < int_meio_ciclo + repete; j++){
            dados[amostras_contadas] = 1 * troca_sinal;
            amostras_contadas++;
        }

        //verifica se é necessário repetir
        repete = 0;
        parte_decimal += meio_ciclo - (float) int_meio_ciclo;
        if(parte_decimal >= 1){
            repete++;
            parte_decimal--;
        }

        troca_sinal *= -1;

    }
}
