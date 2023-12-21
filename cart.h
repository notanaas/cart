#ifndef C_H
#define C_H
////////////////////

#include<unordered_map>
#include<string>
using namespace std;
////////////////////

//build Product class
class Product{
	private://attributes		
		int id;
		string name;
		double price;
		
	public://methodes
		Product(){}
		//constructor 
		Product(int id , string name, double price){
		this->id=id;
		this->name=name;
		this->price=price;
		}

		//accessores
		int 	get_id()const {return id;}
		string  get_name()const {return name;}
		double 	get_price()const {return price;}
		string  get_product_info()const {return "id:" +to_string(id)+" - name:" + name+" - "+ "price:" + to_string(price);}
		//mutatores

		void set_id(int id){this->id=id;}
		void set_name(string name){this->name=name;}
		void set_price(double price){this->price=price;}



};


//build Item class 
class Item{
	
	//attributes
	
	private:
		Product product;
		int quantity;
	
	//methodes
	public:
		Item(){}
		Item(Product p, int q){product=p;quantity=q;}
		void set_quantity(int q){quantity=q;}
		int get_quantity()const{return quantity;}
		double item_price(){return product.get_price() * quantity;}

		string get_item_info(){
			return "id:"+to_string(product.get_id())+" - " +to_string(quantity) +" X " + product.get_name() + " -  price: "+ to_string(item_price()) + "\n";}

		



};

class Cart{
	private:
		unordered_map<int,Item> items;
	public:
		//this function take O(1)
		void add_item(Product p, int q=1){
			//if item not exist
			if(items.find(p.get_id())==items.end()){
				Item newItem(p,q);
				items[p.get_id()]=newItem;
                
			}
			else
				items[p.get_id()].set_quantity(q+items[p.get_id()].get_quantity());

			
		
		}
		
		//this function take O(1)
		void delete_item(int id,int q=1){
			if(items.find(id)==items.end())return;
			else{
				if(items[id].get_quantity() > q){
					items[id].set_quantity(items[id].get_quantity()-q);

				}
				else{
					items.erase(id);
				}
			}
		
		}

		//this function take O(n)
		double total_price(){
			double total=0;
			for(auto i :items){
				total+=i.second.item_price();
			
			}
			return total;
		
		}


		//this function take O(1)
		bool empty(){
			return items.empty();
		}
    //this function take O(n)

		string view_cart(){
			if(items.empty())
				return"Cart is empty\n";
			string cart;
			for(auto i :items){
				cart.append(i.second.get_item_info());
			}
			return cart + "\ntotal price : " + to_string(total_price()) + "\n";
		
		}


};


#endif
