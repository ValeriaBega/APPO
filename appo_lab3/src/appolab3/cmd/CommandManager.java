package appolab3.cmd;

import java.util.LinkedList;
import java.util.List;

public class CommandManager {

    private static final int A = 30;
    private static final int B = 6;
    private List<Command> commands = new LinkedList<>();


    public CommandManager() {
        commands.add(new addition());
        commands.add(new subtraction());
        commands.add(new division());
        commands.add(new multiplication());
    }

    public void executeCommands() {
        commands.forEach(command -> System.out.println(command.compute(A, B)));
    }
}
