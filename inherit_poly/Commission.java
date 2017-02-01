import java.util.*;

public class Commission extends Employee{

	private double week_sales;
	private final double commission_rate = 0.2;


	//constructor
	public Commission(){
		super.setEtype("commission");
		this.week_sales=0.0;
	}

	//constructor
	public Commission(String empName, double weekSales){
		super.setName(empName);
		super.setEtype("commission");
		this.week_sales=weekSales;
	}

	public void setSales(double sales){
		this.week_sales=sales;
	}

	public double getSales(){
		return week_sales;
	}

	@Override //overrides Employee abstract getPay() method
	public double getPay(){
		return week_sales*commission_rate;
	}

	@Override //overrides Employee abstract printPay() method
	public void printPay(){
		System.out.printf(super.getName() + "\t" + super.getEtype() + "\t\t" + "$" +
		"%.2f" + "\t\t" + "$" + "%.2f" + "\n", this.week_sales, getPay());
	}

}