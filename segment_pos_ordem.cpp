void funcao(struct No * atual) {
	if(atual == NULL) return;
	
	funcao(atual -> filho_esq);
	funcao(atual -> filho_dir);
	printf("segmento [%d, %d] = %d\n", atual -> esq, atual -> dir, atual -> soma);
}
