#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int burger(int*, int*, int*);
int fries(int*, int*, int*);
int wings(int*);
int nuggets(int*);
int chowmein(int*);
int soup(int*, int*, int*);
int pizza(int*, int*, int*);
int cold(int*, int*, int*);
void option_checker(int*);
bool endsWithGmail(const char* input)   //to check that the user had enter @gmail.com or not 
{

	int length = 0;
	while (input[length] != '\0')
	{
		length++;
	}


	const char* gmailSuffix = "@gmail.com";
	int suffixLength = 0;
	while (gmailSuffix[suffixLength] != '\0') {
		suffixLength++;
	}


	if (length < suffixLength) {
		return false;
	}


	for (int i = 0; i < suffixLength; i++) {
		if (input[length - suffixLength + i] != gmailSuffix[i]) {
			return false;
		}
	}


	return true;
}

void login(ifstream& obj) //FUNCTION THAT WILL READ THE USER'S LOGIN DATA GMAIL AND PASSWORD
{
	int count = 0, fb = 0;
	int count2 = 0;
	char* sig = new char[100];
	char line[100];
	bool gmail = false;
	bool pass = false;
	char* pas = new char[50];
	char lee[50];
	char com[11] = "@gmail.com";
	obj.open("login.txt");
	if (!obj)                       //CHECK IF FILE IS OPEN OR NOT 
	{
		cout << "FILE NOT OPEN" << endl;
		return;
	}
	cin.ignore();
	cout << "ENTER YOUR GMAIL: ";
	cin.getline(sig, 100);        //USERS EXISTING GMAIL THAT IS SAVED IN OUR FILE
	while (!obj.eof())            //READING THE FILE USING EOF
	{
		count++;
		obj.getline(line, sizeof(line));
		if (strcmp(line, sig) == 0 && count % 2 != 0)
		{
			gmail = true;
			cout << "Gmail found." << endl; //DELETE IT LATER
			break;
		}
	}
	if (!gmail)
	{
		cout << "Incorrect Gmail." << endl;
	}

	while (gmail)
	{
		cout << "Enter your Password: ";
		cin.getline(pas, 50);
		obj.clear();
		obj.seekg(0, ios::beg);
		while (!obj.eof())
		{
			count2++;
			obj.getline(lee, 50);

			if (strcmp(lee, pas) == 0 && count2 == count + 1)
			{
				pass = true;
				break;
			}
		}
		cout << "count2 =" << count2 << endl;
		if (!pass)
		{
			count2 = 0;
			cout << "Incorrect Password Enter again." << endl;
		}
		else
		{
			cout << "Login successful." << endl;
			break;
		}
	}
	delete[] sig;
	delete[] pas;
	obj.close();
}

void signup(ofstream& file)    // Function to create a file and save data in it
{
	char* ar = new char[100];  // Array for Gmail
	char arr[50]; // Array for Password
	file.open("login.txt", ios::app); // Opening the file in append mode
	if (!file) // Check if the file is open or not
	{
		cout << "FILE NOT CREATED" << endl;
		return;
	}
	cin.ignore();
	cout << "ENTER YOUR GMAIL: ";
	cin.getline(ar, 100);
	bool a = endsWithGmail(ar);// Enter Gmail
	if (a != true)
	{
		while (a != true)    //to check the user has entered a gmail id or not
		{
			cout << "Enter correct gmail: ";
			cin.getline(ar, 100);
			a = endsWithGmail(ar);
		}
	}
	ifstream check("login.txt");  //Reading the login file 
	if (!check)
	{
		cout << "File not open" << endl;
		return;
	}
	char line[100];
	bool mail = false;
	while (check.getline(line, sizeof(line)))
	{
		if (strcmp(line, ar) == 0)   //checking that the gmail enterred by the user already exists or not 
		{
			mail = true;
			cout << "Gmail already exists" << endl;
			cout << "Enter a new gmail" << endl;
			cin.getline(ar, 100);
		}
	}
	check.close();  //closing the file for reading
	cout << "ENTER YOUR PASSWORD: ";
	cin.getline(arr, 50); // Enter Password
	file << ar << endl; // Write Gmail to file
	file << arr << endl; // Write Password to file
	file.close(); //closing the file for writing
	delete[] ar;
}

int main()
{
	char select;
	cout << "                                                   WELCOME TO Our Food Resturent                                                   "  << endl;
	cout << "PLEASE SELECT FROM THE GIVEN OPTION" << endl;
	cout << "1-LOGIN\n2-SIGN UP" << endl;
	cin >> select;
	while (select != '1' && select != '2') //FOR LOGIN AND SIGNUP
	{
		cout << "PLEASE ENTER THE CORRECT OPTION" << endl;
		cin >> select;
	}
	if (select == '1') //IF LOGIN 
	{
		ifstream obj;
		login(obj);
	}
	else if (select == '2') //IF SIGNUP
	{
		ofstream file;
		signup(file);
	}
	ofstream fout("items.txt", ios::app);

	int* op = new int;
	int* b1 = new int; // burger
	int* b2 = new int; // burger
	int* r = new int;
	int* f = new int; // friese
	int* f1 = new int; // cheese fries
	int* f2 = new int; // barbecue fries
	int* w = new int; //hot wings
	int* n = new int; // nuggets
	int* ch = new int; // chowmein
	int* s = new int; // soup
	int* s1 = new int; // corn soup;
	int* s2 = new int; // tomato soup
	int* p = new int; // pizza
	int* p1 = new int; // Chicken fajita
	int* p2 = new int; // Chicken Tikka
	int* drink = new int; // cold drink
	int* drink1 = new int; // cock
	int* drink2 = new int; // dew



	int b_sum = 0, f_sum = 0, w_sum = 0, n_sum = 0, c_sum = 0, s_sum = 0, p_sum = 0, d_sum = 0, count = 0;


	char* o = new char;
	int* c = new int;
	int* d = new int;
	int* total = new int;
	int array[8];
	int flag = 0;

	*c = 0;
	*d = 0;
	*total = 0;
	for (int i = 0; i < 8; i++)
	{
		array[i] = 0;
	}


	do
	{
	label1:
		cout << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "|   Category    |            Item             |  Price  |         Description         |     Special Offers        |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------|" << endl;
		cout << "|  1- Burgers       Cheese Burger               200       Juicy beef patty with                  5%               |" << endl;
		cout << "|                                                         melted cheese.                                          |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                   Tower Burger                400       Beef patty topped with                 5%               |" << endl;
		cout << "|                                                         crispy bacon & cheddar                                  |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "|  2- Fries              Cheese                 100          Cheezy fries                        5%               |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                       Barbecue                200           Spicy hot                          10%              |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "|  3- Hot Wings          10 Wings               500         Delicious                            10%              |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                        6 Wings                300         Delicious                            10%              |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "|  4- Nuggets          20 Nugget                400         Crispy Hot                           10%              |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                      10 Nuggets               200         Crispy Hot                           10%              |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "|  5- Chowmenin       1 plate                   1000        Sweet and spicy                      20%              |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "|  6- Soup          Corn Soup                   300        No artificial flavour                 5%               |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|				     Tomato Soup                 400        Delicious soup                        5%               |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "|  7- Pizza            Chicken Fajita           1200      Traditional Italian pizza              30%              |" << endl;
		cout << "|                                                         topped with fresh                                       |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                      Chicken Tikka            1400      Classic pizza topped with              30%              |" << endl;
		cout << "|                                                         pepperoni slices                                        |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "|  8- Cold drink    Cock                        50              -                                 -               |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                   Ddew                        50              -                                 -               |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "|                                                                                                                 |" << endl;
		cout << "+---------------+-----------------------------+---------+-----------------------------+---------------------------+" << endl;
		cout << "Press (1) Burger  (2) Fries  (3) Hot wings  (4) Nuggets  (5) Chowmein  (6) Soup  (7) Pizza  (8) Cold Drink" << endl;
		option_checker(op);


		switch (*op)
		{

		case 1:
			*r = burger(op, b1, b2);
			if (*r)
			{
				b_sum = b_sum + *r;
				array[0] = b_sum;
				cout << "Your burgers order accepted!" << endl;
			}
			cout << endl;
			break;

		case 2:
			*f = fries(op, f1, f2);
			if (*f)
			{
				f_sum = f_sum + *f;
				array[1] = f_sum;
				cout << "Your fries order accepted!" << endl;
			}
			cout << endl;
			break;

		case 3:
			*w = wings(op);
			if (*w)
			{
				w_sum = w_sum + *w;
				array[2] = w_sum;
				cout << "Your Hot wings order accepted!" << endl;
			}
			cout << endl;
			break;

		case 4:
			*n = nuggets(op);
			if (*n)
			{
				n_sum = n_sum + *n;
				array[3] = n_sum;
				cout << "Your order of Nuggets accepted!" << endl;
			}
			cout << endl;
			break;

		case 5:
			*ch = chowmein(op);
			if (*ch)
			{
				c_sum = c_sum + *ch;
				array[4] = c_sum;
				cout << "Your order of Chowmenin accepted!" << endl;
			}
			cout << endl;
			break;

		case 6:
			*s = soup(op, s1, s2);
			if (*s)
			{
				s_sum = s_sum + *s;
				array[5] = s_sum;
				cout << "Your order of Soup accepted!" << endl;
			}
			cout << endl;
			break;

		case 7:
			*p = pizza(op, p1, p2);
			if (*p)
			{
				p_sum = p_sum + *p;
				array[6] = p_sum;
				cout << "Your order of Pizza accepted!" << endl;
			}
			cout << endl;
			break;
		case 8:
			*drink = cold(op, drink1, drink2);
			if (*drink)
			{
				d_sum = d_sum + *drink;
				array[7] = d_sum;
				cout << "Your order for Cold Drink accepted!" << endl;
			}
			cout << endl;
			break;
		default:
			cout << "Invalid option slect from 1 to 8" << endl;
			if (*op != 1 && *op != 2 && *op != 3 && *op != 4 && *op != 5 && *op != 6 && *op != 7 && *op != 8)
			{
				cout << "Please select from 1 to 8" << endl;
				goto label1;
			}
		}

	label:
	again_label:
		cout << "Enter y or Y to select again from the menu " << endl;
		cout << "Enter t or T to see the total cash " << endl;
		cout << "Press e or E to exit" << endl;
		cin >> *o;



		if (*o == 't' || *o == 'T')
		{
			cout << "Ok! Thank you!" << endl;
			*total = *total + b_sum + f_sum + w_sum + n_sum + c_sum + s_sum + p_sum + d_sum;
			cout << "Total is " << *total << endl;

			// storing in file

			fout << "Burger bill " << array[0] << " Rs" << endl;
			fout << "Fries bill " << array[1] << " Rs" << endl;
			fout << "Hot wings bill " << array[2] << " Rs" << endl;
			fout << "Nuggets bill " << array[3] << " Rs" << endl;
			fout << "Chowmein bill " << array[4] << " Rs" << endl;
			fout << "Soup bill " << array[5] << " Rs" << endl;
			fout << "Pizza bill " << array[6] << " Rs" << endl;
			fout << "Cold drink bill " << array[7] << " Rs" << endl;
			fout << "Total is " << *total << " Rs" << endl;
			fout << "----------------------------------" << endl;


			flag = 1;
			goto again_label;
		}
		else if (*o == 'e' || *o == 'E')
		{
			break;                                                                 // e shows termination
		}


		else
		{
			if (*o != 'T' && *o != 't' && *o != 'e' && *o != 'E' && *o != 'Y' && *o != 'y')
			{
				cout << "Select carefully from the menu!" << endl;
				goto label;
			}
		}

	} while (*o == 'y' || *o == 'Y');

	delete op;
	delete b1;
	delete b2;
	delete r;
	delete f;
	delete f1;
	delete f2;
	delete w;
	delete n;
	delete ch;
	delete s;
	delete s1;
	delete s2;
	delete p;
	delete p1;
	delete p2;
	delete drink;
	delete drink1;
	delete drink2;
	delete o
		;
	delete c;
	delete d;
	delete total;

	return 0;

}
int burger(int* op, int* b1, int* b2)
{
	int o, o_1 = ' ', o_2 = ' ', total = 0, total1 = 0;

	if (*op == 1)
	{
	label:
		cout << "Select the following: " << endl;
		cout << "Press (1) Zinger burger  (2) Tower burger  (3) Both '" << endl;
		option_checker(&o);

		if (o != 1 && o != 2 && o != 3)
		{
			cout << "Choose option from 1 to 3" << endl;
			goto label;
		}
		switch (o)
		{

		case 1:
			cout << "How many Zinger burgers :" << endl;
			option_checker(&o_1);
			total = 0.05 * (o_1 * 200);
			return o_1 * 200 - total;
			break;

		case 2:
			cout << "How many Tower burgers :" << endl;
			option_checker(&o_2);

			total = 0.05 * (o_2 * 400);
			return o_2 * 400 - total;
			break;

		case 3:
			cout << "How many Zinger burgers :" << endl;
			option_checker(&o_1);

			cout << "How many Tower burgers :" << endl;
			option_checker(&o_2);

			total = 200 - (0.05 * 200) * o_1;
			total1 = 400 - (0.1 * 400) * o_2;
			return  total + total1;

		}
	}

}
int fries(int* op, int* f1, int* f2)
{
	int o, o_1 = ' ', o_2 = ' ', total = 0, total1 = 0;

	if (*op == 2)
	{
	label:
		cout << "Select the following: " << endl;
		cout << "Press (1) Cheese fries   (2) Barbecue fries  (3) Both Fries" << endl;
		option_checker(&o);

		if (o != 1 && o != 2 && o != 3)
		{
			cout << "Choose option from 1 to 3" << endl;
			goto label;
		}
		switch (o)
		{

		case 1:
			cout << "How many packs of cheese fries :" << endl;
			option_checker(&o_1);

			total = 0.05 * (o_1 * 100);

			return o_1 * 100 - total;
			break;

		case 2:
			cout << "How many packs of Barbecue fries :" << endl;
			option_checker(&o_2);
			total = 0.1 * (o_2 * 200);
			return o_2 * 200 - total;
			break;

		case 3:
			cout << "How many packs of cheese fries :" << endl;
			option_checker(&o_1);
			cout << "How many packs of Barbecue fries :" << endl;
			option_checker(&o_2);
			total = 100 - (0.05 * 100) * o_1;
			total1 = 200 - (0.1 * 200) * o_2;
			return  total + total1;
		}
	}
}

int wings(int* op)
{
	int o;

	if (*op == 3)
	{
	label:
		cout << "Press (1)  10 Hot Wings  (2)  6 Hot Wings " << endl;
		option_checker(&o);
		if (o != 1 && o != 2)
		{
			cout << "Choose option 1 and 2" << endl;
			goto label;
		}

		switch (o)
		{
		case 1:

			return 500 - (0.1 * 500);
			break;

		case 2:
			return 300 - (0.1 * 500);
			break;
		}
	}

}


int nuggets(int* op)
{
	int o;

	if (*op == 4)
	{
	label:
		cout << "Press (1)  20 Nuggets  (2)  10 Nuggets " << endl;
		option_checker(&o);

		if (o != 1 && o != 2)
		{
			cout << "Choose option 1 and 2" << endl;
			goto label;
		}

		switch (o)
		{
		case 1:

			return 400 - (0.1 * 400);
			break;

		case 2:
			return 200 - (0.1 * 200);
			break;
		}
	}

}

int chowmein(int* op)
{
	int t = 0;
	if (*op == 5)
	{
		t = 1000 - (0.2 * 1000);
		return t;
	}

}

int soup(int* op, int* s1, int* s2)
{
	int o, o_1 = ' ', o_2 = ' ', total = 0, total1 = 0;

	if (*op == 6)
	{
	label:
		cout << "Select the following: " << endl;
		cout << "Press (1) Corn soup  (2) Tomato Soup  (3) Both Corn and Tomato Soup '" << endl;
		option_checker(&o);

		if (o != 1 && o != 2 && o != 3)
		{
			cout << "Choose option from 1 to 3" << endl;
			goto label;
		}
		switch (o)
		{

		case 1:
			cout << "How many servings of Corn Soup you want :" << endl;
			option_checker(&o_1);
			total = 0.05 * (o_1 * 300);
			return o_1 * 300 - total;
			break;

		case 2:
			cout << "How many servings of Tomato Soup you want:" << endl;
			option_checker(&o_2);
			total = 0.05 * (o_2 * 400);
			return o_2 * 400 - total;
			break;

		case 3:
			cout << "How many servings of Corn Soup you want :" << endl;
			option_checker(&o_1);
			cout << "How many servings of Tomato Soup you want:" << endl;
			option_checker(&o_2);
			total = 300 - (0.05 * 300) * o_1;
			total1 = 400 - (0.1 * 400) * o_2;
			return  total + total1;

		}
	}
}

int pizza(int* op, int* p1, int* p2)
{
	int o, o_1 = ' ', o_2 = ' ', total = 0, total1 = 0;
	if (*op == 7)
	{
	label:
		cout << "Select the following: " << endl;
		cout << "Press (1) Chiken fajita  (2) Chiken tikka  (3) Both Fajita and tikka '" << endl;
		option_checker(&o);

		if (o != 1 && o != 2 && o != 3)
		{
			cout << "Choose option from 1 to 3" << endl;
			goto label;
		}
		switch (o)
		{

		case 1:
			cout << "How many Chiken Fajita pizza you  want :" << endl;
			option_checker(&o_1);
			total = 0.3 * (o_1 * 1200);
			return o_1 * 1200 - total;
			break;

		case 2:
			cout << "How many Chiken Tikka you want:" << endl;
			option_checker(&o_2);
			total = 0.3 * (o_2 * 1400);
			return o_2 * 1400 - total;
			break;

		case 3:
			cout << "How many Chiken Fajita pizza you  want :" << endl;
			option_checker(&o_1);
			cout << "How many Chiken Tikka you want:" << endl;
			option_checker(&o_2);
			total = 1200 - (0.3 * 1200) * o_1;
			total1 = 1400 - (0.3 * 1400) * o_2;
			return  total + total1;

		}
	}
}
int cold(int* op, int* drink1, int* drink2)
{
	int o, o_1 = ' ', o_2 = ' ', total = 0, total1 = 0;

	if (*op == 8)
	{
	label:
		cout << "Select the following: " << endl;
		cout << "Press (1) Cock  (2) Dew  (3) Both Cock and dew" << endl;
		option_checker(&o);

		if (o != 1 && o != 2 && o != 3)
		{
			cout << "Choose option from 1 to 3" << endl;
			goto label;
		}

		switch (o)
		{
		case 1:
			cout << "How many Cock do you want: ";
			option_checker(&o_1);
			total = o_1 * 50;
			break;

		case 2:
			cout << "How many Dew do you want: ";
			option_checker(&o_2);
			total = o_2 * 50;
			break;

		case 3:
			cout << "How many Cock do you want: ";
			option_checker(&o_1);
			cout << "How many Dew do you want: ";
			option_checker(&o_2);
			total = o_1 * 50 + o_2 * 50;
			break;
		}
	}

	return total;
}

void option_checker(int* op)
{
	while (!(cin >> *op))
	{
		cin.clear();
		cin.ignore(100, '\n');
	}
}