import java.util.*;

public abstract class Employee{

	private String name;
	private String etype;

	//constructor
	public Employee(){
	  name="";
	  etype="";
	}

	//constructor
	public Employee(String empName, String empType){
	  name=empName;
	  etype=empType;
	}

	public void setName(String newName){
	  name = newName;
	}

	public String getName(){
	  return name;
	}

	public void setEtype(String newEtype){
	  etype = newEtype;
	}

	public String getEtype(){
		return etype;
	}

	//to get total weekly pay for each employee
	//will be overridden in subclasses
	public abstract double getPay();

	//to print a summary of weekly pay information for each employee
	//will be overridden in subclasses
	public abstract void printPay();

}