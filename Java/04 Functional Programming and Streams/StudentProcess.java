import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.ToDoubleFunction;
import java.util.function.Consumer;

public class StudentProcess {
	
	// Lambdas should be in related classes, not main.
	public static final Predicate<Student> gradeInRange = stu -> stu.getGrade() >= 50.00 && stu.getGrade() <= 100.00;
	public static final Function<Student, String> fullName = stu -> stu.getName();
	public static final Function<Student, String> firstName = stu -> stu.getFirstName();
	public static final Function<Student, String> lastName = stu -> stu.getLastName();
	public static final Function<Student, Double> grade = stu -> stu.getGrade();
	public static final Function<Student, String> department = stu -> stu.getDepartment();
	public static final Consumer<Map.Entry<String, List<Student>>> printByDepartment = entry -> {
		System.out.println(entry.getKey());
		entry.getValue().forEach(stu -> System.out.println("   " + stu));
	};
	public static final Consumer<Map.Entry<String, Long>> printCountByDepartment = entry -> System.out.println(entry.getKey() + " has " + entry.getValue() + " Student(s)");
	public static final ToDoubleFunction<Student> gradeForCalculation = stu -> stu.getGrade();


}
