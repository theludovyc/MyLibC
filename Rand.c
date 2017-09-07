int randAB(int a,int b){
	srand(time(NULL));
	return rand()%((b+1)-a)+a;
}

int randChoice(int a[]){
	int i=randAB(0,sizeof(a)/4-1);
	return a[i];
}