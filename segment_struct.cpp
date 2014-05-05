struct No {
	// indices dos elementos cobertos por este nó.
	int esq, dir;
	
	// ponteiros para os nós que são filhos deste nó.
	struct No * filho_esq, * filho_dir;
	
	// valor da soma de todos os elementos cobertos por este nó.
	int soma;
};
