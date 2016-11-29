public class CmdCheckIn extends RecordedCommand {
    private Member borrower;
    private Book borrowedBook;

    @Override
    public void execute(String[] cmdParts) {//throws BookNotFound, MemberNotFound {
        for (Member m : Library.getInstance().getMembers())
            if (m.getID().equals(cmdParts[1]))
                borrower = m;
        for (Book b : Library.getInstance().getBooks())
            if (b.getID().equals(cmdParts[2]))
                borrowedBook = b;
        /*
        if (borrowedBook == null)
            throw new BookNotFound();
        if (borrower == null)
            throw new MemberNotFound();
        */
        try {
            borrowedBook.returnBy(borrower);
        } catch (ExBookNotBorrowedByThisMember e) {
            System.out.println(e.getMessage());
            return;
        }
        addUndoCommand(this); //<======
        clearRedoList(); //<======
        System.out.println("Done.");
    }

    @Override
    public void undoMe() {
        try {
            if (borrowedBook.isOnhold()) {
                borrowedBook.cancelAnnouncement();
            }
            borrowedBook.changeStatus(new BookStatusBorrowed(borrower, borrowedBook));
            borrower.borrow();
        } catch (ExLoanQuotaExceeded e) {
            System.out.println(e.getMessage());
        }
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        try {
            borrowedBook.returnBy(borrower);
        } catch (ExBookNotBorrowedByThisMember e) {
            System.out.println(e.getMessage());//could never be reached
        }
        addUndoCommand(this);
    }
}
