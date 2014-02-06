/*
 * Este é um trecho do código utilizado no exercício Imagem - 
 * http://www.urionlinejudge.com.br/judge/pt/problems/view/1516
 * 
 * Caso haja dúvidas, poste um comentário em -
 * http://crbonilha.blogspot.com/2014/02/contest-bonilha-editorial.html
 */
   
// processando
n = a/n;
m = b/m;
for(int i=0; i<a; i++) {
	for(int j=0; j<b; j++) {
		saida[i][j] = matriz[i/n][j/m];
	}
	saida[i][b] = 0;
}

// imprimindo
for(int i=0; i<a; i++) {
	printf("%s\n", saida[i]);
}
printf("\n");
