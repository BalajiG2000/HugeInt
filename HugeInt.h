//FUNCTION DEFINITIONS
int hugeIntCompare(const char* hugeVariable1, const char* hugeVariable2);
static void hugeIntAdder(const char* hugeVariable1, const char* hugeVariable2, char* res);
static char* hugeIntDiffer(const char* hugeVariable1, const char* hugeVariable2);
static void hugeIntMulti(const char* hugeVariable1, const char* hugeVariable2, char* res);
static char* max(char* sum, char* curr);
static void merge(char **arr, int l, int m, int r);
static int isZero(const char* intal);
static char* removeLeadZero(char* intal);	


//FUNCTION TO REMOVE LEAD ZEROES
static char* removeLeadZero(char* res)
{

	int nonz = 0, newlen =0,i = 0;
	for(nonz = 0; nonz < strlen(res); nonz++){
		if(res[nonz] != 48)
			break;	
	}
	if(nonz == 0)
		return res;
	newlen = strlen(res) - nonz;
	for(i = 0; i < newlen; i++)
		res[i] = res[i+nonz];
	//res = (char*)realloc(res,sizeof(char)*(newlen+1)); //6474
	res[i] = '\0';
	if(res[0] == '\0'){
		free(res);
		res = (char*)calloc(2,sizeof(char));
		res[0] = 48;
		res[1] = '\0';	
	}
	return res;

}


static void hugeIntAdder(const char* hugeIntVariable1, const char* hugeIntVariable2, char* res)
{
	//printf("Reached intal_adder\n");
	int l1 = strlen(hugeIntVariable1)-1;
	int l2 = strlen(hugeIntVariable2)-1;
	int sum = 0, carry = 0,k = l1+1;
	//printf("%d %d %d\n",l1,l2,k);
	for(int i = 0; i <= k;i++)
		res[i] = '0';
	while(l2>=0){
		sum = hugeIntVariable1[l1] + hugeIntVariable2[l2] + carry - 96;
		res[k] = 48 + sum%10;
		carry = sum/10;
		--l1;--l2;--k;		
	}
	while(l1>=0){
		sum = hugeIntVariable1[l1]+carry-48;
		res[k] = 48 + sum%10;
		carry = sum/10;
		--l1;--k;		
	}
	if(carry){
		res[k] = 48 + carry;
	}
	
}
char* hugeIntAdd(const char* hugeIntVariable1, const char* hugeIntVariable2){
	int bigger = hugeIntCompare(hugeIntVariable1,hugeIntVariable2);
	//printf("Found biggger\n");
	if(bigger == -1){
		char* res = (char*)calloc(strlen(hugeIntVariable2)+2,sizeof(char));
		hugeIntAdder(hugeIntVariable2, hugeIntVariable1, res);
		return removeLeadZero(res);
	}
	char* res = (char*)calloc(strlen(hugeIntVariable1)+2,sizeof(char));
	hugeIntAdder(hugeIntVariable1, hugeIntVariable2, res);
	return removeLeadZero(res);
}
int hugeIntCompare(const char* hugeIntVariable1, const char* hugeIntVariable2){
	int p1 = strlen(hugeIntVariable1)-1;
	int p2 = strlen(hugeIntVariable2)-1;
	int diff = 0, bigger = 0;
	int i =0;
	if(p1 < p2)
		return -1;
	if(p1 == p2){
		bigger = 0;
		do{
			diff = hugeIntVariable1[i] - hugeIntVariable2[i];
			if(diff > 0){
				bigger = 1;
			}else if(diff < 0){
				bigger = -1;
			}++i;
		}while(diff == 0 && i<=p1 && i <= p2);
		return bigger;
	}
	//printf("p1 %d p2 %d\n",p1,p2);
	return 1;	
}


// TESTED OK ABOVE

static char* hugeIntDiffer(const char* hugeIntVariable1, const char* hugeIntVariable2){
	int l1 = strlen(hugeIntVariable1)-1;
	int l2 = strlen(hugeIntVariable2)-1;
	int top = 0,bottom = 0,k = l1,i;
	int taken = 0;
	char* res = (char*)calloc(k+2,sizeof(char));
	for(i = 0; i <= k;i++)
		res[i] = 48;
	res[i] = '\0';
	while(l2>= 0){
		top = hugeIntVariable1[l1]-48;
		bottom = hugeIntVariable2[l2]-48;
		if(taken > 0){
			if(taken == 1){
				//printf("if %c\n",intal1[l1]);
				top -=1;
			}else{	
				//printf("else %c\n",intal1[l1]);
				top = 9 + hugeIntVariable1[l1]-48 ;
			}
			//printf("updated top in if taken >0\n");
			--taken;		
		}
		//printf("%d %d %d\n",top, bottom, (top-bottom));
		if(top < bottom){
			//int look = 0;
			do{
				++taken;
			}while(hugeIntVariable1[l1-taken] == 48 && (l1-taken) > 0);
			top +=10;		
		}
		
		//printf("%d %d %d %d\n",top, bottom, (top-bottom), taken);
		res[k] = 48+ top - bottom;
		--l1;--l2;--k;
	}
	//printf("taken = %d\n",taken);
	while(l1>=0){
		if(taken >  0){
			res[k] = hugeIntVariable1[l1]-1; 
			if(hugeIntVariable1[l1] == 48)
				res[k] = 57;
			--taken;
		}else{
			res[k] = hugeIntVariable1[l1];		
		}
		--l1;--k;		
	}
	return res;
}
char* hugeIntDifference(const char* hugeIntVariable1, const char* hugeIntVariable2){
	int bigger = hugeIntCompare(hugeIntVariable1,hugeIntVariable2);
	//int i;
	//printf("bigger = %d\n",bigger);
	if(bigger == -1){
		//char* res = (char*)calloc(strlen(intal2)+1,sizeof(char));
		char* res = hugeIntDiffer(hugeIntVariable2, hugeIntVariable1);
		return removeLeadZero(res);
	}
	//char* res = (char*)calloc(strlen(intal1)+1,sizeof(char));
	char* res = hugeIntDiffer(hugeIntVariable1, hugeIntVariable2);
	return removeLeadZero(res);
}
static int isZero(const char* hugeIntVariable){
	int i =0, len = strlen(hugeIntVariable);
	while(i<len){
		if(hugeIntVariable[i] == 48)
			++i;
		else
			break;		
	}
	//printf("values of i%d, strlen = %d\n",i,len);
	if(hugeIntVariable[i] == '\0')
		return 1;
	//printf("Returning zero\n");
	return 0;
}
static void hugeIntMulti(const char* hugeIntVariable1, const char* hugeIntVariable2, char* res){
	int l1 = strlen(hugeIntVariable1);
	int l2 = strlen(hugeIntVariable2);
	int sum = 0, carry = 0;
	int l3 = l1+l2;
	int ptr1 = 1;
	int ptr2;
	int i;
	//res = (char*)realloc(res,l3*sizeof(char));
	//printf("strlen before%d\n",strlen(res));
	for(i = 0; i < l3; i++){
		res[i] = '0';		
	}
	for(i = l2-1; i >= 0; i--){
		sum = 0;
		carry = 0;
		ptr2 = l3-ptr1;
		for(int j = l1-1; j >=0; j--){
			//printf("%c %c\n",hugeIntVariable1[j], hugeIntVariable2[i]);
			sum = (hugeIntVariable1[j]-'0')*(hugeIntVariable2[i]-'0') + (res[ptr2]-'0')+carry;
			//printf("%c %c %d\n",intal1[j], intal2[i],sum);
			res[ptr2] = 48+sum%10;
			carry = sum/10;
			--ptr2;	
			//printf("%d %d\n",ptr1,ptr2);	
		}
		if(carry){
			res[ptr2] += carry;		
		}
		++ptr1;		
	}
}
char* hugeIntMultiply(const char* hugeIntVariable1, const char* hugeIntVariable2){
	//printf("%d %d\n",isZero(hugeIntVariable1),isZero(hugeIntVariable2));
			
	if(!isZero(hugeIntVariable1) && !isZero(hugeIntVariable2)){
		int bigger = hugeIntCompare(hugeIntVariable1,hugeIntVariable2);
		//int i;
		char* res = (char*)calloc(strlen(hugeIntVariable1)+strlen(hugeIntVariable2)+1,sizeof(char));
		if(bigger>=0){
			hugeIntMulti(hugeIntVariable1, hugeIntVariable2, res);
		}else{
			hugeIntMulti(hugeIntVariable2, hugeIntVariable1, res);
		}
		return removeLeadZero(res);
	}
	char* res = (char*)malloc(2*sizeof(char));
	strcpy(res,"0");
	return res;
}

//TESTED ABOVE OK

char* hugeIntFibonacci(unsigned int n){
	unsigned int i;	
	//char **res = (char**)malloc(2 * sizeof(char*));
	char *res1 = (char*)malloc(2 * sizeof(char));
	strcpy(res1,"0");
	if(n==0)
		return res1;
	char *res2 = (char*)malloc(2 * sizeof(char));

	strcpy(res2,"1");
	//printf("%s %s\n",res[0],res[1]);
	char* temp = NULL;
	for(i = 2; i <= n; i++){
		temp = hugeIntAdd(res1,res2);
		free(res1);
		res1 = res2;
		res2 = temp;
		//printf("%s %s\n",res[0],res[1]);	
	}
	free(res1);
	return res2;
}
char* hugeIntFactorial(unsigned int n){
	char* res = (char*)calloc(2,sizeof(char));
	strcpy(res,"1");	
	if(n == 0 || n== 1){
		return res;
	}
	char* num = (char*)calloc(2,sizeof(char));
	char* copy = NULL;
	strcpy(num,"1");
	unsigned int i = 2;
	while(i <= n){
		copy = hugeIntAdd(num,"1");
		free(num);
		num = copy;
		//printf("%s %s\n",num,res);
		copy = hugeIntMultiply(num,res);
		free(res);
		res = copy;
		++i;	
	}
	//free(copy);
	free(num);
	return removeLeadZero(res);
}

//TESTED OK ABOVE

char* hugeIntMod(const char* hugeIntVariable1, const char* hugeIntVariable2){
	//return iter_mod(hugeIntVariable1,hugeIntVariable2);
	int comp = hugeIntCompare(hugeIntVariable1,hugeIntVariable2);
	int l1 = strlen(hugeIntVariable1);
	int l2 = strlen(hugeIntVariable2);
	int i;	
	//char* res;
	//printf("Compare = %d\n",comp);
	if(isZero(hugeIntVariable1) || comp == 0){
		char* res = (char*)calloc(2,sizeof(char));
		strcpy(res,"0");
		return res;
	}
	if(comp == -1){	
		//printf("hugeIntVariable2 is bigger\n");
		char* res = (char*)calloc(l1+1,sizeof(char));
		strcpy(res,hugeIntVariable1);
		return res;
	}
	int diff = l1-l2;
	if(hugeIntVariable1[0] <= hugeIntVariable2[0])
		--diff;
	if(diff == 0){
		char* temp = hugeIntDifference(hugeIntVariable1,hugeIntVariable2);
		char* t2 = temp;
		char* res = hugeIntMod(temp, hugeIntVariable2);
		free(t2);
		return res;
	}
	char* ni1 = (char*)malloc(sizeof(char)*(l1+1));
	strcpy(ni1, hugeIntVariable1);
	char* ni2 = (char*)malloc(sizeof(char)*(l2+diff+2));
	for(i = 0; i < l2; i++)
		ni2[i] = hugeIntVariable2[i];
	for(i = 0; i < diff; i++)
		ni2[l2+i] = 48;
	ni2[l2+i] = '\0';
	while(hugeIntCompare(ni1,ni2) >0){
		char* temp = hugeIntDifference(ni1,ni2);
		char* t2 = ni1;
		ni1 = temp;
		free(t2);
	}
	free(ni2);
	if(hugeIntCompare(ni1,hugeIntVariable2) <= 0)
		return ni1;
	char* temp = ni1;
	char* res = hugeIntMod(ni1,hugeIntVariable2);
	free(temp);
	return res;
}

char* hugeIntPower(const char* hugeIntVariable1, unsigned int n){
	if(isZero(hugeIntVariable1)){
		char* res = (char*)malloc(sizeof(char)*2);
		strcpy(res,"0");
		return res;	
	}
	char* res = (char*)malloc(sizeof(char)*2);
	strcpy(res,"1");
	char* x = (char*)malloc(sizeof(char)*(strlen(hugeIntVariable1)+1));
	strcpy(x,hugeIntVariable1);
	char* temp;
	while(n > 0){
		if(n & 1){
			temp = hugeIntMultiply(res,x);
			free(res);
			res = temp;		
		}	
		n = n >> 1;
		temp = hugeIntMultiply(x,x);
		free(x);
		x = temp;
	}
	free(x);
	return res;
}

char* hugeIntGCD(const char* hugeIntVariable1, const char* hugeIntVariable2){
	if(strcmp(hugeIntVariable1,"0")==0 && strcmp(hugeIntVariable2,"0")==0){
		char* res = (char*)calloc(2,sizeof(char));
		res[0] = '0';
		res[1] = '\0';	
		return res;
	}
	if(strcmp(hugeIntVariable1,"0")==0){
		char* res = (char*)calloc(strlen(hugeIntVariable2)+1,sizeof(char));
		int i = 0;		
		for(i = 0; i < strlen(hugeIntVariable2);i++)
			res[i] = hugeIntVariable2[i];
		res[i] = '\0';	
		return res;
	}
	if(strcmp(hugeIntVariable2,"0") == 0){
		char* res = (char*)calloc(strlen(hugeIntVariable1)+1,sizeof(char));
		int i = 0;		
		for(i = 0; i < strlen(hugeIntVariable1);i++)
			res[i] = hugeIntVariable1[i];
		res[i] = '\0';	
		return res;	
	}
	char* temp = hugeIntMod(hugeIntVariable1, hugeIntVariable1);
	char* res =  hugeIntGCD(hugeIntVariable2, temp);
	free(temp);
	return res;	
}
