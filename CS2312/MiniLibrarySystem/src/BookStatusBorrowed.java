public class BookStatusBorrowed implements BookStatus {
    private Member borrowingMember;
    private Day loanDate;
    private Book referredBook;
    public BookStatusBorrowed(Member borrowingMember, Book book) throws ExLoanQuotaExceeded {
        if (borrowingMember.borrowQuotaFull())
            throw new ExLoanQuotaExceeded();
        this.borrowingMember = borrowingMember;
        this.loanDate = SystemDate.getInstance().clone();
        this.referredBook = book;
    }

    public Member getBorrowMember() {
        return this.borrowingMember;
    }
    @Override
    public String toString() {
        if (referredBook.getReservations().size() == 0)
            return String.format("Borrowed by %s %s on %s ", borrowingMember.getID(), borrowingMember.getName(), loanDate);
        String s = String.format("Borrowed by %s %s on %s + %d request(s): ", borrowingMember.getID(),
                borrowingMember.getName(), loanDate, referredBook.getReservations().size());
        for (Member m : referredBook.getReservations())
            s += m.getID() + " ";
        return s;
    }
}
