import java.util.*;

public class BookStatusOnhold implements BookStatus {
    private Day dueDate;
    private Member newHolder;
    private Book referredBook;

    public BookStatusOnhold(Book b) {
        dueDate = SystemDate.getInstance().getNextDay().getNextDay().getNextDay();
        newHolder = b.getReservations().get(0);
        referredBook = b;
    }

    public Day getDueDate() {
        return dueDate;
    }

    public Member getNewHolder() {
        return newHolder;
    }

    @Override
    public String toString() {
        String s = "On holdshelf for " + newHolder.getID() + " " + newHolder.getName() + " until " + dueDate + " ";
        if (referredBook.getReservations().size() > 0) {
            s += String.format("+ %d request(s): ", referredBook.getReservations().size());
            for (Member m : referredBook.getReservations())
                s += m.getID() + " ";
        }
        return s;
    }
}