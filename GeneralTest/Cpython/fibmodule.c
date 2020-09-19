double fib(int n){
	double temp[2]={1, 1};
	int loop=n/2;
	for(int i=0; i<loop; i++){
		temp[0]+=temp[1];
		temp[1]+=temp[0];
	}

	return temp[n-loop*2];
}

double foo(){
	return 5.0;
}