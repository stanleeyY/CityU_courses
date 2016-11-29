import java.util.Collections;

public class CmdCancelRequest extends RecordedCommand {
    private Member requester;
    private Book requestedBook;

    @Override
    public void execute(String[] cmdParts) throws ExBookNotFound, ExMemberNotFound {
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
        boolean cancelable = false;
        for (Member m : requestedBook.getReservations())
            if (m.getID().equals(requester.getID()))
                cancelable = true;
        try {
            if (!cancelable)
                throw new ExRequestRecordNotFound();

            requestedBook.getReservations().remove(requester);
            requester.cancelrequest();
            addUndoCommand(this); //<======
            clearRedoList(); //<======
            System.out.println("Done.");
        } catch (ExRequestRecordNotFound e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void undoMe() {
        requestedBook.getReservations().add(requester);
        Collections.sort(requestedBook.getReservations());
        requester.makerequest();
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        boolean cancelable = false;
        for (Member m : requestedBook.getReservations())
            if (m.getID().equals(requester.getID()))
                cancelable = true;
        try {
            if (!cancelable)
                throw new ExRequestRecordNotFound();
            requestedBook.getReservations().remove(requester);
            requester.cancelrequest();
            addUndoCommand(this);
        } catch (ExRequestRecordNotFound e) {
            System.out.println(e.getMessage());
        }
    }
}
