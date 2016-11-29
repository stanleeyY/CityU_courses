public interface Command {
    void execute(String[] cmdParts) throws ExBookNotFound, ExMemberNotFound, ExInsufficientCommand;
}