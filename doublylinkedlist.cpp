#include<iostream>
using namespace std;

class Node{
	public :
		int key;
		int data;
		Node* next;
		Node* previous;
		Node()
		{
			key=0;
			data=0;
			next=NULL;
			previous=NULL;
			
		}
		Node(int k,int d)
		{
			key=k;
			data=d;
			
		}
};

class DoublyLinkedList{
	public:
		Node* head;
		
		DoublyLinkedList(Node *n)
		{
			head=n;
		}
		
	//1. chexk if node exist
	Node* nodeExists(int k)
	{
		Node* temp=NULL;
		Node* ptr=head;
		
		while(ptr!=NULL)
		{
			if(ptr->key==k)
			{
				temp=ptr;
			}
			ptr=ptr->next;
		}
		return temp;
	}	


// append a node to the list
void appendNode(Node* n)
{
	if(nodeExists(n->key)!=NULL)
	{
		cout<<"Node already exists with key value :"<<n->key<<".Append another node with different key"<<endl;
	}
	else
	{
		if(head==NULL)
		{
			head=n;
			cout<<"Node append as head node"<<endl;
		}
		else
		{
			Node* ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=n;
			n->previous=ptr;
			cout<<"Node Appended"<<endl;
		}
	}
}
//3 Prepend Node attach a node at a first
void prependNode(Node* n)
{
	if(nodeExists(n->key)!=NULL)
	{
		cout<<"Node Already exists with key value :"<<n->key<<".Append another node different key"<<endl;
	}
	else
	{
		if(head==NULL)
		{
			head=n;
			cout<<"Node prpended as head node"<<endl;
		}
		else
		{
		
		head->previous=n;
		n->next=head;
		head=n;
		cout<<"Node Prepend"<<endl;
	}
	}
}
//4Insert a node after a particular node in the list
void insertNodeAfter(int k,Node *n)
{
	Node* ptr=nodeExists(k);
	if(ptr==NULL)
	{
		cout<<"No Node exists with key value :"<<k<<endl;
	}
	else
	{
		if(nodeExists(n->key)!=NULL)
		{
			cout<<"Node Already exists with key value :"<<n->key<<".Append another node different key"<<endl;
		}
		else
		{
			Node *nextNode=ptr->next;
			if(nextNode==NULL)
			{
				ptr->next=n;
				n->previous=ptr;
				cout<<"Node Inserted sat the end"<<endl;
			}
			else
			{
				n->next=nextNode;
				nextNode->previous=n;
				n->previous=ptr;
				ptr->next=n;
				cout<<"Node Inserted in between"<<endl;
			}
		}
	}
}
// delete node by unique key 

void deleteNodeByKey(int k)
{
	Node* ptr=nodeExists(k);
	if(ptr==NULL)
	{
		cout<<"No Node exists with key value :"<<k<<endl;
	}
	else 
	{
		if(head==NULL)
		{
			cout<<"Doubly Linked List alredy emty cant delete"<<endl;
		}
		else if(head!=NULL)
		{
			if(head->key==k)
			{
				head=head->next;
				cout<<"Node Unlinked with key value :"<<k<<endl;
			}
			else
			{
				Node *nextNode=ptr->next;
				Node *prevNode=ptr->previous;
				if(nextNode==NULL)
				{
					prevNode->next=NULL;
					cout<<"Node Deleted at the end"<<endl;
				}
				else
				{
					prevNode->next=nextNode;
					nextNode->previous=prevNode;
					cout<<"Node deleted in between"<<endl;
				}
			}
		}
	}
}

// 6 update node
void updateNodeByKey(int k,int d)
{    Node* ptr=nodeExists(k);
	if(ptr!=NULL)
	{
		ptr->data=d;
		cout<<"Node data updated successfukly"<<endl;
	}
	else
	{
		cout<<"Node does not exists with key value : "<<k<<endl;
	}
}

//7 printing
void printList()
{
	if(head==NULL)
	{
		cout<<"No doubly nodes";
	}
	else
	{
		cout<<endl<<"Doubly Linked List values :";
		Node* temp=head;
		while(temp!=NULL)
		{
			cout<<"("<<temp->key<<","<<temp->data<<")<-->";
			temp=temp->next;
		}
	}
}
};


int main()
{
	DoublyLinkedList obj;
	int option;
	int key1,k1,data1;
	do
	{
		cout<<"\n What operation do you want to perform ?select option no .Enter 0 to exit"<<endl;
		cout<<"1.appendNode()"<<endl;
		cout<<"2.prependNode()"<<endl;
		cout<<"3.insertNodeAfter()"<<endl;
		cout<<"4.deleteNodeByKey()"<<endl;
		cout<<"5.updateNodeByKey()"<<endl;
		cout<<"6.print()"<<endl;
		cout<<"7.Cler screen"<<endl;
		
		cin>>option;
		Node* n1=new Node();
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Append Node operaton \nEnter key and data of the node t be appended"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				obj.appendNode(n1);
				break;
			case 2:
				cout<<"Prepend Node operaton \nEnter key and data of the node t be appended"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				obj.prependNode(n1);
				break;
			case 3:
				cout<<"Insert Node operaton \nEnter key and data of the node t be appended"<<endl;
				cin>>k1;
				cout<<"Enter key &data of the new node first :"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				obj.insertNodeAfter(k1,n1);
				break;
			case 4:
				cout<<"Delete Node by key operation \nEnter the key of the node to be deleted:"<<endl;
				cin>>k1;
				obj.deleteNodeByKey(k1);
				break;
			case 5:
				cout<<"Update Node by key operation \nEnter key &New data t be updated"<<endl;
				cin>>key1;
				cin>>data1;
				obj.updateNodeByKey(key1,data1);
				break;
			case 6:
				obj.printList();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter proper number"<<endl;
		}
	}while(option!=0);
	return 0;
}
