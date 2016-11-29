
public class ExBookHasBeenRequested extends Throwable {
    public ExBookHasBeenRequested() {
        super("The same member has already requested the book!");
    }
}
