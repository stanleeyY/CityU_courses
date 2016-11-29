public class CmdListMembers implements Command //<=== note the change
{
    @Override
    public void execute(String[] cmdParts) {
        Library.getInstance().listLibraryMembers();
    }
}