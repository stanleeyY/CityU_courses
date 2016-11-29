
public class CmdRequest extends RecordedCommand {
    private Member requester;
    private Book requestedBook;

    @Override
    public void execute(String[] cmdParts) throws ExBookNotFound, ExMemberNotFound, ExInsufficientCommand {
        if(cmdParts.length<3)
            throw new ExInsufficientCommand();
        for (Member m : Library.getInstance().getMembers())
            if (m.getID().equals(cmdParts[1]))
                requester = m;
        for (Book b : Library.getInstance().getBooks())
            if (b.getID().equals(cmdParts[2]))
                requestedBook = b;
        if (requestedBook == null)
            throw new ExBookNotFound();
        if (requester == null)
            throw new ExMemberNotFound();
        try {
            requestedBook.checkBorrowIsValid(requester);
            int numberOfReservation = requestedBook.addReserve(requester);
            addUndoCommand(this); //<======
            clearRedoList(); //<======
            System.out.println("Done. This request is no. " + numberOfReservation + " in the queue.");
        } catch (ExBookRequestQuotaExceed | ExRequestedBookIsAvailable | ExBookHasBeenRequested | ExBookBorrowedByThisMember e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void undoMe() {
        requestedBook.cancelReserve(requester);
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        try {
            requestedBook.addReserve(requester);
        } catch (ExBookRequestQuotaExceed | ExRequestedBookIsAvailable e) {
            System.out.println(e.getMessage());
        }
        addUndoCommand(this);
    }

}

