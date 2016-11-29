public class SystemDate extends Day implements Cloneable {
    private static SystemDate instance;

    private SystemDate(String sDay) {
        super(sDay);
    }


    public static SystemDate getInstance() {
        return instance;
    }

    public static void createTheInstance(String sDay) {
        if (instance != null) {
            instance = new SystemDate(sDay);
            for(Book b:Library.getInstance().getBooks())
                b.checkOnhold();
            System.out.println("Done.");
        } else {
            instance = new SystemDate(sDay);
        }
    }
    @Override
    public Day clone() {
        Day copy = (Day) super.clone();
        return copy;
    }

}