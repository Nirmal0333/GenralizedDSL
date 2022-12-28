import java.lang.*;
import java.util.*;

//create table student(RID int,Name varchar(255),Salary int);
//Database table/schema
class Student
{
	public int RID;
	public String Name;
	public int Salary;
	
	private static int Generator = 0;
	
	static			//static block
	{
		Generator = 0;
	}
	
	public Student(String str, int value)
	{
		this.RID = ++Generator;
		this.Name = str;
		this.Salary = value;
	}
	
	public void DisplayData()
	{
		System.out.println(this.RID + "\t" + this.Name + "\t" + this.Salary);
	}
}

class DBMS
{
	public LinkedList <Student> lobj;
	
	public DBMS()		//constructor
	{
		lobj = new LinkedList<>();
	}
	
	//Insert into student Piyush 1000;
	//Select * from student
	public void StartDBMS()
	{
		Scanner scanobj = new Scanner(System.in);
		
		System.out.println("Marvellous customised DBMS started successfully....");
		String Query = "";
		
		while(true)		//ek loop jo infinitely firel
		{
			System.out.print("Marvellous DBMS console >");
			Query =  scanobj.nextLine();
			
			String tokens[] = Query.split(" ");
			int QuerySize = tokens.length;
			
			if(QuerySize == 1)
			{
				if("Help".equals(tokens[0]))
				{
					System.out.println("This application is used to demonstrates the customised DBMS");
					System.out.println("Exit : Terminate DBMS");
					System.out.println("Display all data : select * from student");
					System.out.println("Insert data : Insert into student Name Salary");
				}
				else if("Exit".equals(tokens[0]))
				{
					System.out.println("Thank you for using Marvellous DBMS");
					break;
				}
			}
			else if(QuerySize == 2)
			{
				
			}
			else if(QuerySize == 4)
			{
				if("select".equals(tokens[0]))
				{
					if("*".equals(tokens[0]))
					{
						DisplayAll();
					}
				}
			}
			else if(QuerySize == 5)
			{
				//Insert into student Piyush 1000;
				if("Insert".equals(tokens[0]))
				{
					InsertData(tokens[3],Integer.parseInt(tokens[4]));
				}
			}
			
		}
	}
	
	// Insert into qeury
	public void InsertData(String str, int value)
	{
		Student sobj  = new Student(str,value);
		lobj.add(sobj);
	}
	
	//Display without condition
	public void DisplayAll()
	{
		for(Student sref : lobj)
		{
			sref.DisplayData();
		}
	}
	
	//Display by RID
	public void DisplaySpecific(int rid)
	{
		for(Student sref : lobj)
		{
			if(sref.RID == rid)
			{
				sref.DisplayData();
				break;
			}
		}
	}
	
	//Display by Name
	public void DisplaySpecific(String str)
	{
		for(Student sref : lobj)
		{
			if(str.equals(sref.Name))
			{
				sref.DisplayData();
			}
		}
	}
	
	//Delete by RID
	public void DeleteSpecific(int rid)
	{
		int index = 0;
		for(Student sref : lobj)
		{
			if(sref.RID == rid)
			{
				lobj.remove(index);
				break;
			}
			index++;
		}
	}
	
	//Delete by Name
	public void DeleteSpecific(String str)
	{
		int index = 0;
		for(Student sref : lobj)
		{
			if(str.equals(sref.Name))
			{
				lobj.remove(index);
			}
			index++;
		}
	}
	
	public void AggregateMax()
	{
		int iMax = 0;
		Student temp = null;
		
		for(Student sref : lobj)
		{
			if(sref.Salary > iMax)
			{
				iMax = sref.Salary;
				temp = sref;
			}
		}
		
		System.out.println("Information of student having maximum salary :");
		temp.DisplayData();
	}
	
	public void AggregateMin()
	{
		int iMin = (lobj.getFirst()).Salary;
		Student temp = lobj.getFirst();
		
		for(Student sref : lobj)
		{
			if(sref.Salary < iMin)
			{
				iMin = sref.Salary;
				temp = sref;
			}
		}
		
		System.out.println("Information of student having minimum salary :");
		temp.DisplayData();
	}
	
	public void AggregateSum()
	{
		int iSum = 0;
		
		for(Student sref : lobj)
		{
			iSum = iSum + sref.Salary;
		}
		
		System.out.println("Summation of salary is :" +iSum);
	}
	
	public void AggregateAverage()
	{
		int iSum = 0;
		
		for(Student sref : lobj)
		{
			iSum = iSum + sref.Salary;
		}
		
		System.out.println("Average salary is :" +iSum/lobj.size());
	}
	
	public void AggregateCount()
	{
		System.out.println("Count is :" +lobj.size());
	}
	
}

class Program304
{
	public static void main(String arg[])
	{
		DBMS dobj = new DBMS();
		
		dobj.StartDBMS();
		
		/*dobj.InsertData("Piyush", 1000);
		dobj.InsertData("Sakshi", 3000);
		dobj.InsertData("Sachin", 2000);
		dobj.InsertData("Neha", 10000);
		dobj.InsertData("Atharva", 8000);
		dobj.InsertData("Radhika", 9000);
		
		//dobj.DisplaySpecific(2);
		//dobj.DisplaySpecific("Sachin");
		
		//dobj.DeleteSpecific(1);
		
		//dobj.DeleteSpecific("Sakshi");
		dobj.DisplayAll();
		
		dobj.AggregateMax();
		dobj.AggregateMin();
		
		dobj.AggregateSum();
		dobj.AggregateAverage();
		dobj.AggregateCount();   */
	}
}


/*
Aggregate Functions below
1. Min 
2. Max 
3. Sum 
4. Average
*/