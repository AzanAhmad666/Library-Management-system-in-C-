#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct BST{
 	int id;
 	string name_book;
 	float price;
 
 	BST *left;
 	BST *right;
 	
 };
 struct UserRecord{
 	string UserName;
 	string CNIC;
 	string Address;
 	string dateOfEntry;
	string Phone;
 	UserRecord *next; 	 	
 };
 struct queue {
	string arr[100];
	int length = 100;
	int count = 0;
	int rear = -1;
	int front = 0;

	bool isEmpty() {
		return count == 0;
	}
	bool isFull() {
		return count == 100;
	}

	void Enqueue(string data) {
		if (!isFull())
		{
			rear = (rear + 1) % length;
			arr[rear] = data;
			count++;
		}
	}

	string Dequeue() {
		if (!isEmpty()) {
			string element = arr[front];
			front = (front + 1) % length;
			count--;
			return element;

		}
		else {
			cout<<"No customer in queue: "<<endl;
			string s="NULL";
			return s;
		}
	}
};
queue bookstore;
void insertQ(string cust) {

	bookstore.Enqueue(cust);
	cout << "Customer name is " << cust << endl;
}

void serveQ() {
	string aaa= bookstore.Dequeue();
	if(aaa!="NULL"){
	
	cout << "Customer Name : "<<aaa << " .Your Book Order is ready." << endl;
	cout<<endl;
	cout<<" Thanks for Visiting Us ."<<endl;
}
else{
	return;
}
	
}


bool found;
BST *root=NULL;
 
 
void inorder(struct BST *root) {
  
  if (root != NULL) {
  	cout<<endl;
    inorder(root->left);
    cout<<endl;
    cout <<"ID of book is: " <<root->id <<endl;
    cout<<"Name of Book is: "<<root->name_book<<endl;
    cout<<"Price of Book is: "<<root->price<<endl;;
    cout<<endl;
    inorder(root->right);
    if(root==NULL){
    	return;
	}
  }

}
float TotalCost;
void searchCust(int key){
	
	BST *p=root;
	
	while (p!=NULL){
		if(p->id==key){
		cout<<"Book is Available."<<endl;
	//	cout<<"ID of book is: "<<endl;
    	cout<<"Name of Book is: "<<p->name_book<<endl;
    	cout<<"Price of Book is "<<p->price<<endl;
    	TotalCost=p->price;
    	found=true;
    	return;
	}
	else if(key<p->id){
		p=p->left;
	  }
	  else{
	  	p=p->right;
	  }
	}
	
	cout<<"Book is not Available."<<endl;
	found=false;

		
	}
 
BST* searchAdm(int key){
	
	BST *p=root;
	
	
	while (p!=NULL){
		if(p->id==key){
    	break;  	
	}
	else if(key<p->id){
		p=p->left;
	  }
	  else{
	  	p=p->right;
	  }
	}
	return p;
	
		
	}
 void insert(int x,string name,float price){
 	
 	BST *newnode=new BST;
 	newnode->id=x;
 	newnode->name_book=name;
 	newnode->price=price;
 	newnode->left = NULL;
 	newnode->right = NULL;
 	
 	if (root==NULL){
 		root=newnode;
	 }
	 else{
	 	
	 	BST *p=root, *q;
	
	 	
	 	while(p!=NULL){
	 		q=p;
	 		
	 		if(newnode->id>q->id){
	 			p=p->right;
	 			
			 }
			 
			 else{
			 	p=p->left;
			 }
	 }
	 if(newnode->id>q->id){
	 	q->right=newnode;
	 }
	 else{
	 	q->left=newnode;
	 }
 }
 
}
 
void deletebook(int key) {
	BST* p = root, *k;
	if(root==NULL){
		cout<<"No book is available in store to delete."<<endl;
	}
	
	else{
		while(p->id!=key && p!=NULL){
			k = p;
			
			if(key>p->id){
				p = p->right;
			}
			else{
				p = p->left;
			}
			if (p==NULL){
				cout<<"Book with this id not available.";
			}
		}
		
		if(p->left==NULL && p->right==NULL){
			if(p==root){
				root=NULL;
			}
			
			else if(left){
				k->left=NULL;
				delete p;
				}
				
			else{
				k->right=NULL;
				delete p;
					
				}
			cout<<"\n Book is deleted.";
			}
		else if(p->right==NULL||p->left==NULL){
			if(p->right == NULL){
				if(k->left == p){
					k->left = p->left;
					delete p;
				}
				else if(k->right == p){
					k->right = p->left;
					delete p;
				}
			}
			else if(p->left == NULL){
				if(k->right==p){
					k->right = p->right;
					delete p;
				}
				else if(k->left == p){
					k->left = p->right;
					delete p;
				}
			}
	 
  }
		else{
			k = p;
			p = p->right;
			BST* p2;
			while(p->left!=NULL){
				p2 = p;
				p = p->left;
			}
			k->id = p->id;
			
			if(p->right!=NULL){
				p2->left=p->right;
				delete p;
			}
			else{
				p2->left = NULL;
				delete p;
			}
		}
		
		
	}
	
}


int cost[7][7];
int city;
	
//Returning vertex having minimum distance
int min_distance(int distancearray[],int visited[]){
	int minvalue=INT_MAX;
	int minnode;
	for(int i=0;i<7;i++) 
	{
		if(visited[i]==false && distancearray[i]<=minvalue)      
		{
			minvalue=distancearray[i];
			minnode=i;
		}
	}
	return minnode;
	
}

void dijkstra(int matrix[7][7],int src){
//distance array
int dist[7]; 
//variable to check whether vertex is visited or not
int visited[7];
//Initialzing distance and visited array of all vertex
for(int i=0;i<7;i++){
	dist[i]=INT_MAX;
	visited[i]=false;
}
dist[src]=0;

for(int i = 0; i<7; i++){
	int nearest=min_distance(dist,visited);
	visited[nearest]=true;
	//Adjacent node
        for(int adj = 0; adj<7; adj++){
			if(!visited[adj] && matrix[nearest][adj] && dist[nearest]!=INT_MAX && dist[nearest]+matrix[nearest][adj]<dist[adj]){
					dist[adj]=dist[nearest]+matrix[nearest][adj];
				}
		
		}
	}

cout<<"Delivery charges will be: "<<dist[city] <<"/. Rs"<<endl;
cout<<"Total Cost : "<<dist[city]+TotalCost<<"/. Rs"<<endl;

}


UserRecord *start=NULL;
 
void insertionn(string c){
 	UserRecord *current;
 	current=new UserRecord;
 	current->next=NULL;
 	
	
	current->UserName=c;
   //	cin>>current -> UserName;
   	cout<<" Enter CNIC: ";
	cin>>current -> CNIC;
	cout<<" Enter Address : ";
	cin.ignore();
	getline(cin,current->Address);
	//cin>>current -> Address;
	cout<<" Enter date : ";
	cin>>current -> dateOfEntry;
	cout<<" Enter PhoneNumber : ";
	cout<<endl;
	cin.ignore();
	getline(cin,current->Phone);
	//cin>>current -> Phone;
	if (start == NULL){
 		start = current;
	 }
	else{
		UserRecord *end = start;	
		while (end  -> next  != NULL){
			end = end -> next;
			}
			end -> next = current;
		}
		
		
}
		
void deletion(string Name){
	if(start==NULL){
		cout<<"No Customers are available"<<endl;
	}
	
	else{
		
		UserRecord *traverse = start;
		UserRecord * prev;
		UserRecord *p = NULL;
		
		while(traverse->next != NULL && p->UserName != Name ) {
			prev = traverse;
			traverse = traverse -> next;
			p=p->next;
		}
		prev -> next = traverse-> next;
		delete(traverse);
		
		
	}
	
	
}


void display(){
	
 	UserRecord *p;
 	p = start;
 	if(p==NULL){
 		cout<<"No customers are available."<<endl;
	 }
 	while(p!=NULL){
 		cout<<"\n Name: "<<p->UserName<<" ";
 		cout<<"\n Date of Entry: "<<p->dateOfEntry<<" ";
 		cout<<"\n Address: "<<p->Address<<" ";
 		cout<<"\n CNIC: "<<p->CNIC<<" ";
 		cout<<"\n Phone No: "<<p->Phone<<" ";
 		p=p->next;
	 }
	 
 }

 


int main(){
	string c;

	insert(45,"The Hobbit",5000);
	insert(30,"Black Beauty",6000);
	insert(35,"Heidi",2000);
	insert(50,"Lolita",1000);
	insert(47,"Cosmos",1050);
	insert(60,"War and Peace",750);
	insert(55,"Flowers in the Attic",500);
	insert(65,"Angels and Demons",1000);
	insert(75,"The kite Runner",4000);
	
	int choice=-1;
	while(choice!=0){
		cout<<endl;	
		cout<<"\t \t \t \t  <<  Online Book Store  >>"<<endl;	
		cout<<"For Admin press 1 : "<<endl;
 		cout<<"For Customer press 2 : "<<endl;
 		cout<<"To exit press 0 "<<endl;
 		cout<<endl;
 	
 	cin>>choice;
 	if(choice==1){
 		int z;
 		do{
 		cout<<endl;
		cout<<"\t \t \t \t  <<  Admin Section  >>"<<endl;		
		cout<<"For Insertion of new book press 1 : "<<endl;
 		cout<<"For deletion of a book press 2 : "<<endl;
 		cout<<"To search a specific book press 3: "<<endl;
 		cout<<"To display books press 4 : "<<endl;
 		cout<<"To view all the customers press 5: "<<endl;
 		cout<<"To exit press 0 "<<endl;
 		cout<<endl;
 		cin>>z;
		switch(z){
			case 0: {
		
				break;
			}
				case 1:	{
		 
				int x;
				string name;
				float price;
		 		cout<<endl;
				cout<<"Enter ID of new book : "<<endl;
				cin>>x;
				cout<<"Enter name of new book "<<endl;
				cin.ignore();
				getline(cin,name);
				cout<<"Enter price of new book: "<<endl;
				cin>>price;
				cout<<endl;
				insert(x,name,price);
	 			break;
	 			}
	 		
		 		case 2:{
		 		int y;
		 		cout<<"Enter book id to delete: "<<endl;
		 		cin>>y;
		 		deletebook(y);
				break;	
				}
				 
				case 3:{
				int key;
				cout<<"Enter id of the book you want to search: "<<endl;
				cin>>key;
				searchCust(key);
				break;
				}	 
				 
				case 4:{
				inorder(root);
				break;
				}
				
				
				case 5:{
				display();
				break;
			}
			
			default:{
				cout<<"Wrong input"<<endl;
				break;
			}
		}
 		
	}
	while (z!=0);
}
	else if(choice==2){
		cout<<"\t \t \t \t  <<  Customer Section  >>"<<endl;
		cout<<"Enter your information: "<<endl;
		cout<<" Enter your name: ";
	//	cin.ignore();
	//	getline(cin , c);
	    cin>>c;
		insertionn(c);
		
		int choice_cust;
		do{
		cout<<endl;
		cout<<"For displaying all books press 1:"<<endl;
		cout<<"For delivering a book press 2 : "<<endl;
 		cout<<"For issuing a book  press 3 : "<<endl;
 		cout<<"To exit press 0: "<<endl;
 		cout<<endl;
 		cin>>choice_cust;
 		switch (choice_cust){
 			case 1:{
 				inorder(root);
				break;
			}
			
			case 2:{
				int bookid;
				cout<<"Enter id of the book you want to deliver: "<<endl;
				cin>>bookid;
				searchCust(bookid);
				if(found==true){
				string place[6]={"I8","Comsats University","Hostel City","Rawal","Taramri ","G10/2"};
				for(int i=0;i<6;i++){
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``" << endl;
					cout<<i+1<<" "<<place[i]<<endl;
				}
				while(true){
					cout<<"\n Enter place where you want to deliver the book:  ";
					cin>>city;
					if(city==1||city==2||city==3||city==4||city==5||city==6)
						break;
					else
						cout<<"\n Wrong input.Enter again!!";
				}
				int cost[7][7]={{0,25,40,0,20,0,0},
			            {25,0,0,10,0,0,0},
			            {40,0,0,0,12,0,50},
						{0,10,0,0,0,15,0},
						{20,0,12,0,0,0,0},
						{0,0,0,15,0,0,100},
						{0,0,50,0,0,100,0}};
						
				dijkstra(cost,0);
				
			}
			
			
				break;
		
			}
			case 3:{
				
				int bookid;
				cout<<"Enter id of the book you want to issue: "<<endl;
				cin>>bookid;
				searchCust(bookid);
				//cout<<"The price of book is "<<(searchCust(bookid))->price<<endl;
				
		while (true) {
		cout << "****************************************BOOK STORE **************************************\n";
		cout << "To enqueue press 1\n";
		cout << "To dequeue press 2\n";
		cout << "To Exit press 0\n";
		cout << "\nChoose your option: ";
		int opt;
		cin >> opt;

		if (opt == 1) {
			
			cout<<"Customer Details : ";
			insertQ(c);
			
	
			system("PAUSE");
			system("CLS");
		}
		else if (opt == 2) {
			serveQ();
			system("PAUSE");
			system("CLS");
		}
		else if (opt == 0) {
			break;
		}
		else
		{
			cout << "Enter a valid commandn\n";
			system("PAUSE");
			system("CLS");
		}
	}
				
				
				
				
				
				break;
			}
			
				
 				
		 }
	}
		 
		while(choice_cust!=0);{
		}
 			}	
 		}
	}

 	

