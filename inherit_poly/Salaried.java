import java.util.*;

public class Salaried extends Employee{

	private double salary;
	private char give_bonus;
	private final double bonus=0.1;

	//constructor
	public Salaried(){
		super.setEtype("salaried");
		this.salary=0.0;
		this.give_bonus='n';
	}

	//constructor to use if no bonus is awarded
	public Salaried(String empName, double empSalary){
		super.setName(empName);
		super.setEtype("salaried");
		this.salary=empSalary;
		this.give_bonus='n';
	}

	//constructor to use if a bonus is awarded
	public Salaried(String empName, double empSalary, char empBonus){
		super.setName(empName);
		super.setEtype("salaried");
		this.salary=empSalary;
		this.give_bonus=empBonus;
	}

	public void setSalary(double setSalary){
		this.salary=setSalary;
	}

	public void setGiveBonus(char setGiveBonus){
		this.give_bonus=setGiveBonus;
	}

	public char getGiveBonus(){
		return give_bonus;
	}

	public double getBonus(){
		return bonus;
	}

	@Override //overrides Employee abstract getPay() method
	public double getPay(){
		//add in a bonus if one was given
		if(give_bonus=='y'){
			return salary*(1+bonus);
		}
		else{
			return salary;
		}
	}

	@Override //overrides Employee abstract printPay() method
	public void printPay(){
		if(give_bonus=='n')
			System.out.printf(super.getName() + "\t" + super.getEtype() + "\t\t\t\t\t" +
			"$" + "%.2f" + "\n", getPay());
		else{
			System.out.printf(super.getName() + "\t" + super.getEtype() + "\t\t\t\t\t" + "$" +
			"%.2f" + "*" + "\n", getPay());
		}
	}

}