#include<iostream>

using namespace std;

struct node{
	node(int m,int n){
		_m=m;
		_n=n;
	}//:_m(m),_n(n){};
	int _m;
	int _n;
	node * next;
};
	
class stack{
private:
	//int _size;
	node * head;
public:
	stack(int m, int n){
		head = new node(NULL,NULL);
		node * p = new node(m,n);
		p->next=head;
		head=p;
		//_size = 0;
	}
	void push(int m, int n){
		node * p = new node(m,n);
		p->next=head;
		head=p;
		cout<<"push "<<head->_m<<" "<<head->_n<<endl;
		//_size += 1;
	}
	void pop(){
		node * p=NULL;
		p=head;
		head=p->next;
		cout<<"pop "<<p->_m<<" "<<p->_n<<endl;
		delete p;
		//_size-=1;
	}
/*	int size(){
		return _size;
	}*/
	int m(){
		return head->_m;
	}
	int n(){
		return head->_n;
	}
};



int main(){
	int m,n;
	cout<<"Input m n" <<endl;
	cin>>m>>n;

	stack  stack(m,n);
	
	int _m=m,_n=n;
	do{
	//	cout<<"==="<<endl;
		if(stack.n()==0){
			_m=stack.m()-1;
			_n=1;
			stack.pop();
			stack.push(_m,_n);
			system("pause");
			//cout<<que.m()<<" "<<que.n()<<endl;
		}else if(stack.m()==0){
			_n=stack.n()+1;
			stack.pop();
			_m=stack.m()-1;
			stack.pop();
			stack.push(_m,_n);
			system("pause");
			//cout<<que.m()<<" "<<que.n()<<endl;
		}else{
			while(stack.n()!=0){
				_n-=1;
			    stack.push(_m,_n);
				system("pause");
			//cout<<que.m()<<" "<<que.n()<<endl;
			}
		}
	}while(stack.m()!=-1);
/*	
	do{
		if(que.n()==0){
			_n=1;
			_m=que.m()-1;
			que.pop();
			que.push(_m,_n);
			system("pause");
		}else if(que.m()==0){
			_n=que.n()+1;
			que.pop();
			_m=que.m()-1;
			que.pop();
			que.push(_m,_n);
			system("pause");
		}else{
			while(que.n()!=0){
				_m=que.m();
				_n=que.n()-1;
				que.push(_m,_n);
				system("pause");
			}
		}
	}while(que.size()!=1);
	*/
	int result = stack.n();
	stack.pop();
	cout<<"The result is "<<result<<endl;
	
	system("pause");
	return 0;
}
	