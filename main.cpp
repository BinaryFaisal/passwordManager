#include<bits/stdc++.h>
using namespace std;

//class
class root
{
private:
    string domain;
    string id;
    string pass;

public:
    void add();
    void display();
    void displayAll();
    void edit();
    void deleteFile();
    void self_exit();
    string encrypt(string pass);
    string decrypt(string pass);
    void change_pass();
};

// Functions
void root::change_pass()
{
    system("cls");
    bool found = false;
    string key1, key2,username,pass;
    cout << "\n\n\n\t\tEdit Record";
    cout << "\n\n\tEnter Username : ";
    cin >> key1;
    cout << "\n\tEnter Password : ";
    cin >> key2;

    ifstream inputFile("Admin.txt");
    ofstream outputFile("temp.txt", ios::app);
    while (inputFile >> username >> pass)
    {
        if (key1 == username && key2 == pass)
        {
            system("cls");
            cout << "\n\n\n\t\tEdit Record";
            cout << "\n\n\tCurrent Username : " << username;
            cout << "\n\tCurrent Password : " << pass;
            cout<<"\n\n\tEnter New Usernaeme: ";
            cin>>username;
            cout << "\n\tEnter New Password : ";
            cin >> pass;

            outputFile << username << "\n" << pass << endl;
            cout << "\n\tPassword Updated Successfully !";
            found = true;
        }
        else
        {
            outputFile << username << "\n" << pass << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("Admin.txt");
    rename("temp.txt", "Admin.txt");

    if (found == false)
        cout<<"\n\n\t\tInvalid Username and Password!";
    cout << "\n\n\tPress Any Key To Continue..";
    cin.ignore();
    cin.get();
}

void root::add()
{
    ofstream myFile("data.txt", ios::app);
    system("cls");
    cout << "\n\n\n\t\tNew Record";
    cout << "\n\n\tEnter Domain : ";
    cin >> domain;
    cout << "\n\tEnter User Name : ";
    cin >> id;
    cout << "\n\tEnter Password : ";
    cin >> pass;
    pass = encrypt(pass);
    if (myFile.is_open())
    {
        myFile << domain << " " << id << " " << pass << endl;
        cout << "\n\tContact Saved Successfully !";
    }
    else
    {
        cout << "\n\tError Opening File !";
    }
    myFile.close();
    cout << "\n\tPress Any Key To Continue..";
    cin.ignore();
    cin.get();
}

void root::display()
{
    system("cls");
    bool found = false;
    ifstream myfile("data.txt");
    cout << "\n\n\n\t\tSearch Record";
    string key1, key2;
    cout << "\n\tEnter Domain Name : ";
    cin >> key1;
    cout << "\n\tEnter User Name : ";
    cin >> key2;
    while (myfile >> domain >> id >> pass)
    {
        if (key1 == domain && key2 == id)
        {
            system("cls");
            cout << "\n\n\n\t\tInformation..";
            cout << "\n\n\tDomain Name : " << domain;
            cout << "\n\n\tUser Name : " << id;
            pass = decrypt(pass);
            cout << "\n\n\tPassword : " << pass;
            found = true;
            break;
        }
    }
    if (found == false)
        cout << "\n\tNo Such Information Found";
    cout << "\n\n\tPress Any Key To Continue..";
    cin.ignore();
    cin.get();
}

void root::displayAll()
{
    bool found = false;
    system("cls");
    ifstream myfile("data.txt");
    cout << "\n\n\n\t\tSearch Record";
    string key1;
    cout << "\n\tEnter Domain Name : ";
    cin >> key1;
    system("cls");
    cout << "\n\n\n\t\tShowing Information of Domain " << key1;
    while (myfile >> domain >> id >> pass)
    {
        if (key1 == domain)
        {
            cout << "\n\n\tDomain Name : " << domain;
            cout << "\n\tUser Name : " << id;
            pass = decrypt(pass);
            cout << "\n\tPassword : " << pass;
            found = true;
        }
    }
    if (found == false)
        cout << "\n\tNo Such Information Found";
    cout << "\n\n\tPress Any Key To Continue..";
    cin.ignore();
    cin.get();
}

void root::edit()
{
    system("cls");
    bool found = false;
    string key1, key2;
    cout << "\n\n\n\t\tEdit Record";
    cout << "\n\n\tEnter Domain Name : ";
    cin >> key1;
    cout << "\n\tEnter User Name : ";
    cin >> key2;

    ifstream inputFile("data.txt");
    ofstream outputFile("temp.txt", ios::app);
    while (inputFile >> domain >> id >> pass)
    {
        if (key1 == domain && key2 == id)
        {
            cout << "\n\n\tDomain Name : " << domain;
            cout << "\n\tUser Name : " << id;
            pass = decrypt(pass);
            cout << "\n\tCurrent Password : " << pass;

            cout << "\n\n\tEnter New Password : ";
            cin >> pass;
            pass = encrypt(pass);

            outputFile << domain << " " << id << " " << pass << endl;
            cout << "\n\tInformation Updated Successfully !";
            found = true;
        }
        else
        {
            outputFile << domain << " " << id << " " << pass << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found == false)
        cout << "\n\tNo Such Information Found";
    cout << "\n\n\tPress Any Key To Continue..";
    cin.ignore();
    cin.get();
}


void root::deleteFile()
{
    system("cls");
    bool found = false;
    string key1, key2;
    cout << "\n\n\n\t\tDelete Record";
    cout << "\n\n\tEnter Domain Name : ";
    cin >> key1;
    cout << "\n\tEnter User Name : ";
    cin >> key2;

    ifstream inputFile("data.txt");
    ofstream outputFile("temp.txt", ios::app);
    while (inputFile >> domain >> id >> pass)
    {
        if (key1 == domain && key2 == id)
        {
            cout << "\n\n\tDomain Name : " << domain;
            cout << "\n\tUser Name : " << id;
            pass = decrypt(pass);
            cout << "\n\tPassword : " << pass;

            cout << "\n\n\tAre you sure you want to delete this record? (Y/N): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y')
            {
                cout << "\n\tInformation Deleted Successfully !";
                found = true;
            }
            else
            {
                found = true;
                pass=encrypt(pass);
                outputFile << domain << " " << id << " " << pass << endl;
            }
        }
        else
        {
            outputFile << domain << " " << id << " " << pass << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found == false)
        cout << "\n\tNo Such Information Found";
    cout << "\n\n\tPress Any Key To Continue..";
    cin.ignore();
    cin.get();
}

void root::self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank You For Using !";
    exit(1);
}

string root::encrypt(string pass)
{
    int i, key = 15;
    for (i = 0; i < pass.size(); i++)
        pass[i] = pass[i] - key;
    return pass;
}

string root::decrypt(string pass)
{
    int i, key = 15;
    for (i = 0; i < pass.size(); i++)
        pass[i] = pass[i] + key;
    return pass;
}

int menu()
{
    root obj;
    short int choice;
    do
    {
        system("cls");
        system("color 1F");
        cout << "\n\n\n\t\tPassword Manager";
        cout << "\n\n\t1. Add New Username and Password\n\t2. Search Username and Password\n\t3. Show List of Username and Password\n\t4. Edit Username and Password\n\t5. Delete Username and Password\n\t6. Change Log in Username and password\n\t7. Exit\n\tEnter Your Choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character from the previous input

        switch (choice)
        {
        case 1:
            obj.add();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.displayAll();
            break;
        case 4:
            obj.edit();
            break;
        case 5:
            obj.deleteFile();
            break;
        case 6:
            obj.change_pass();
            break;
        case 7:
            obj.self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            cin.ignore();
        }
    }
    while (choice != 0);
    return 0;
}

class adminClass {
private:
    string username;
    string password;

public:
    adminClass() {}

    bool adminLogin() {
        int i = 0;
        string k1, k2;

        do {
            system("cls");
            cout << "\n\n\n\t\t\tPassword Manager";
            cout << "\n\n\n\t\tENTER USERNAME: ";
            cin >> username;
            cout << "\n\t\tENTER PASSWORD: ";
            cin >> password;

            ifstream inputFile("Admin.txt");
            inputFile >> k1 >> k2;
            inputFile.close();

            if (username == k1 && password == k2) {
                return true;
            } else {
                int choice;
                cout << "\n\t\tInvalid Log in Information!";
                cout << "\n\t\t1. Retry\n\t\t2. Exit";
                cout << "\n\t\tEnter your choice: ";
                cin >> choice;
                if (choice == 1) {
                    i++;
                } else {
                    exit(1);
                }
            }
        } while (i < 3);

        return false;
    }
};

int main() {
    adminClass objLog;
    system("color 1F");
    if (objLog.adminLogin()) {
        menu();
    }
    else {
        cout << "\n\n\t\tToo Many Attempts, Try again later.\n\n";
    }
    return 0;
}
