public class CmdRegister implements Command //<=== note the change
{
    private Member newMember;

    @Override
    public void execute(String[] cmdParts) {
        Library lib = Library.getInstance();
        String theID = cmdParts[1];
        String theName = cmdParts[2];
        try {
            for (Member m : lib.getMembers()) {
                if (m.getID().equals(theID))
                    throw new ExMemberIDinUse(m);
            }
            newMember = new Member(theID, theName);
            lib.addMember(newMember);
            System.out.println("Done.");
        } catch (ExMemberIDinUse e) {
            System.out.println(e.getMessage());
        }
    }
}