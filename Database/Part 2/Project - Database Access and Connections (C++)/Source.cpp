#include <iostream>
#include <iomanip>
#include <occi.h>


using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;


int mainMenu();
int customerLogin(Connection* conn, int customerId);
double findProduct(Connection* conn, int product_id);
int addToCart(Connection* conn, struct Cart cart[]);
void displayProducts(struct Cart cart[], int productCount);
int checkout(Connection* conn, struct Cart cart[], int customerId, int productCount);
int yesOrno();

struct Cart {
	int product_id;
	double price;
	int quantity;
};

const int MAX_CART = 5;

int main(void)
{
	// OCCI Variables
	Environment* env = nullptr;
	Connection* conn = nullptr;
	// User Variables
	string str;
	string user = "dbs311_211b12";
	string pass = "42761549";
	string constr = "myoracle12c.senecacollege.ca:1521/oracle12c";

	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(user, pass, constr);


		int selection{};
		
		do
		{
			selection = mainMenu();

			if (selection == 1)
			{
				cout << "Enter the customer ID: ";
				int customerID{};
				cin >> customerID;

				if (customerLogin(conn, customerID))
				{
					Cart cart[MAX_CART]{};
					int numOfProd = addToCart(conn, cart);
					displayProducts(cart, numOfProd);
					checkout(conn, cart, customerID, numOfProd);
				}
				else
					cout << "The customer does not exist." << endl;

			}
			else
				cout << "Thank you --- Good bye...";

		} while (selection);


		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}

	return 0;
}



// mainMenu: to display a menu, prompt users to input a number, and return the number
int mainMenu()
{
	cout << "*************Main Menu by Jun ********************" << endl;
	cout << "1)      Login" << endl;
	cout << "0)      Exit" << endl;
	cout << "Enter an option (0-1): ";
	int selection{};
	cin >> selection;

	while (selection < 0 || selection > 1)
	{
		cout << "*************Main Menu by Jun ********************" << endl;
		cout << "1)      Login" << endl;
		cout << "0)      Exit" << endl;
		cout << "You entered a wrong value. Enter an option (0-1): ";
		cin >> selection;
	}

	return selection;
}

// customerLogin: to receive a OCCI pointer and customer ID,
//                and make sure if the customer Id is in the database
//                by calling the stored procedure
int customerLogin(Connection* conn, int customerId)
{
	Statement* stmt = conn->createStatement();

	int found;

	stmt->setSQL("BEGIN find_customer(:1, :2); END;");
	stmt->setInt(1, customerId);
	stmt->registerOutParam(2, Type::OCCIINT, sizeof(found));
	stmt->executeUpdate();
	found = stmt->getInt(2);

	conn->terminateStatement(stmt);

	return found;
}

// findProduct: to receive a OCCI pointer and product ID, 
//              search for the price of the product by calling the store procedure
//              and return the value of the price
double findProduct(Connection* conn, int product_id)
{
	Statement* stmt = conn->createStatement();

	double price{};

	stmt->setSQL("BEGIN find_product(:1, :2); END;");
	stmt->setInt(1, product_id);
	stmt->registerOutParam(2, Type::OCCIDOUBLE, sizeof(price));
	stmt->executeUpdate();
	price = stmt->getDouble(2);


	conn->terminateStatement(stmt);

	return price;
}

// addToCart: to receive a OCCI pointer and the array of ShoppingCart,
//            add the product users have searched for to the array,
//            and return the number of products added
int addToCart(Connection* conn, struct Cart cart[])
{
	Statement* stmt = conn->createStatement();

	cout << "-------------- Add Products to Cart --------------" << endl;

	int prodID{};
	double price{};
	int qty{};

	int numOfProd = 0;
	int addMore = 1;
	while (numOfProd < MAX_CART && addMore)
	{
		cout << "Enter the product ID: ";
		cin >> prodID;
		price = findProduct(conn, prodID);

		while (price == 0)
		{
			cout << "The product does not exist. Please try again..." << endl;
			cout << "Enter the product ID: ";
			cin >> prodID;
			price = findProduct(conn, prodID);
		}

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Product Price: " << price << endl;
		cout.unsetf(ios::fixed);
		cout.precision(6);

		cout << "Enter the product Quantity: ";
		cin >> qty;

		cart[numOfProd++] = Cart{ prodID , price , qty };

		if (numOfProd < MAX_CART)
		{
			cout << "Enter 1 to add more products or 0 to checkout: ";
			cin >> addMore;
		}
	}

	conn->terminateStatement(stmt);
	return numOfProd;
}

// displayProducts: to receive the array of ShoppingCart and the number of products
//                  and display all elements stored in the array
void displayProducts(struct Cart cart[], int productCount)
{
	cout << "------- Ordered Products -----------------------------" << endl;

	double total = 0;

	for (int i = 0; i < productCount; ++i)
	{
		cout << "---Item " << i + 1 << "  Product ID: " << setw(3) << cart[i].product_id << "  Price: ";

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << setw(6) << cart[i].price;

		cout << "  Quantity: " << cart[i].quantity << endl;

		total += cart[i].price * cart[i].quantity;
	}

	cout << "-------------------------------------------------------" << endl;
	cout << "Total: " << total << endl;
	cout << "=======================================================" << endl;

	cout.unsetf(ios::fixed);
	cout.precision(6);

}

// yesOrno: return 1 when user inputs 'Y' or 'y', return 0 when user inputs 'N' or 'n'
int yesOrno()
{
	char input{};
	cin >> input;
	while (input != 'Y' && input != 'y' && input != 'N' && input != 'n')
	{
		cout << "Wrong input. Please try again..." << endl;
		cout << "Would you like to checkout? (Y/y or N/n) ";
		cin >> input;
	}

	int yesno = (input == 'Y' || input == 'y') ? 1 : 0;

	return yesno;
}

// checkout: to receive a OCCI pointer, the array of ShoppingCart, customer ID, and the number of
//           products and then if a customer want, save an order and order detail in ShoppingCart
//           by calling the stored procedures
int checkout(Connection* conn, struct Cart cart[], int customerId, int productCount)
{
	cout << "Would you like to checkout? (Y/y or N/n) ";

	int checkoutStatus = yesOrno();

	if (checkoutStatus)
	{
		Statement* stmt = conn->createStatement();

		cout << "The order is successfully completed." << endl;

		int new_orderID{};

		stmt->setSQL("BEGIN add_order(:1, :2); END;");
		stmt->setInt(1, customerId);
		stmt->registerOutParam(2, Type::OCCIINT, sizeof(new_orderID));
		stmt->executeUpdate();
		new_orderID = stmt->getInt(2);


		for (int i = 0; i < productCount; ++i)
		{
			stmt->setSQL("BEGIN add_orderline(:1, :2, :3, :4, :5); END;");
			stmt->setInt(1, new_orderID);
			stmt->setInt(2, i + 1);
			stmt->setInt(3, cart[i].product_id);
			stmt->setInt(4, cart[i].quantity);
			stmt->setDouble(5, cart[i].price);
			stmt->executeUpdate();
		}

		conn->terminateStatement(stmt);
	}
	else
		cout << "The order is cancelled." << endl;

	return checkoutStatus;

}
