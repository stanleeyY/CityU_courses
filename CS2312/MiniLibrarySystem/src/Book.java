import java.util.*;

public class Book {
    private String id;
    private String name;
    private Day arrivalDate;
    private BookStatus status;
    private ArrayList<Member> reservations;

    public Book(String id, String name) {
        this.id = id;
        this.name = name;
        this.arrivalDate = SystemDate.getInstance();
        status = new BookStatusAvailable();
        reservations = new ArrayList<Member>();
    }

    public void borrowedBy(Member m) throws ExBookBorrowedByOthers, ExLoanQuotaExceeded {
        if (status instanceof BookStatusBorrowed)
            throw new ExBookBorrowedByOthers();
        if(status instanceof BookStatusOnhold) {
            if (!((BookStatusOnhold) status).getNewHolder().getID().equals(m.getID()))
                throw new ExBookBorrowedByOthers();
        }
        this.status = new BookStatusBorrowed(m, this);
        m.borrow();
    }

    public void addToTop(Member m) {
        m.makerequest();
        ArrayList<Member> newlist = new ArrayList<>();
        newlist.add(m);
        for (Member n : getReservations())
            newlist.add(n);
        reservations = newlist;
    }

    public void cancelAnnouncement() {
        System.out.println(String.format("Sorry. %s %s please ignore the pick up notice for %s %s.",
                ((BookStatusOnhold) status).getNewHolder().getID(),
                ((BookStatusOnhold) status).getNewHolder().getName(), id, name));
        addToTop(((BookStatusOnhold) status).getNewHolder());
    }

    public void returnBy(Member m) throws ExBookNotBorrowedByThisMember {
        if (!this.isBorrowedBy(m))
            throw new ExBookNotBorrowedByThisMember();
        m.unborrow();
        if (reservations.isEmpty())
            status = new BookStatusAvailable();
        else
            holding();
    }

    public void holding() {
        this.status = new BookStatusOnhold(this);
        System.out.println("Book [" + id + " " + name + "] is ready for pick up by ["
                + reservations.get(0).getID() + " " + reservations.get(0).getName() + "].  On hold due on "
                + SystemDate.getInstance().getNextDay().getNextDay().getNextDay() + ".");
        reservations.get(0).cancelrequest();
        reservations.remove(0);
    }

    public int addReserve(Member m) throws ExBookRequestQuotaExceed, ExRequestedBookIsAvailable {
        if (m.requestQuotaFull())
            throw new ExBookRequestQuotaExceed();
        if (status instanceof BookStatusOnhold && ((BookStatusOnhold) status).getNewHolder().getID().equals(m.getID()))
            throw new ExRequestedBookIsAvailable();
        reservations.add(m);
        m.makerequest();
        //Collections.sort(reservations);
        return reservations.size();
    }

    public void cancelReserve(Member requester) {
        reservations.remove(requester);
        requester.cancelrequest();
    }

    public boolean isBorrowedBy(Member m) {
        return status instanceof BookStatusBorrowed && ((BookStatusBorrowed) status).getBorrowMember() == m;
    }

    @Override
    public String toString() {
        return String.format("%-5s%-20s%-12s%s", id, name, arrivalDate, status);
    }

    public static String getListingHeader() {
        return String.format("%-5s%-20s%-12s%s", "ID", "Name", "Arrival", "Status");
    }

    public String getID() {
        return id;
    }

    public String getName() {
        return name;
    }

    public ArrayList<Member> getReservations() {
        return reservations;
    }

    public int compareTo(Book another) {
        return this.id.compareTo(another.id);
    }

    public boolean isAvailable() {
        return status instanceof BookStatusAvailable;
    }

    public void checkBorrowIsValid(Member requester) throws ExRequestedBookIsAvailable, ExBookHasBeenRequested, ExBookBorrowedByThisMember {
        if (this.status instanceof BookStatusAvailable)
            throw new ExRequestedBookIsAvailable();

        if (this.status instanceof BookStatusBorrowed &&
                ((BookStatusBorrowed) status).getBorrowMember() == requester)
            throw new ExBookBorrowedByThisMember();
        boolean requesterRequestedThisBook = false;
        for (Member m : reservations) {
            if (m == requester) {
                requesterRequestedThisBook = true;
                break;
            }
        }
        if (requesterRequestedThisBook) {
            throw new ExBookHasBeenRequested();
        }
    }

    public void checkOnhold() {
        if (status instanceof BookStatusOnhold)
            if (((BookStatusOnhold) status).getDueDate().compareTo(SystemDate.getInstance()) < 0) {
                System.out.printf("On hold period is over for %s %s.\n", id, name);
                if (reservations.isEmpty())
                    status = new BookStatusAvailable();
                else
                    holding();
            }
    }

    public boolean isOnhold() {
        return status instanceof BookStatusOnhold;
    }

    public void changeStatus(BookStatus newStatus) {
        status = newStatus;
    }

    public BookStatus getStatus() {
        return status;
    }
}