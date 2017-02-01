import java.util.*;

public class Hourly extends Employee{

	private double hours_rate;
	private double hours;
	private double payamount;

	//Constructor
	public Hourly(){
		super.setEtype("hourly");
		this.hours_rate=0.0;
		this.hours=0.0;
	}

	//Constructor
	public Hourly(String empName, double hoursRate, double hoursWorked){
		super.setName(empName);
		super.setEtype("hourly");
		this.hours_rate=hoursRate;
		this.hours=hoursWorked;
	}

	public void setHours(double hoursWorked){
		this.hours=hoursWorked;
	}

	public double getHours(){
		return hours;
	}

	public void setHoursRate(double hoursRate){
		this.hours_rate=hoursRate;
	}

	public double getHoursRate(){
		return hours_rate;
	}

	@Override //overrides Employee abstract getPay() method
	public double getPay(){
		double overtime;
		double overtimePay;
		double totalPay;

		//check if employee has earned overtime pay
		if(hours > 40){
			overtime=hours-40;
			overtimePay=overtime*(2*hours_rate);
			totalPay=(40*hours_rate)+overtimePay;
		}
		else{
			totalPay=hours_rate*hours;
		}
		return totalPay;
	}

	@Override //overrides Employee abstract printPay() method
	public void printPay(){
		System.out.printf(super.getName() + "\t" + super.getEtype() + "\t\t" + hours +
		"\t\t\t$" + "%.2f" + "\t$" + "%.2f" + "\n", hours_rate, getPay());
	}

}