public class CmdStartNewDay implements Command //<=== note the change
{

    @Override
    public void execute(String[] cmdParts) {
        SystemDate.createTheInstance(cmdParts[1]);
    }
}