#include<stdio.h>
#define LENGTH 5

typedef struct {
	int cont[LENGTH];
	int top;
} stack;

void stack_init(stack *s){

	s->top = -1;

}

int stack_full(stack *s){

	if(s->top-1 > LENGTH){
		return 1;
	}else{
		return 0;
	}

}

int stack_enpty(stack *s){

	if(s->top < 0){
		return 1;
	}else{
		return 0;
	}

}

int stack_show(stack *s){

	int i;
	for(i = 0; i <= s->top; i++){

		printf("%d ",s->cont[i]);

	}
	printf("\n");

	return 0;

}

int push(stack* s,int n){

	if(stack_full(s)){

		printf("Stack Overflow\n");
		return 1;

	}
	s->top++;
	s->cont[s->top] = n;

	return 0;
	
}

int pop(stack *s){

	if(stack_enpty(s)){

		printf("Stack Underflow\n");
		return 1;

	}
	s->top--;
	
	return 0;
}

int main(){

	stack s;
	stack_init(&s);

	push(&s,10);
	stack_show(&s);

	push(&s,3);
	stack_show(&s);

	pop(&s);
	stack_show(&s);

	push(&s,5);
	stack_show(&s);

	pop(&s);
	stack_show(&s);

	pop(&s);
	stack_show(&s);

	return 0;

}
