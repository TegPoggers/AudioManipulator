/*============================================================================*/
/* CSF13 - 2020-2 - PROJETO 3                                                 */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/** Funções pedidas para o 4o projeto da disciplina Fundamentos de Programação
 * 1, 2o semestre de 2020, prof. Bogdan T. Nassu e Leyza E. B. Dorini,
 * Universidade Tecnológica Federal do Paraná. */
/*============================================================================*/

#ifndef __PROJETO4_H
#define __PROJETO4_H

/*============================================================================*/

void mudaGanho (double* dados, int n_amostras, double ganho);
int contaSaturacoes (double* dados, int n_amostras);
int hardClipping (double* dados, int n_amostras, double limite);
void limitaSinal (double* dados, int n_amostras, int n_passos);
void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq);

/*============================================================================*/
#endif /* __PROJETO4_H */
