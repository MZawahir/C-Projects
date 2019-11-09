// ConsoleApplication61.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <string.h>  //string operations
/** Main function started */
int main()
{
	
	float basic, da, hra, ta, others;
	float pf, it;
	float net_salary;

	FILE *fp, *ft; // file pointers
	char choice,another;
	/** structure that represent a employee */

	struct emp
	{
		char name[40]; //name of employee
		float age; //age of employee
		float bs; // basic salary of employee
	};
	struct emp e; // structure variable creation
	char empname[40]; // string to store name of the employee
	long int recsize; // size of each record of employee
	/** open the file in binary read and write mode
	* if the file EMP.DAT already exists then it open that file in read write mode
	* if the file doesn't exit it simply create a new copy
	*/
	fp = fopen("DATA.DAT", "rb+");
	if (fp == NULL)
	{
		fp = fopen("DATA.DAT", "wb+");
		if (fp == NULL)
		{
			printf("Connot open file");
			exit(1);
		}
	}
	// sizeo of each record i.e. size of structure variable e
	recsize = sizeof(e);
	// infinite loop continues untile the break statement encounter

	
	while (1)
	{
	
		system("cls");
		
		printf("\n\n\t\t\t\t*******************************************************");
		printf("\n\n\t\t\t\t\t\tEmployee Record System");
		printf("\n\n\t\t\t\t*******************************************************");
		printf("\n\n\t\t1. Add Record"); 
		printf("\n\n\t\t2. Modify Records");
		printf("\n\n\t\t3. Delete Records");//option for add record
		printf("\n\n\t\t4. Salary Calculation"); // option for showing existing record
		printf("\n\n\t\t5. List Record");//option for calculating salary
		printf("\n\n\t\t6. Exit");// exit from the program
		
			printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\tBy : Muhammad Zawahir & Abeerah Shamshad");
		
		
		 // enter the choice 1, 2, 3, 4, 5
		fflush(stdin); // flush the input buffer
		printf("\n\n\t\t\t\t\t Your Choice: ");
		choice = _getch(); // get the input from keyboard
		switch (choice)
		{
		case '1':  // if user press 1
		{
		system("cls");
		fseek(fp, 0, SEEK_END); /// search the file and move cursor to end of the file
		/// here 0 indicates moving 0 distance from the end of the file
	
		printf("\n\n\t\t\t\t*******************************************************");
		printf("\n\n\t\t\t\t\t\tInsert Employee Record System");
		printf("\n\n\t\t\t\t*******************************************************");
		 /// if user want to add another record
	another = 'y';
            while(another == 'y')  /// if user want to add another record
            {	
			printf("\n\nEnter name: ");
			scanf("%s", &e.name);
			printf("\nEnter age: ");
			scanf("%f", &e.age);
			printf("\nEnter basic salary: ");
			scanf("%f", &e.bs);
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t\tYour Record is sucessfully inserted ");

			
			fwrite(&e, recsize, 1, fp); /// write the record in the file
			
			
			printf("\n\n\n\n\n\t\t\tAdd another record(y/n) ");
		
                fflush(stdin);
                another = _getch();
	}
		break;	
		}
		case '2':
		{
			system("cls");
		
			printf("\n\n\t\t\t\t*******************************************************");
			printf("\n\n\t\t\t\t\t\tModify Employee Details");
			printf("\n\n\t\t\t\t*******************************************************");
			another = 'y';
            while(another == 'y')
            {
			
				printf("\n\nEnter the employee name to modify: ");
				scanf("%s", &empname);
				rewind(fp);
				while (fread(&e, recsize, 1, fp) == 1)  /// fetch all record from file
				{
					if (strcmp(e.name, empname) == 0)  ///if entered name matches with that in file
					{
						printf("\nUpdate Information ");
						printf("\n\nEnter Name : ");
						scanf("%s", e.name);
						printf("\n\nEnter Updated Age : ");
						scanf("%f",&e.age);
						printf("\n\nEnter Updated Salary : ");
						scanf("%f",&e.bs);

						fseek(fp, -recsize, SEEK_CUR); /// move the cursor 1 step back from current position
						fwrite(&e, recsize, 1, fp); /// overwritee the record
						break;
					}
					
				}
				system("cls");

				printf("\n\n\n\n\n\t\t\t\t\tData Has Been Updated Thank You!!");
				
				printf("\n\n\n\n\n\t\t\tModify another record(y/n)");
				fflush(stdin);
				 another = _getch();
		}
			break;
		}
		case '3':
		{
			
			system("cls");
			
			printf("\n\n\t\t\t\t*******************************************************");
			printf("\n\n\t\t\t\t\t\tDelete Employee Details");
			printf("\n\n\t\t\t\t*******************************************************");
			 another = 'y';
            while(another == 'y')
            {
				printf("\n\nEnter name of employee to delete: ");
				scanf("%s", empname);
				ft = fopen("Temp.dat", "wb");  /// create a intermediate file for temporary storage
				rewind(fp); /// move record to starting of file
				while (fread(&e, recsize, 1, fp) == 1)  /// read all records from file
				{
					if (strcmp(e.name, empname) != 0)  /// if the entered record match
					{
						fwrite(&e, recsize, 1, ft); /// move all records except the one that is to be deleted to temp file
					}
				}
				
				system("cls");
				printf("\n\n\n\n\n\t\t\t\t\tData has been deleted!!");
				fclose(fp);
				fclose(ft);
				remove("EMP.DAT"); /// remove the orginal file
				rename("Temp.dat", "EMP.DAT"); /// rename the temp file to original file name
				fp = fopen("EMP.DAT", "rb+");
				 printf("\n\n\n\n\n\t\t\tDelete another record(y/n)");
                fflush(stdin);
                another = _getch();
            }
            break;
	}
		

		case '4':
		{
			
				//variable to store values
			system("cls");
				//input required fields
			printf("\n\n\t\t\t\t*******************************************************");
			printf("\n\n\t\t\t\t\t\tEmployee Salary Calculator");
			printf("\n\n\t\t\t\t*******************************************************");
				printf("\n\nEnter Basic Salary (Rs.): ");
				scanf("%f", &basic);
				printf("Enter HRA (Rs.): ");
				scanf("%f", &hra);
				printf("Enter TA (Rs.): ");
				scanf("%f", &ta);
				printf("Enter others (Rs.): ");
				scanf("%f", &others);

				//calculate DA 12% of Basic Salary
				da = (basic * 12) / 100;
				//calculate PF 14% of Basic salary
				pf = (basic * 14) / 100;
				//calculate IT, 15% of Basic salary
				it = (basic * 15) / 100;

				//calculate net salary
				net_salary = basic + da + hra + ta + others - (pf + it);

				//printing Net salary
				printf("\n\n\n\n\n\t\t\tNet Salary is: Rs. %f\n", net_salary);
				
				fflush(stdin);
				printf("\n\n\n\n\n\t\t\t\t\tpress any key to continue !!");
				_getch();
				

				break;
		}
		
		
		case '5':
		{

			system("cls");
			rewind(fp); //this moves file cursor to start of the file
			printf("\n\n\t\t\t\t*******************************************************");
			printf("\n\n\t\t\t\t\t\t  Employee Details");
			printf("\n\n\t\t\t\t*******************************************************");
				printf("\n\n\n\n\t\tName\t\t\t\tAge\t\t\t\tSalary\t\n\n");
				printf("\t===========================================================================================");
			while (fread(&e, recsize, 1, fp) == 1)  // read the file and fetch the record one record per fetch
			{
				printf("\n\n\t       %s\t\t\t      %f \t\t\t%.2f", e.name, e.age, e.bs);// print the name, age and basic salary

			}

			
			fflush(stdin);
			printf("\n\n\n\n\n\t\t\t\t\tpress any key to continue !!");
			_getch();

			break;
			
			
		}
		
		case '6':
		{
			//print closing messege
			printf("\n\n\n\n\n\t\t\t\t\tPress ant key to Continue action....\n\n\n");
			fclose(fp);  // close the file
			exit(0); // exit from the program
			break;
		}
		default:
		{
			//repeate the loop 
			break;
			
		}
		}
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
