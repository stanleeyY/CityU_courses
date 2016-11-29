
public class ExMemberIDinUse extends Exception {

    public ExMemberIDinUse(Member oldMember) {
        super(String.format("Member ID already in use: %s %s", oldMember.getID(), oldMember.getName()));
    }
}