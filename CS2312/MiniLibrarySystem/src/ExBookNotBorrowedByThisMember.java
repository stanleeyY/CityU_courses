public class ExBookNotBorrowedByThisMember extends Exception {
    public ExBookNotBorrowedByThisMember() {
        super("The book is not borrowed by this member!");
    }
}