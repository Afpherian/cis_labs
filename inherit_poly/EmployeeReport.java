import java.util.*;

public class EmployeeReport{

  public static void main(String[] args){
	  String employeeType;
	  String employeeName;
	  double employeeSalary;
	  char giveBonus;
	  double hoursRate;
	  double hoursWorked;
	  double weekSales;
	  int addAnotherEmployee;


  	//create a new array list to store Employee objects
  	ArrayList<Employee> employeeList= new ArrayList();

  	Scanner input = new Scanner(System.in);

	//adds new Employee objects to array list based on employee type
	do{
  		System.out.println("What type of employee would you like to add?\nOptions include: salaried, hourly or commission");
  		employeeType = input.nextLine();

		//employee type validation loop
  		while(!employeeType.equalsIgnoreCase("salaried") && !employeeType.equalsIgnoreCase("hourly") &&
  			!employeeType.equalsIgnoreCase("commission")){
			System.out.println("Invalid employee type entered. Options include salaried, hourly or commission");
			employeeType = input.nextLine();
			}

		//adds a salaried employee object to array list
		if(employeeType.equalsIgnoreCase("salaried")){
			System.out.print("Employee Name: ");
			employeeName = input.nextLine();
			System.out.print("Employee Salary: $");
			employeeSalary = input.nextDouble();
			System.out.print("Did this employee earn a bonus? y/n: ");
			giveBonus = input.next().charAt(0);
				//if a bonus is awarded, call constructor with bonus parameter and adds it to array list
				if(giveBonus=='y'){
					employeeList.add(new Salaried(employeeName, employeeSalary, giveBonus));
				}
				else{
					employeeList.add(new Salaried(employeeName, employeeSalary));
				}
		}
		//adds an hourly employee object to array list
		else if(employeeType.equalsIgnoreCase("hourly")){
			System.out.print("Employee Name: ");
			employeeName = input.nextLine();
			System.out.print("Employee Pay Per Hour: $");
			hoursRate = input.nextDouble();
			System.out.print("Number of hours worked by Employee: ");
			hoursWorked = input.nextDouble();
			//call hourly constructor and add object to array list
			employeeList.add(new Hourly(employeeName, hoursRate, hoursWorked));
		}
		//adds a commission employee object to array list
		else if(employeeType.equalsIgnoreCase("commission")){
			System.out.print("Employee Name: ");
			employeeName = input.nextLine();
			System.out.print("This Week's Sales for This Employee: $");
			weekSales = input.nextDouble();
			//call commission constructor and add object to array list
			employeeList.add(new Commission(employeeName, weekSales));
		}

		//prompt and check for do-while loop to continue
		System.out.print("Do you need to enter another employee? Enter 1 for Yes and 2 for No:");
		addAnotherEmployee = input.nextInt();
		String junk = input.nextLine(); //to catch the extra garbage from previous nextInt
 	} while (addAnotherEmployee==1);

	//print the required table to display a summary of each object
	System.out.println("\nName\t\tClass\t\tHours\tSales\t\tRate\tWeekly Pay Amount");
	System.out.println("=========================================================================");
	for (int i = 0; i < employeeList.size(); i++){
		employeeList.get(i).printPay();
	}
	System.out.println("=========================================================================");

	//get total pay for all employees in the array list
	double total = 0;
	for (int i = 0; i < employeeList.size(); i++){
		total += employeeList.get(i).getPay();
	}
	System.out.printf("\t\t\t\t\t\t\tTotal\t$" + "%.2f\n", total);

	System.out.println("*A 10% bonus is awarded");

	}
}