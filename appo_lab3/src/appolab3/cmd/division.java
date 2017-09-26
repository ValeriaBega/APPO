package appolab3.cmd;

public class division implements Command {
    /**
     * @param a - simple variable of integer type
     * @param b - simple variable of integer type
     * @return Division of A over B
     */
    @Override
    public int compute(int a, int b) {
        return a / b;
    }
}
