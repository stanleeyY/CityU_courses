
public class ExBookBorrowedByThisMember extends Exception {
    public ExBookBorrowedByThisMember() {
        super("The book is already borrowed by the same member!");
    }
}
