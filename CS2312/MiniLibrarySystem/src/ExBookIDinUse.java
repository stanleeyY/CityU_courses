public class ExBookIDinUse extends Exception {

    public ExBookIDinUse(Book oldBook) {
        super(String.format("Book ID already in use: %s %s", oldBook.getID(), oldBook.getName()));
    }
}