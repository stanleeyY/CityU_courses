import com.sun.org.apache.bcel.internal.generic.InstructionComparator;

public class Member implements Comparable<Member> {
    private String id;
    private String name;
    private Day joinDate;
    private double fine;
    private int borrowCounts;
    private int requestCounts;

    public Member(String id, String name) {
        this.id = id;
        this.name = name;
        joinDate = SystemDate.getInstance().clone();
    }

    @Override
    public String toString() {
        return String.format("%-5s%-10s%-12s  %-10d  %-10d", id, name, joinDate, borrowCounts, requestCounts);
    }

    public static String getListingHeader() {
        return String.format("%-5s%-10s%-12s%-12s%-12s", "ID", "Name", "Join Date", "#Borrowed", "#Requested");
    }

    public int compareTo(Member another) {
        return this.id.compareTo(another.id);
    }

    public String getID() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void borrow() {
        borrowCounts++;
    }

    public void unborrow() {
        borrowCounts--;
    }

    public void makerequest() {
        requestCounts++;
    }

    public void cancelrequest() {
        requestCounts--;
    }

    public boolean borrowQuotaFull() {
        return borrowCounts >= 6;
    }

    public boolean requestQuotaFull() {
        return requestCounts >= 3;
    }

}