bool funcao(int a, int b, int c) {
	if(a == b && b == c && c == n)
		return true;
	
	if(a < n && pilha[0][a]%3 == 0 && funcao(a+1, b, c)) return true;
	if(b < n && pilha[1][b]%3 == 0 && funcao(a, b+1, c)) return true;
	if(c < n && pilha[2][c]%3 == 0 && funcao(a, b, c+1)) return true;
	if(a < n && b < n && (pilha[0][a]+pilha[1][b])%3 == 0 && funcao(a+1, b+1, c)) return true;
	if(a < n && c < n && (pilha[0][a]+pilha[2][c])%3 == 0 && funcao(a+1, b, c+1)) return true;
	if(b < n && c < n && (pilha[1][b]+pilha[2][c])%3 == 0 && funcao(a, b+1, c+1)) return true;
	if(a < n && b < n && c < n && (pilha[0][a]+pilha[1][b]+pilha[2][c])%3 == 0 && funcao(a+1, b+1, c+1)) return true;
	
	return false;
}
