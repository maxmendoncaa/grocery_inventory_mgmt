#include<iostream>
#include<fstream>
using namespace std;
class grocery
{
	
	void add_items();
	void modify_stock();
	void view_stock();
	void checkout();
	void read_stock();
	int cart[10];
	int stock[10];
	public:
	grocery()
	{
		read_stock();
		for(int i=0;i<=10-1;i++)
		{
			cart[i]=0;
		}
		menu();
	}
	void menu()
	{
	int n;
	do
	{
		cout<<"Enter the number of your respective choice:"<<endl;
		cout<<"1.Add items to cart"<<endl;
		cout<<"2.Modify stock"<<endl;
		cout<<"3.View Stock"<<endl;
		cout<<"4.Exit"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:add_items();
					break;
			case 2:modify_stock();
					break;
			case 3:view_stock();
					break;
			
			case 4:break;
		
			default : printf("Invalid number entered\n");
					break;
		}
		
	}while(n>5||n<1);
	
	
}
};

void grocery::add_items()
{
	char choice;
	int c,q;
	do
	{
		
		cout<<"Enter the item no. of the item you wish to buy"<<endl;
		cout<<"1.Milk(1/2 ltr)"<<endl;
		cout<<"2.Cheese(500g)"<<endl;
		cout<<"3.Eggs(12)"<<endl;
		cout<<"4.Bacon(250g)"<<endl;
		cout<<"5.Sausages(500g)"<<endl;
		cout<<"6.Carrots"<<endl;
		cout<<"7.Brocolli"<<endl;
		cout<<"8.Onions"<<endl;
		cout<<"9.Jam(250g)"<<endl;
		cout<<"10.Bread Loaf(400g)"<<endl;
		cin>>c;
		
		cout<<"Quantity of item to add:";
		cin>>q;
		if(q<=stock[c-1])
		{
			if(q<=10&&q>=1)
			{
				cart[c-1]=cart[c-1]+q;
			}
			stock[c-1]=stock[c-1]-q;
		}
		
		cout<<"Do you wish to buy more items?(Y/N):";
		cin>>choice;
	
	}while(choice=='y'||choice=='Y');
	ofstream a("stock.txt");
	for(int i=0;i<10;i++)
	{
		a<<stock[i]<<endl;
	}
	a.close();
	checkout();
}

void grocery::checkout()
{
	int total;
	
		cout<<"*************BILL*************"<<endl;
		cout<<"1.Milk(1/2 ltr):      "<<cart[0]<<"X 20"<<endl;
		cout<<"2.Cheese(500g):       "<<cart[1]<<"X 100"<<endl;
		cout<<"3.Eggs(12):           "<<cart[2]<<"X 66"<<endl;
		cout<<"4.Bacon(250g):        "<<cart[3]<<"X 120"<<endl;
		cout<<"5.Sausages(500g):     "<<cart[4]<<"X 200"<<endl;
		cout<<"6.Carrots:            "<<cart[5]<<"X 7"<<endl;
		cout<<"7.Brocolli:           "<<cart[6]<<"X 3"<<endl;
		cout<<"8.Onions:             "<<cart[7]<<"X 5"<<endl;
		cout<<"9.Jam(250g):          "<<cart[8]<<"X 150"<<endl;
		cout<<"10.Bread Loaf(400g):  "<<cart[9]<<"X 40"<<endl;

total=cart[0]*20+cart[1]*100+cart[2]*66+cart[3]*120+cart[4]*200
		+cart[5]*7+cart[6]*3+cart[7]*5+cart[8]*150+cart[9]*40;
				
		cout<<"Total..............................="<<total<<endl;
		
		menu();
		
				
} 

void grocery::modify_stock()
{
	fstream m("stock.txt", ios::ate);
	char choice;
	int mv,c;
	do
	{
		cout<<"Enter the item no. of the item you wish to modify"<<endl;
		cout<<"1.Milk(1/2 ltr)"<<endl;
		cout<<"2.Cheese(500g)"<<endl;
		cout<<"3.Eggs(12)"<<endl;
		cout<<"4.Bacon(250g)"<<endl;
		cout<<"5.Sausages(500g)"<<endl;
		cout<<"6.Carrots"<<endl;
		cout<<"7.Brocolli"<<endl;
		cout<<"8.Onions"<<endl;
		cout<<"9.Jam(250g)"<<endl;
		cout<<"10.Bread Loaf(400g)"<<endl;
		cin>>c;
		cout<<"Enter the modified value"<<endl;
		cin>>mv;
		stock[c-1]=mv;
		ofstream m("stock.txt");
		for(int i=0;i<10;i++)
		{
			m<<stock[i]<<endl;
		}
		m.close();
		cout<<"Do you wish to modify more items?(Y/N):";
		cin>>choice;
		
	}while(choice=='y'||choice=='Y');
	
	menu();
}
	
void grocery::read_stock()
{
	ifstream ip("stock.txt");
	for(int i=0;i<10;i++)
	{
		ip>>stock[i];
	}
}

void grocery::view_stock(){
	cout<<"*************Stock*************"<<endl;
		cout<<"1.Milk(1/2 ltr):      "<<stock[0]<<endl;
		cout<<"2.Cheese(500g):       "<<stock[1]<<endl;
		cout<<"3.Eggs(12):           "<<stock[2]<<endl;
		cout<<"4.Bacon(250g):        "<<stock[3]<<endl;
		cout<<"5.Sausages(500g):     "<<stock[4]<<endl;
		cout<<"6.Carrots:            "<<stock[5]<<endl;
		cout<<"7.Brocolli:           "<<stock[6]<<endl;
		cout<<"8.Onions:             "<<stock[7]<<endl;
		cout<<"9.Jam(250g):          "<<stock[8]<<endl;
		cout<<"10.Bread Loaf(400g):  "<<stock[9]<<endl<<"\n";
		
		menu();
}

int main()
{
	grocery g;
	return 0;
}

