struct Object{
	int size;
	char type;
};
typedef struct Object Object;

Object object(Object*o,int i,char c){
	(*o).size=i;
	(*o).type=c;
	return *o;
}