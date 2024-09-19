//Banking Record System.
//File handling has been effectively used for each feature of this project
//Operations  
//Add Record:  
//Show/List Data: 
//Search Record:  
//Edit Record: 
//Delete Record:
	
	
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Bank
{
	public:
	    string name;
	    int accountNumber;
	    double balance;
	
	    void addRecord()
		 {
	        ofstream file("records.txt",ios::app);
	        cout<<"Enter Name: ";
	        cin>>name;
	        cout<<"Enter Account Number: ";
	        cin>>accountNumber;
	        cout<<"Enter Balance: ";
	        cin>>balance;
	        file<<name<<" "<<accountNumber<<" "<<balance<<"\n";
	        file.close();
	    }
	
	    void showRecords() 
		{
	        ifstream file("records.txt");
	        string line;
	        while (getline(file, line)) 
			{
	            cout<<line<<"\n";
	        }
	        file.close();
	    }
	
	    void searchRecord() 
		{
	        ifstream file("records.txt");
	        string line;
	        int accNum;
	        cout << "Enter Account Number to search: ";
	        cin >> accNum;
	        while (getline(file, line)) {
	            if (line.find(to_string(accNum))!='\0') {
	                cout << line << "\n";
	                break;
	            }
	        }
	        file.close();
	    }
	
	    void editRecord() 
		{
		    ifstream file("records.txt");
		    ofstream temp("temp.txt");
		    int accNum, newAccNum;
		    cout<<"Enter Account Number to edit: ";
		    cin>>accNum;
		
		    bool flag=false;
		    string line;
		    while (getline(file, line)) 
			{
		        if (line.find(to_string(accNum))!='\0') 
				{
		            cout<<"Enter New Name, Account Number, and Balance: ";
		            cin>>name>>newAccNum>>balance;
		            temp<<name<<" "<<newAccNum<<" "<<balance<< "\n";
		            flag=true;
		        } 
				else 
				{
		            temp<<line<<"\n";
		        }
		    }
		    file.close(); 
			temp.close();
		    if (flag) 
			{
		        remove("records.txt");
		        rename("temp.txt", "records.txt");
		    } 
			else 
			{
		        cout<<"Record not found!\n";
		        remove("temp.txt");
		    }
		}

	    void deleteRecord() 
		{
	        ifstream file("records.txt");
	        ofstream temp("temp.txt");
	        string line;
	        int accNum;
	        cout<<"Enter Account Number to delete: ";
	        cin>>accNum;
	
	        while(getline(file, line)) 
			{
	            if (line.find(to_string(accNum))=='\0') {
	                temp<<line<< "\n";
	            }
	        }
	        file.close();
	        temp.close();
	        remove("records.txt");
	        rename("temp.txt", "records.txt");
	    }
	};

int main() 
{
    Bank record;
    int choice;
    
     do{
     	cout<<"\n#Banking Record System#\n";
     	cout<<"\n1. Add Record";
		cout<<"\n2. Show Records";
		cout<<"\n3. Search Record";
		cout<<"\n4. Edit Record";
		cout<<"\n5. Delete Record";
		cout<<"\n0. Exit\n";
        cin >> choice;
        switch (choice) 
		{
            case 1: 
				record.addRecord(); 
				break;
            case 2: 
				record.showRecords(); 
				break;
            case 3: 
				record.searchRecord(); 
				break;
            case 4: 
				record.editRecord(); 
				break;
            case 5: 
				record.deleteRecord(); 
				break;
			case 0:
				break;
            default: 
				cout << "\nInvalid choice. Please enter 1,2,3,4,5,0 ";
        }
    }while(choice!=0);
    
	
}
