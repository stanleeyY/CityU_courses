
public class CmdArrive implements Command{

    @Override
    public void execute(String[] cmdParts) {
        try {
            if(Library.getInstance().getBooks().size()>0) {
                for (Book b : Library.getInstance().getBooks()) {
                    if (b.getID().equals(cmdParts[1]))
                        throw new ExBookIDinUse(b);
                }
            }
            Book newBook = new Book(cmdParts[1], cmdParts[2]);
            Library.getInstance().addBook(newBook);
            System.out.println("Done.");
        } catch (ExBookIDinUse e) {
            System.out.println(e.getMessage());
        }
    }
}
