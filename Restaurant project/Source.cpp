#include<iostream>
#include<assert.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<windows.h>
#include<vector>
using namespace std;
void mysetcolor(int fg, int bg)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(h, fg | (bg << 4));
}

template<class T>
class Stack {
	T* data;
	size_t size = 0;
public:
	Stack() :data(NULL), size(NULL) {}
	void Push(const T& newdata) {
		auto newarray = new T[size + 1]{};
		for (size_t i = 0; i < size; i++)
		{
			newarray[i] = data[i];
		}
		newarray[size] = newdata;
		data = newarray;
		newarray = nullptr;
		++size;
	}
	void Pop(int index = -1) {
		if (index != -1) {
			auto newitems = new T[size - 1]{};
			for (size_t i = 0; i < index; i++)
			{
				newitems[i] = data[i];
			}
			int index1 = index + 1;
			int index2 = index;
			for (size_t i = 0; i < size - (index + 1); i++)
			{
				newitems[index2] = data[index1];
				index1++;
				index2++;
			}
			data = newitems;
			newitems = nullptr;
			size -= 1;
		}
		else {
			auto newitems = new T[size - 1]{};
			for (size_t i = 0; i < size - 1; i++)
			{
				newitems[i] = data[i];
			}
			data = newitems;
			newitems = nullptr;
			size -= 1;
		}
	}
	int Peek()const {
		assert(size > 0 && "Empty Stack");
		return data[size - 1];
	}
	void Clear() {
		if (this->data == NULL || this->size == NULL) {
			return;
		}
		delete[]data;
		this->data = NULL;
		this->size = NULL;
	}
	void Show()const {
		for (size_t i = 0; i < size; i++)
		{
			cout << data[i] << endl;
		}
	}
	size_t GetSize()const {
		return size;
	}
	T& operator[](int index) {
		assert(index >= 0 && index <= size && "Invalid Index");
		return data[index];
	}
	~Stack()
	{
		//delete[]data;
	}
};

class Product {
	string name;
	double price;
	double calories;
	int id;
	int count;
public:
	static int ID;
	Product() = default;
	Product(const string& name, const double& price, const double& calories, const int& count) {
		SetId(ID++);
		SetName(name);
		SetPrice(price);
		SetCalories(calories);
		SetCount(count);
	}
	void SetId(const int& id) {
		this->id = id;
	}
	void SetCount(const int& count) {
		assert(count > 0 && "Product count will be more than 0");
		this->count = count;
	}
	void SetName(const string& name) {
		assert(!name.empty() && "Name of product is null");
		this->name = name;
	}
	void SetCalories(const double& calories) {
		assert(calories > 0 && "Calories of product is negative or equal to 0");
		this->calories = calories;
	}
	void SetPrice(const double& price) {
		assert(price >= 0 && "Price of product is negative or equal to 0");
		this->price = price;
	}
	double GetPrice()const {
		return price;
	}
	int GetCount()const {
		return count;
	}
	double GetCalories()const {
		return calories;
	}
	int GetId()const {
		return id;
	}
	string GetName()const {
		return name;
	}
	friend ostream& operator<<(ostream& out, const Product& products);
};
int Product::ID = 1;
ostream& operator<<(ostream& out, const Product& products) {
	//out << "Id : " << products.GetId() << endl << endl;
	out << "Product name : " << products.name << endl;
	//out << "Product price : " << products.price << endl;
	out << "Product calories : " << products.calories << endl;
	return out;
}


class Meal {
	int id;
	double price;
	Stack<Product>products;
	string name;
	double allCalories;
public:
	static int ID;
	Meal() = default;
	Meal(const double& price, const string& name) {
		SetId(ID++);
		SetName(name);
		SetPrice(price);
		//allCalories += GetCalories();
	}
	void SetName(const string& name) {
		assert(!name.empty() && "Name of Meal is null");
		this->name = name;
	}
	void SetPrice(const double& price) {
		assert(price > 0 && "Price of Meal is negative or equal to 0");
		this->price = price;
	}
	void SetId(const int& id) {
		this->id = id;
	}
	int GetId()const {
		return id;
	}
	double GetPrice()const {
		return price;
	}
	string GetName()const {
		return name;
	}
	void AddProduct(Product& product) {
		products.Push(product);
	}
	void GetAllCalories() {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			allCalories += products[i].GetCalories();
		}
	}

	Product* GetProductById(int id) {
		for (size_t i = 0; i < products.GetSize(); i++)
		{
			if (products[i].GetId() == id) {
				return &products[i];
			}
		}
	}


	void UpdateProduct() {
		cout << "Enter id of product : ";
		int id;
		cin >> id;
		auto product = GetProductById(id);
		cout << "[1] Product name" << endl;
		cout << "[2] Product price" << endl;
		cout << "[3] Product calories" << endl;
		cout << "[4] Product count" << endl;
		cout << "Enter choice : ";
		int choice;
		cin >> choice;
		if (choice == 1) {
			cin.ignore();
			cin.clear();
			cout << "Enter name : ";
			string name;
			getline(cin, name);
			product->SetName(name);
		}
		else if (choice == 2) {
			cout << "Enter price : " << endl;
			double price;
			cin >> price;
			product->SetPrice(price);
		}
		else if (choice == 3) {
			cout << "Enter calories : " << endl;
			double calories;
			cin >> calories;
			product->SetCalories(calories);
		}
		else if (choice == 4) {
			cout << "Enter count : " << endl;
			int count;
			cin >> count;
			product->SetCount(count);
		}

	}

	void ShowProductOfMeal()
	{
		products.Show();
	}
	friend ostream& operator<<(ostream& out, Meal& meal) {
		out << "Id : " << meal.GetId() << endl << endl;
		out << "Name of Meal : " << meal.name << endl << endl;
		meal.products.Show();
		meal.GetAllCalories();
		out << "Calories of Meal : " << meal.allCalories << endl;
		return out;
	}
};


class ClientNotification {
	string content;
	string tableNo;
public:
	ClientNotification() = default;
	ClientNotification(const string& content, const string& tableNo) {
		SetContent(content);
		SetTableNo(tableNo);
	}

	void SetContent(const string& content) {
		if (!content.empty()) {
			this->content = content;
		}
		//throw "Content is null of client notification";
	}
	void SetTableNo(const string& tableNo) {
		if (!tableNo.empty()) {
			this->tableNo = tableNo;
		}
		//throw "No of table is empty";
	}

	string GetTableNo()const noexcept {
		return tableNo;
	}
	string GetContent()const noexcept {
		return content;
	}

	friend ostream& operator<<(ostream& out, const ClientNotification& clientnotifications);
};
ostream& operator<<(ostream& out, const ClientNotification& clientnotifications) {
	out << "Content : " << clientnotifications.GetContent() << endl;
	out << "Table NO : " << clientnotifications.GetTableNo() << endl;
	return out;
}

class Notification {
	int quantity;
	string tableNo;
public:
	Stack<Meal>meals;
	Notification() = default;
	Notification(const int& quantity, const string& tableNo) {
		SetNotificationQuantity(quantity);
		SetTableNo(tableNo);
	}
	void SetNotificationQuantity(const int& quantity) {
		if (quantity > 0) {
			this->quantity = quantity;
		}
		//throw "Quantity of notification is null";
	}
	void SetTableNo(const string& tableNo) {
		if (!tableNo.empty()) {
			this->tableNo = tableNo;
		}
		//throw "No of table is empty";
	}

	int GetQuantity()const noexcept {
		return quantity;
	}
	string GetTableNo()const noexcept {
		return tableNo;
	}

	void AddMealToNotification(Meal* meal) {
		meals.Push(*meal);
	}
	friend ostream& operator<<(ostream& out, const Notification& notifications);
};
ostream& operator<<(ostream& out, Notification& notifications) {
	for (size_t i = 0; i < notifications.meals.GetSize(); i++)
	{
		out << notifications.meals[i] << endl;
	}
	out << "Meal count : " << notifications.GetQuantity() << endl;
	out << "Table no : " << notifications.GetTableNo() << endl;
	return out;
}

class Table {
	string message;
	string name;
public:
	static int notificationcount;
	Stack<ClientNotification>clientnotification;
	Stack<Notification>notifications;
	Table() = default;
	Table(const int& notif) {
		SetCount(notificationcount);
	}

	void SetMessage(const string& message) {
		this->message = message;
	}
	void SetCount(const int& notificationcount) {
		this->notificationcount = notificationcount;
	}
	void SetName(const string& name) {
		this->name = name;
	}

	string GetMessage() const {
		return message;
	}
	int GetNotificationCount()const {
		return notificationcount;
	}
	string GetName()const {
		return name;
	}

	void AddNotification(const Notification& notification) {
		notifications.Push(notification);
	}
};
int Table::notificationcount = 0;

int Meal::ID = 1;

class Kitchen :public Meal {
public:
	Stack<Meal>meals;
	Stack<Notification>notification;
	static int notificationCount;
	Kitchen() = default;
	Kitchen(const int& notificationCount, const string& meal) {
		SetNotificationCount(notificationCount);
	}
	void SetNotificationCount(const int& notificationCount) {
		assert(notificationCount >= 0 && "Notification count is negative number");
		this->notificationCount = notificationCount;
	}
	int GetNotificationCount()const {
		return notificationCount;
	}

	void AddMeal(Meal& meal) {
		meals.Push(meal);
	}
	void Show()const {
		meals.Show();
	}
	void ShowName() {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			cout << meals[i].GetId() << ". " << meals[i].GetName() << " - " << meals[i].GetPrice() << " $" << endl;
		}
	}
	void ShowMealById(int id) {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			if (meals[i].GetId() == id) {
				cout << meals[i] << endl;
			}
		}
	}
	Meal* GetMealById(int id) {
		for (size_t i = 0; i < meals.GetSize(); i++)
		{
			if (meals[i].GetId() == id) {
				return &meals[i];
			}
		}
	}
	void MealsPop(int index) {
		meals.Pop(index);
	}
	int GetMealCount() {
		return meals.GetSize();
	}


	void AddMeal() {
		cin.ignore();
		cin.clear();
		cout << "Enter name : ";
		string name;
		getline(cin, name);
		cout << "Enter price : ";
		double price;
		cin >> price;
		cout << endl;
		Meal newMeal(price, name);
		cout << "PRODUCT COUNT : ";
		int count;
		cin >> count;
		for (size_t i = 1; i <= count; i++)//2
		{
			cin.ignore();
			cin.clear();
			cout << "Enter " << i << " product name : ";
			string pName;
			getline(cin, pName);
			cout << "Enter " << i << " product price : ";
			double price;
			cin >> price;
			cout << "Enter " << i << " product calories : ";
			double calories;
			cin >> calories;
			cout << "Enter " << i << " product count : ";
			int count;
			cin >> count;
			Product p(name, price, calories, count);
			newMeal.AddProduct(p);
		}
		meals.Push(newMeal);
		cout << "Meal added successfully" << endl;
	};
	void UptadeMeals(int id) {
		auto meal = GetMealById(id);
		cout << "[1] Name" << endl;
		cout << "[2] Price" << endl;
		cout << "[3] Products" << endl;
		cout << "Enter select : " << endl;
		int select;
		cin >> select;
		if (select == 1) {
			cin.ignore();
			cin.clear();
			cout << "Enter meal name : ";
			string name;
			getline(cin, name);
			meal->SetName(name);
		}
		else if (select == 2) {
			cout << "Enter meal price : ";
			double price;
			cin >> price;
			meal->SetPrice(price);
		}
		else if (select == 3) {
			meal->ShowProductOfMeal();
			meal->UpdateProduct();
		}
	}
};

int Kitchen::notificationCount = 0;

class Stock {
public:
	vector<Product>products;
	Stock() = default;
	void AddProduct(Product& product) {
		products.push_back(product);
	}
	void Show() {
		int id = 1;
		cout << "------ALL PRODUCTS------" << endl << endl;
		for (size_t i = 0; i < products.size(); i++)
		{
			cout << "Id : " << id++ << endl << endl;
			cout << products[i];
			cout << "Product count : " << products[i].GetCount() << endl << endl;
		}
	}
	auto* GetProductById(int index) {
		for (size_t i = 0; i < products.size(); i++)
		{
			if (products[i].GetId() == index) {
				return &products[i];
			}
		}
	}
	bool ProductCount(int index, int count) {
		auto product = GetProductById(index);
		int temp = product->GetCount() - count;
		if (temp >= 0) {
			products[index].SetCount(temp);
			return true;
		}
		return false;
	}
	void DeleteIngredientsByID(int index) {
		if (index == 1) {
			products.pop_back();
		}
		else {
			products.erase(products.begin() + index);
		}
	}

	void ShowProductCount() {
		for (size_t i = 0; i < products.size(); i++)
		{
			cout << products[i].GetId() << " - " << products[i].GetName() << " count " << products[i].GetCount() << endl << endl;
		}

	}

	int GetProductCount() {
		return products.size();
	}
};
class Client {
	Stack<Kitchen>menu;
	Stack<Table>table;
public:
	string tableNo;
	Client() = default;
	Client(const string& tableNo) {
		SetTable(tableNo);
	}
	void SetTable(const string& tableNo) {
		assert(!tableNo.empty() && "Table no is empty");
		this->tableNo = tableNo;
	}
	string GetTableNo()const {
		return tableNo;
	}
	void AddMenu(Kitchen& kitchen) {
		menu.Push(kitchen);
	}
	void ShowMenu() {
		for (size_t i = 0; i < menu.GetSize(); i++)
		{
			menu[i].ShowName();
		}
	}
};

class FileHelper {
public:
	static string filename;

	static void Save(Stock& stock) {
		ofstream fout(filename, ios::app);
		if (fout.is_open()) {
			int count1 = stock.GetProductCount();
			fout << count1 << endl;
			for (size_t i = 0; i < stock.products.size(); i++)
			{
				fout << stock.products[i].GetName() << " " << stock.products[i].GetPrice() << " " << stock.products[i].GetCalories() << " " << stock.products[i].GetCount() << endl;
			}
			fout.close();
		}

	}


	static Stock Read() {
		Stock stock;
		ifstream fin(filename);
		int count1;
		fin >> count1;
		if (fin.is_open()) {

			for (size_t i = 0; i < count1; i++)
			{
				Product p;
				string name;
				double price;
				double calories;
				int count;

				fin >> name;
				fin >> price;
				fin >> calories;
				fin >> count;
				p.SetName(name);
				p.SetPrice(price);
				p.SetCalories(calories);
				p.SetCount(count);
				stock.AddProduct(p);
			}
			fin.close();

			return stock;
		}
	}
};

string FileHelper::filename = "products.txt";

void AdminMenu(Kitchen& k, Stock& s) {
	system("cls");
	cout << "[1] KITCHEN " << endl;
	cout << "[2] STOCK   " << endl;
	cout << "[3] BACK   " << endl;
	cout << "Enter select : ";
	int adminselect = 0;
	cin >> adminselect;
	if (adminselect == 1) {
		cout << "-----KITCHEN-----" << endl;
		k.ShowName();
		cout << "[1] Delete meal " << endl;
		cout << "[2] Update meal" << endl;
		cout << "[3] Add meal" << endl;
		cout << "[4] Notification" << endl;
		cout << "Enter your select : ";
		int select;
		cin >> select;
		if (select == 1) {
			while (true)
			{
				cout << "Enter ID of meal : ";
				int id;
				cin >> id;
				if (k.GetMealCount() >= id) {
					--id;
					k.MealsPop(id);
					system("cls");
					k.ShowName();
					cout << endl << "Food deleted!" << endl;
					system("pause");
					break;
				}
				else {
					cout << "Meal not found!" << endl;
				}
			}
			AdminMenu(k, s);
		}
		else if (select == 2) {
			cout << "Select meal id : ";
			int id;
			cin >> id;
			k.UptadeMeals(id);
			cout << "Meal updated succesfully" << endl;
			system("pause");
			AdminMenu(k, s);
		}
		else if (select == 3) {
			k.ShowName();
			k.AddMeal();
			AdminMenu(k, s);
		}
		else if (select == 4) {


		}
	}
	else if (adminselect == 2) {
		while (true) {
			system("cls");
			cout << "\n<><><><><><>STOCK<><><><><><>" << endl << endl;
			cout << "[1] Show Ingredients" << endl;
			cout << "[2] Add Ingredients" << endl;
			cout << "[3] Delete Ingredients" << endl;
			cout << "[4] Update ingredients count" << endl;
			cout << "[5] BACK" << endl;
			cout << "Select : ";
			int select;
			cin >> select;
			if (select == 1) {
				s.Show();
				system("pause");
			}
			else if (select == 2) {
				cin.ignore();
				cin.clear();
				cout << "Enter ingredients name : ";
				string name;
				getline(cin, name);

				cout << "Enter ingredients price : ";
				double price;
				cin >> price;

				cout << "Enter ingredients calories : ";
				double calories;
				cin >> calories;


				cout << "Enter ingredient count : ";
				int count;
				cin >> count;

				Product p(name, price, calories, count);
				s.AddProduct(p);
				remove("products.txt");
				FileHelper::Save(s);
				cout << "Ingredient added successfully" << endl;
				system("pause");
			}
			else if (select == 3) {
				s.Show();
				cout << "Enter id of ingredients : ";
				int id;
				cin >> id;
				--id;
				s.DeleteIngredientsByID(id);
				remove("products.txt");
				FileHelper::Save(s);
				cout << "Ingredient deleted successfully" << endl;
				system("pause");
			}
			else if (select == 4) {
				s.ShowProductCount();
				cout << "Enter id of ingredient : ";
				int id1;
				cin >> id1;
				Product* p = s.GetProductById(id1);
				cout << "Enter new count : ";
				int count;
				cin >> count;
				p->SetCount(count);
				remove("products.txt");
				FileHelper::Save(s);
				cout << "Count uptaded successfully" << endl;

			}
			else if (select == 5) {
				break;
			}
			else {
				cout << "Invalid select !!" << endl;
				system("pause");
			}
		}


	}
	else if (adminselect == 3) {
		return;
	}
}


void ClientMenu(double totalPrice, Client c, Kitchen k, Stock stock) {
	c.ShowMenu();
	cout << "[1] Select meal" << endl;
	cout << "[2] Search meal" << endl;
	cout << "[3] Notification" << endl;
	cout << "Enter your select : ";
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << "Enter your choice to view : ";
		int select;
		cin >> select;
		cout << endl;
		k.ShowMealById(select);
		cout << "[1] Order" << endl;
		cout << "[2] Add ingredients" << endl;
		cout << "Enter select : ";
		int select1;
		cin >> select1;
		if (select1 == 1) {
			cout << "Enter meal count : ";
			int count;
			cin >> count;
			if (count > 0) {
				auto meal = k.GetMealById(select);
				totalPrice += count * meal->GetPrice();
				cout << "Total price : " << totalPrice << " $" << endl;
				cout << "[1] Continue" << endl;
				cout << "[2] Finish" << endl;
				cout << "Select : ";
				int select;
				cin >> select;
				if (select == 1) {
					ClientMenu(totalPrice, c, k, stock);
				}
				else if (select == 2) {


				}
			}
		}
		else if (select1 == 2) {
			cout << endl;
			stock.Show();
			cout << "Enter ingredients id : ";
			int id;
			cin >> id;
			auto product = stock.GetProductById(id);
			cout << *product << endl;
			cout << "Enter " << product->GetName() << " count : ";
			double count;
			cin >> count;
			if (stock.ProductCount(id, count)) {
				auto meal = k.GetMealById(select);
				meal->AddProduct(*product);
				totalPrice += meal->GetPrice();
				double a = product->GetPrice();
				totalPrice += product->GetPrice() * count;
				cout << "\n" << *meal << endl;
				cout << "Ingredients added successfully" << endl << endl;
				cout << "Total price : " << totalPrice << " $" << endl;
			}
			else {
				auto meal = k.GetMealById(select);
				totalPrice += meal->GetPrice();
				cout << "Ingredients out of stock" << endl;
			}
		}
	}
	else if (choice == 2) {
		cout << "Enter meal name : ";
		int a1;
		int num = 0;
		for (size_t i = 0; i < 6; i++)
		{
			char meal = _getch();
			cout << meal;
			int b = k.GetMealCount();
			for (size_t i3 = 0; i3 < k.GetMealCount(); i3++)
			{
				Meal meal1 = k.meals[i3];
				cout << endl;
				int i2 = 0;
				while (true)
				{
					char a = meal1.GetName()[i2];
					if (meal1.GetName()[i2] == meal) {
						string a = meal1.GetName();
						cout << "[" << ++num << "] " << a << endl;
					}
					++i2;
					if (meal1.GetName().length() == i2) {
						a1 = i3;
						break;
					}
				}
			}
			if (char(meal) >= 48 && char(meal) <= 57) {
				break;
			}
			else {

			}
		}
		k.ShowMealById(a1);
		cout << "[1] Order" << endl;
		cout << "[2] Add ingredients" << endl;
		cout << "Enter select : ";
		int select1;
		cin >> select1;
		if (select1 == 1) {
			cout << "Enter meal count : ";
			int count;
			cin >> count;
			if (count > 0) {
				auto meal = k.GetMealById(a1);
				totalPrice += count * meal->GetPrice();
				cout << "Total price : " << totalPrice << " $" << endl;
				cout << "[1] Continue" << endl;
				cout << "[2] Finish" << endl;
				cout << "Select : ";
				int select;
				cin >> select;
				if (select == 1) {
					ClientMenu(totalPrice, c, k, stock);
				}
				else if (select == 2) {


				}
			}
		}
		else if (select1 == 2) {
			cout << endl;
			stock.Show();
			cout << "Enter ingredients id : ";
			int id;
			cin >> id;
			auto product = stock.GetProductById(id);
			cout << *product << endl;
			cout << "Enter " << product->GetName() << " count : ";
			double count;
			cin >> count;
			if (stock.ProductCount(id, count)) {
				auto meal = k.GetMealById(a1);
				meal->AddProduct(*product);
				totalPrice += meal->GetPrice();
				double a = product->GetPrice();
				totalPrice += product->GetPrice() * count;
				cout << "\n" << *meal << endl;
				cout << "Ingredients added successfully" << endl << endl;
				cout << "Total price : " << totalPrice << " $" << endl;
			}
			else {
				auto meal = k.GetMealById(a1);
				totalPrice += meal->GetPrice();
				cout << "Ingredients out of stock" << endl;
			}
		}



	}

};

void SendNotificationToClient(ClientNotification& n, Table& t) {
	t.clientnotification.Push(n);
	t.notificationcount++;
}
void SendNotification(Notification& n1, Kitchen& k) {
	k.notification.Push(n1);
	k.notificationCount++;
}

void main() {
	Product p("Tomato", 0.4, 18, 100);
	Product p1("Olive", 0.1, 115, 100);
	Product p2("Mashroom", 0.8, 22, 100);
	Product p3("Flour", 1, 364, 100);
	Product p4("Cucumber", 1, 364, 100);

	Stock stocksave;
	stocksave.AddProduct(p);
	stocksave.AddProduct(p1);
	stocksave.AddProduct(p2);
	stocksave.AddProduct(p3);
	stocksave.AddProduct(p4);
	Meal f(20, "Moz");
	f.AddProduct(p);
	f.AddProduct(p1);
	f.AddProduct(p2);
	f.AddProduct(p3);
	Meal f1(13, "SeMzar");
	f1.AddProduct(p);
	f1.AddProduct(p1);
	Kitchen k;
	k.AddMeal(f);
	k.AddMeal(f1);
	Client c("T-20");
	c.AddMenu(k);
	//FileHelper::Save(stocksave);
	Stock stock = FileHelper::Read();

#pragma region START
	double totalPrice = 0;
	while (true)
	{
		system("cls");

		mysetcolor(11, 0);
		cout << "                                                          _____                    _____                    _____                    _____                _____          	                         " << endl;
		cout << "                                                         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\              /\\    \\         	             " << endl;
		cout << "                                                        /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\            /::\\    \\        	             " << endl;
		cout << "                                                       /::::\\    \\              /::::\\    \\              /::::\\    \\              /::::\\    \\           \\:::\\    \\       	             " << endl;
		cout << "                                                      /::::::\\    \\            /::::::\\    \\            /::::::\\    \\            /::::::\\    \\           \\:::\\    \\      	             " << endl;
		cout << "                                                     /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\           \\:::\\    \\     	         " << endl;
		cout << "                                                    /:::/  \\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\           \\:::\\    \\    	         " << endl;
		cout << "                                                   /:::/    \\:::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\          /::::\\    \\   	         " << endl;
		cout << "                                                  /:::/    / \\:::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\        /::::::\\    \\  	         " << endl;
		cout << "                                                 /:::/    /   \\:::\\ ___\\  /:::/\\:::\\   \\:::\\____\\  /:::/\\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\    \\      /:::/\\:::\\    \\       " << endl;
		cout << "                                                /:::/____/  ___\\:::|    |/:::/  \\:::\\   \\:::|    |/:::/__\\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::\\____\\    /:::/  \\:::\\____\\	         " << endl;
		cout << "                                                \\:::\\    \\ /\\  /:::|____|\\::/   |::::\\  /:::|____|\\:::\\   \\:::\\   \\::/    /\\::/    \\:::\\  /:::/    /   /:::/    \\::/    /	         " << endl;
		cout << "                                                 \\:::\\    /::\\ \\::/    /  \\/____|:::::\\/:::/    /  \\:::\\   \\:::\\   \\/____/  \\/____/ \\:::\\/:::/    /   /:::/    / \\/____/ 	         " << endl;
		cout << "                                                  \\:::\\   \\:::\\ \\/____/         |:::::::::/    /    \\:::\\   \\:::\\    \\               \\::::::/    /   /:::/    /          	             " << endl;
		cout << "                                                   \\:::\\   \\:::\\____\\           |::|\\::::/    /      \\:::\\   \\:::\\____\\               \\::::/    /   /:::/    /           	             " << endl;
		cout << "                                                    \\:::\\  /:::/    /           |::| \\::/____/        \\:::\\   \\::/    /               /:::/    /    \\::/    /                                " << endl;
		cout << "                                                     \\:::\\/:::/    /            |::|  ~|               \\:::\\   \\/____/               /:::/    /      \\/____/                                  " << endl;
		cout << "                                                      \\::::::/    /             |::|   |                \\:::\\    \\                  /:::/    /                           	                     " << endl;
		cout << "                                                       \\::::/    /              \\::|   |                 \\:::\\____\\                /:::/    /                            	                     " << endl;
		cout << "                                                        \\::/____/                \\:|   |                  \\::/    /                \\::/    /                             	                     " << endl;
		cout << "                                                                                  \\|___|                   \\/____/                  \\/____/                              	                     " << endl;
		cout << "                                                                                                                                                                            	                     " << endl;
		cout << "                                                                                                                                                                                                    " << endl;
		mysetcolor(3, 0);
		cout << "                                                                                                  _                              _                                     	                         " << endl;
		cout << "                                                                                    _ __ ___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_ 	                                                             " << endl;
		cout << "                                                                                   | '__/ _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __|	                                                         " << endl;
		cout << "                                                                                   | | |  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_ 	                                                         " << endl;
		cout << "                                                                                   |_|  \\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__|	                                                     " << endl;
		cout << "                                                                                                                                         	                                                         " << endl;
		cout << "			                           											                                                                                                                     " << endl;
		mysetcolor(7, 0);
		cout << "                                                                                                        CLIENT [1]                                                                                  " << endl << endl;
		cout << "                                                                                                        ADMIN  [2]                                                                                  " << endl << endl;
		cout << "                                                                                                    Enter select [1/2] : ";
		string select;
		cin >> select;
		if (select == "1") {
			system("cls");
			ClientMenu(totalPrice, c, k, stock);
		}
		else if (select == "2") {
			system("cls");
			while (true)
			{
				cin.ignore();
				cin.clear();
				system("cls");
				cout << "Enter username : ";
				string username;
				getline(cin, username);
				system("cls");
				cout << "Enter Password: ";
				string password, P;
				char p;
				p = _getch();
				while (p != 13)
				{
					if (p == 8)
					{
						P.resize(P.length() - 1);
						cout << P;
						password.resize(password.length() - 1);
					}
					else {
						P = P + "*";
						cout << P;
						password.push_back(p);
					}
					p = _getch();
					if (p != 13) {
						system("cls");
						cout << "Enter Password: ";
					}
				}
				cout << endl;
				if (username == "admin") {
					if (password == "admin") {
						AdminMenu(k, stock);
						break;
					}
					else {
						cout << "Wrong password!" << endl;
					}
				}
				else {
					cout << "Wrong username!" << endl;
				}
			}
		}
		else {
			cout << "Your select is incorrect!!!\n";
			cout << "Please enter retry" << endl;
		}
		system("pause");
	}
#pragma endregion	
}


