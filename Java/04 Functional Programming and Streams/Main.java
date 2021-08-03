import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream; 

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Student[] students = {
				new Student("Jack", "Smith", 50.0, "IT"),
				new Student("Aaron", "Johnson", 76.0, "IT"),
				new Student("Maaria", "White", 35.8, "Business"),
				new Student("John", "White", 47.0, "Media"),
				new Student("Laney", "White", 62.0, "IT"),
				new Student("Jack", "Jones", 32.9, "Business"),
				new Student("Wesley", "Jones", 42.89, "Media") };

		List<Student> studentList = Arrays.asList(students);


		// Task 1: Prints all its elements
		System.out.println("Task 1:\n\nComplete Student list:");
		studentList.forEach(System.out::println); // *println(Object x): Prints an Object and then terminate the line.
		System.out.println("\n");

		// Task 2: Display Students with grades in the range 50.0-100.0, sorted into ascending order by grade
		System.out.println("Task 2:\n\nStudents who got 50.0-100.0 sorted by grade:");
		Stream<Student> StudentStream = studentList.stream();
		StudentStream.filter(StudentProcess.gradeInRange).sorted(Comparator.comparing(StudentProcess.grade)).forEach(System.out::println);
		// Comparator.comparing() returns Comparator object.
		System.out.println("\n");

		// Task 3: Display the first student in the collection with grade in the range 50.0-100.0
		System.out.println("Task 3:\n\nFirst Student who got 50.0-100.0:");
		StudentStream = studentList.stream();
		StudentStream.filter(StudentProcess.gradeInRange).limit(1).forEach(System.out::println);
		System.out.println("\n");

		// Task 4: Display the Students in ascending order by last name then first, then
		// in descending order by last name then first
		System.out.println("Task 4:\n\nStudents in ascending order by last name then first:");
		StudentStream = studentList.stream();
		StudentStream.sorted(Comparator.comparing(StudentProcess.lastName).thenComparing(StudentProcess.firstName)).forEach(System.out::println);
		System.out.println("\nStudents in descending order by last name then first:");
		StudentStream = studentList.stream();
		StudentStream.sorted(Comparator.comparing(StudentProcess.lastName).thenComparing(StudentProcess.firstName).reversed()).forEach(System.out::println);
		System.out.println("\n");

		// Task 5: Display unique Student last names, sorted.
		System.out.println("Task 5:\n\nUnique Student last names:");
		StudentStream = studentList.stream();
		StudentStream.map(StudentProcess.lastName).distinct().sorted().forEach(System.out::println);
		System.out.println("\n");

		// Task 6: Display Student full names, sorted in order by last name then first name.
		System.out.println("Task 6:\n\nStudent names in order by last name then first name:");
		StudentStream = studentList.stream();
		StudentStream.sorted(Comparator.comparing(StudentProcess.lastName).thenComparing(StudentProcess.firstName)).map(StudentProcess.fullName).forEach(System.out::println);
		System.out.println("\n");

		// Task 7: Display Students, grouped by their departments.
		System.out.println("Task 7:\n\nStudents by department:");
		Map<String, List<Student>> groupedByDepartment = studentList.stream().collect(Collectors.groupingBy(StudentProcess.department));
		groupedByDepartment.entrySet().forEach(StudentProcess.printByDepartment);
		System.out.println("\n");

		// Task 8: Count and display the number of Students in each department.
		System.out.println("Task 8:\n\nCount of Students by department:");
		Map<String, Long> countByDepartment = studentList.stream().collect(Collectors.groupingBy(StudentProcess.department, Collectors.counting()));
		countByDepartment.entrySet().forEach(StudentProcess.printCountByDepartment);
		System.out.println("\n");

		// Task 9: Calculate and display the sum of all Students’ grades.
		System.out.println("Task 9:\n");
		StudentStream = studentList.stream();
		double totalGrade = StudentStream.mapToDouble(StudentProcess.gradeForCalculation).sum();
		System.out.println("Sum of Students' grades: " + totalGrade);
		System.out.println("\n");

		// Task 10: Calculate and display the average of all Students’ grades. 
		System.out.println("Task 10:\n");
		StudentStream = studentList.stream();
		OptionalDouble avgGrade = StudentStream.mapToDouble(StudentProcess.gradeForCalculation).average();
		System.out.printf("Average of Students' grades: %.2f", avgGrade.getAsDouble());
		System.out.println("\n");
	}

}
