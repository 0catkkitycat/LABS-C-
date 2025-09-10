#include <iostream>
#include <string>

class ShopItemOrder
{
private:
	std::string itemName;
	float unitPrice;
	int numberItem;

public: 
	ShopItemOrder(std::string itemName, float unitPrice, int numberItem) {
		this->itemName = itemName;
		this->unitPrice = unitPrice;
		this->numberItem = numberItem;
	}
	void set_itemName(std::string itemName);
	void set_unitPrice(float unitPrice);
	void set_numberItem(int numberItem);

	std::string get_itemName() {
		return itemName;
	}


	float get_unitPrice() {
		return unitPrice;
	}

	int get_numberItem() {
		return numberItem;
	}

	float get_totalShop();

	void printOrder();
};

void ShopItemOrder::set_itemName(std::string itemName) {
	this->itemName = itemName;
}
void ShopItemOrder::set_unitPrice(float unitPrice) {
	this->unitPrice = unitPrice;
}

void ShopItemOrder::set_numberItem(int numberItem) {
	this->numberItem = numberItem;
}

float ShopItemOrder::get_totalShop() {
	return numberItem * unitPrice;
}

void ShopItemOrder::printOrder() {
	std::cout << "Item name: " << itemName << " Unit price: " << unitPrice << " Number of items: " << numberItem << " Total price: " << get_totalShop() << std::endl;
}

int main()
{
	ShopItemOrder orderTShirts("T-shirt mens black size M", 23.4, 3);
	ShopItemOrder orderJeans("Jeans mens blue size M", 42.2, 2);

	orderJeans.printOrder();
	orderTShirts.printOrder();

	return 0;
}



