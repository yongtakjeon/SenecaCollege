// Name: Yongtak Jun
// Date: July/05/2021

import java.util.ArrayList;

public class Student implements java.io.Serializable {
	private int stdID;
	private String firstName;
	private String lastName;
	private String courses;
	
	//constructors
	public Student() {
		
	}
	
	public Student(int stdID, String firstName, String lastName, String courses) {
		this.stdID = stdID;
		this.firstName = firstName;
		this.lastName = lastName;
		this.courses = courses;
	}
	
	//getters
	public int getStudentID() {
		return stdID;
	}

	public String getName() {
		return firstName + " " + lastName;
	}
	
	public String getCourses() {
		return courses;
	}
	
	//setters
	public void setStudentID(int stdID) {
		this.stdID = stdID;
	}

	public void setName(String firstName, String lastName) {
		this.firstName = firstName;
		this.lastName = lastName;
	}
	
	public void setCourses(String courses) {
		this.courses = courses;
	}
	

}
