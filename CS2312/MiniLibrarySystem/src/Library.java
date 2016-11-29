import java.util.*;

public class Library {
    private ArrayList<Member> members;
    private ArrayList<Book> books;
    private static Library instance = new Library();

    private Library() {
        members = new ArrayList<>();
        books = new ArrayList<>();
    }
    public static Library getInstance() {
        return instance;
    }

    public void addMember(Member newMember) {//run two times
        members.add(newMember);
        Collections.sort(members);
    }
    public void deleteMember(Member sayBye) {
        members.remove(sayBye);
    }
    public void addBook(Book newBook) {
        books.add(newBook);
        Collections.sort(members);
    }
    public void deleteBook(Book theBook) {
        books.remove(theBook);
    }
    public void listLibraryMembers() {
        System.out.println(Member.getListingHeader());
        for (Member m : members)
            System.out.println(m);
    }
    public void listLibraryBooks() {
        System.out.println(Book.getListingHeader());
        for (Book m : books)
            System.out.println(m);
    }
    public void checkoutBook(Book oldBook) {
        books.remove(oldBook);
    }
    public ArrayList<Member> getMembers() {
        return members;
    }
    public ArrayList<Book> getBooks() {
        return books;
    }

}