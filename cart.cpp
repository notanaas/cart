#include<iostream>
#include<vector>
#include "cart.h"
using namespace std;

vector<Product> allProducts={
	Product(1,"apple",26),
	Product(3,"mango",16),
	Product(2,"guava",36),
	Product(5,"banana",56),
	Product(4,"strawberry",29),
	Product(6,"pineapple",20),


};


string pList(){
	string productList;
	for(auto product : allProducts){
		productList.append(product.get_product_info());
		productList.append("\n");
	}
	return productList;
}
Product* chooseProduct(){

	cout<<"----------------"<<endl;
	cout<<"enter name of product you want to add it\n";
	string choice;
	cin>>choice;

	for(int i=0; i< allProducts.size(); i++){
		if(allProducts[i].get_name()==choice){
			return &allProducts[i];
		}
	}
	cout<<"Product not found!" <<endl;
	return NULL;
}

bool checkout(Cart &cart){
	if(cart.empty()){
		return false;
	}

	double  total = cart.total_price();
	cout<<"total amount is "<<total<<" please pay in Cash \n";

	double paid;
	cin>> paid;

	if(paid>=total){
		cout<<"Change " <<paid - total << endl;
		cout<<"Thank you for shopping!";
		return true;
	}

	else{
		cout<<"Not enough cash!";
		return false;
	}

}

int main(){
	string productList=pList();
	char action;
	Cart cart;

	while(true){
		cout<<"-----------------------\n";
		cout<<"Select an action -  (a)dd item, (v)iew cart, (d)elete item ,(c)heckout" <<endl;
		cin>> action;

		if(action=='a'){
				//this take O(n)
				cout<<productList<<"\n";
				Product * product = chooseProduct();
				if(product!=NULL){
				int q;
				cout<<"enter quantity \n";
				cin>>q;
				cout<<"--------------------\n";
				cout<<"Added to the Cart "<<"\nid: "<<product->get_id()<<"\nname: "<<product->get_name()<<"\nquantity: "<<q <<"\nprice:"<<q*product->get_price() <<endl;
				cart.add_item(*product,q);
			}

		}
		else if(action=='v'){
			//this take O(n)
			cout<<"------------------" <<endl;
			cout << cart.view_cart();
			cout<<"------------------"<<endl;
		}
		else if(action=='d'){
			//this take O(n) whitout view it take o(1)
			cout<<"------------------" <<endl;
			cout << cart.view_cart();
			cout<<"------------------"<<endl;
			cout<< "enter the id of item you want delete it";
			int id;
			cin>>id;
			cout<<"enter the amount of quantity you want delete";
			int q;
			cin>>q;
			cart.delete_item(id,q);
		
		}
		else{
			// Checkout this take o(n)
			if(checkout(cart)){
				break;
			}
		}
	}




}
