public class CmdCheckOut extends RecordedCommand {
    private Member borrower;
    private Book borrowedBook;
    private BookStatus originalStatus;
    @Override
    public void execute(String[] cmdParts) throws ExBookNotFound, ExMemberNotFound, ExInsufficientCommand {
        if(cmdParts.length<3)
            throw new ExInsufficientCommand();
        for (Member m : Library.getInstance().getMembers())
            if (m.getID().equals(cmdParts[1]))
                borrower = m;
        for (Book b : Library.getInstance().getBooks())
            if (b.getID().equals(cmdParts[2]))
                borrowedBook = b;
        if (borrowedBook == null)
            throw new ExBookNotFound();
        if (borrower == null)
            throw new ExMemberNotFound();
        try {
            originalStatus=borrowedBook.getStatus();
            borrowedBook.borrowedBy(borrower);
        } catch (ExBookBorrowedByOthers | ExLoanQuotaExceeded e) {
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
            if (!borrowedBook.isBorrowedBy(borrower))
                throw new ExBookNotBorrowedByThisMember();
            borrower.unborrow();
            borrowedBook.changeStatus(originalStatus);
        } catch (ExBookNotBorrowedByThisMember e) {
            System.out.println(e.getMessage());//could never be reached
        }
        addRedoCommand(this);
    }
    @Override
    public void redoMe() {
        try {
            borrowedBook.borrowedBy(borrower);
        } catch (ExBookBorrowedByOthers | ExLoanQuotaExceeded e) {
            System.out.println(e.getMessage());
        }
        addUndoCommand(this);
    }
}
