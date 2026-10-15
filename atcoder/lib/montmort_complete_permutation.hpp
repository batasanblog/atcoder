auto logic(){
	ll N;
	cin>>N;

	vector<mint>s(N+1,1),g(N+1,1),NK(N+1,1);
	mint now=1;
	ll sign=-1;
	reps(i,1,N+1){
		now*=mint(i).inv();
		at(g,i)=now*sign;
		sign=-sign;
		at(NK,i)=at(NK,i-1)*i;
	}
	auto f=convolution(s,g);

	vector<mint>dp(N+1);
	at(dp,1)=0;
	at(dp,2)=1;
	reps(i,3,N+1){
		at(dp,i)=(i-1)*(at(dp,i-1)+at(dp,i-2));
	}
	rep1(i,N){
		show(i,"i!",at(NK,i),"conv",at(f,i)*at(NK,i),"dp",at(dp,i));
	}
	return;
}
